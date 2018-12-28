#include <iostream>
#include <deque>

int main(){
	std::deque<int> deque = {20, 10, 25, 13};

	deque.push_back(222);
	deque.push_front(1);

	for(auto item:deque){
		std::cout<<item<<" ";
	}

	std::cout<<std::endl;

	std::cout<<deque.size()<<std::endl;

	std::cout<<std::endl;

	return 0;
}