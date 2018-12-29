#include <iostream>
#include <vector>
using namespace std;

int main() {

    int number_of_test = 0;

    cin >> number_of_test;

    vector< vector<int> > vectors;
    vector< vector<int> > leaders;

    // To get input
    for (int i = 0; i < number_of_test; i++)
    {

        int size_of_vector = 0;

        cin>>size_of_vector;

        vector<int> tempVector;

        tempVector.reserve(size_of_vector);

        for(int k = 0; k<size_of_vector; k++)
        {
            int  number = 0;
            cin>> number;
            tempVector.push_back(number);
        }

        vectors.push_back(tempVector);
    }


    // To find leaders
     for(int j=0; j<number_of_test; j++)
     {
        int max = vectors[j][vectors[j].size()-1];

        vector<int> tempLeader;

        tempLeader.push_back(vectors[j][vectors[j].size()-1]);

        for (int t = int(vectors[j].size()-2); t>=0; t--)
        {
            if (max <= vectors[j][t])
            {
                max = vectors[j][t];
                tempLeader.push_back(vectors[j][t]);

            }
        }
        leaders.push_back(tempLeader);

     }

       // To print leaders
    for(int o = 0; o<number_of_test; o++)
    {
        for(int h = leaders[o].size() - 1; h>=0; h--)
        {
              cout<<leaders[o][h]<<" ";

        }
        cout<<endl;
     }




    return 0;
}
