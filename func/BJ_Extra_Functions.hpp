#pragma once
#include "../pch.hpp"
#include "BJ_Classes_Functions.h"

/*
������� ����� Deck, ������� ��������� �� ������ Hand � ������������ ����� ������ ����. ����� Deck ����� 4 ������:
� vold Populate() - ������� ����������� ������ �� 52 ����, ���������� �� ������������.
� void Shuffle() - �����, ������� ������ �����, ����� ������������ ������� �� ���������� STL random_shuffle
� vold Deal (Hand& aHand) - �����, ������� ������� � ���� ���� �����
� void AddltionalCards (GenericPlayer& aGenerlcPlayer) - ������� ������ �������������� ����� �� ��� ���,
  ���� �� ����� � ����� �� ��������

�������� �������� �� ���������� ������������. � ����� ������� ����������� ���� ������� ���?
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