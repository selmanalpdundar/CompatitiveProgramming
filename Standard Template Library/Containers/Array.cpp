#include <iostream>
#include <array>



int main(int argc, char** argv){

    const uint32_t N = 100;

    std::array<uint32_t, N> array;

    for(uint32_t i = 0; i<N; ++i){
    		array[i] = i;
    }

    array[4] = 10;
    array[0] = 23;

    array.front() = 454;
    array.back() = 100;

	for(auto it = array.begin(); it != array.end(); ++it){
		std::cout<<*it<<" ";
	}
    
    return 0;
}
