#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <climits>

#define ll long long int

using namespace std;

bool canRepresentPreorder(vector<ll> &arr, int n)
{
    stack<ll> stack;
    
    ll root = INT_MIN;
    
    for (int i=0; i<n; i++)
    {
        if (arr[i] < root)
            return false;
        
        while (!stack.empty() && stack.top()<arr[i])
        {
            root = stack.top();
            stack.pop();
        }
        
        stack.push(arr[i]);
    }
    return true;
}

int main()
{
    
    vector<bool> outputs;
    
    
    int testNumber = 0;
    cin>>testNumber;
    outputs.reserve(testNumber);
    
    for(int i=0; i<testNumber; i++)
    {
        vector<ll> inputs;
        
        int size =  0;
        cin>> size;
        
        inputs.reserve(size);
        
        for(int j = 0; j<size; j++)
        {
            ll number = 0;
            cin>>number;
            
            inputs.push_back(number);
        }
        
        outputs[i] = canRepresentPreorder(inputs,size);
        
    }
    
    for(int i = 0; i<testNumber; i++){
        cout<<outputs[i]<<endl;
    }
    
    return 0;
}
