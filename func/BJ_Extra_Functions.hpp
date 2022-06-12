#pragma once
#include "../pch.hpp"
#include "BJ_Classes_Functions.h"

/*
—оздать класс Deck, который наследует от класса Hand и представл€ет собой колоду карт.  ласс Deck имеет 4 метода:
Х vold Populate() - —оздает стандартную колоду из 52 карт, вызываетс€ из конструктора.
Х void Shuffle() - ћетод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
Х vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
Х void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор,
  пока он может и хочет их получать

ќбратите внимание на применение полиморфизма. ¬ каких методах примен€етс€ этот принцип ќќѕ?
*/

class Deck : public Hand
{
protected:
	void Populate();
public:
	Deck() { void Populate(); };
	~Deck() {};

	//void Shuffle();
	//void Deal(Hand& aHand);
	//void AdditionalCards(GenericPlayer& aGenerlcPlayer);
};