#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Card{
friend ostream& operator<<(ostream& os, const Card& aCard);

public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;

};

Card::Card(rank r, suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const{
	int value = 0;
	if(m_IsFaceUp){
	  value = m_Rank;
	  if(value > 10)
	    value = 10;
	}
	return value;
}

void Card::Flip(){
	m_IsFaceUp = !m_IsFaceUp;
}
