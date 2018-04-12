#include "Board.hpp"
#include "Ant.hpp"

int main() {
	int nRow = 100;
	int nCol = 100; 
	Board board(nRow, nCol);


	// TODO: Must handle if user puts then Ant out of Bounds
	// TODO: Put the ant in a random location on the grid..EASY...

	int x = 50;
	int y = 50;
	int steps = 14000;
	Ant ant(x, y, steps, board);
	ant.showInfo();

	// Start routine
	while (ant.getSteps() > 0) {
		ant.moveForward();
		std::cout << "-----------------------" << std::endl;	// REMOVE
	}
	return 0;
}