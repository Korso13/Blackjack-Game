#pragma once
#include "../pch.hpp"
#include "BJ_Extra_Functions.hpp"
#include "BJ_Classes_Functions.h"
#include "custom_operators.h"
#include <algorithm>

//Deck methods
void Deck::Populate()
{
	this->Clear();
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 1; k < 14; k++)
		{
			Suits s = static_cast<Suits>(i);
			Ranks r = static_cast<Ranks>(k);
			this->Add(new Card(r, s, 1));
		}
	}
	return;
}

void Deck::Shuffle()
{
	auto start = m_hand.begin();
	auto end = m_hand.end();
	std::random_shuffle(start, end);
	return;
}

void Deck::Deal(Hand& aHand)
{
	if (!m_hand.empty())
	{
		aHand.Add(m_hand.back());
		m_hand.pop_back();
	}
	else
	{
		std::cout << "Deck out of cards!" << std::endl; //should actually return bool false here to trigger use of next deck (put decks in own vector with 1 being last)
	}
	return;
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << std::endl;
	while (aGenericPlayer.IsHitting() && !(aGenericPlayer.IsBoosted()))
	{
		this->Deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;
		if (aGenericPlayer.IsBoosted())
		{
			aGenericPlayer.Bust();
			return;
		}
	}
	return;
}

//Game methods

Game::Game(std::vector<std::string> _Players)
{
	for (size_t i = 0; i < _Players.size(); i++)
	{
		Players.push_back(*(new Player(_Players[i])));
	}
	Deck.Populate();
	Deck.Shuffle();
}

void Game::play()
{
	//Dealing starting cards
	Deck.Deal(Dealer);			
	Deck.Deal(Dealer);
	Dealer.FlipFirstCard();
	for (size_t i = 0; i < Players.size(); i++)  
	{
		Deck.Deal(Players[i]);
		Deck.Deal(Players[i]);
		std::cout << Players[i] << std::endl;	//And printing them in console
	}
	std::cout << Dealer << std::endl;
	
	//now asking if anyone needs extra cards
	for (size_t i = 0; i < Players.size(); i++)
	{
		std::cout << std::endl << Players[i];
		Deck.AdditionalCards(Players[i]);
	}
	
	//Now dealer opens card and deals oneself
	Dealer.FlipFirstCard();
	std::cout << std::endl;
	std::cout << std::endl << Dealer;
	Deck.AdditionalCards(Dealer);

	//Now we determine winners and chicken dinners :)
	for (size_t i = 0; i < Players.size(); i++)
	{
		if (Players[i].GetValue() == Dealer.GetValue() && !(Players[i].IsBoosted()))
			Players[i].Push();
		else if (Players[i].GetValue() > Dealer.GetValue() && !(Players[i].IsBoosted()))
			Players[i].Win();
		else if(Players[i].GetValue() < Dealer.GetValue() && Dealer.IsBoosted())
			Players[i].Win();
		else if(Players[i].IsBoosted() && Dealer.IsBoosted())
			Players[i].Push();
		else
			Players[i].Lose();
	}

	//Printing out end of the game hands for clarity (and debugging) and then clear them
	std::cout << std::endl;
	std::cout << Dealer << std::endl;
	Dealer.Clear();
	for (size_t i = 0; i < Players.size(); i++)
	{
		std::cout << Players[i] << std::endl;
		Players[i].Clear();
	}

}