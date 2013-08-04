#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hand{
public:
	Hand();
	virtual ~Hand();
	// add a card to the hand
	void Add(Card* aCard);
	// clear hand of all cards
	void Clear();
	int GetTotal() const;

protected:
	vector<Card*> m_Cards;
};

Hand::Hand(){
	m_Cards.reserve(7);
}

Hand::~Hand(){
	Clear();
}

void Hand::Add(Card* pCard){
	m_Cards.push_back(pCard);
}

void Hand::Clear(){
	vector<Card*>::iterator iter = m_Cards.begin();
	for(iter = m_Cards.begin(); iter != m_Cards.end(); iter++){
	  delete *iter;
	  *iter = NULL;
	}
	m_Cards.clear();
}

int Hand::GetTotal() const{
	if(m_Cards.empty()){
	  return 0;
	}
// if the first card is face down, it will return 0, so the total of hand cannot be calc, return 0
	if(m_Cards[0]->GetValue() == 0){
	  return 0;
	}

	int total = 0;
	bool containAce = false;
	vector<Card*>::const_iterator iter;
	for(iter = m_Cards.begin(); iter != m_Cards.end(); iter++){
	  total += (*iter)->GetValue();
	  if((*iter)->GetValue() == Card::ACE){
	    containAce = true;
	  }
	}

	if(containAce && total <=11){
	  total += 10;
	}

	return total;
}










