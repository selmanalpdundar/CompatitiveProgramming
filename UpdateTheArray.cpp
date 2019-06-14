#include <iostream>
#include <vector>

using namespace std;

void updateBIT(vector<int> &BITree, int n, int index, int val)
{
    index = index + 1;
    
    while (index <= n)
    {
        BITree[index] += val;
        
        index += index & (-index);
    }
}
vector<int> constructBITree(vector<int> &arr, int n)
{
    vector<int> BITree(n+1,0);
    
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    
    return BITree;
}

void update(vector<int> &BITree, int l, int r, int n, int val)
{
    updateBIT(BITree, n, l, val);
    
    updateBIT(BITree, n, r+1, -val);
}


int getElement(vector<int> BITree, int index)
{
    int result = 0; 
    
    index = index + 1;
    
    while (index>0)
    {
        result += BITree[index];
        index -= index & (-index);
    }
    return result;
}
int main(){
    
    std::ios_base::sync_with_stdio(false);

    int testNumber = 0;
    cin>>testNumber;
    
    while(testNumber != 0){
        int n = 0; // number of element
        int u = 0; // number of update
        
        cin>>n>>u;
        vector<int> inputs(n,0);
        vector<int> binaryIndexTree = constructBITree(inputs,n);
        
        while(u!=0){
            int l = 0; // lower boundary
            int r = 0; // upper boundary
            int val = 0; // value of update operation
            cin>>l>>r>>val;
            update(binaryIndexTree,l,r,n,val);
            u--;
        }
        
        
        int q = 0; // number of queries
        cin>>q;
        
        vector<int> results;
        while(q!= 0){
            int index = 0;
            cin>>index;
            results.push_back(getElement(binaryIndexTree,index));
            q--;
        }
        
        for(int i = 0; i<results.size(); i++){
            cout<<results[i]<<endl;
        }
        testNumber--;
    }
    
    
    
    
    return 0;
}
