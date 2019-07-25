#include <iostream>
#include <vector>
#include <algorithm>


#define ll long long

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    
    ll n = 0; // number of integer
    ll k = 0; // the index of pair
    cin>>n>>k;
    
    vector<ll> inputs;
    inputs.reserve(n);
    
    for(ll i =0; i<n; i++){
        ll number = 0;
        cin>>number;
        inputs[i] = number;
    }
    
    sort(inputs.begin(),inputs.end());
    
    
    
    if( k < n ){
        cout <<inputs[0] << " " <<inputs[k-1];
    } else {
        
        ll first = inputs[(k-1)/n];
        
 
        
        cout <<first << " " << endl;
    }
//    vector< pair<ll,ll > > pairs;
//
//    for(ll i = 0; i<n; i++){
//
//        ll first = inputs[i];
//
//        for(int j = 0; j<n; j++){
//
//            ll second = inputs[j];
//
//            pair<ll, ll> pair = make_pair(first, second);
//            pairs.push_back(pair);
//
//        }
//    }
//
//    sort(pairs.begin(),pairs.end());
//    cout<<pairs[k-1].first<<" "<<pairs[k-1].second;
    
    return 0;
}
