#pragma once
#include "../pch.hpp"
#include "BJ_Extra_Functions.hpp"
#include "BJ_Classes_Functions.h"

//Deck methods
void Deck::Populate()
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t k = 1; k < 14; k++)
		{
			Suits s = static_cast<Suits>(i);
			Ranks r = static_cast<Ranks>(k);
			Card aCard(r, s, 1);
			this->Add(&aCard);
			delete &aCard;
		}
		
	}
	return;
}