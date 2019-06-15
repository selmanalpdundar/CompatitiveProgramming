#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);

    int n = 0;
    cin>>n;
    
    vector<int> inputs;
    inputs.reserve(2*n);
    
    for(int i = 0; i<2*n; i++){
        cin>>inputs[i];
    }
    
    for(int i = 0; i<2*n; i++){
        cout<<inputs[i]<<endl;
    }
    
    return 0;
}
