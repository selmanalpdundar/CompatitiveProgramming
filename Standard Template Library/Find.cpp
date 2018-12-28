#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    // using std::find with array and pointer.
    int array[] ={10,20,30,40};
    int *p;
    
    p = std::find(array,array+4,30);
    
    if(p != array+4){
        std::cout<<"Element found in array = "<< *p<<std::endl;
    }else{
        std::cout<<"Element not found in array"<< std::endl;
    }
    
    // using std::find with vector and iterator.
    
    std::vector<int> vector(array,array+4);
    std::vector<int>::iterator it;
    
    it = std::find(vector.begin(), vector.end(), 30);
    
    if(it != vector.end()){
        std::cout<<"Element found in vector = "<<*it<<std::endl;
    }else{
        std::cout<<"Element not found in vector"<< std::endl;
    }
    
    
    
    return 0;
}
