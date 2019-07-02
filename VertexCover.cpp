#include <iostream>
#include <utility>


using namespace std;


int main(){


    int n = 0 ;

    cin>>n;
    

    pair<int,int> edges[n-1];

    for(int i = 0; i<n-1; i++){
        int u  = 0; 
        int v  = 0;

        cin>>u>>v;
        
        edges[i] = make_pair(u,v);
    }

    
    return 0;
}