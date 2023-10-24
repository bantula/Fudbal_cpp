#include "Player.h"

Player::Player(string name, Position* position) {
	this->name = name;
	this->position = position;
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
