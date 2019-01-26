#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

ll merge(vector<ll> &arr,vector<ll> &temp, ll left, ll mid, ll right);



ll mergeSort(vector<ll> &arr, vector<ll> &temp, ll left, ll right)
{
    ll mid, inversionCount = 0;
    if(right > left)
    {
        mid = (right + left) / 2;
        inversionCount = mergeSort(arr, temp, left, mid);
        inversionCount += mergeSort(arr, temp, mid + 1, right);
        
        inversionCount += merge(arr,temp,left, mid+1,right);
    }
    return inversionCount;
}

ll merge(vector<ll> &arr,vector<ll> &temp, ll left, ll mid, ll right)
{
    ll i,j,k;
    ll inversionCount = 0;
    
    i = left;
    j = mid;
    k = left;
    
    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversionCount = inversionCount + (mid - i);
        }
    }
    
    while(i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    
    while(j <= right)
    {
        temp[k++] = arr[j++];
    }
    
    for(int y = left; y <= right; y++)
    {
        arr[y] = temp[y];
    }
    return inversionCount;
}


int main()
{
    
    int t = 0;
    vector<ll> inversionCounts;
    vector< vector<ll> > inputs;
    
    cin>>t;
    cout<<endl;
    inversionCounts.reserve(t);
    inputs.reserve(t);
    
    for(int j = 0; j<t; j++)
    {
      
        int n = 0;
        cin>>n;
        vector<ll> input;
        input.reserve(n);
        
        for(int i =0; i<n; i++)
        {
            int number = 0;
            cin>> number;
            input.push_back(number);
        }
    
        inputs.push_back(input);
        cout<<endl;
    }

    for(int k = 0; k<t; k++)
    {
        ll size = (ll) inputs.at(k).size();
        vector<ll> temp;
        temp.reserve(size);
        cout<< mergeSort(inputs.at(k), temp, 0, size-1)<<endl;
    }
    
    
    
    return 0;
}
