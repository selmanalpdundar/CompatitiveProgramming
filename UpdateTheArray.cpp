#include <iostream>
#include <vector>

using namespace std;

void updateBIT(vector<int> &BITree, int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
    
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
        
        // Update index to that of parent in update View
        index += index & (-index);
    }
}
vector<int> constructBITree(vector<int> &arr, int n)
{
    // Create and initialize BITree[] as 0
    vector<int> BITree(n+1,0);
    
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
    
    return BITree;
}
// Updates such that getElement() gets an increased
// value when queried from l to r.
void update(vector<int> &BITree, int l, int r, int n, int val)
{
    // Increase value at 'l' by 'val'
    updateBIT(BITree, n, l, val);
    
    // Decrease value at 'r+1' by 'val'
    updateBIT(BITree, n, r+1, -val);
}


int getSum(vector<int> BITree, int index)
{
    int sum = 0; // Iniialize result
    
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
    
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
        
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
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
            results.push_back(getSum(binaryIndexTree,index));
            q--;
        }
        
        for(int i = 0; i<results.size(); i++){
            cout<<results[i]<<endl;
        }
        testNumber--;
    }
    
    
    
    
    return 0;
}
