#ifndef ENUMS_H
#define ENUMS_H

#include <string>

enum class Suit { Clubs, Diamonds, Hearts, Spades };
enum class Value { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };


std::string suitToString(Suit suit)
{
    switch (suit) {
    case Suit::Clubs: return "Clubs";
    case Suit::Diamonds: return "Diamonds";
    case Suit::Hearts: return "Hearts";
    case Suit::Spades: return "Spades";
    default: return "Unknown";
    }
}


std::string valueToString(Value value)
{
    switch (value) {
    case Value::Two: return "2";
    case Value::Three: return "3";
    case Value::Four: return "4";
    case Value::Five: return "5";
    case Value::Six: return "6";
    case Value::Seven: return "7";
    case Value::Eight: return "8";
    case Value::Nine: return "9";
    case Value::Ten: return "10";
    case Value::Jack: return "Jack";
    case Value::Queen: return "Queen";
    case Value::King: return "King";
    case Value::Ace: return "Ace";
    default: return "Unknown";
    }
}

#endif