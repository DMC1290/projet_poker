#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player
{
public:
    std::vector<Card> hand;
    int balance;
    bool isActive;

    Player(int initialBalance) : balance(initialBalance), isActive(true) {}

    void addCard(const Card& card)
	{
        hand.push_back(card);
    }

    void showHand() const
	{
        for (const Card& card : hand) 
        {
            std::cout << card.ToString() << std::endl;
        }
    }

    bool placeBet(int amount)
	{
        if (amount <= balance) 
        {
            balance -= amount;
            return true;
        }
        else 
        {
            std::cout << "Not enough balance!" << std::endl;
            return false;
        }
    }

    void fold()
	{
        isActive = false;
        std::cout << "Player has folded." << std::endl;
    }

    void check()
	{
        std::cout << "Player checks." << std::endl;
    }

    bool isInGame() const
	{
        return isActive;
    }
};

#endif
