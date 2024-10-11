#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck()
	{
        for (int s = 0; s <= 3; s++) 
        {
            for (int v = 2; v <= 14; v++) 
            {
                cards.push_back(Card(static_cast<Suit>(s), static_cast<Value>(v)));
            }
        }
    }

    void shuffle()
	{
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
    }

    Card dealCard()
	{
        Card dealt = cards.back();
        cards.pop_back();
        return dealt;
    }
};

#endif