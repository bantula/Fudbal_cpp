#ifndef POSITION_H
#define POSITION_H


enum Direction {
	UP, LEFT, DOWN, RIGHT
};

// Definicija klase
class Position {
// Sve sto se nalazi u javnoj sekciji bice dostupno van klase
public:
	// Konstruktor klase - moze se pozvati pri kreiranju objekata radi inicijalizacije stanja objekta
	Position();
	Position(int row, char column);
	/*
	Konstruktor koji se poziva prilikom kreiranja objekta se automatski bira na osnovu parametara
	npr: Position *p1 = new Position(); --> poziva se konstruktor bez parametara
		 Position *p2 = new Position(2, 'B') --> poziva se konstruktor sa dva parametra (int i char)
		 itd.
	*/

	// Funkcije clanice (metode) - mogu se pozivati nad konkretnim objektima
	void setPosition(int row, char column);
	void print();
	void move(Direction direction);
	// bool sameDirection(Position other);
	bool sameDirection(Position* other);
	bool sameDirection(Position& other);

	// Tzv. getter funkcije - funkcije koje daju pristup poljima objekta bez mogucnosti izmene 'spolja'
	int getRow();
	char getColumn();

// Sve sto se nadje u privatnoj sekciji nije dostupno van klase, vec iskljucivo unutar definicija funkcija clanica date klase
private:
	// Podaci clanovi (polja) - objekti sadrze konkretne vrednosti za sva polja definisana u klasi
	int row;
	char column;
};

#endif // !POSITION_H