#pragma once
#include "../pch.hpp"

enum Ranks : int { two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, jack = 11, queen = 12, king = 13, ace = 1, faceDown = 0 };
enum Suits : int { spades = 0, clubs = 1, diamonds = 2, hearts = 3};

class Card
{
protected:
	Ranks m_value;
	Suits m_suit;
	bool m_faceUp{ false }; //0 - рубашкой кверху, 1 - в открытую
public:
	Card(Ranks value, Suits suit, bool faceUp = 0) : m_value(value), m_suit(suit), m_faceUp(faceUp) {}
	virtual ~Card() {}
	void Flip();

	friend std::ostream& operator<<(std::ostream& out, const Card &card);

	Ranks GetCardValue() const;
};


class Hand
{
protected:
	std::vector<Card*> m_hand;
public:
	Hand() {}
	virtual ~Hand() {}

	void Add(Card* card);

	void Clear();

	int GetValue() const;
};

class GenericPlayer : public Hand
{
protected:
	std::string m_name;
public:
	GenericPlayer(std::string name) : Hand(), m_name(name) {}
	virtual ~GenericPlayer() {}

	virtual bool IsHitting() const = 0;

	bool IsBoosted() const;

	void Bust() const;

	friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& player);
};


class Player : public GenericPlayer
{
public:
	Player(std::string name) : GenericPlayer(name) {};
	~Player() {};

	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};

class House : public GenericPlayer
{
public:
	House(std::string name = "Диллер") : GenericPlayer(name) {};
	~House() {};
	virtual bool IsHitting() const;
	void FlipFirstCard();
};