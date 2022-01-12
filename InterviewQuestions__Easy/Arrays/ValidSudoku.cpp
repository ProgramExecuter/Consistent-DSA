class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), grids(9);
        
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                
                // Find GRID no.
                int gridNo = (i/3)*3 + (j/3);
                
                if(board[i][j] == '.') {
                    continue;
                }
                // If the element is between '1' to '9'
                else {
                    // If the element exists in respective row or column
                    // then return false
                    if(
                        (rows[i].find(board[i][j]) != rows[i].end()) ||
                        (cols[j].find(board[i][j]) != cols[j].end()) ||
                        (grids[gridNo].find(board[i][j]) != grids[gridNo].end())
                    ) {
                        return false;
                    }
                    // Insert the values in rows, columns and grid sets
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    grids[gridNo].insert(board[i][j]);
                }
                
            }
        }
        
        return true;
    }
};