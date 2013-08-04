#include <iostream>
#include <vector>
#include <string>

using namespace std;

class House : public GenericPlayer{
public:
	House(const string& name = "House");
	virtual ~House();
	
	virtual bool IsHitting() const;
	void FlipFirstCard();
};

House::House(const string& name):GenericPlayer(name)
{}

House::~House()
{}

bool House::IsHitting() const{
	return (GetTotal() <= 15);
}

void House::FlipFirstCard(){
	if(!(m_Cards.empty())){
	  m_Cards[0]->Flip();
	}
	else{
	  cout << "No card to flip!" << endl;
	}
}





