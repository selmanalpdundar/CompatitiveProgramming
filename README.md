# Competitive Programming and Contests

## Leaders in an array  
**Problem Link**: [Leaders in an array](https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0)  
**Source**      : Geeks for Geeks  
**Code**        : [C++](LeadersInArray.cpp)  
**Time Complexity**  : O(N)  
**Space Complexity**: O(N)

### Description
We will take last element as a maximum and start to go leftforward and check each element witch this maximum if any of them bigger then current maximum push it to leaders and change current maximum with this number. 
### Explanation of Time Complexity
```c++
    for (int t = int(vectors[j].size()-2); t>=0; t--)  // T = 2n-2 :  n-2 times assignment and n-1 times checking
        {
            if (max <= vectors[j][t])                  // T = n : n times checking
            {
                max = vectors[j][t];                   // T = n : n times assignment at most
                tempLeader.push_back(vectors[j][t]);   // T = n : n times assignment at most
            }
        }                                              // Total = 5n - 2  and Big O(5n-2) = n
```      
The time complexity of algorithm will be linear because we only make a scanning on given input array.

### Explanation of Space Complexity
We will use at most 2n space n space for storing input and n space for storing leaders.

## Kadane's Algorithm   
**Problem Link**: [Kadane's Algorithm ](https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0)    
**Source**      : Geeks for Geeks  
**Code**        : [C++](KadanesAlgorithm.cpp)    
**Complexity**  : O(N)
### Explanation :
