#include <iostream>
#include <algorithm>

using namespace std;

void constructTree(int input[], int segmentTree[],int low, int high, int position)
{
    if(low == high)
    {
        segmentTree[position] = input[low];
        return;
    }
    int middle = (low + high) / 2;
    constructTree(input,segmentTree,low,middle, 2*position + 1);
    constructTree(input,segmentTree,middle + 1,high, 2 * position + 2);
    segmentTree[position] = min(segmentTree[2*position+1],segmentTree[2*position+2]);
    
}

int rangeMinimumQuery(int segmentTree[], int queryLow, int queryHigh, int low, int high, int position)
{
    if(queryLow <= low && queryHigh >= high)
    {
        return segmentTree[position];
    }
    
    if(queryLow > high || queryHigh < low)
    {
        return INT_MAX;
    }
    int middle = (low + high) / 2;
    
    return min(rangeMinimumQuery(segmentTree,queryLow,queryHigh,low,middle,2*position +1),
               rangeMinimumQuery(segmentTree,queryLow,queryHigh,middle+1,high,2*position + 2));
}

void updateQuery(int segmentTree[],int delta, int queryLow, int queryHigh, int low, int high, int position)
{
    if(low>high || queryLow > high || queryHigh < low)
    {
        return;
    }
    
    if(low == high)
    {
        segmentTree[position] += delta;
        return ;
    }
    int middle = (low + high) / 2;
    
    updateQuery(segmentTree,delta,queryLow,queryHigh,low,middle,2*position +1);
    updateQuery(segmentTree,delta,queryLow,queryHigh,middle+1,high,2*position + 2);
    segmentTree[position] = min(segmentTree[2*position+1],segmentTree[2*position+1]);
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
    
    constructTree(input,segmentTree,0,3,0);
    
    std::cout<<rangeMinimumQuery(segmentTree,1,3,0,3,0);
    
    
    return 0;
}
