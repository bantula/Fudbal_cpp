/*#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(){
	this->first = this->last = this->current = nullptr;
	this->count = 0;
}

Table::~Table(){
	while (this->first != nullptr) {
		Elem* old = this->first;
		this->first = this->first->next;
		delete old->player;
		delete old;
	}
	this->first = this->last = this->current = nullptr;
}

void Table::createNewPlayer() {
	Player* player = nullptr;

	cout << "Name: ";
	string name;
	cin >> name;

	cout << "Position [1-8][A-H]: ";
	int row;
	char column;
	cin >> row >> column;

	Position* position = new Position(row, column);
	player = new Player(name, position);

	Elem* element = new Elem();
	element->player = player;
	element->next = nullptr;
	element->prev = nullptr;

	if (!this->first) {
		this->first = this->last = this->current = element;
	}
	else {
		element->prev = this->last;
		this->last->next = element;
		this->last = element;
	}
	this->count++;
}

void Table::moveNextPlayer(){
	if (!this->current) return;

	cout << "Move player (UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3)" << endl;
	int direction;
	cin >> direction;
	this->current->player->move((Direction) direction);

	Elem* element = this->first;
	while (element) {
		if (element != current && element->player->getPosition()->samePosition(current->player->getPosition())) {
			if (element == this->first) this->first = this->first->next;
			if (element == this->last) this->last = this->last->prev;
			if (element->next) element->next->prev = element->prev;
			if (element->prev) element->prev->next = element->next;
			delete element;
			count--;
			break;
		}
		element = element->next;
	}

	this->current = this->current->next;
	if (!this->current) this->current = this->first;
}

void Table::drawTable() {
	Elem* element = this->first;

	char table[ROW_MAX][COL_MAX];

	for (int i = ROW_MAX; i >= ROW_MIN; i--) {
		for (int j = COL_MIN; j <= COL_MAX; j++) {
			table[i - 1][j - 'A'] = '-';
		}
	}

	while (element) {
		table[element->player->getPosition()->getRow() - 1][element->player->getPosition()->getColumn() - 'A'] = element->player->getName()[0];
		element = element->next;
	}
	
	for (int i = ROW_MAX; i >= ROW_MIN; i--) {
		for (int j = COL_MIN; j <= COL_MAX; j++) {
			cout << table[i - 1][j - 'A'] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int Table::numberOfPlayers() {
	return count;
}
*/