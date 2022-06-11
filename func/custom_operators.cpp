#pragma once
#include "../pch.hpp"
#include "BJ_Classes_Functions.h"

//Operator overloads
std::ostream& operator<<(std::ostream& out, const Card& card)
{
	if (card.m_faceUp == false)
	{
		out << "XX";
	}
	else
	{
		switch (card.m_value)
		{
		case(ace):
			out << "ace" << " of ";
			break;
		case(jack):
			out << "jack" << " of ";
			break;
		case(queen):
			out << "queen" << " of ";
			break;
		case(king):
			out << "king" << " of ";
			break;
		case(ten):
			out << "ten" << " of ";
			break;
		case(nine):
			out << "nine" << " of ";
			break;
		case(eight):
			out << "eight" << " of ";
			break;
		case(seven):
			out << "seven" << " of ";
			break;
		case(six):
			out << "six" << " of ";
			break;
		case(five):
			out << "five" << " of ";
			break;
		case(four):
			out << "four" << " of ";
			break;
		case(three):
			out << "three" << " of ";
			break;
		case(two):
			out << "two" << " of ";
			break;
		default:
			out << "fail";
		}

		switch (card.m_suit)
		{
		case(spades):
			out << "spades";
			break;
		case(hearts):
			out << "hearts";
			break;
		case(clubs):
			out << "clubs";
			break;
		case(diamonds):
			out << "diamonds";
			break;
		default:
			out << "fail";
		}
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
{
	if (player.m_name == "Диллер")
		out << "Диллер имеет на руках следующие карты: \n";
	else
		out << "Игрок " << player.m_name << " имеет на руках следующие карты: \n";
	for (size_t i = 0; i < player.m_hand.size(); i++)
	{
		out << *(player.m_hand[i]) << '\n';
	}
	out << "Сумма всех карт игрока равна: " << player.GetValue() << '\n';
	return out;
};

