#include <iostream>

int search(int array[], int low , int high, int element){
	
	while(low <= high){
		int middle = low + ((high - low ) / 2);
			
		if(array[middle] == element){
			return middle;
		} 

		if(array[middle] < element){
			low = middle + 1; 
		} else {
			high = middle -1;
		}
	}
	
	return -1;
}





 int main(){

	int array[] = {1,2,6,87,99,123,231,234,664,678};

	std::cout<<search(array,0,9,678)<<std::endl;

	return 0;
}