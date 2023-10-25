#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Position.h"
using namespace std;

class Player {
public:
	Player(string name, Position* position);
	~Player();

	// Kljucna rec 'virtual' omogucava redefiniciju navedene metode u izvedenim klasama
	virtual void move(Direction direction);

	string getName();
	Position* getPosition();

	/*
	 Pravo pristupa koje svim metodama ove klase i svim metodama klasa koje su izvedene iz ove
	 omogucava pristup poljima/metodama u narednoj sekciji
	*/
protected:
	string name;
	Position* position;
};

// Izvodjenje klase Runner iz klase Player
// Sva polja i metode iz klase Player se nasledjuju i implicitno postoje i u klasi Runner
// Metode koje su u klasi Player oznacene kao virtuelne, u klasi Runner mogu da se izmene tako da imaju drugaciju implementaciju (method overriding)
class Runner : public Player {
public:
	Runner(string name, Position* position, int speed);

	int getSpeed();
	void move(Direction direction);

private:
	// ...
	int speed;
};

#endif#include "Player.h"

Player::Player(string name, Position* position) {
	this->name = name;
	this->position = position;
}

// Inicijalizacija objekata izvedenih klasa zapocinje inicijalizacijom nasledjenih polja iz osnovne klase te je potrebno pozvati neki od konstruktora osnovne klase
// Konstruktor se poziva u listi inicijalizatora
Runner::Runner(string name, Position* position, int speed) : Player(name, position) {
	this->speed = speed;
}

int Runner::getSpeed() {
	return this->speed;
}

void Runner::move(Direction direction) {
	for (int i = 0; i < speed; i++)
		this->position->move(direction);
}

Player::~Player() {
	delete this->position;
}

void Player::move(Direction direction) {
	this->position->move(direction);
}

string Player::getName() {
	return this->name;
}

Position* Player::getPosition() {
	return position;
}
