#include <iostream>
using namespace std;



int main(){
  std::ios_base::sync_with_stdio(false);

  int numberOfTest = 0;
  cin>>numberOfTest;

  int outputs[numberOfTest];

  for(int i = 0; i<numberOfTest; i++){

      int numberOfItem = 0;
      cin>>numberOfItem;

      int startTimes[numberOfItem];
      int finishTimes[numberOfItem];

      for(int j=0; j<numberOfItem; j++){
        int temp = 0 ;
        startTimes[j] = temp;
      }

      for(int k=0; k<numberOfItem; k++){
        int temp = 0 ;
        finishTimes[k] = temp;
      }
  }

  return 0;
}
