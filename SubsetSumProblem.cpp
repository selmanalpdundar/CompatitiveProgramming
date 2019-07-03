#include <iostream>
#include <vector>

using namespace std;

bool subSetSum(int inputs[],int n, int sum){

    bool T[n+1][sum+1];

    for(int i =0; i<=n; i++){
        T[i][0] = true;
    }

    for(int i =1; i<=sum; i++){
        T[0][i] = false;
    }
    for(int i = 1; i<=n; i++){
        for( int j = 1; j<=sum; j++){
            if(j - inputs[i-1] >= 0){
                T[i][j] = T[i-1][j] ? T[i-1][j] : T[i - 1][j-inputs[i-1]];
            }else{
                T[i][j] = T[i-1][j];
            }
        }
        
    }
    return T[n][sum];
}
int main(){
    std::ios_base::sync_with_stdio(false);

    int t = 0 ;

    cin>>t;
    bool outputs[t];

    for(int i = 0; i<t; i++){
        
        int n = 0;
        cin>>n;

        int inputs[n];
        int sum = 0;
        for(int j = 0; j<n; j++){
            int number = 0 ;
            cin>>number;
            inputs[j] = number;
            sum += number;
        }

        outputs[i] = (sum%2) != 0 ? false : subSetSum(inputs,n,sum/2);
        


    }

    for(int j = 0; j<t; j++){
        if(outputs[j] == true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}