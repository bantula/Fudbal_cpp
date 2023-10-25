#include "Position.h"
#include "Player.h"
#include <iostream>
using namespace std;

// Test za zadatak 1
void test1() {
	// Kreiranje objekata klase Position pozivom konstruktora na nekoliko nacina
	Position p1 = Position(4, 'B');
	Position p2(-1, 'x');
	Position* p = new Position(1, 'H');

	// p1->row = -1; // NE BI SMELO => polja moraju da se definisu u privatnoj sekciji

	// Poziv funkcije clanice nad objektom
	p1.print();
	p2.print();
	p->print();

	p1.move(DOWN);
	p1.move(LEFT);
	p1.move(UP);
	p1.print();

	p1.move(LEFT);
	p1.print();

	cout << p1.sameDirection(p) << endl;
	cout << p1.sameDirection(p2) << endl;

	p2.print();

	delete p;
}

// Test za zadatak 2
void test2() {

	Player* player1 = nullptr; // nullptr, C++ zamena za NULL
	Player* player2 = nullptr;

	cout << "Enter name of player one:" << endl;
	string name1;
	// Primer ucitavanja jedne reci sa standardnog ulaza
	cin >> name1;
	// Primer ucitavanja jednog reda sa standardnog ulaza
	// getline(cin, name1);

	cout << "Enter position of player one (first row [1-8] and then column [A-H])" << endl;
	int row1;
	char column1;
	cin >> row1 >> column1;

	Position* position1 = new Position(row1, column1);
	player1 = new Player(name1, position1);

	cout << "Enter name of player two:" << endl;
	string name2;
	cin >> name2;
	// getline(cin, name1);

	cout << "Enter position of player two (first row [1-8] and then column [A-H])" << endl;
	int row2;
	char column2;
	cin >> row2 >> column2;

	Position* position2 = new Position(row2, column2);
	player2 = new Player(name2, position2);

	while (true) {
		cout << "Move player one (UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3, EXIT = -1)" << endl;
		int direction1;
		cin >> direction1;
		if (direction1 == -1) break;
		player1->move((Direction)direction1);

		cout << "Move player two (UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3, EXIT = -1)" << endl;
		int direction2;
		cin >> direction2;
		if (direction2 == -1) break;
		player2->move((Direction)direction2);

		// PRVI NACIN ISPISA POZICIJA
		/*
		cout << player1->getName() << "'s position: ";
		player1->getPosition()->print();

		cout << player2->getName() << "'s position: ";
		player2->getPosition()->print();
		*/

		// DRUGI NACIN ISPISA POZICIJA
		for (int i = 8; i >= 1; i--) {
			for (int j = 'A'; j <= 'H'; j++) {
				if (player1->getPosition()->getRow() == i && player1->getPosition()->getColumn() == j) {
					cout << " o ";
				}
				else if (player2->getPosition()->getRow() == i && player2->getPosition()->getColumn() == j) {
					cout << " x ";
				}
				else {
					cout << " - ";
				}
			}
			cout << endl;
		}
	}
	delete position1;
	delete position2;
	delete player1;
	delete player2;
}

// Test za zadatak 3
void test3() {
	// Pravilo supstitucije: Pokazivac na osnovnu klasu moze da pokazuje na objekat izvedene klase
	// Odnosno postoji implicitna konverziija Runner* -> Player*
	Player* p1 = new Player("Ivan", new Position(1, 'A'));
	Runner* r1 = new Runner("Marina", new Position(1, 'A'), 2);
	Player* p2 = new Runner("Natalija", new Position(1, 'A'), 2);

	// Zbog tog pravila mozemo u jedinstvenom nizu pokazivaca na podatke osnovne klase cuvati objekte bilo koje izvedene klase
	Player* players[] = { p1, r1, p2 };

	// Pozivom neke metode koje je oznacena sa virtual preko pokazivaca osnovne klase (Clock*) pozivamo onu implementaciju metode koja odgovara pokazivanom objektu - POLIMORFIZAM
	// Implementacija metode koja se poziva se bira u trenutku izvrsavanja na osnovu tipa objekta na koji pokazuje dati pokazivac
	players[0]->move(UP);
	players[1]->move(UP);
	players[2]->move(UP);

	players[0]->getPosition()->print(); cout << endl; // 2A
	players[1]->getPosition()->print(); cout << endl; // 3A
	players[2]->getPosition()->print(); cout << endl; // 2A

	return;
}

// main() funkcija u C++ obicno ima 'int' za povratnu vrednost, za razliku od C-a gde je povratna vrednost bila 'void'
int main() {

	//test1();
	//test2();
	test3();

	return 0;
}