#include <iostream>
#include <vector>

int main(int argc, char** argv){

	size_t N = std::stoul(argv[1]);
	
	std::vector<uint32_t> vector;

	vector.reserve(N);

	for(uint32_t i = 0; i<N; i++){
		vector.push_back(i);
	}

	std::cout<<"Vector size is : "<<vector.size()<<std::endl;

	for(auto item:vector){
		std::cout<<item<<" ";
	}

	std::cout<<std::endl;
}