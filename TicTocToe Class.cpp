#include "../../std_lib_facilites.h"

class ticTacToe
{
public:
	// throw error
	class Invalid {};

	//constructor
	ticTacToe();

	//accessors
	void print() const;
	int winner() const; //determine the winner after each move

	//mutators
	void getMove(char, int, int);
	bool checkMove(char, int, int);

private:

	char board[3][3];
};

//-----------------------------------------------------------------------------------------------------------

void updateTurn(bool p[])
{
	p[0] = !p[0];
	p[1] = !p[1];
}

int main()
try {
	bool players[2] = { true,false };
	ticTacToe playBoard;

	int x, y;

	int win = 0;
	while (win == 0) // no winner yet
	{
		// get a move
		if (players[0] == true)
		{
			cout << "Player 1: Enter two integers representing the positions of your next move: ";
			cin >> x >> y;
			playBoard.getMove('X', x, y);
		}
		else
		{
			cout << "Player 2: Enter two integers representing the positions of your next move: ";
			cin >> x >> y;
			playBoard.getMove('O', x, y);

		}
		// print the current board
		playBoard.print();
		cout << endl;

		// check if there is a winner
		win = playBoard.winner();

		// update the turn
		updateTurn(players);

	}
	playBoard.print();
	cout << endl;

	if (win == 1)
		cout << "Player 1 wins!!" << endl;
	else
		cout << "Player 2 wins!!" << endl;


	return 0;
}
catch (ticTacToe::Invalid)
{
	cerr << "Game ended!" << endl;
}

//------------------------------------------------------------------------------------------------------------

ticTacToe::ticTacToe()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = '-';
}


void ticTacToe::print() const
{
	cout << "   0 1 2 " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < 3; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}

}

int ticTacToe::winner() const
{
	// check rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
				return 1;
			else
				return 2;
		}
	}

	// check columns
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[0][i] == 'X')
				return 1;
			else
				return 2;
		}
	}

	// check diagonals
	if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
			return 1;
		else
			return 2;
	}

	if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[2][0] == 'X')
			return 1;
		else
			return 2;
	}

	return 0;

}

void ticTacToe::getMove(char m, int x, int y)
{
	if (!checkMove(m, x, y))
		throw Invalid{};

	board[x][y] = m;
}

bool ticTacToe::checkMove(char m, int x, int y)
{
	if (m != 'X' && m != 'O')
	{
		cout << "Invalid symbol." << endl;
		return false;
	}

	if (x > 2 || y > 2)
	{
		cout << "Invalid range." << endl;
		return false;
	}

	if (board[x][y] != '-')
	{
		cout << "This position is already filled." << endl;
		return false;
	}

	return true;

}