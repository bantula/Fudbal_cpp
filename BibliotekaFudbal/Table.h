#ifndef TABLE_H
#define TABLE_H

#include "Player.h"

struct Elem {
	Player* player;
	Elem* next;
	Elem* prev;
};

class Table {
public:
	Table();
	~Table();

	void createNewPlayer();
	void moveNextPlayer();
	void drawTable();
	int numberOfPlayers();

private:

	Elem *first, *last, *current;
	int count;
};

#endif