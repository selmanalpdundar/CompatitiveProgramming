#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 0;
    cin >> n;  // n keeps how many case will be given

    for (int i = 0; i < n; i++) {  // to take set of data for test

        unsigned int m = 0;
        cin >> m; // size of vector
        vector<int> array(m-1);

        for(int j = 0; j<m-1; j++){
            cin>>array[j];
        }

        /* ----- Algorithm -------
            1.Calculate the sum of numbers froms 1 to N
            2.Subtract each element from sum 
            3.Print Sum
        */
        
        int sum = (m*(m+1))/2;      // Gauss summation formula

        for(int k = 0; k<m-1; k++){
            sum -= array[k];
        }

        cout<<sum;
        cout<<endl;
    }

    return 0;
}
