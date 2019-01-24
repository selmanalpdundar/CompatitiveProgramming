#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    
    unsigned int t = 0;
    cin>>t;
    
    while(t>0){
        unsigned int n = 0;
        
        int64_t *array;
        
        cin>>n;
        
        array = new int64_t[n];
        
        for(int i = 0; i<n; i++){
            array[i] = -1;
        }
        
        // 10^18
        vector<uint64_t> numbers;
        numbers.reserve(n);
        
        for(int k=0; k<n; k++){
            cin>>numbers[k];
        }
        
        stack<int> stack;
        
        stack.push(0);
        
        for(int i = 1; i<n; i++){
            while(!stack.empty() && numbers[i] > numbers[stack.top()]){
                array[stack.top()] = numbers[i];
                stack.pop();
            }
            stack.push(i);
        }
        
        for(int t = 0; t<n; t++){
            cout<<array[t]<<" ";
        }
        
        t--;
        
        cout<<endl;
    }
    return 0;
}
