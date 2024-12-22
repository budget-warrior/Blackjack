#include <iostream>

#include "../include/dealer.hpp"

void game()
{
    std::vector<int> dealer_cards = dealer::generate_dealer_cards();
    int dealer_total = dealer::add_card_values(dealer_cards);

    std::cout << "Your cards are:\n";
    std::vector<int> player_cards = {1, 1};
    int player_total = dealer::add_card_values(player_cards);
    for (const int card : player_cards)
    {
        dealer::display_card_value(card);
    }
    std::cout << "Your total is: " << player_total << '\n';

    bool bust = false;

    while (bust == false)
    {
        if (player_total == 21)
        {
            break;
        }

        std::cout << "Hit (h) or stand (s)? ";
        char answer;
        std::cin >> answer;

        if (answer == 's')
        {
            break;
        }
        else if (answer == 'h')
        {
            int card = dealer::get_random_card();

            std::cout << "Your card is: ";
            dealer::display_card_value(card);

            player_cards.push_back(card);
            player_total = dealer::add_card_values(player_cards);
            std::cout << "Your total now is: " << player_total << '\n';

            if (player_total > 21)
            {
                bust = true;
            }
        }
        else if (answer != 'h' || answer != 's')
        {
            std::cout << "Reply with the character 'h' (if you want to hit) or 's' (if you want to stand)!\n";
        }
    }

    if (bust)
    {
        std::cout << "You busted! Dealer wins.";
    }
    else
    {
        if (player_total == 21)
        {
            std::cout << "Blackjack! You win.";
            return;
        }

        std::cout << "Dealer's cards:\n";

        for (const int card : dealer_cards)
        {
            dealer::display_card_value(card);
        }
        std::cout << "Dealer's total: " << dealer_total << '\n';

        if (dealer_total > 21)
        {
            std::cout << "Dealer busted! You win!";
        }
        else if (dealer_total > player_total)
        {
            std::cout << "The dealer has a better hand than yours. Dealer wins.";
        }
        else if (dealer_total == player_total)
        {
            std::cout << "Push! You and the dealer have the same total.";
        }
        else
        {
            std::cout << "You have a better hand than the dealer. You win.";
        }
    }
}

int main()
{
    srand(time(NULL));
    game();

    return 0;
}