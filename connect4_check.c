#include <stdio.h>
#include <stdlib.h>
#include "connect4.h"


// Start the simulation
int main() {	

        int board[ROWS][COLUMNS] = {{}};

	printf("\n");
	printf(" .... starting program ... \n");
	printf("\n");
	
	check_valid_move(board, 1);
	printf("\n");

	check_add_move_board(board, 1, 2);
	printf("\n");

	check_check_winning(board, 1);
	printf("\n");

	check_computer_move(board, 1, 0);
	printf("\n");

}

