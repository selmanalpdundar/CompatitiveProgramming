#include <iostream>
#include <vector>
class NumberOfWays{
  
    
private:
    int sum;
    int size;
    std::vector<int> vector;
    
public:
    NumberOfWays(int n, int array[])
    {
        size = n;
        vector.reserve(n);
        
        for(int i = 0; i<n; i++){
            vector[i] = array[i];
            sum += array[i];
        }
    }

    int split(){
        if(sum % 3 != 0){
            return -1;
        }
        
        int checkPoint = sum / 3;
        int temp = 0;
        int counter = 0;
        int index1, index2 = 0;
        
        for(int j=0; j<size; j++){
            temp = vector[j];
        
            if(temp == checkPoint){
            
            }   
        }
        return 0;
    }

    
};

int main(){

    
    return 0;
}