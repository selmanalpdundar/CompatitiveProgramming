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
    for (int t = int(vectors[j].size()-2); t>=0; t--)  // T = 2(n-1) + 1 :  1 for assignment n-1 for checking and increment
        {
            if (max <= vectors[j][t])                  // T = n : n for checking
            {
                max = vectors[j][t];                   // T = n : n for assignment at most
                tempLeader.push_back(vectors[j][t]);   // T = n : n for assignment at most
            }
        }                                              // Total = 2(n - 1) + 1 + n + n + n   
                                                       // Total = 2n - 2 + 1 + n + n + n  = 5n - 1 = O(5n - 1) = n 
```      
The time complexity of algorithm will be linear because we only make a scanning on given input array.

### Explanation of Space Complexity
We will use at most 2n space n space for storing input and n space for storing leaders.

## Kadane's Algorithm   
**Problem Link**: [Kadane's Algorithm ](https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0)    
**Source**      : Geeks for Geeks  
**Code**        : [C++](KadanesAlgorithm.cpp)    
**Time Complexity**  : O(N)  
**Space Complexity**: O(N)

### Description
We start with taking first element from given array sum and max at the beginning and start loop from index 1. we look current sum is positive or not.If it is positive add current element of array to sum. if it is negative assign current element to sum. After checking current sum we will check maximum  because  maximum represents pervious maximum contiguous sub-array, if our sum is bigger than maximum assign it to maximum.
### Explanation of Time Complexity
```c++
int sum = array[0];
int max = array[0];

for(int k = 1; k<m; k++)   // T = 2(m-1)+ 1 
{
  
  if(sum > 0  )            // T = m-1
  {
    sum += array[k];       // T = m-1
  } else 
  {
    sum = array[k];        // T = m-1
  }

  if(sum > max)            // T = m-1  
  {
   max = sum;              // T = m-1  
  }
            
 }                         
                           //Total =  2(m - 1) +1 + m-1 + m - 1 + m - 1 + m - 1
                           //Total = 2m - 2 + 1 + m - 1 + m - 1 + m - 1 + m - 1 
                           //Total = 6m - 4 = O(6m - 4) = m
```   

We will need only one scan from left to right. Because we just checking sum and max with adding or assignment.
### Explanation of Space Complexity
We do not use extra space for doing anything. The system will use n space to store given input system.

