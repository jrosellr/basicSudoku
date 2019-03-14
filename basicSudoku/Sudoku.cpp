#include "Sudoku.h"



Sudoku::Sudoku()
{

}


Sudoku::~Sudoku()
{
}

void Sudoku::loadFromFile(const std::string & fileName)
{
}

void Sudoku::setNumber(int number, int row, int col)
{
	board[row - 1][col - 1].setValue(number);
}

bool Sudoku::checkWinCondition() const
{
	bool gameWon(true);
	int row(0);
	int col(0);

	while (gameWon)
	{
		gameWon = board[row][col].isCorrect();
		row++;
		col++;
	}

	return gameWon;
}

//	More work needed, end check loop
bool Sudoku::checkQuadrant() const
{
	int row(0);
	int col(0);
	bool quadrantCorrect(true);

	while (row < MAX_ROWS && quadrantCorrect)
	{
		int firstRow = (row / 3) * 3;
		int lastRow = firstRow + 3;
		int firstCol = (col / 3) * 3;
		int lastCol = firstCol + 3;

		for (int thisRow = firstRow; firstRow < lastRow; firstRow++)
			for (int thisCol = firstCol; firstCol < lastCol; firstCol++)
				quadrantCorrect = board[thisRow][thisCol].isCorrect();
		
		row += 3;
	}
	return quadrantCorrect;
}


