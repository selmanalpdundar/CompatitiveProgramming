#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct meeting{
    int start;
    int finish;
    int id;

};

bool compare(struct meeting a, struct meeting b){
    if(a.finish == b.finish){
          return a.start < b.start;
    }
    
    return a.finish < b.finish;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    
    int numberOfTest = 0;
    cin>>numberOfTest;
    
    vector< int > outputs[numberOfTest];
    
    for(int i = 0; i<numberOfTest; i++){
        int numberOfItem = 0;
        cin>>numberOfItem;
        
        struct meeting meeting[numberOfItem];
        
        for(int j=0; j<numberOfItem; j++){
            int number  = 0;
            
            cin>>number;
            meeting[j].start = number;
            meeting[j].id = j+1;
        }
        
        for(int k=0; k<numberOfItem; k++){
            int number = 0;
            cin>>number;
            meeting[k].finish = number;
        }
        
        sort(meeting, meeting+numberOfItem, compare);
        
        struct meeting temp= meeting[0];
        
        outputs[i].push_back(temp.id);
        
        int prev=temp.finish;
        
        for(int k=1;k<numberOfItem;k++)
        {
            temp=meeting[k];
            if(temp.start>prev)
            {
                outputs[i].push_back(temp.id);
                prev=temp.finish;
            }
        }
        
    }
    
    for(int i = 0; i<numberOfTest; i++){
        for(int j = 0; j<outputs[i].size(); j++){
            cout<<outputs[i].at(j)<<" ";
        }
        
        cout<<endl;
    }
    
    
    
    return 0;
}
