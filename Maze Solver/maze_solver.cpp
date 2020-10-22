#include <iostream>
#include <stdlib.h>
using namespace std;

//void call for function print
void print(char maze[12][12], int row, int col);
//This function solves the maze
void mazeTraverse(char maze[12][12], int &row, int &col)
{
	//This if statement searches for the end of the maze
	if (row==8 && col==10)
	{
		cout << endl << endl << "Solved!!!" << endl;
		exit(0);
	}
	else if (maze[row][col] == '.')
	{
		maze[row][col] = 'X';
	}
	//this else if searches for the dot on the bottom of the current maze position
	else if (maze[row + 1][col] == '.')
	{
		row += 1;
		maze[row][col] = 'X';
	}
	//this else if searches for the dot on the right of the current maze position
	else if (maze[row][col + 1] == '.')
	{
		col += 1;
		maze[row][col] = 'X';
	}
	//this else if searches for the dot on the top of the current maze position
	else if (maze[row - 1][col] == '.')
	{
		row -= 1;
		maze[row][col] = 'X';
	}
	//this else if searches for the dot on the left of the current maze position
	else if (maze[row][col - 1] == '.')
	{
		col -= 1;
		maze[row][col] = 'X';
	}
	//this else statement backtracks in case we reached a stuck position
	else
	{
		//this if statement searches for the 'X' on left of it and replaces it by a a '.'
		if (maze[row][col - 1] == 'X')
		{
			maze[row][col - 1] = '.';
			col--;
		}
		//this else if statement searches for the 'X' on top of it and replaces it by a a '.'
		else if (maze[row - 1][col] == 'X')
		{
			maze[row - 1][col] = '.';
			row--;
		}
		//this else if statement searches for the 'X' on right of it and replaces it by a a '.'
		else if (maze[row][col + 1] == 'X')
		{
			maze[row][col + 1] = '.';
			col++;
		}
		//this else if statement searches for the 'X' on bottom of it and replaces it by a a '.'
		else if (maze[row + 1][col] == 'X')
		{
			maze[row + 1][col] = '.';
			row++;
		}
		
		
		
	}
	//calls the print function with the new 'X's in place
	print(maze, row, col);
	cin.ignore();
	//calls the maze function again
	mazeTraverse(maze, row, col);
}
//this function prints the maze everytime the maze function makes changes to it
void print(char maze[12][12], int row, int col)
{
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 12; col++)
			cout << maze[row][col] << " ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	//maze initialization
	char maze[12][12] = { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
						  '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#',
						  '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
						  '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
						  '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
						  '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
						  '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#',
						  '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#',
						  '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', 'E',
						  'S', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
						  '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
						  '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' };
	 
	int row = 9, col = 0;
	//calls the print function to print the initial maze
	print(maze, row, col);
	//calls the maze function for the first time
	mazeTraverse(maze, row, col);

}
