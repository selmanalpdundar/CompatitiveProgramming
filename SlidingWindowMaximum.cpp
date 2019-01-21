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

        cin>>n; // Array Size
        cin>>k; // Windows size

        vector<int> numbers; // Stores given array
        deque<int> deque;    // Stores windows element 
        vector<int> result;  // Stores maximums in windows

        numbers.reserve(n);

        for(int i =0; i<n; i++)
        {
            cin>>numbers[i];
        }

        for(int i =0; i<n; i++)
        {

            // Remove element that is not inside range of windows      
            if(!deque.empty() && deque.front() == i - k) 
            {
                deque.pop_front();
            }

            // Remove element that smaller than current element.
            while (!deque.empty() && numbers[deque.back()] < numbers[i])
            {
                deque.pop_back();
            }

            // Push back current element.
            deque.push_back(i);

            // Check if i grater or equal to k - 1  push front to result array.
            if(i >= k-1)
            {
                result.push_back(numbers[deque.front()]);
            }

        }

        // Printing result to out.
        for(int j=0; j<result.size(); j++)
        {

            cout<<result[j]<<" ";
        }
        cout<<endl;

        t--;
    }


    return 0;
}
