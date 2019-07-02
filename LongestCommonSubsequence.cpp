#include <iostream>
#include <string>

using namespace std;


int LongestCommonSubsequence(string first, string second, int m, int n){
    int L[m + 1][n + 1];
    int i, j;
    
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (first[i - 1] == second[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}



int main(){
    
    
    int t = 0;
    
    
    cin>>t;
    
    int outputs[t];
    
    for(int i =0; i<t; i++){
        
        int n = 0, m = 0;
        
        cin>>n>>m;
        
        string first;
        string second;
        
        cin>>first;
        cin>>second;
        
        
        outputs[i] = LongestCommonSubsequence(first,second,n,m);
        
    }
    
    for(int j = 0; j<t; j++){
        
        cout<<outputs[j]<<endl;
    }
    
    
    return 0;
}
