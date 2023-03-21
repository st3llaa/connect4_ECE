#include <stdio.h>
#include <stdlib.h>
#include "connect4.h"

// Start the simulation
int main() {	

	int board[ROWS][COLUMNS] = {0};
	int board1[ROWS][COLUMNS] =  { { 0 , 0 , 0 , 0 , 0 , 0 , 0 },
         				{ 0 , 0 , 0 , 0 , 1 , 0 , 0 },
         				{ 0 , 0 , 1 , 1 , 2 , 0 , 0 },
         				{ 0 , 0 , 1 , 2 , 1 , 0 , 0 },
        				{ 0 , 1 , 2 , 2 , 1 , 1 , 0 },
         				{ 1 , 2 , 1 , 1 , 2 , 1 , 2 } };


	// Seed the random number generator
	srand(time(NULL));


	// Inform the user
	int input;
	char first;
	int player;
	int computer;
	printf("Do you want to make the first move (y/n)? ");
	scanf("%c", &first);
	if(first == 'y'){
		player = 1; // uses the "X" symbol
		computer = 2;
	}
	else{
		player = 2; //uses the "O" symbol
		computer = 1;
	}

	int col_curr;
	int col_comp;
	int i;
	/*for(i=0; i <4; i++){ //playing arbitrary 5 rounds
		//getting player move
		col_curr = player_move(board);
		add_move_board(board, col_curr, player);
		//getting computer move
		//col_comp = computer_move(board, computer, 0);
		//add_move_board(board, col_comp, computer);
		printf("The computer played in column %d\n", col_comp+1);
		display_board_ASCII(board); 
	}
	printf("player: %d won! \n", check_winning(board, col_curr));*/


/*while(check_winning(board, col_curr) == 0 || check_winning(board, col_comp) == 0){
	//getting player move
	col_curr = player_move(board);
	add_move_board(board, col_curr, player);
	//getting computer move
	col_comp = computer_move(board, computer, 0);
	add_move_board(board, col_comp, computer);
	printf("The computer played in column %d\n", col_comp+1);
	display_board_ASCII(board);
}*/	
	// Display the game board
	//display_board_ASCII(board);
	//printf("player: %d won! \n", check_winning(board1, 0));
	display_board_ASCII(board);
	printf("\n");
	
}

