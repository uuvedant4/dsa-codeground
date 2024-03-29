// https : // leetcode.com/problems/n-queens/

class Solution
{
public:
    bool is_valid_board(int row, int col, int n, vector<string> &board)
    {
        int store_row = row, store_col = col;

        while (row >= 0 and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--, col--;
        }

        row = store_row, col = store_col;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = store_row, col = store_col;

        while (row < n and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--, row++;
        }

        return true;
    }

    void gen_boards(int col, int n, vector<string> &board, vector<vector<string>> &all_boards)
    {
        if (col == n)
        {
            all_boards.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (is_valid_board(row, col, n, board))
            {
                board[row][col] = 'Q';
                gen_boards(col + 1, n, board, all_boards);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string>> all_boards;
        gen_boards(0, n, board, all_boards);
        return all_boards;
    }
};