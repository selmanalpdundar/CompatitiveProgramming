#include <iostream>
#include <vector>

#define min(a,b) ( (a) < (b) ? (a) : (b) )


using namespace std;


int main() {
    
    int t = 0;
    cin>>t;
    
    while(t != 0)
    {
        
        vector<int> numbers;
        vector<int> rightMax;
        vector<int> leftMax;
        
        unsigned n = 0;
        
        cin>>n;
        
        numbers.reserve(n);
        rightMax.reserve(n);
        leftMax.reserve(n);
        
        for(int i = 0; i<n; i++){
            cin>>numbers[i];
        }
        
        int lMax = numbers[0];
        
        for(int j=1; j<n; j++)
        {
            if((numbers[j-1] > numbers[j]) & (lMax < numbers[j-1]))
            {
                leftMax[j] = numbers[j-1];
                lMax = numbers[j-1];
            } else
            {
                leftMax[j] = lMax;
            }
        }
        
        int rMax = numbers[n-1];
        for(int k=n-2; k>=0; k--){
            if((numbers[k] < numbers[k + 1]) & (rMax < numbers[k+1]))
            {
                rightMax[k] = numbers[k+1];
                rMax = numbers[k+1];
                
            } else
            {
                rightMax[k] = rMax;
            }
        }
        
        
        int total = 0;
        
        for(int r=1; r<n-1; r++)
        {
            int min = min(leftMax[r],rightMax[r]);
            if( min > numbers[r]){
                total += min - numbers[r];
            }
        }
        
        
        cout<<total<<endl;
        
        
        t--;
    }
    
    
    return 0;
}
