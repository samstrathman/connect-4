/******************************************************************************
Title:	   	  Connect 4
Name:	  	  Sam Strathman
Course:		  CSCI240.01
Due Date:	  Wednesday, December 10th, 2014

Description:  This program uses a Game class to simulate a game of connect 4.
			  It uses a two dimensional array to simulate the board, and
			  X's and O's to denote the players.

Input:        The user will enter a number between 1 and 7, which corrosponds			
			  to a column on the board. 

Output:		  The connect 4 board will be printed at the beginning of the 
			  game and after every turn, and a congratulatory message will be
			  printed after a player wins.
******************************************************************************/

#include "Game.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
using namespace std;

void randomizeFirstTurn(Game &G);

int main(){
   Game G;
   int  dropSpot;
   char winner = ' ';
   srand((unsigned)time(0));

   randomizeFirstTurn(G);
   
   while(winner == ' '){
	   cout << endl;
	   cout << "Turn number " << G.getTurnNum() << endl;
	   cout << "It is " << G.getPlayerTurn() << "\'s turn." << endl;
	   cout << "Please select a number from 1-7" << endl;
	   cout << "\n  1   2   3   4   5   6   7  " << endl;

	   G.drawBoard();

	   cin >> dropSpot;
	   while(G.isFull(dropSpot - 1) || !G.play(dropSpot - 1)){
		   cout << "Invalid move. Play again." << endl;
		   cin >> dropSpot;
	   }

	   winner = G.checkWinner();
	   
	   G.togglePlayer();
   }

   G.drawBoard();	//draws the board after the game to show the end result

   cout << winner << " wins!" << endl;
   system("pause");

   return 0;
}

///////////////////////////////////////////////////////////////////////////////
//Function that randomizes who plays first
///////////////////////////////////////////////////////////////////////////////
void randomizeFirstTurn(Game &G){
	int randomPlayer;

	randomPlayer = rand() % 2;
	if(randomPlayer == 1){
		G.togglePlayer();
	}
}