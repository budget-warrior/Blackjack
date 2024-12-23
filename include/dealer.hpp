#pragma once

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>

namespace dealer
{
    // Returns a random card
    int get_random_card();

    // Draws the dealer's cards
    std::vector<int> generate_dealer_cards();

    // Adds the values of all of the cards
    int add_card_values(std::vector<int> cards);

    // Prints the value of the card (ace is 1 or 11 and also the possibility of a 10 being a J, Q or a K)
    void display_card_value(int card);
}
