/******************************************************************************
Title:	   	  Connect 4
Name:	  	  Sam Strathman & Aaron Reasor
Course:		  CSCI240.01
Due Date:	  Wednesday, December 10th, 2014 
******************************************************************************/

#include <string>
using namespace std;

class Game{
private:
	static const int ROWS = 6;
	static const int COLS = 7;
	char    board[ROWS][COLS];
	char    player;
	int     turnNum;
public:
	Game();
	void	drawBoard();		//displays the board
	char	getPlayerTurn();    //returns the current player
	int		getTurnNum();		//returns the current turn number
	void	togglePlayer();		//switches between the two players
	bool	play(int col);		//adds a piece to the board for the turn
	bool	isFull(int col);	//checks to see whether or not a column is full
	char	checkWinner();		//checks to see if a player has won
};