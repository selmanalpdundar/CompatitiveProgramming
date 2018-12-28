#include <iostream>
#include <forward_list>

int main(){

	std::forward_list<int> list;

	list.push_front(150);
	list.push_front(10);
	list.push_front(102);


	for(int item : list){
		std::cout<<item << " ";
	}

	std::cout<<std::endl;

	return 0;
}