#include "Player.h"

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
