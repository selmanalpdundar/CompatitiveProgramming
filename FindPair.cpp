#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    
    int n = 0; // number of integer
    int k = 0; // the index of pair
    cin>>n>>k;
  
    vector<int> inputs;
    inputs.reserve(n);
    
    for(int i =0; i<n; i++){
        int number = 0;
        cin>>number;
        inputs[i] = number;
    }
    
    sort(inputs.begin(),inputs.end()+n);

    vector< pair<int,int > > pairs;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int first = inputs[i];
            int second = inputs[j];
            
            pair<int, int> pair = make_pair(first, second);
            pairs.push_back(pair);
            
        }
    }
    
    cout<<pairs[k-1].first<<" "<<pairs[k-1].second;
    
    return 0;
}
