#include <iostream> 
#include <vector> 
#include <deque>
using namespace std;
int main() 
{
    int t = 0;
    cin>>t;  

    while(t!= 0 )
    {
        unsigned int n = 0;  
        unsigned int k = 0; 

        cin>>n; 
        cin>>k; 

        vector<int> numbers; 
        deque<int> deque;
        vector<int> result;

        numbers.reserve(n);

        for(int i =0; i<n; i++)
        {
            cin>>numbers[i];
        }

        for(int i =0; i<n; i++)
        { 
            if(!deque.empty() && deque.front() == i - k) 
            {
                deque.pop_front();
            }

            while (!deque.empty() && numbers[deque.back()] < numbers[i])
            {
                deque.pop_back();
            }
        
            deque.push_back(i);

            if(i >= k-1)
            {
                result.push_back(numbers[deque.front()]);
            }

        }

        for(int j=0; j<result.size(); j++)
        {
            cout<<result[j]<<" ";
        }
        cout<<endl;

        t--;
    }


    return 0;
}
