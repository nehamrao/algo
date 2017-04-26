#include <iostream>
#include <vector>
#include <tuple> 

using namespace std;

enum STATUS {
  UNVISITED = 1,
  PROCESSING = 2,
  VISITED = 3,
};

class Board {
  public:
    
    Board (vector<vector<char>> &grid) {
        this->grid = &grid;
              
       // Set visited grid to UNVISITED
       vector<vector<int>> temp(grid.size(), vector<int>(grid.at(0).size(), UNVISITED));
       this->visited = temp;
    }
  
    bool canReachEndGame (int start_i, int start_j, int end_i, int end_j) {
     // Empty grid
       if (grid->at(0).size() == 0) {
            return false;
       }
       
       // No direction picked initially
       // Populate start and end points for instance
       setIndexGlobals(&start_tup, start_i, start_j);
       setIndexGlobals(&end_tup, end_i, end_j);
        
       bool fal = false;
       return canReachEndHelper(start_i, start_j, nodir, &fal);
    }
                
    
    private:
      vector<vector<char>> *grid; // Global board
      vector<vector<int>> visited;
      std::tuple<int, int> start_tup;
      std::tuple<int, int> end_tup;
      
                         
      enum DIR {
        nodir = 0,
        right = 1,
        left = 2,
        up = 3,
        down = 4,
      };
    
      void setIndexGlobals (std::tuple<int, int> *a, int i, int j) {
        auto temp = std::make_tuple (i,j);
        *a = temp;
      }
        
      bool checkHitEnd (int i, int j) {
          if (i == std::get<0>(end_tup) && j == std::get<1>(end_tup)) {
              return true;
          }
          return false;
      }
    
      bool checkOutOfBounds (int i, int j) {
          if (i < 0 || j < 0 || i >= grid->at(0).size() || j >= grid->size()) {
              return true;
          }
          return false;
      }
    
      bool checkHitWall (int i, int j) {
          if (grid->at(i).at(j) == '#') {
              return true;
          }  
          return false; 
          
      }
    
      bool canReachEndHelper (int i, int j, DIR prevDir, bool *change_dir) {            
            cout << "Current Index (" << i << "," << j << ")\n";    
        
            // If we go out of boundary or hit a wall
            if (checkOutOfBounds(i,j) || checkHitWall(i, j)) {
                *change_dir = true;
                return false;
            } 
         
            visited[i][j] = PROCESSING;
            bool fal = false; 
        
            // If we hit our End
            if (checkHitEnd(i, j)) {
                return true;
            }
          
            if (prevDir == nodir) {
                return (canReachEndHelper(i+1, j, up, &fal) || 
                        canReachEndHelper(i-1, j, down, &fal) ||  
                        canReachEndHelper(i, j+1, right, &fal) || 
                        canReachEndHelper(i, j-1, left, &fal));
            }
            
            if (*change_dir) {
                if (prevDir == right || prevDir == left) {
                    return canReachEndHelper(i+1, j, up, &fal) || 
                      canReachEndHelper(i-1, j, down, &fal);
                } else if (prevDir == up || prevDir == down) {
                    return canReachEndHelper(i, j+1, right, &fal) || 
                      canReachEndHelper(i, j-1, left, &fal);
                }   
            } else {
                if (prevDir == right) {
                    return canReachEndHelper(i, j+1, right, &fal);
                } else if (prevDir == left) {
                    return canReachEndHelper(i, j-1, left, &fal);
                } else if (prevDir == up) {
                    return canReachEndHelper(i+1, j, up, &fal); 
                } else if (prevDir == down) {
                    return canReachEndHelper(i-1, j, down, &fal);
                }
            }
            
            visited[i][j] = VISITED;
            return false;
      }

};

int main () {
  
  
  vector<vector<char>> game(5, vector<char>(5));

  // . S . . .
  // . # # # .
  // . # # E . 
  // . # # . .
  // . . . . .

  // . S . . .
  // . # # # .
  // . # . . . 
  // . # . . .
  // . # E . .
  //game[0][2] = '#';
  game[1][1] = '#';
  game[2][1] = '#';
  game[3][1] = '#';
  game[4][1] = '#';
  game[1][3] = '#';
  game[1][2] = '#';
  
  Board b(game);
  bool result = b.canReachEndGame(0,0,4,2);
  if (result) {
    cout << "Can reach S -- E\n"; 
  } else {
    cout << "Cannot reach!"; 
  }
  return 0; 
}





  