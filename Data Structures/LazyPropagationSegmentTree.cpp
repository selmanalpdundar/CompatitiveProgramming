#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

void constructTree(int input[], int segmentTree[], int low, int high, int position)
{
    if(low == high)
    {
        segmentTree[position] = input[low];
        return;
    }
    int middle = (low + high) / 2;
    constructTree(input,segmentTree,low,middle, 2*position + 1);
    constructTree(input,segmentTree,middle + 1,high, 2 * position + 2);
    segmentTree[position] = min(segmentTree[2*position+1], segmentTree[2*position+2]);
    
}

int rangeMinimumQueryWithLazyPropagation(int *segmentTree, int *lazy, int queryLow, int queryHigh, int low, int high, int position){
    
    if(low>high)
    {
        return INT_MAX;
    }
    
    if(lazy[position] != 0)
    {
        segmentTree[position] += lazy[position];
        if(low!=high)
        {
            lazy[2*position+1] += lazy[position];
            lazy[2*position+2] += lazy[position];
        }
        lazy[position] = 0;
    }
    
    if(queryLow > high || queryHigh < low)
    { // No overlap
        return INT_MAX;
    }
    
    if(queryLow <= low && queryHigh >= high)
    { // Total overlap
        return segmentTree[position];
    }
    
  
    int middle = (low + high) / 2;
    
    return min(
               rangeMinimumQueryWithLazyPropagation(segmentTree,lazy,queryLow,queryHigh,low,middle,2*position +1),
               rangeMinimumQueryWithLazyPropagation(segmentTree,lazy,queryLow,queryHigh,middle+1,high,2*position + 2)
               );
}

void updateSegmentTreeRangeWithLazyPropagation(int *segmentTree,int *lazy,int delta, int queryLow,
                                               int queryHigh, int low, int high, int position)
{
    if(low>high)
    {
        return;
    }
    
    if(lazy[position]!= 0)
    {
        segmentTree[position] += lazy[position];
        if(low!=high)
        {
            lazy[2*position+1] += lazy[position];
            lazy[2*position+2] += lazy[position];
        }
        lazy[position] = 0;
    }
    
    if(queryLow > high || queryHigh < low)
    { // No overlap
        return;
    }
    
    if(queryLow <= low && queryHigh >= high)
    { // Total overlap
        segmentTree[position] += delta;
        if(low!=high)
        {
            lazy[2*position+1] += delta;
            lazy[2*position+2] += delta;
        }
        return;
    }
    
    int middle = (low + high) / 2;
    

    rangeMinimumQueryWithLazyPropagation(segmentTree,lazy,queryLow,queryHigh,low,middle,2*position +1);
    rangeMinimumQueryWithLazyPropagation(segmentTree,lazy,queryLow,queryHigh,middle+1,high,2*position + 2);
    segmentTree[position] = min(segmentTree[2*position+1],segmentTree[2*position+2]);
    
}

int main()
{
    
    int input[] = {-1,2,4,0};
    
    /*
     if input size equals power of 2
     segment tree size is 2n -1;
     if it is not power of 2
     find next power of 2 and take  it as
     a size.
     
     left child of segment tree is  2i + 1;
     right child of segment tree is 2i + 2;
     */
    
    int segmentTree[7] = {0};
    int lazy[7] = {0};
    
    constructTree(input,segmentTree,0,3,0);
    
    
    cout << rangeMinimumQueryWithLazyPropagation(segmentTree,lazy,0,2,0,3,0)<<endl;
    
    
    return 0;
}
