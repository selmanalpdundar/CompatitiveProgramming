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
    
    if(size > pow(10, 5))
    {
        cout<<0<<endl;
        return 0;
    }
    
    vector<ll> inputs;

    inputs.reserve(size);
    
    for(int i = 0; i<size; i++)
    {
        ll number = 0;
        cin>>number;
        
        inputs[i] = number;
        sum += number;
    }
    

    ll Alice = 0;
    ll Bob = 0;
    int NumberOfBarOfAlice = 0;
    int NumberOFBarOfBob = 0;
    int left = 0;
    int right = size - 1;
    
    while(left<=right)
    {
        if(Alice<=Bob)
        {
            Alice+=inputs[left++];
            NumberOfBarOfAlice++;
        }
        else
        {
            Bob+=inputs[right--];
            NumberOFBarOfBob++;
        }
    }
    cout<<NumberOfBarOfAlice<<" "<<NumberOFBarOfBob<<endl;
    
    return 0;
}
