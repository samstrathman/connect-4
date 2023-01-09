/******************************************************************************
Title:	   	  Connect 4
Name:	  	  Sam Strathman & Aaron Reasor
Course:		  CSCI240.01
Due Date:	  Wednesday, December 10th, 2014

Description:  This class includes a number of functions that are used to 
			  simulate a game of connect 4.
******************************************************************************/

#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

//Constructor sets the player as X and initializes the board to blank spaces
Game::Game(){
	turnNum = 0;
	player = 'X';
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			board[i][j] = ' ';
		}
	}
}

//Displays the board
void Game::drawBoard(){
	for(int i = 0; i < ROWS; i++){
		cout << "-----------------------------" << endl;
		for(int j = 0; j < COLS; j++){
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "-----------------------------" << endl;
	cout << "|                           |" << endl;
}

//Returns the current player
char Game::getPlayerTurn()		{ return player; }

//Increments and returns the current turn number
int  Game::getTurnNum(){
	turnNum++;
	return turnNum; 
}

//Toggles between the two players
void Game::togglePlayer(){
	if(player == 'X'){
		player = 'O';
	}
	else{
		player = 'X';
	}
}

//Places a piece at the lowest available open spot on the game board 
//in the specified column
bool Game::play(int col){
	if(col > COLS - 1){
		return false;
	}
	for(int i = ROWS - 1; i >= 0; i--){
			if(board[i][col] == ' '){
			   board[i][col] = player;
			   break;
			}
	}
	return true;
}

//Checks to see if a specified column is full
bool Game::isFull(int col){
	if(board[0][col] == ' '){
		return false;
	}
	else{
		return true;
	}
}

//Checks the board to see if the current player has achieved a Connect 4
char Game::checkWinner(){
	int tally;
	int rowCount;
	int colCount;
	int rowIndex;
	int colIndex;

	//checks for vertical connect 4's
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(board[i][j] == player){
				rowIndex = i;
				rowCount = i + 3;
				//the following if statment checks to see if it is possible to
				//have 4 more game pieces in this location
				if(rowCount < ROWS){ 
					tally = 0;
					while(rowIndex <= rowCount){
						if(board[rowIndex][j] == player){
							tally++;
						}
						if(tally == 4){
							return player;
						}
					rowIndex++;	
					}
				}
			}
		}
	}
	
	//checks for horizontal connect 4's
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(board[i][j] == player){
				colIndex = j;
				colCount = j + 3;
				//the following if statment checks to see if it is possible to
				//have 4 more game pieces in this location
				if(colCount < COLS){  
					tally = 0;
					while(colIndex <= colCount){
						if(board[i][colIndex] == player){
							tally++;
						}
						if(tally == 4){
							return player;
						}
						colIndex++;
					}
				}
			}
		}
	}
	
	//checks for upper left to bottom right connect 4's
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(board[i][j] == player){
				rowIndex = i;
				colIndex = j;
				rowCount = i + 3;
				colCount = j + 3;
				//the following if statment checks to see if it is possible to
				//have 4 more game pieces in this location
				if(rowCount < ROWS && colCount < COLS){
					tally = 0;
					while(rowIndex <= rowCount && colIndex <= colCount){
						if(board[rowIndex][colIndex] == player){
							tally++;
						}
						if(tally == 4){
							return player;
						}
					rowIndex++, colIndex++;
					}	
				}
			}
		}
	}
	
	//checks for bottom left to upper right connect 4's
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			if(board[i][j] == player){
				rowIndex = i;
				colIndex = j;
				rowCount = rowIndex - 3;
				colCount = colIndex + 3;
				//the following if statment checks to see if it is possible to
				//have 4 more game pieces in this location
				if(rowCount >= 0 && colCount < COLS){
					tally = 0;
					while(rowIndex >= rowCount && colIndex <= colCount){
						if(board[rowIndex][colIndex] == player){
							tally++;
						}
						if(tally == 4){
							return player;
						}
					rowIndex--, colIndex++;
					}
				}
			}
		}
	}

	return ' ';
}