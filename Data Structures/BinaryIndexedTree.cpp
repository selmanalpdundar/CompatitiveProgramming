#include <iostream>
using namespace std;
// Bınary Indexed Tree or Fen-wick Tree

/**
     * To get parent
     * 1) 2's complement to get minus of index
     * 2) AND this with index
     * 3) Subtract that from index
*/

int getParent(int index){
    return index - (index & -index);
}

/**
     * To get next
     * 1) 2's complement of get minus of index
     * 2) AND this with index
     * 3) Add it to index
*/

    
int getNext(int index){
    return index + (index & -index);
}

// Add
void updateBinaryIndexedTree(int binaryIndexedTree[], int size, int index, int value){
    while(index <= size){
        binaryIndexedTree[index] += value;
        index = getNext(index);
    }
}
void constructTree(int input[], int binaryIndexedTree[], int size){
    for(int i=1; i<size; i++){
        updateBinaryIndexedTree(binaryIndexedTree,size+1,i,input[i-1]);
    }
}
//Sum
int getSum(int binaryIndexedTree[], int index){
    index += 1;
    int sum = 0;
    while(index > 0){
        sum += binaryIndexedTree[index];
        index = getParent(index);
    }
    return sum;
}




int main(){
    int input[] = {5,5,1,4,5,6,7};
    int binaryIndexedTree[8] = {0};
     
    constructTree(input,binaryIndexedTree,7);

    cout<< getSum(binaryIndexedTree,4)<<endl;

   //  rangeSum(l, r) = getSum(r) – getSum(l-1)
   
    return 0;
}