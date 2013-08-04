#include <iostream>
#include <vector>
#include <string>
#include "Card.cpp"
#include "Hand.cpp"
#include "GenericPlayer.cpp"
#include "Player.cpp"
#include "House.cpp"
#include "Deck.cpp"
#include "Game.cpp"

using namespace std;

int main(){
	cout<<"\t\tWelcome to Blackjack!\n\n"<<endl;

	int numPlayer = 0;
	while(numPlayer<1 || numPlayer>7){
		cout<<"How many players? (1-7): ";
		cin >> numPlayer;
	}

	vector<string> names;
	string name;
	for(int i=0; i<numPlayer; i++){
		cout<<"Enter name of player"<<i<<": ";
		cin>>name;
		names.push_back(name);
	}
	cout<<endl;

	// start game loop
	Game aGame(names);
	char again = 'y';
	while(again != 'n'&& again != 'N'){
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}

	return 0;
}

ostream& operator<<(ostream& os, const Card& aCard){
	const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	char clubs[]    = {0xE2, 0x99, 0xA7, 0};
	char diamonds[] = {0xE2, 0x99, 0xA2, 0};
        char hearts[]   = {0xE2, 0x99, 0xA1, 0};
	char spades[]   = {0xE2, 0x99, 0xA4, 0};
	const string SUITS[] = {clubs,diamonds,hearts,spades};

	if(aCard.m_IsFaceUp){
	  os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit] << "  ";
	}
	else{
	  os << "XX";
	}

	return os;
}
	
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer){
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if(!aGenericPlayer.m_Cards.empty()){
	   for(pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); pCard++){
	     os << *(*pCard) << "\t";
	   }
	   if(aGenericPlayer.GetTotal() != 0){
	      cout << "(" << aGenericPlayer.GetTotal() << ")";
	   }
	}
	else{
	   os << "<empty>";
	}

	return os;
}






