#include "Board.hpp"
#include "Ant.hpp"

int main() {
	int nRow = 5;
	int nCol = 5; 
	Board board(nRow, nCol);

	int x = 2;
	int y = 1;
	int steps = 5;
	Ant ant(x, y, steps, board);
	ant.showInfo();
	board.show();

	// Start routine
	while (ant.getSteps() > 0) {
		std::cout << "[D]: # of steps left = " << std::endl;
		ant.moveForward();
		std::cout << "-----------------------" << std::endl;	// REMOVE
		ant.showInfo();	// REMOVE
	}
	return 0;
}