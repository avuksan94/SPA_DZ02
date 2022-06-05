#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

const int HEIGHT = 20;
const int WIDTH = 40;

int gen_Rand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void copy_grid(int grid1[HEIGHT + 2][WIDTH + 2], int grid2[HEIGHT + 2][WIDTH + 2])
{
	for (int i = 0; i < HEIGHT + 2; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			grid2[i][j] = grid1[i][j];
		}
	}
}

void new_generation(int grid[HEIGHT + 2][WIDTH + 2])
{
	int neighbours;
	int temp_grid[HEIGHT + 2][WIDTH + 2];

	for (int i = 0; i < HEIGHT + 2; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			if (i == 0 || j == 0 || i == HEIGHT + 2 || j == WIDTH + 2)
				temp_grid[i][j] = 0;
			else
			{
				//Counting my alive cells
				neighbours = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1]
					+ grid[i][j - 1] + grid[i][j + 1] + grid[i + 1][j - 1]
					+ grid[i + 1][j] + grid[i + 1][j + 1];
				if (grid[i][j] == 1)
				{
					if (neighbours < 2 || neighbours > 3)
						temp_grid[i][j] = 0; //cell dies
					else
						temp_grid[i][j] = 1;
				}
				else
				{
					if (neighbours == 3)
						temp_grid[i][j] = 1; //creation of a new cell
					else
						temp_grid[i][j] = 0;
				}
			}
		}
	}

	copy_grid(temp_grid, grid);
}

void display_grid(int grid[HEIGHT + 2][WIDTH + 2])
{
	for (int i = 1; i < HEIGHT + 1; i++)
	{
		for (int j = 1; j < WIDTH + 1; j++)
		{
			if (grid[i][j] == 1)
				cout << "O";
			else
				cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	int userCh;
	int counter = 0;

	int grid[HEIGHT + 2][WIDTH + 2] = {};

	//napuni grid
	for (int i = 0; i < HEIGHT + 2; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			grid[i][j] = gen_Rand(0, 1);
		}
	}

	while (true)
	{
		system("cls");
		cout << "Displaying GEN " << counter << endl;
		counter++;
		display_grid(grid);
		new_generation(grid);
		Sleep(1000);
	}

	return 0;
}
