#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GenericPlayer : public Hand{
friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();

	virtual bool IsHitting() const = 0;
	bool IsBusted() const;
	void Bust() const;

protected:
	string m_Name;
};

GenericPlayer::GenericPlayer(const string& name):m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted() const{
	return (GetTotal() > 21);
}

void GenericPlayer::Bust() const{
	cout << m_Name << " busts. " << endl;
}
