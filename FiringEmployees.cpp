#include <iostream>
#include <vector>

using namesspace std;


int main() {


    int t = 0;

    vector< vector<int> > vectors;

    cin>>t;

    for(int i = 0; i<t; i++){

        int n = 0;

        cin>>n;

        vector<int> vector;


        for(int j=0; j<n; j++){
            int temp = 0;
            cin>>temp;
            vector.push_back(temp);
        }
        vectors.push_back(vector);

    }

    return 0;
}
