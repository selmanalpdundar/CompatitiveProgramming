#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int LongestIncreasingSubsequence(vector<int> &arr){
    long n = arr.size();
    int lis[n];

    for(int k = 0; k<n; k++){
        lis[k] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]> arr[j] && lis[i] < lis[j] +1){
                lis[i] = lis[j] +1;
            }
        }
    }

    int max = lis[0];

    for(int t=0; t<n; t++){
        if(lis[t] > max){
            max = lis[t];
        }
    }
    return max;

}

int main()
{


    int t = 0;

    cin>>t;
    int outputs[t];

    for(int i=0; i<t; i++){

        int size = 0;

        cin>>size;

        vector<int> input;
        input.reserve(size);

        for(int j = 0; j<size; j++){
            int value = 0;
            cin>>value;
            input.push_back(value);
        }

        outputs[i] = LongestIncreasingSubsequence(input);
    }

    for(int i = 0; i<t; i++){
        cout<<outputs[i]<<endl;
    }

    return 0;
}
