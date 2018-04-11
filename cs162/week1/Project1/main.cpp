#include "Board.hpp"
#include "Ant.hpp"

int main() {
	// int nRow = 3;
	// int nCol = 3; 
	// Board board(nRow, nCol);
	// board.show();
	int x = 1;
	int y = 2;
	Ant ant(x, y);
	std::cout << "Ant's current x position = " << ant.getCurrentXPosition() << std::endl;
	std::cout << "Ant's current y position = " << ant.getCurrentYPosition() << std::endl;
	std::cout << "Ant's current direction = " << ant.getDirection() << std::endl;

	return 0;

	// TODO: Free memory
	// for (int i = 0; i < nRow; i++) {
	// 	delete [] board
	// }
}