#include <iostream>


template<typename T>
T max(T x, T y){
    return x > y ? x : y;
}

template<typename T1, typename T2>
bool are_eqaul(T1 x, T2 y){
    return x == y;
}

template<class T>
class Math{
    T  a, b ;
public:
    Math(T a , T b){
        this->a = a;
        this->b = b;
    }
    
    void add(){
        std::cout<< this->a + this-> b << std::endl;
    }
    
    void multiply(){
        std::cout<< this->a * this-> b << std::endl;

    }
    
    void divede(){
        std::cout<< this->a / this-> b << std::endl;

    }
};

int main(){
    
    auto x = max<int>(3,12);
    auto y = max<float>(3.4, 0.03);
    
    std::cout<< x << std::endl;
    std::cout<< y << std::endl;

    std::cout<< are_eqaul<int, double>(5,5.0)<<std::endl;

    Math<int> math(100,100);
    math.add();
    math.multiply();
    math.divede();
    
}
