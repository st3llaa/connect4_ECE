#include "connect4.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Checks whether 'move' is valid given the current state of 'board'.
// It returns 1 when the move is valid, otherwise 0.
int valid_move(int board[][COLUMNS], int move) { //move in computer index formate
	if(board[0][move]==0 && move <= COLUMNS-1){ 
		return 1; //valid move
	}
	else{
		return 0; //not valid
	}

}


// Update the board with a move for a specific player.
// Returns 0 in case of failure (the move is not a valid
// one); otherwise it returns 1. 
int add_move_board(int board[][COLUMNS], int move, int player) { //move in computer index form
	if(valid_move(board, move) == 1){ //move is valid
		//checking row for empty slot
		int row;
		for(row = ROWS-1; row >= 0; row--){
			if(board[row][move] == 0){ //empty
				board[row][move] = player;
				return 1; //success
			}
		}
	}
	else{
		return 0; //failed
	}
}


// It asks the user to pick a column to play, and repeats
// this until a valid one is chosen.
// The user should enter a number between 1 and COLUMNS (1-indexed).
// It returns the column in the board array, so a value between 
// 0 and COLUMNS-1 (0-indexed)
int player_move(int board[][COLUMNS]) {
	int input;
	printf("\nWhich column do you want to play? ");
	scanf("%d", &input);
	while(valid_move(board, input-1) != 1){
		printf("Which column do you want to play? ");
		scanf("%d", &input);
	}
	return input-1;
}


// This function chooses a move for the computer player,
// given the state of the board and the player number the
// computer is playing with.
// It supports two modes: 0 for making random valid moves
// and 1 for using a more advanced algorithm.
// It returns the move chosen (a value between 0 an COLUMNS-1).
int computer_move(int board[][COLUMNS], int player, int mode) {
	int col = NULL;
	if(mode == 0){ //random generator
		col = (rand()%(COLUMNS-1));
		while(valid_move(board, col)!=1){
			col = (rand()%(COLUMNS-1)); //regenerate until move is valid
		}
	}
	return col;
}	


// Checks whether there is a winning player on the board.
// It gets passed the last move that was made.
// It returns 0 if there is no winner, or the otherwise the number
// of the player who won (1 or 2).
int check_winning(int board[][COLUMNS], int last_move) {
	int player;
	int streak = 1; //counts the number of counters in a row
	int i;
	int row_last;
//finding the row of the last move and assigning the player
	for(i = 0; i < ROWS; i++){
		if(board[i][last_move] != 0){
			player = board[i][last_move];
			row_last = i;
			break;
		}
	}
//Check horizontal : WORKS
	for(i = 0; i <= COLUMNS-1; i++){ //checking right
		if(board[row_last][last_move+i] != player){
			break; 
		}
		streak++;
	}
	for(i = 0; i <= COLUMNS -1; i++){ //checking left
		if(board[row_last][last_move-i] != player){
			break; 
		}
		streak++; //adds to the right streak found
	}
	//update streak & check streak
	if(streak >=4){
		//printf("horizontal winning\n");
		return player;
	}
	else{
		streak = 1;
	}
//check vertical : WORKS
	for(i = row_last; i < ROWS; i++){//executes 6 times, stays in col, loops through row
		if(board[i][last_move] == player){
			streak++;
		}
	}
	if(streak >=4){
		//printf("vertical winning\n");
		return player;
	}
	else{
		streak= 1;
	}
//check diagonal : WORKS	
	int directions[4][2] = {{-1, 1},{1, 1} , {-1, -1} , {1, -1}};
//				UpLeft, UpRight, DownLeft, DownRight
	int x, y, curr;
	int diagonalDir[2];
	int dir;
	int directionalStreaks[4]; //index correponds to direction (from directions array)
	//check each direction
	for(dir =0; dir < 4; dir++){
		//accessing the direction
		int c;
		int currentDirection[2];
		for(c=0; c <2; c++){
			currentDirection[c] = directions[dir][c];
		}
		//implementing the direction: transforming the origional position
		int changeX = currentDirection[0]; //columns
		int changeY = currentDirection[1]; //rows
		
		x = last_move+changeX;
		y = row_last+changeY;
		curr = board[y][x]; //apply direction
		//check starting point of direction is in bounds
		if(x < ROWS && y < COLUMNS && x >= 0 && y >= 0){ //curr is within bounds
			while(curr == player && x < ROWS && y < COLUMNS && x >=0 && y >= 0){
				streak++;
				x += changeX;
				y += changeY;
				curr = board[y][x];	
				//printf("x = %d, y = %d\n", x, y);
			}
		}
		directionalStreaks[dir] = streak;
		streak = 1; //reset counter
		//get combined streak: upLeft + downRight, upRight + downLeft	
	}
	int digNeg = directionalStreaks[0] + directionalStreaks[3];
	int digPos = directionalStreaks[1] + directionalStreaks[2];
	//check if combined streak is >=4
	if(digNeg >= 4 || digPos >= 4){
		//printf("diagonal winning\n");
		return player;
	}
	return 0;
}




	
