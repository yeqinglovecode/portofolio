// tictactoe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <vector>

class TicTacToe
{
private:
	int xMax;				// max horizontal board size
	int yMax;				// max vertical board size
	int player;				// current player
	int numPlayers;			// number of players (unlimited)
	int rowSize;			// need in a row to win
	bool dropPieces;		// connect4 style pieces drop
	std::vector<int>posMoveX;		// possible X move
	std::vector<int>posMoveY;		// possible Y move
	std::vector<bool>playerType;	// true = human, false = comp
	std::vector<int>arrangeTurns;	// list for checking moves
	std::vector<std::vector<int> > board;    // 2D gameboard
public:
	TicTacToe();

	void welcome();			// welcome screen
	void setup();			// game setup at start
	void printTurn();		// whos turn?

	bool playerHuman();		// is player human?
	void humanMove();		// human moves
	void computerMove();	// computer moves
	
	bool placePieces(const int &x, int &y);		// is spot taken?
	bool findWinner(const bool &findMove);		// is there a winner?
	bool searchLine(const int &x, const int &y, const int &xAdd, const int &yAdd, const int &howManyToWin, const int &playerPiece);

	void sayWinner();	// winner!!
	void tieGame();		// nobody can win, so its a tie

	void formatBoard();	// initialize board vector
	void drawBoard();	// display board
	bool nextTurn();	// switch turn
};
#endif // TICTACTOE_H 
