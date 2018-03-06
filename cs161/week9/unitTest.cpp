#include "gtest/gtest.h"
#include "T3Reader.hpp"

int main() {
	const std::string path = "data/";

	// Game 1: UNFINISHED, GAME COMPLETE
	std::cout << "\n*** STARTING GAME 1 ***" << std::endl;
	std::string filename1 = path + "game1.txt";
	T3Reader game1('x');
	if (game1.readGameFile(filename1)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 2: UNFINISHED
	std::cout << "\n*** STARTING GAME 2 ***" << std::endl;
	std::string filename2 = path + "game2.txt";
	T3Reader game2('o');
	if (game2.readGameFile(filename2)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 3: UNFINISHED
	std::cout << "\n*** STARTING GAME 3 ***" << std::endl;
	std::string filename3 = path + "game3.txt";
	T3Reader game3('x');
	if (game3.readGameFile(filename3)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 4: UNFINISHED
	std::cout << "\n*** STARTING GAME 4 ***" << std::endl;
	std::string filename4 = path + "game4.txt";
	T3Reader game4('o');
	if (game4.readGameFile(filename4)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 5: X_WON
	std::cout << "\n*** STARTING GAME 5 ***" << std::endl;
	std::string filename5 = path + "game5.txt";
	T3Reader game5('x');
	if (game5.readGameFile(filename5)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 6: O_WON, even though 'x' also finishes afterwards
	std::cout << "\n*** STARTING GAME 6 ***" << std::endl;
	std::string filename6 = path + "game6.txt";
	T3Reader game6('o');
	if (game6.readGameFile(filename6)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 7: X_WON, x wins with horizontal line
	std::cout << "\n*** STARTING GAME 7 ***" << std::endl;
	std::string filename7 = path + "game7.txt";
	T3Reader game7('x');
	if (game7.readGameFile(filename7)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 8: O_WON, o wins with diagonal
	std::cout << "\n*** STARTING GAME 8 ***" << std::endl;
	std::string filename8 = path + "game8.txt";
	T3Reader game8('x');
	if (game8.readGameFile(filename8)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	// Game 9: DRAW
	std::cout << "\n*** STARTING GAME 9 ***" << std::endl;
	std::string filename9 = path + "game9.txt";
	T3Reader game9('x');
	if (game9.readGameFile(filename9)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	std::cout << "\n*** INVALID MOVE TEST ***" << std::endl;
	std::string filename10 = path + "game10.txt";
	T3Reader game10('x');
	if (game10.readGameFile(filename10)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

	std::cout << "\n*** GAME WON, EXTRA MOVES ***" << std::endl;
	std::string filename11 = path + "game11.txt";
	T3Reader game11('x');
	if (game11.readGameFile(filename11)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "INVALID GAME" << std::endl;
	}

}