#include <iostream>
#include <vector>
#include <string>



using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false);
    
    string input;
    
    cin>>input;
    
    bool isMagic = true;
    
    for(int i = 0; i<input.size(); i++){
        
        if( input[i] == '1' ||
           ( input[i] == '4' && i>0 && input[i-1] == '1')
           || (input[i] == '4' && i > 1 && input[i - 1] == '4' && input[i - 2] == '1')){
        } else{
            isMagic = false;
        }
        
    }
    
    isMagic == true ? cout<< "YES" : cout<<"NO";
    
    return 0;
    
}

