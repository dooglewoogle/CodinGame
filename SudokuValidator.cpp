#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

You get a sudoku grid from a player and you have to check if it has been correctly filled.

A sudoku grid consists of 9×9 = 81 cells split in 9 sub-grids of 3×3 = 9 cells.
For the grid to be correct, each row must contain one occurrence of each digit (1 to 9), each column must contain one occurrence of each digit (1 to 9) and each sub-grid must contain one occurrence of each digit (1 to 9).

You shall answer true if the grid is correct or false if it is not.
Input - 9 rows of 9 space-separated digits representing the sudoku grid.
Output - true or false
Constraints
For each digit n in the grid: 1 ≤ n ≤ 9.

Example:
Input

1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
9 1 2 3 4 5 6 7 8
3 4 5 6 7 8 9 1 2
6 7 8 9 1 2 3 4 5
8 9 1 2 3 4 5 6 7
2 3 4 5 6 7 8 9 1
5 6 7 8 9 1 2 3 4

Output
true
*/

int main()
{
    vector<vector<int>> grid(9);
    set<int> dupdetctor;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n; cin.ignore();
            grid[i].push_back(n);
        }
    }

    //row
    int sum;
    for (int i=0; i<grid.size(); i++){
        sum = 0;
        for (int j=0; j<grid[i].size(); j++){
            sum += grid[i][j];
        }
        if (sum != 45){
            cout<<"false"<<endl;
            exit(0);
        }
    }

    //column 
    
    for (int i=0; i<grid.size(); i++){
        sum = 0;
        for (int j=0; j<grid[i].size(); j++){
            int n = grid[j][i];
            sum += n;
        }    
        if (sum != 45){
            cout<<"false"<<endl;
            exit(0);
        }   
    }

    cerr<<endl;

    // subgrid
    for (int i=0; i<9; i+=3){
        
        for (int j=0; j<9; j+=3){
            sum = 0;
            for (int k=0; k<3;k++){
                for (int l=0; l<3; l++){
                    // use set to detect duplicate numbers
                    auto r = dupdetctor.insert(grid[i+k][j+l]);
                    if (!r.second){
                        cout<<"false"<<endl;
                        exit(0);
                    }
                    sum += grid[i+k][j+l];
                }
            }
            cerr<<" :"<<sum<<endl;
            if (sum != 45){
                cout<<"false"<<endl;
                exit(0);
            }
            dupdetctor.clear();
        }  
    }

    cout << "true" << endl;
}
