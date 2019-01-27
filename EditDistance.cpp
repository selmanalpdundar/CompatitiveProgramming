#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int EditDistance(int size1, int size2, string word1, string word2)
{
    
    int l1 = size1+1;
    int l2 = size2+1;
    
    int matrix[l1][l2];
    
    // Filling Row
    for(int i=0; i<l2; i++)
    {
        matrix[0][i] = i;
    }
    
    // Filling Column
    for(int j=0; j<l1; j++)
    {
        matrix[j][0] = j;
    }
    
    
    
    for(int i = 1; i<=size1; i++)
    {
        for(int j= 1; j<=size2; j++)
        {
            if(word1.at(i-1) == word2.at(j-1))
            {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = 1 + min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i][j-1]);
            }
        }
    }

    return matrix[size1][size2];
}

int main()
{
    
    int t = 0;
    cin>>t;
    cin.ignore();
    
    queue<int> queue;
    
    for(int i = 0; i<t; i++)
    {
        string sizes;
        getline(cin,sizes);
      
        string words;
        getline(cin,words);
        
        long indexOfSpaceOfSize = sizes.find(" ");
        string sizeSideOne = sizes.substr(0,indexOfSpaceOfSize);
        string sizeSideTwo = sizes.substr(indexOfSpaceOfSize+1,sizes.size());
        
        long indexOfSpaceOfWords = words.find(" ");
        string wordsSideOne = words.substr(0,indexOfSpaceOfWords);
        string wordsSideTwo = words.substr(indexOfSpaceOfWords+1, words.size());
        
        queue.push(EditDistance(stoi(sizeSideOne), stoi(sizeSideTwo), wordsSideOne, wordsSideTwo));
        
     
    }
    
    for(int i=0; i<t; i++)
    {
        cout<<queue.front()<<endl;
        queue.pop();
    }
    return 0;
}
