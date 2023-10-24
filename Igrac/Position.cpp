#include "Position.h"
// Biblioteka za rad sa ulazom i izlazom
#include <iostream>
// Prostor imena u kojem se nalaze imena za rad sa standardnim ulazom i izlazom
// Sledeca linija koda je potrebna da bi identifikatori iz prostora imena 'std' mogli da se pisu bez prefiksa 'std::'
using namespace std;

Position::Position() {
	this->row = 1;
	this->column = 'A';
}

Position::Position(int row, char column) {
	// Inicijalizacija polja u okviru konstruktora
	this->setPosition(row, column);
}

void Position::setPosition(int row, char column) {
	// Pokazivac 'this' pokazuje na objekat za koji je pozvana funkcija
	this->row = row >= 1 && row <= 8 ? row : 1;
	this->column = column >= 'A' && column <= 'H' ? column : 'A';
}

void Position::print() {
	// Ispis na stanardni izlaz 'cout'
	cout << this->column << this->row << endl;
}

void Position::move(Direction direction) {
	switch (direction) {
	case UP:
		if (this->row < 8) this->row += 1;
		break;
	case LEFT:
		if (this->column > 'A') this->column -= 1;
		break;
	case DOWN:
		if (this->row > 1) this->row -= 1;
		break;
	case RIGHT:
		if (this->column < 'H') this->column += 1;
		break;
	default:
		break;
	}
}

// Primer rada sa argumentima prenesenim po vrednosti
/* bool Position::sameDirection(Position other) {
	return this->row == other.row || this->column == other.column;
} */

// Primer rada sa argumentima prenesenim po adresi
bool Position::sameDirection(Position* other) {
	return this->row == other->row || this->column == other->column;
}

// Primer rada sa argumentima prenesenim po referenci
// Referenca je alijas (drugo ime) za nesto u memoriji
// U ovom slucaju referenca ukazuje (daje drugo ime 'other') za argument prosledjen pri pozivu funkcije
// Rad sa referencama je isti kao i rad sa objektima po vrednosti,
// ali se ne vrsi bespotrebna kopija pri inicijalizaciji (vise o tome kasnije na kursu)
bool Position::sameDirection(Position& other) {
	return this->row == other.row || this->column == other.column;
}

int Position::getRow() {
	return this->row;
}

char Position::getColumn() {
	return this->column;
}
