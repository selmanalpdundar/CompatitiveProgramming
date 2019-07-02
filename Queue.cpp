#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;


int main(){

    int n = 0;

    cin>>n;

    vector< pair<string,int> > inputs;

    for(int i = 0; i<n; i++){
        string name;
        int number;
        cin>>name>>number;
        inputs.push_back(make_pair(name,number));
    }



    return 0;
}