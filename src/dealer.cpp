#include "../include/dealer.hpp"

namespace dealer
{
    namespace // Anonymous namespace so that only the functions inside of the namespace can access should_draw_card
    {
        bool should_draw_card(bool busts, int total_card_value)
        {
            if (busts)
                return true;

            if (total_card_value <= 17)
                return true;
            else
                return false;
        }

    }

    int get_random_card()
    {
        int card = 1 + (rand() % 10);

        return card;
    }

    std::vector<int> generate_dealer_cards()
    {
        bool busts = false;
        if (rand() % 101 < 10)
        {
            busts = true; // there is a 10% chance that the dealer busts
        }

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
        int total = 0;

        std::sort(cards.begin(), cards.end(), std::greater<>());

        for (const int card : cards)
        {
            if (card == 1)
            {
                int aces = 0;
                for (const int c : cards)
                {
                    if (c == 1)
                    {
                        aces++;
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
                    break;
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
            }
            else
            {
                total += card;
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
