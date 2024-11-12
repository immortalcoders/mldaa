#include <iostream>
#include <vector>

bool isSafe(const std::vector<std::vector<int>>&board, int row, int col, int n)
{
    for (int i = 0; i < col; ++i)
    {
        if(board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; ++1, --j)
    {
          if (board[i][j] == 1)
        {
            return false;
        }
    }

    return false;
}

bool solveNQuenns(std)