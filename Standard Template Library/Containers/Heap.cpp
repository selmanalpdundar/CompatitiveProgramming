#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct greaters{
    bool operator()(const long& a, const long & b) const{
        return a>b;
    }
};

int main(){
    
    vector<int> heap = {10,20,41,89,534,21};
    make_heap(heap.begin(),heap.end(),greaters());
    
    cout<<heap.front();
    
}
