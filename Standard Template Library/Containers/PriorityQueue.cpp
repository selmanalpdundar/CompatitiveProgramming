#include <iostream>
#include <queue>

int main(){

	std::priority_queue<int> queue;

	for(int i = 0; i<20; i++){
		queue.push(i);
	}


	
	std::cout<<queue.top();

	std::cout<<std::endl;

	return 0;
}