#include <iostream>

int main() {


    int n = 0;
    int s = 0;


    std::cin>>n;
    std::cout<<std::endl;

    std::cin>>s;
    std::cout<<std::endl;

    if(n<1 || n>1000){
        exit(0);

    } else if(s<1 || s>1000000){
        exit(0);
    }






    return 0;
}
