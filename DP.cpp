/*
 [A] [Question]: Determine the number of unique paths from a given 
 cell to another in a 2D array, which means from point A to point B.
 Directions allowed : right and down */
*/
struct Point {
    int i;
    int j;
};  

int findNumUniquePath (vector<vector<int>> grid, Point *From , Point *To)
{   
     // Validate input grid
    if (grid.size() == 0)
        return 0;
    
    vector<vector<int>> dp;
    // Initialize dp 2D vector
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            dp[i][j] = -1;
    
    return numPathHelper (grid, From, To, dp);
}

int numPathHelper (vector<vector<int>> grid, Point *From , Point *To, vector<vector<int>>& dp) 
{
   
    // Lookup in dp 2D vector
    if (dp[From->i][From->j] != -1)
        return dp[From->i][From->j];
    
    // If we reached destination or met with a corner cell
    if (From == To || From->start == 0 || From->end == 0) {
        dp[From->i][From->j] = 1;
        return  dp[From->i][From->j];
    }
    
    // Recurse
    
    //Case 1: Traverse Down
    Point *X = new Point();
    X->i = From->i + 1;
    X->j = From->j;
    
    // Case 2: Traverse Right
    Point *Y = new Point();
    Y->i = From->i;
    Y->i = From->j + 1;
    
    dp[From->i][From->j] = findUniquePath(grid, X, To) + findUniquePath(grid, Y, To);
    
    return dp[From->i][From->j];
}

/*
 [B] [Question]: Determine the all the unique paths from a given 
 cell to another in a 2D array, which means from point A to point B.
 Directions allowed : right and down
 */
int findUniquePaths (vector<vector<int>> grid, Point *From , Point *To)
{   
     // Validate input grid
    if (grid.size() == 0)
        return 0;
    
    vector<vector<int>> dp;
    // Initialize dp 2D vector
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            dp[i][j] = -1;
    
    return PathHelper (grid, From, To, dp);
}

int PathHelper (vector<vector<int>> grid, Point *From , Point *To, vector<vector<int>>& dp) 
{
   
    // Lookup in dp 2D vector
    if (dp[From->i][From->j] != -1)
        return dp[From->i][From->j];
    
    // If we reached destination or met with a corner cell
    if (From == To || From->start == 0 || From->end == 0) {
        dp[From->i][From->j] = 1;
        return  dp[From->i][From->j];
    }
    
    // Recurse
    
    //Case 1: Traverse Down
    Point *X = new Point();
    X->i = From->i + 1;
    X->j = From->j;
    
    // Case 2: Traverse Right
    Point *Y = new Point();
    Y->i = From->i;
    Y->i = From->j + 1;
    
    dp[From->i][From->j] = findUniquePath(grid, X, To) + findUniquePath(grid, Y, To);
    
    return dp[From->i][From->j];
}

    
