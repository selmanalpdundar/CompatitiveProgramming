#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    
    int n = 0;
    
    cin>>n;
    
    vector< pair<int,int> > cordinates;
    cordinates.reserve(n);
    
    for(int i = 0; i<n; i++){
        int left = 0;
        int right = 0;
        cin>>left>>right;
        pair<int, int> temp = make_pair(left,right);
        cordinates.push_back(temp);
    }
//    
//    for(int i = 0; i<n; i++){
//        int left = cordinates[i].first;
//        int right = cordinates[i].second;
//        cout<<left<<" "<<right<<endl;
//        
//    }
    return 0;
}
