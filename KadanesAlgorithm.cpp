#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    cin >> n;  

    for (int i = 0; i < n; i++) 
    { 

        unsigned int m = 0;
        cin >> m; 
        vector<int> array(m);

        for(int j = 0; j<m; j++)
        {
            cin>>array[j];
        }

        int sum = array[0];
        int max = array[0];

        for(int k = 1; k<m; k++)
        {
          if(sum > 0  )
          {
            sum += array[k];
          } else 
          {
            sum = array[k];
           }

            if(sum > max)
            {
                max = sum;
            }
        }

        cout<<max;
        cout<<endl;
    }

    return 0;
}
