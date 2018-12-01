#include <iostream>
/*
1.  if we calculate everyting at runtime
    it will take m*n time for all query if m and
    n big numbers it is not efficient

2.  n*n matrix (Optimal)
    O(n^2) to create  matrix
    O(n^2) to maintante matrix
    O(1) to answer
    
3. Segment Tree  (Best)
    O(n) to create tree
    O(n) to maintane tree
    O(logn) time to answer
*/

// use case: Range Query (range min, range max, range sum)

// Array implementation of Segment Tree
// Source : https://www.youtube.com/watch?v=ZBHKZF5w4YU

int min(int number1, int number2){
    if(number1<=number2){
        return number1;
    }else{
        return number2;
    }
}

void constructTree(int input[], int segmentTree[],int low, int high, int position){
    if(low == high){
        segmentTree[position] = input[low]; 
        return; 
    }
    int middle = (low + high) / 2;
    constructTree(input,segmentTree,low,middle, 2*position + 1);
    constructTree(input,segmentTree,middle + 1,high, 2 * position + 2);
    segmentTree[position] = min(segmentTree[2*position+1], segmentTree[2*position+2]);

}

int rangeMinimum(int segmentTree[], int queryLow, int queryHigh, int low, int high, int position){
    if(queryLow <= low && queryHigh >= high){ // Total overlap
        return segmentTree[position];
    }

    if(queryLow > high || queryHigh < low){ // No overlap
         return INT_MAX;
    }
    int middle = (low + high) / 2;

    return min(rangeMinimum(segmentTree,queryLow,queryHigh,low,middle,2*position +1),
               rangeMinimum(segmentTree,queryLow,queryHigh,middle+1,high,2*position + 2));
}

void updateQuery(){

}

int main(){

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

    int segmentTree[7];

    constructTree(input,segmentTree,0,3,0);

    std::cout<<rangeMinimum(segmentTree,1,3,0,3,0);


    return 0;
}