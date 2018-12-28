#include <iostream>
#include <list>


int main(){

	std::list<int> list = {7,5,16,8};

	list.push_back(10);
	list.push_front(20);

	for(auto item:list){
		std::cout<<item<<" ";
	}

	std::cout<<std::endl;

	return 0;
}