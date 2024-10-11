#ifndef DEALER_H
#define DEALER_H

#include "card.h"
#include <vector>

class Dealer
{
public:
	std::vector<Card> communityCards;

	void addCommunityCard(const Card& card)
	{
		communityCards.push_back(card);
	}

	void showCommunityCards() const
	{
		std::cout << "Community Cards:" << std::endl;
		for (const Card& card : communityCards) {
			std::cout << card.ToString() << std::endl;
		}
	}
};
#endif