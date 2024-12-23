#include "../include/dealer.hpp"

namespace dealer
{
    bool should_draw_card(bool busts, int total_card_value)
    {
        return busts || total_card_value <= 17;
    }

    int get_random_card()
    {
        return 1 + (rand() % 10);
    }

    std::vector<int> generate_dealer_cards()
    {
        bool busts = rand() % 101 < 10; // there is a 10% chance that the dealer busts
        std::vector<int> cards = {get_random_card(), get_random_card()};

        while (should_draw_card(busts, add_card_values(cards)))
        {
            // The dealer should draw, so generate a random card and add it to the cards array
            cards.push_back(get_random_card());
        }

        return cards;
    }

    int add_card_values(std::vector<int> cards)
    {
        int total = 0, aces = 0;

        std::sort(cards.begin(), cards.end(), std::greater<>());

        for (const int card : cards)
        {
            if (card == 1)
            {
                aces++;
            }
            else
            {
                total += card;
            }
        }

        if (aces > 1)
        {
            // equivalent to total + 11 + (aces - 1)
            // the main idea is that only one of the aces can be 11 at a time
            if (total + 10 + aces < 21)
            {
                total += 10 + aces;
            }
            else
            {
                total += aces;
            }
        }
        else
        {
            if (total + 11 > 21)
            {
                total += 1;
            }
            else
            {
                total += 11;
            }
        }

        return total;
    }

    void display_card_value(int card)
    {
        if (card == 1)
        {
            std::cout << "A\n";
        }
        else if (card > 1 && card < 10)
        {
            std::cout << card << '\n';
        }
        else
        {
            int chance = rand() % 101;

            if (chance < 10)
            {
                std::cout << "10\n";
            }
            else if (chance < 30)
            {
                std::cout << "J\n";
            }
            else if (chance < 60)
            {
                std::cout << "Q\n";
            }
            else
            {
                std::cout << "K\n";
            }
        }
    }
}
