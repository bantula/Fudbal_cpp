// Biblioteka za rad sa tipom 'string'
#include <string>
#include "Position.h"
using namespace std;

class Player {
public:
	Player(string name, Position* position);

	void move(Direction direction);

	string getName();
	Position* getPosition();

private:
	string name;
	Position* position;
};