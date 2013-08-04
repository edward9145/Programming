#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player : public GenericPlayer{
public:
	Player(const string& name="");
	virtual ~Player();

	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};

Player::Player(const string& name):GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::IsHitting() const{
	cout << m_Name << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const{
	cout << m_Name << " wins" << endl;
}

void Player::Lose() const{
	cout << m_Name << " loses." << endl;
}

void Player::Push() const{
	cout << m_Name << " pushes." << endl;
}

