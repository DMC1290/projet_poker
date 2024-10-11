#include <iostream>
#include "deck.h"
#include "player.h"
#include "dealer.h"

class PokerGame
{
private:
    Deck deck;
    Player player1;
    Player player2;
    Dealer dealer;
    int pot;

public:
    PokerGame() : player1(1000), player2(1000), pot(0)
	{
        deck.shuffle();
    }

    void dealInitialHands()
	{
        player1.addCard(deck.dealCard());
        player1.addCard(deck.dealCard());

        player2.addCard(deck.dealCard());
        player2.addCard(deck.dealCard());
    }

    void dealFlop()
	{
        for (int i = 0; i < 3; i++) {
            dealer.addCommunityCard(deck.dealCard());
        }
    }

    void dealTurn()
	{
        dealer.addCommunityCard(deck.dealCard());
    }

    void dealRiver()
	{
        dealer.addCommunityCard(deck.dealCard());
    }

    void showHands() const
	{
        std::cout << "Player 1's Hand:" << std::endl;
        player1.showHand();

        std::cout << "Player 2's Hand:" << std::endl;
            player2.showHand();
    }

    void showCommunityCards() const
	{
        dealer.showCommunityCards();
    }

    void bettingRound(Player& player)
	{
        if (!player.isInGame()) 
        {
            return;
        }

        std::cout << "Player's balance: " << player.balance << std::endl;
        std::cout << "1. Bet 2. Check 3. Fold" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice)
    	{
        case 1: 
        {
            std::cout << "Enter bet amount: ";
            int bet;
            std::cin >> bet;
            if (player.placeBet(bet)) 
            {
                pot += bet;
            }
            break;
        }
        case 2:
            player.check();
            break;
        case 3:
            player.fold();
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }

    void preFlopBetting()
	{
        std::cout << "\nPre-Flop Betting Round" << std::endl;
        bettingRound(player1);
        bettingRound(player2);
    }

    void flopBetting()
	{
        std::cout << "\nFlop Betting Round" << std::endl;
        bettingRound(player1);
        bettingRound(player2);
    }

    void turnBetting()
	{
        std::cout << "\nTurn Betting Round" << std::endl;
        bettingRound(player1);
        bettingRound(player2);
    }

    void riverBetting()
	{
        std::cout << "\nRiver Betting Round" << std::endl;
        bettingRound(player1);
        bettingRound(player2);
    }

    void determineWinner()
	{
        std::cout << "\nComparing hands to determine winner..." << std::endl;
        std::cout << "It's a tie for now!" << std::endl;
    }

    void play()
	{
        dealInitialHands();
        showHands();
        preFlopBetting();

        dealFlop();
        showCommunityCards();
        showHands();
        flopBetting();

        dealTurn();
        showCommunityCards();
        showHands();
        turnBetting();

        dealRiver();
        showCommunityCards();
        showHands();
        riverBetting();

        determineWinner();
    }
};

int main()
{
    PokerGame game;
    game.play();

    return 0;
}