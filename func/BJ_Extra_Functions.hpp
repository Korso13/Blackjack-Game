#pragma once
#include "../pch.hpp"
#include "BJ_Classes_Functions.h"

//=======================================================================================================================================
//Task 3. Deck class
//=======================================================================================================================================

class Deck : public Hand
{
public:
	Deck() { Populate(); };
	~Deck() { m_hand.clear(); };

	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};

//=======================================================================================================================================
//Task 4. Game class
//=======================================================================================================================================

class Game
{
private:
	Deck Deck;
	House Dealer;
	std::vector<Player> Players;
public:
	Game(std::vector<std::string> _Players);
	~Game() { Players.clear(); };

	void play();
};