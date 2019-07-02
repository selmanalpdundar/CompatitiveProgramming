#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


string LexicographicallyMaximumSubsequence(string text){
    
    string localMax = "";
    char current = text.at(text.length()-1);
    localMax += current;
    
    unsigned int size = text.length() -2;

    for(int i=size; i>=0; i--){
       
        if(text.at(i)>=current){
            
            localMax = text.at(i) + localMax;
            current = text.at(i);
        }
    }
    return localMax;
}
int main(){
    
    
    string text;
    
    cin>>text;
    
    cout<<LexicographicallyMaximumSubsequence(text)<<endl;

    
    return 0;
}
