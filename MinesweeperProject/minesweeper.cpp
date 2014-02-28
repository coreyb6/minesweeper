#include<iostream>
#include<string>

using namespace std;

#include "utilities.h"
using Scobey::RandomGenerator;

int main(int argc, char* argv[])
{
    string difficulty;
    RandomGenerator randGen;
    int mines = 0;
    cout << "Please enter the diffiulty you would like to play on "
        "(easy, medium, hard): ";
    cin >> difficulty;
    if(difficulty == "easy")
    {
        const int sizeX = 9;
        const int sizeY = 9;
        mines = 10;
        int grid[sizeX][sizeY] = {0};
        char blankGrid[sizeX][sizeY];
        for(int i = 0; i < sizeX; i++)
        {
            for(int j = 0; j < sizeY; j++)
            {
                blankGrid[i][j] = 'X';
            }
        }

        for(int i = 0; i < mines; i++)
        {
            int tempX = randGen.getNextInt(0,8);
            int tempY = randGen.getNextInt(0,8);
            if(grid[tempX][tempY] != 9)
            {
                grid[tempX][tempY] = 9;
                if(tempX == 0 && tempY == 0) //top Left corner
                {
                    if(grid[0][1] != 9)
                    {
                        grid[0][1] += 1;
                    }
                    if(grid[1][1] != 9)
                    {
                        grid[1][1] += 1;
                    }
                    if(grid[1][0] != 9)
                    {
                        grid[1][0] += 1;
                    }
                }
                else if(tempX == 0 && tempY == 8) //bottom left corner
                {
                    if(grid[0][7] != 9)
                    {
                        grid[0][7] += 1;
                    }
                    if(grid[1][8] != 9)
                    {
                        grid[1][8] += 1;
                    }
                    if(grid[1][7] != 9)
                    {
                        grid[1][7] += 1;
                    }
                }
                else if(tempX == 8 && tempY == 0) //top right corner
                {
                    if(grid[8][1] != 9)
                    {
                        grid[8][1] += 1;
                    }
                    if(grid[7][1] != 9)
                    {
                        grid[7][1] += 1;
                    }
                    if(grid[7][0] != 9)
                    {
                        grid[7][0] += 1;
                    }
                }
                else if(tempX == 8 && tempY == 8) //bottom right corner
                {
                    if(grid[8][7] != 9)
                    {
                        grid[8][7] += 1;
                    }
                    if(grid[7][8] != 9)
                    {
                        grid[7][8] += 1;
                    }
                    if(grid[7][7] != 9)
                    {
                        grid[7][7] += 1;
                    }
                }
                else if(tempX == 0 && tempY != 0 && tempY != 8) //left wall
                {
                    for(int i = 1; i < 8; i++)
                    {
                        if(tempY == i)
                        {
                            if(grid[0][i-1] != 9)
                                grid[0][i-1] += 1;
                            if(grid[0][i+1] != 9)
                                grid[0][i+1] += 1;
                            if(grid[1][i-1] != 9)
                                grid[1][i-1] += 1;
                            if(grid[1][i] != 9)
                                grid[1][i] += 1;
                            if(grid[1][i+1] != 9)
                                grid[1][i+1] += 1;
                        }
                    }
                }
                else if(tempX == 8 && tempY != 0 && tempY != 8) //right wall
                {
                    for(int i = 1; i < 8; i++)
                    {
                        if(tempY == i)
                        {
                            if(grid[8][i-1] != 9)
                                grid[8][i-1] += 1;
                            if(grid[8][i+1] != 9)
                                grid[8][i+1] += 1;
                            if(grid[7][i-1] != 9)
                                grid[7][i-1] += 1;
                            if(grid[7][i] != 9)
                                grid[7][i] += 1;
                            if(grid[7][i+1] != 9)
                                grid[7][i+1] += 1;
                        }
                    }
                }
                else if(tempY == 8 && tempX != 0 && tempX != 8) //bottom wall
                {
                    for(int i = 1; i < 8; i++)
                    {
                        if(tempX == i)
                        {
                            if(grid[i-1][8] != 9)
                                grid[i-1][8] += 1;
                            if(grid[i+1][8] != 9)
                            grid[i+1][8] += 1;
                            if(grid[i-1][7] != 9)
                                grid[i-1][7] += 1;
                            if(grid[i][7] != 9)
                                grid[i][7] += 1;
                            if(grid[i+1][7] != 9)
                                grid[i+1][7] += 1;
                        }
                    }
                }
                else if(tempY == 0 && tempX != 0 && tempX != 8) //top wall
                {
                    for(int i = 1; i < 8; i++)
                    {
                        if(tempX == i)
                        {
                            if(grid[i-1][0] != 9)
                                grid[i-1][0] += 1;
                            if(grid[i+1][0] != 9)
                                grid[i+1][0] += 1;
                            if(grid[i-1][1] != 9)
                                grid[i-1][1] += 1;
                            if(grid[i][1] != 9)
                                grid[i][1] += 1;
                            if(grid[i+1][1] != 9)
                                grid[i+1][1] += 1;
                        }
                    }
                }
                else // all of the middle
                {
                    for(int i = -1; i < 2; i++)
                    {
                        for (int j = -1; j < 2; j++)
                        {
                            if(grid[tempX-i][tempY-j] != 9)
                            {
                                grid[tempX-i][tempY-j] += 1;
                            }
                        }
                    }
                }
            }
            else
            {
                i--;
            }
        }
        for(int j = 0; j < sizeY; j++)
        {
            for(int m = 0; m < sizeX; m++)
            {
                cout << blankGrid[m][j];
            }
            cout << "\n";
        }
        bool gameOver = false;
        while(gameOver != true)
        {
            cout << endl << "Enter a position (X,Y) that you would like to check "
                "\n(numbers separated by a space)(numbers must be between 1-9): ";
            int checkX;
            int checkY;
            cin >> checkX >> checkY;
            checkX = checkX - 1;
            checkY = checkY - 1;

            for(int j = 0; j < sizeY; j++)
            {
                for(int m = 0; m < sizeX; m++)
                {
                    if(checkX == m && checkY == j)
                    {
                        blankGrid[m][j] = grid[m][j]+48;
                        if(grid[m][j] == 9)
                            gameOver = true;
                    }
                    cout << blankGrid[m][j];
                }
                cout << "\n";
            }
            if(gameOver == true)
            {
                cout << "\nYou hit a mine, you have lost!\n";
                for(int j = 0; j < sizeY; j++)
        {
            for(int m = 0; m < sizeX; m++)
            {
                cout << grid[m][j];
            }
            cout << "\n";
        }
            } //does not show all zeros connected when a zero is chosen
        }
    }

    else if(difficulty == "medium") //unfinished
    {
        const int sizeX = 16;
        const int sizeY = 16;
        mines = 40;
        int grid[sizeX][sizeY];
    }
    else if(difficulty == "hard") //unfinished
    {
        const int sizeX = 30;
        const int sizeY = 16;
        mines = 99;
        int grid[sizeX][sizeY];
    }
    else
    {
        exit(0);
    }
}