#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    long long inputs[n+1];
    long long result = 0;
    
    inputs[0] = 0;
    
    
    for(int i = 1; i <= n; i++)
    {
        int number = 0;
        cin>>number;
        inputs[i] = number;
        result += abs(inputs[i] - inputs[i-1]);
    }

    cout<<result;
    
    return 0;
}
