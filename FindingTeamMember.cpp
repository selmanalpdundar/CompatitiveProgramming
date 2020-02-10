#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie();

    int numberOfTeam = 0 ;
    int strengths = 0;

    priority_queue< pair <int , pair<int, int> > > pairs;
 
  
    cin>>numberOfTeam;
    
    if(numberOfTeam >= 1  && numberOfTeam <= 400){
        int teamNumber = numberOfTeam * 2;

        // initilaize number of pair that maximum need to seen by the loop
        bool seen[teamNumber+1];
        // initliza number of answer
        int answer[teamNumber+1];
        
        // initializa seen and answer array
        for(int i = 0; i<=teamNumber; i++){
            seen[i] = false ;
        }
            
        // read stregths of each pair and save them on vector as a pair
        for(int i = 2; i<=teamNumber; i++){
            for(int j = 1; j<=i-1; j++){
                cin >> strengths;
                pairs.push( make_pair(strengths, make_pair(i, j)));
            }
        }
      
        // itarate on pairs that is saved.
        while(!pairs.empty()){
            // get first element of second pair
            int first = pairs.top().second.first;
            // get second element of second pair
            int second = pairs.top().second.second;
            // pop that pair
            pairs.pop();
            
            // check if the element is seen before in loop
            if(!seen[first] && !seen[second]){
                
                // assign team memebers are seen
                seen[first] = true;
                seen[second] = true;
                
                // asagin each of them as a team together because we used pioratiy queue it ordered incrementally
                // so first pair  has higher score
                answer[first] = second;
                answer[second] = first;
            }
                   
        }

        // print all the answers
        for(int i =  1; i<teamNumber+1; i++){
               cout << answer[i] << " ";
        }
    }
  return 0;


}
