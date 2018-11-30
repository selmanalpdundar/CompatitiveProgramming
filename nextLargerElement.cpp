#include <iostream>
#include <vector>
#include <stack>  

int main() {
    /* Problem
         Given an array A of size N having distinct elements,
         the task is to find the next greater element for each element of 
         the array in order of their appearance in the array.
         If no such element exists, output -1
     */

    unsigned int t = 0;  // it is not going to be lower than 0
    std::cin>>t;

    while(t>0){

        //----- Declaration of Variables ----- //
        unsigned int n = 0;
        std::cin>>n;

        std::vector<int> numbers;
        numbers.reserve(n);

        for(int k=0; k<n; k++){
            std::cin>>numbers[k];
        }

        std::stack<int> stack;

        // Push first element into stack
        stack.push(numbers[0]);

        for(int i = 1; i<n; i++){

            /*
                While stack is not empty and top of stack not bigger than i 
                pop element from stack and push numbers
            */
            while(!stack.empty() && numbers[i]>stack.top()){
                std::cout<<numbers[i]<<" ";
                stack.pop();
            }
            stack.push(numbers[i]);
        }

        for(int j=0; j<stack.size(); j++){
            std::cout<<-1<<" ";
        }

        t--;

        std::cout<<std::endl;
    }
    return 0;
}