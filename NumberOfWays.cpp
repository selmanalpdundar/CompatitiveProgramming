
/* Problem 3
 (Number of Ways). Given an array A[1, n], count the number of ways to split
 all the elements of the array into three contiguous parts so that the sum of elements in each
 part is the same.
 More formally, you need to find the number of such pairs of indices i and j (2  i  j 
 n − 1) such that
 Pi−1
 k=1 A[k] = Pj
 k=i A[j] = Pn
 k=j+1 A[k]
 Let S be the sum of the values in the array. If 3 does not divide S, we conclude that the
 number of ways is zero.
 
 
 Otherwise, we compute the array C which stores in position i the
 number suffixes of A[i . . . n] that sum to S3
 . We then compute the sum of the prefixes of A.  Every time a prefix i sums to S3
 , we add C[i + 2] to the result.
 
 
 */

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
    
    if(sum % 3 != 0)
    {
        cout<<0<<endl;
        
        return 0;
    }
    
    ll portion = sum/3;
    
    vector<ll> sufficies(size,0);
    
    ll ss = 0;
    
    for(int j = size - 1; j >= 0; j--)
    {
        ss += inputs[j];
        if(ss == portion)
        {
            sufficies.at(j) = 1;
        }
    }
    
    for(int k = size - 2; k >= 0; k--)
    {
        sufficies.at(k) += sufficies.at(k+1);
    }
    
    ll answer = 0;
    ss = 0;
    
    for(int i = 0; i+2 <size; i++)
    {
        ss += inputs[i];
        if(ss == portion)
        {
            answer += sufficies.at(i+2);
        }
    }
    
    cout<<answer<<endl;
    
    return 0;
}
