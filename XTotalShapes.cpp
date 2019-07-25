#include <iostream>
#include <vector>



using namespace std;

#define COLUMN 50
#define ROW 50

char inputs[ROW][COLUMN];
bool visited[ROW][COLUMN];


int number(int row, int column);
void DFS(int i, int j, bool visited[][50], int r, int c);

int main(){
    
    int t = 0;
    cin>> t;
    
    int outputs[t];
    
    for(int i = 0; i<t; i++){
        
        int row = 0;
        int column = 0;
        
        cin>>row>>column;
        
        for(int i = 0; i <row; i++){
            
            for(int j = 0; j<column; j++){
                visited[i][j] = false;
            }
        }
      
        
        for(int j = 0; j<row; j++){
            for(int k = 0; k<column; k++){
                char letter;
                cin>>letter;
                inputs[j][k] = letter;
            }
        }
        outputs[i] = number(row, column);
    }
    
    for(int i = 0; i<t; i++){
        cout<<outputs[i]<<endl;
    }
    
    return 0;
}


void DFS(int i, int j, int row, int column) {
    if (i < 0 || i > row-1) return;
    
    if (j <0 || j > column-1) return;
    
    if (inputs[i][j] == 'O' || visited[i][j]) {
        return;
    }
    
    visited[i][j] = true;
    DFS(i+1, j, row, column);
    DFS(i-1, j, row, column);
    DFS(i, j+1, row, column);
    DFS(i, j-1, row, column);
    
}



int number(int row, int column) {
  
    int count = 0;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (inputs[i][j] == 'X' && !visited[i][j]) {
                DFS(i, j, row, column);
                count++;
            }
        }
    }
    
    return count;
}
