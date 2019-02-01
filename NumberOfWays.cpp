#include <iostream>
#include <vector>
#include <cmath>

#define ll long long int

using namespace std;

int main()
{
    int size =  0;
    ll sum = 0;
    cin>> size;
    
    vector<ll> inputs;
    inputs.reserve(size);
    
    for(int i = 0; i<size; i++)
    {
        ll number = 0;
        cin>>number;
        
        inputs[i] = number;
        sum += number;
    }
    
    if(sum % 3 != 0)
    {
        cout<<0<<endl;
        
        return 0;
    }
    
    sum = sum/3;
    
    vector<ll> sufficies(size,0);
    
    ll ss = 0;
    
    for(int j = size - 1; j >= 0; j--)
    {
        ss += inputs[j];
        if(ss == sum)
        {
            sufficies[j] = 1;
        }
    }
    
    for(int k = size - 2; k >= 0; k--)
    {
        sufficies[k] += sufficies[k+1];
    }
    
    ll answer = 0;
    ss = 0;
    
    for(int i = 0; i<size-2; i++)
    {
        ss += inputs[i];
        if(ss == sum)
        {
            answer += sufficies.at(i+2);
        }
    }
    
    cout<<answer<<endl;
    
    return 0;
}
