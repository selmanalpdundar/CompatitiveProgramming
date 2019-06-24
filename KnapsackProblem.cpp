#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int knapsack(int maximumCapacity, int weights[], int values[], int numberOfItem){
    int i, w;
    int knapsack[numberOfItem+1][maximumCapacity+1];

    for(i = 0; i<=numberOfItem; i++){
        for(w = 0; w<=maximumCapacity; w++){
            if(i==0 || w==0){
                knapsack[i][w] = 0;
            }
            else if( weights[i-1] <= w){
                knapsack[i][w] = max(values[i-1] + knapsack[i-1][w-weights[i-1]],knapsack[i-1][w]);
            }
            else{
                knapsack[i][w] = knapsack[i-1][w];
            }
        }
    }

    return knapsack[numberOfItem][maximumCapacity];
}

int main(){
    std::ios_base::sync_with_stdio(false);

    int numberOfTest = 0;
    cin>>numberOfTest;

    int outputs[numberOfTest];

    for(int k = 0; k<numberOfTest; k++){

        int numberOfItem = 0;
        cin>>numberOfItem;

        int maximumCapacity = 0;
        cin>>maximumCapacity;

        int weigths[numberOfItem];

        int values[numberOfItem];

        for(int j = 0; j<numberOfItem; j++){
            int item = 0;
            cin>>item;
            values[j] = item;
        }


        for(int i = 0; i<numberOfItem; i++){
            int item = 0;
            cin>>item;
            weigths[i] = item;
        }


        outputs[k] = knapsack(maximumCapacity,weigths,values,numberOfItem);

    }

    for(int output : outputs){
        cout<<output<<endl;
    }
    return 0;
}
