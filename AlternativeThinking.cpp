#include <iostream>
#include <string>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    
    int numberOfItem = 0;
    cin>>numberOfItem;
    
    string scores;
    cin>>scores;
    

    int count = 0;
  
    for(int i=0;i<numberOfItem;i++){
        if(scores[i]!=scores[i+1])
            count++;
    }
    
    cout<< (count+2>numberOfItem ? numberOfItem: count+2 );

    
    return 0;
}
