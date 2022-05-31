#include<iostream>
#include "tictactoe.hpp"
#include<string>
#include<vector>

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position;

void introduction() {
	
	std::cout << "Press Enter to start the game: ";
	std::cin.ignore();


	std::cout << "==================== ";
	std::cout << "Tic Tac Toe";
	std::cout << " ====================\n\n";

	std::cout << ">> Player 1 : x <<\n";
	std::cout << ">> Player 2 : o <<\n\n";

	std::cout << "Here is the 3x3 grid: \n";
	std::cout << "       |       |       \n";
	std::cout << "   1   |   2   |   3   \n";
	std::cout << "_______|_______|_______\n";
	std::cout << "       |       |       \n";
	std::cout << "   4   |   5   |   6   \n";
	std::cout << "_______|_______|_______\n";
	std::cout << "       |       |       \n";
	std::cout << "   7   |   8   |   9   \n";
	std::cout << "       |       |       \n\n\n";
}

bool isWinner() {
	
	bool win = false;

	if( (board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
		win = true;
	} else if( (board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ") {
		win = true;
	} else if( (board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ") {
		win = true;
	}

	else if( (board[0] == board[4]) && (board[4] == board[8]) && board[4] != " ") {
		win = true;
	} else if( (board[2] == board[4]) && (board[4] == board[6]) && board[4] != " ") {
		win = true;
	}

	else if( (board[0] == board[3]) && (board[3] == board[6]) && board[0] != " ") {
		win = true;
	} else if( (board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ") {
		win = true;
	} else if( (board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ") {
		win = true;
	}

return win;
}

bool isDraw() {
	
	bool isFilledUp = true;

	for(int i = 0; i < 9; i++){
	
		if(board[i] == " "){
	
			isFilledUp = false;
	
		}
	
	}

	return isFilledUp;
}


void set_position() {
	
	std::cout << "Player " << player << "'s turn (Enter 1-9): ";
	
	while( !(std::cin >> position) ) {
	
		std::cout << "Some thing went wrong, please enter number between 1 and 9: ";
		std::cin.clear();
		std::cin.ignore();
	
	}

	std::cout << "\n\n";

		
	while(board[position - 1] != " ") {
	
		std::cout << "Oops, there's something already in that position!\n";
		std::cout << "Player " << player << "'s turn (Enter 1-9): ";
		std::cin >> position;
	
	}


	
}

void update_board() {
	
	if(player % 2 == 1) {
	
		board[position - 1] = "x";
	
	} 

	else {
	
		board[position - 1] = "o";
	
	}

}

void change_player() {
	
	if(player == 1) {
	
		player ++;
	
	} 

	else {
	
		player --;
	
	}

}

void draw_board() {
	
	std::cout << "       |       |       \n";
	std::cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   \n";
	std::cout << "_______|_______|_______\n";
	std::cout << "       |       |       \n";
	std::cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   \n";
	std::cout << "_______|_______|_______\n";
	std::cout << "       |       |       \n";
	std::cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   \n";
	std::cout << "       |       |       \n";
}


void take_turn() {
	
	while( !isWinner() && !isDraw() ) {	
	
		set_position();

		update_board();
		
		change_player();
		
		draw_board();

	}
	
}

void end_game() {
	
	if( isWinner() ) {
	
		std::cout << "Congratulations! You won the game!\n";
	
	}
	
	else if( isDraw() ) {
	
		std::cout << "The game is a tie.\n";
	
	}

}

