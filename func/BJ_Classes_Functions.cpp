#pragma once
#include "../pch.hpp"
#include "BJ_Classes_Functions.h"

//Card class methods:

void Card::Flip()
{
	m_faceUp = !m_faceUp;
}


Ranks Card::GetCardValue() const
{
	return m_value;
}


//Hand class methods:

void Hand::Add(Card* card)
{
	m_hand.push_back(card);
}

void Hand::Clear()
{
	m_hand.clear();
	m_hand.resize(0);
	m_hand.shrink_to_fit();
}

int Hand::GetValue() const
{
	int sum{ 0 };
	int aces{ 0 };
	for (size_t i = 0; i < m_hand.size(); i++)
	{
		if (m_hand[i]->GetCardValue() == ace)
		{
			sum += 11;
			aces++;
		}
		else if (m_hand[i]->GetCardValue() == jack || m_hand[i]->GetCardValue() == queen || m_hand[i]->GetCardValue() == king)
			sum += 10;
		else
			sum += m_hand[i]->GetCardValue();
	}

	//if total value exceeds 21 we remove extra 10 points per ace reducing it from 11 to 1. This way aces work even if drawn from index 0 and value exceeds 21 later on
	if (sum > 21 && aces > 0)
		sum = sum - (aces * 10);

	return sum;
}

//GenericPlayer class methods:
bool GenericPlayer::IsBoosted() const
{
	if (GetValue() > 21)
		return true;
	else
		return false;
};

void GenericPlayer::Bust() const
{
	std::cout << "� ������ " << m_name << " �������!" << std::endl;
};

//Player class methods
bool Player::IsHitting() const
{
	std::string t;
	std::cout << "����� " << m_name << ", ����� �� ��� ��� �����? ";
	for (;;) //fool protection
	{
		std::cin >> t;
		if (t == "yes" || t == "Yes" || t == "y" || t == "Y" || t == "��" || t == "�" || t == "��" || t == "�" || t == "no" || t == "No" || t == "n" || t == "N" || t == "���" || t == "�" || t == "���" || t == "�")
			break;
		else
		{
			std::cout << "������������ ����! ������� Enter � ���������� �����!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << '\n' << "����� �� ��� ��� �����? ";
			t.clear();
		}
	}
	if (t == "yes" || t == "Yes" || t == "y" || t == "Y" || t == "��" || t == "�" || t == "��" || t == "�")
		return true;
	else
		return false;
}

void Player::Win() const { std::cout << "����� " << m_name << " �������!" << "\n"; }
void Player::Lose() const { std::cout << "����� " << m_name << " ��������!" << "\n"; }
void Player::Push() const { std::cout << "� ������ " << m_name << " � ������� ����� �������!" << "\n"; }

//House class methods
bool House::IsHitting() const
{
	if (GetValue() < 17)
		return true;
	else
		return false;
}

void House::FlipFirstCard()
{
	m_hand[0]->Flip();
}