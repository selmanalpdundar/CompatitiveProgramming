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


## Missing number in array   
**Problem Link**: [Missing number in array ](https://practice.geeksforgeeks.org/problems/missing-number-in-array/0)    
**Source**      : Geeks for Geeks  
**Code**        : [C++](MissingNumberInArray.cpp)    
**Time Complexity**  : O(N)  
**Space Complexity**: O(N)

### Description
Intead of checking all number in array first calculate total sum from 1 to N with Gauss summation formula. Then subtract all the element of array from it. the number that will remain will be the missing one.
### Explanation of Time Complexity
```c++
int sum = (m*(m+1))/2;      // Gauss summation formula

for(int k = 0; k<m-1; k++) // T = 2(m - 1) + 1
{
    sum -= array[k];       // T = m - 1
}                          // Total = 2(m - 1) + 1 + m - 1 
                           // Total = 2m -2 + 1 + m - 1 = 3m - 1 = O(3m -1 ) = m                
```   
We are going to just travel in array to subtract each element of the array from gauss summation.
### Explanation of Space Complexity
We do not use extra space for doing anything. The system will use n space to store given input system.

## Trapping Rain Water  
**Problem Link**: [Trapping Rain Water](https://practice.geeksforgeeks.org/problems/trapping-rain-water/0)    
**Source**      : Geeks for Geeks  
**Code**        : [C++](TrappingRainWater.cpp)    
**Time Complexity**  : O(N)  
**Space Complexity**: O(N)

### Description
We start with calculating maximum number of both side and we follow it with getting maximum of left and right with us while iterating on array. After that we just check wich side is smallar for given index and calculate it by subracting current element.

### Explanation of Time Complexity

#### Finding Left Maximum of Current Element
```c++
int lMax = numbers[0];
for(int j=1; j<n; j++)                                      // T = 2(n - 1) + 1
{
  if((numbers[j-1] > numbers[j]) & (lMax < numbers[j-1]))   // T = 2(n - 1)
  {
     leftMax[j] = numbers[j-1];                             // T = n - 1
     lMax = numbers[j-1];                                   // T = n - 1
   } 
   else
   {
     leftMax[j] = lMax;                                     // T = n - 1
    }
}
// Total = 2(n-1) + 1 + 2(n-1) + n-1 + n -1 + n -1 
// Total = 2n-2+1 + 2n -2 +3n -3 = 7n-2  = O(7n-2) = N
```   
We are going to just scan in array to find maximum of left side of given element. 

#### Finding Right Maximum of Current Element
```c++
int rMax = numbers[n-1];
for(int k=n-2; k>=0; k--)                                        // T = 2(k - 1) + 1
{  
    if((numbers[k] < numbers[k + 1]) & (rMax < numbers[k+1]))    // T = 2(k - 1)
    {
        rightMax[k] = numbers[k+1];                              // T = k - 1
        rMax = numbers[k];                                       // T = k - 1
    } 
    else 
    {
        rightMax[k] = rMax;                                     // T = k - 1
    }
 }

// Total = 2(k-1) + 1 + 2(k-1) + k-1 + k -1 + k -1 
// Total = 2k-2+1 + 2k -2 +3k -3 = 7k-2  = O(7k-2) = N
```
We are going to just scan in array to find maximum of right side of given element. 

#### Finding Total Water 
```c++
int total = 0;
for(int r=1; r<n-1; r++)                          // T = 2(r - 2) + 1         
{
  int min = min(leftMax[r],rightMax[r]);          // T = r - 2)
  if( min > numbers[r]){                          // T = r - 2)
     total += min - numbers[r];                   // T = r - 2)
   }
}
 
// Total = 2(r-2)+1 + 3(r-2) = 2r-4+1 + 3r-6 = 5r - 9 = O(5r-9) = N
```
We are going to take both mimum of maximum of both side of current element. We need to check this minimum bigger than current element to subtract.

### Explanation of Space Complexity
We use here 2n more space to keep maximum of left and maximum of right. We do not use any other space therefore the space complexity is N.


## Sliding Window Maximum  
**Problem Link**: [Sliding Window Maximum](https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0) 
**Source**      : Geeks for Geeks  
**Code**        : [C++](SlidingWindowMaximum.cpp)    
**Time Complexity**  : O(N)  
**Space Complexity** : O(N)

### Description
This had been explained in class notes.
### Explanation of Time Complexity
This had been explained in class notes.
### Explanation of Space Complexity
This had been explained in class notes.

## Next larger element
**Problem Link**: [Next larger element](https://practice.geeksforgeeks.org/problems/next-larger-element/0) 
**Source**      : Geeks for Geeks  
**Code**        : [C++](NextLargerElement.cpp)    
**Time Complexity** : O(N)  
**Space Complexity**: O(N)

### Description
This problem is similar to Sliding Window Maximum problem. Instead of using dequeue we are using here stack. We just make one iteration from 1 to n check stack top if stack top smaller than current element print current element as a next element of stack top. We push current element to stack after finishing.

### Explanation of Time Complexity
```c++
  for(int i = 1; i<n; i++)
        {
            while(!stack.empty() && numbers[i] > numbers[stack.top()])
            {
                array[stack.top()] = numbers[i];
                stack.pop();
            }
            stack.push(i);
        }
```   
It seems like we have n^2 complexity but in fact we have n complexity. In while loop we do not do more than 2n operation because we do not pop and push more than n. we push a number to check later. if it is smaller than current element then we pop it and we done with this number. Therefore we will do at most n pop and n push operation.

### Explanation of Space Complexity
In here we have n space complexity because we use a stack n size and array n size. Stack cannot be bigger than n because we make push inside for not while.



## Towers
**Problem Link**: [Towers](http://codeforces.com/problemset/problem/37/A?locale=en) 
**Source**      : Code Forces  
**Code**        : [C++](Towers.cpp)    
**Time Complexity** : O(NLogN)  
**Space Complexity**: O(N)

### Description
We first start with sorting our input array because in the problem description it says you can only merge same length bars therefore when we sort we will have same length bars in a contigous order. The time complexity is here about sorting algoirthm I used stl sort but if we use counting sort it will be linear solution. I just scann sorted array and carry global and local level along scanning. When there is not matching I compare local level with global and assign it to global and resert local level. Also I count merging along scanning to find out how many bars I will have end of the scanning.

### Explanation of Time Complexity
```c++
    for(int j = 0; j<n-1; j++)                         
        {
            if(arr[j] == arr[j+1])
            {
                llevel += 1;
                
                if(llevel > glevel)
                {
                    glevel = llevel;
                }
                merged += 1;
            }
            else
            {
                if(llevel > glevel)
                {
                    glevel = llevel;
                    llevel = 1;
                }
                else
                {
                    llevel = 1;
                }
            }
        }
        
        cout<< glevel <<" " << n - merged;
```   
The time complexity is O(O) to find solution but we need to preprocess out input array there for we need to sort it. the complexity of it will be depend on sorting algorithm I use stl sort. If we use counting sort it will be O(N) but here it is O(NLogN)
### Explanation of Space Complexity
There is no need to use extra space for given input array I make everything in place.


## Finding Team Member
**Problem Link**: [Finding Team Member](http://codeforces.com/problemset/problem/579/B?locale=en) 
**Source**      : Code Forces  
**Code**        : [C++](FindingTeamMember.cpp)    
**Time Complexity** :   
**Space Complexity**: 

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## Finding Team Member
**Problem Link**: [Finding Team Member](http://codeforces.com/problemset/problem/579/B?locale=en) 
**Source**      : Code Forces  
**Code**        : [C++](FindingTeamMember.cpp)    
**Time Complexity** :   
**Space Complexity**: 

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## Inversion Count
**Problem Link**: [Inversion Count](https://www.spoj.com/problems/INVCNT/) 
**Source**      : Sphere Online Judge  
**Code**        : [C++](InversionCount.cpp)    
**Time Complexity** :   
**Space Complexity**: 

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity

## Largest Even Number
**Problem Link**: [Largest Even Number](https://practice.geeksforgeeks.org/problems/largest-even-number/0) 
**Source**      : Geeks for Geeks
**Code**        : [C++](LargestEvenNumber.cpp)    
**Time Complexity** :   
**Space Complexity**: 

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity
