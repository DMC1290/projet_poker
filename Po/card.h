#ifndef CARD_H
#define CARD_H

#include "enum.h"
#include <iostream>

class Card
{
public:
    Suit suit;
    Value value;

    Card(Suit s, Value v) : suit(s), value(v) {}

    std::string ToString() const
	{
        return valueToString(value) + " of " + suitToString(suit);
    }
};

#endif