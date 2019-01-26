#include <iostream>
#include <vector>

using namespace std;

int main()
{

        int n = 0;
        vector<int> arr;
        cin>>n;
        
        arr.reserve(n);
        
        
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
        }

        sort(arr.begin(), arr.begin()+n);
        
        int glevel = 1; // Global maximum level
        int llevel = 1; // Local maximum level
        int merged = 0;
        
        for(int j = 0; j<n-1; j++)
        {
            if(arr[j] == arr[j+1])
            {
                llevel += 1;
                
                if(llevel > glevel)
                {
                    glevel = llevel;
                }
                merged += 1;
            }
            else
            {
                if(llevel > glevel)
                {
                    glevel = llevel;
                    llevel = 1;
                }
                else
                {
                    llevel = 1;
                }
            }
        }
        
        cout<< glevel <<" " << n - merged;
    
    return 0;
}
