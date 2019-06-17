# Competitive Programming and Contests

## 1.Leaders in an array  
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

## 2.Kadane's Algorithm   
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


## 3.Missing number in array   
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

## 4.Trapping Rain Water  
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


## 5.Sliding Window Maximum  
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

## 6.Next larger element
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



## 7.Towers
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


## 8.Finding Team Member
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

## 9.Inversion Count
**Problem Link**: [Inversion Count](https://www.spoj.com/problems/INVCNT/)   
**Source**      : Sphere Online Judge    
**Code**        : [C++](InversionCount.cpp)     
**Time Complexity** : O(NLogN)    
**Space Complexity**:  O(N)  

### Description
Instead of couting every inversion as one piece we dive them in to sub problems. We know number of inversion in left and right side of the array
an while merging we are counting inversions. Therefore to get number of inversions we need to add number of inversiıns in left and rigt subarray and merge.

### Explanation of Time Complexity
The time complexity is NlogN and it comes from merge sort in side problem.

### Explanation of Space Complexity
We are using in place sorting algorthim for that reason we will not use any extra space for thar reason


## 10.Largest Even Number
**Problem Link**: [Largest Even Number](https://practice.geeksforgeeks.org/problems/largest-even-number/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](LargestEvenNumber.cpp)    
**Time Complexity** : O(N)
**Space Complexity**: O(N)

### Description
The problems solution comes from counting sort we have limited digit range like 0-9. First we sort all input array with counting sort. First pass will find smallest event number and number of its occurence. Second pass will print out starting from biggest and check even number count if it is bigger than 1 it will also printed. End of the two pass we have print out a number finally we need to print smallest even number one more time to make even given input.

### Explanation of Time Complexity
```c++
     for(int j = size; j>=0; j--)
        {
            if(digits[j] % 2 == 0)
            {
                if(smallestEven == digits[j]){
                    countOfSmallest += 1;
                }else{
                  smallestEven = digits[j];
                  countOfSmallest = 1;
                }
                flag = true;
            }
        }
        // First pass to find smallest even number  
       for(int k = size; k>=0; k--)
        {
            if(digits.at(k) == smallestEven)
            {
                if(countOfSmallest > 1)
                {
                    cout<<digits.at(k);
                    countOfSmallest--;
                }
            }
            else
            {
               cout<<digits.at(k);
            }
        }
        // Second pass to print out
        if(flag == true){
            cout<<smallestEven;
        }
        // Finally we are printig smallest element.
```   
We just pass input array 2 time after counting sort to find smallest element and printing.
### Explanation of Space Complexity
We use 2n space because of counting sort counting sor need n more space to  sort.


## 11.Firing Employees
**Problem Link**: [Firing Employees](https://practice.geeksforgeeks.org/problems/firing-employees/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](FiringEmployees.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 12. Check for BST
**Problem Link**: [Check for BST](https://practice.geeksforgeeks.org/problems/check-for-bst/1)      
**Source**      : Geeks for Geeks      
**Code**        : [C++](CheckForBST.cpp)             
**Time Complexity** :  O(N)        
**Space Complexity**:  O(N)    

### Description
To understand it is binary search tree or not we need to consider 3 properties. The left subtree of a node contains only nodes with keys less than the node’s key and right subtree of a node contains only nodes with keys greater than the node’s key. Both the left and right subtrees must also be binary search trees. We first check right subtree and left subtree after checking both we need to be sure both are BST. In here instead of using maximum and minimum we are using NULL value.  We will check both side individually. if given side is not NULL we are checking it. The point is here the node cannot have bigger value than high and smaller value than low.

### Explanation of Time Complexity
```c++
bool isBST(Node* root, Node* low=NULL, Node* high=NULL)
{
    if (root == NULL)
        return true;

    if (low != NULL && root->data < low->data)
        return false;

    if (high!= NULL && root->data > high->data)
        return false;

    return isBST(root->left, low, root) && isBST(root->right, root, high);
}
```   
Every node will be called only once. We do not call any node more than once therefore the complexity will be linear O(N)
### Explanation of Space Complexity
we do not use any extra space we only use node if we consider function calles it will be N.


## 13. Preorder Traversal and BST
**Problem Link**: [Preorder Traversal and BST](https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0)  
**Source**      : Geeks for Geeks  
**Code**        : [C++](PreorderTraversalAndBST.cpp)        
**Time Complexity** :O(N)   
**Space Complexity**: O(N)  

### Description
Preorder traversal of BST will always have properties that are root element first followed by left sub tree and
 left sub tree followed by right sub tree. If the value to be placed on top of Stack  is larger than top of stack, then we will push to hold new value. If the value to be placed on top of Stack is smaller than variable top of Stack, then we will stop our execution because it says that given preorder traversal is invalid traversal sequence of BST.


### Explanation of Time Complexity
We will not push any element to stack more than one. Inner loop will be execute only n time. The outer loop also same for that reason we will have O(n) time complexity.

### Explanation of Space Complexity
We are using stack and it cannot be more than n. we just push and pop each element of array only once.


## 14.Maximum Path Sum
**Problem Link**: [Maximum Path Sum](https://practice.geeksforgeeks.org/problems/maximum-path-sum/1)   
**Source**      : Geeks for Geeks   
**Code**        : [C++](MaximumPathSum.cpp)      
**Time Complexity** :  O(N)    
**Space Complexity**:  O(N)    

### Description
For each node there can be four ways that the max path goes through the node. node only, max path through left child plus node , max path through right chhild plus node, and max path through left child plus node plus max path through right child. The idea is to keep trace of four paths and pick up the max one in the end. An important thing to note is, root of every subtree need to return maximum path sum such that at most one child of root is involved. This is needed for parent function call. In below code, this sum is stored in ‘max_single’ and returned by the recursive function.

### Explanation of Time Complexity
Time complexity is n becuase we will only execute number of node.

### Explanation of Space Complexity
Space complexiy is n it is number of node.


## 15.Ilya and Queries
**Problem Link**: [Ilya and Queries](http://codeforces.com/problemset/problem/313/B?locale=en)    
**Source**      : Code Forces   
**Code**        : [C++](IlyaAndQueries.cpp)      
**Time Complexity** : O(N)    
**Space Complexity**: O(N)

### Description
We created a sum array to store s<sub>i</sub> = s<sub>i+1</sub>. After this we can make query in constant time.
### Explanation of Time Complexity
```c++
  for(int i = 1; i<m; i++){
        if(array.at(i) == array.at(i - 1)){
            sum[i] = sum[i - 1] + 1;
        } else {
            sum[i] = sum[i - 1];
        }
    }
```   
The time complexity of query is constant becuase we already store answers in sum array. But we need to build sum array to make this query
It take n time to construct it.
### Explanation of Space Complexity
We only store sum array extra and it space is also N.

## 16.Alice, Bob and Chocolate
**Problem Link**: [Alice, Bob and Chocolate](http://codeforces.com/problemset/problem/6/C?locale=en)     
**Source**      : Code Forces     
**Code**        : [C++](AliceBobAndChocolate.cpp)        
**Time Complexity** : O(N)   
**Space Complexity**: O(N)   

### Description
We start following our inputs from both ways left and right. The problem give privilege to Alice to eat. If Alice eats less than or equal
Bob cannot eat therefore in loop Alice has privilege to eat first.   

### Explanation of Time Complexity
```c++
   while(left<=right)
    {
        if(Alice<=Bob)
        {
            Alice+=inputs[left++];
            NumberOfBarOfAlice++;
        }
        else
        {
            Bob+=inputs[right--];
            NumberOFBarOfBob++;
        }
    }
```   
We will iterate at most N times and we do not do anything else.

### Explanation of Space Complexity
We only use given input array nothing else.

## 17. Number of Ways
**Problem Link**: [Number of Ways](http://codeforces.com/problemset/problem/466/C?locale=en)   
**Source**      : Code Forces    
**Code**        : [C++](NumberOfWays.cpp)      
**Time Complexity** : O(n)     
**Space Complexity**: O(n)     

### Description
We first sum all of the our inputs to find threshold of our sub-parts. First we check the 3 is divisor of the sum or not.
We create a suffix array that holds the index which equals to sum/3 from i to n. After finding suffix array we calculate the
cumulative sum of the suffix array. Then we start from beginning of original input array to find prefix that equals to sum/3
if there is a prefix equals to sum/3 we value of the i+2th element of suffix array to answer.
### Explanation of Time Complexity
```c++
for(int j = size - 1; j >= 0; j--){
    ss += inputs[j];
    if(ss == sum){
        sufficies[j] = 1;
    }
}

for(int k = size - 2; k >= 0; k--){
    sufficies[k] += sufficies[k+1];
}

for(int i = 0; i<size-2; i++){
    ss += inputs[i];
    if(ss == sum){
        answer += sufficies.at(i+2);
    }
}
```   
Calculating suffix array takes linear time. Calculating cumulative sum of the suffix array also will take linear time.
Finally, finding prefix array and calculating the answer will take linear time
### Explanation of Space Complexity
We just need to suffix array that is the same size with the input array so our space complexity also linear.


## 18.Little Girl and Maximum Sum
**Problem Link**: [ Little Girl and Maximum Sum](http://codeforces.com/problemset/problem/276/C?locale=en)
**Source**      : Code Forces
**Code**        : [C++](LittleGirlAndMaximumSum.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




## 19. Update the Array
**Problem Link**: [ Update the Array](https://www.spoj.com/problems/UPDATEIT/)       
**Source**      : Sphere Online Judge     
**Code**        : [C++](UpdateTheArray.cpp)       
**Time Complexity** : Both Operation O(lgn)    
**Space Complexity**: O(n)     

### Description
For update the array problem, we are using binary index tree. In binary index three update and get value of element takes
O(logn) time.

### Explanation of Time Complexity
// Complexity of Time the Algorithm same with Binary indexed three structure

### Explanation of Space Complexity
// Complexity of Space the Algorithm same with Binary indexed three structure.



## 20.Megacity
**Problem Link**: [Megacity](http://codeforces.com/problemset/problem/424/B?locale=en)
**Source**      : Code Forces
**Code**        : [C++](MegaCity.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 21.Find Pair
**Problem Link**: [Find Pair](http://codeforces.com/problemset/problem/160/C?locale=en)
**Source**      : Code Forces
**Code**        : [C++](FindPair.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 22.Two Heaps
**Problem Link**: [Two Heaps](http://codeforces.com/problemset/problem/353/B?locale=en)
**Source**      : Code Forces
**Code**        : [C++](TwoHeaps.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 23.Circular RMQ
**Problem Link**: [Circular RMQ](http://codeforces.com/problemset/problem/52/C)
**Source**      : Code Forces
**Code**        : [C++](CircularRMQ.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 24.Nested Segments
**Problem Link**: [Nested Segments](http://codeforces.com/problemset/problem/652/D?locale=en)
**Source**      : Code Forces
**Code**        : [C++](NestedSegments.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


### Explanation of Space Complexity


## 25.Pashmak and Parmida's problem
**Problem Link**: [Pashmak and Parmida's problem](http://codeforces.com/problemset/problem/459/D?locale=en)
**Source**      : Code Forces
**Code**        : [C++](PashmakAndParmidasProblem.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 26.Powerful Array
**Problem Link**: [Powerful Array](http://codeforces.com/contest/86/problem/D)
**Source**      : Code Forces
**Code**        : [C++](PowerfulArray.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 27.Tree and Queries
**Problem Link**: [Tree and Queries](http://codeforces.com/contest/375/problem/D)
**Source**      : Code Forces
**Code**        : [C++](TreeAndQueries.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity

## 28.Array Copy
**Problem Link**: [Array Copy](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text23012018.pdf)
**Source**      : Exercise
**Code**        : [C++](ArrayCopy.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 29.Triplets
**Problem Link**: [Triplets](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf)
**Source**      : Exercise
**Code**        : [C++](Triplets.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 30.X Total Shapes
**Problem Link**: [X Total Shapes](https://practice.geeksforgeeks.org/problems/x-total-shapes/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](XTotalShapes.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 31.Bipartite Graph
**Problem Link**: [Bipartite Graph](https://practice.geeksforgeeks.org/problems/bipartite-graph/1)
**Source**      : Geeks for Geeks
**Code**        : [C++](BipartiteGraph.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




##  32.Fox And Names
**Problem Link**: [Fox And Names](http://codeforces.com/problemset/problem/510/C?locale=en)
**Source**      : Code Forces
**Code**        : [C++](FoxAndNames.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 33.Learning Languages
**Problem Link**: [Learning Languages](http://codeforces.com/problemset/problem/277/A?locale=en)
**Source**      : Code Forces
**Code**        : [C++](LearningLanguages.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity





## 34.Checkposts
**Problem Link**: [Checkposts](http://codeforces.com/problemset/problem/427/C?locale=en)
**Source**      : Code Forces
**Code**        : [C++](Checkposts.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 35.Xenia and Tree *
**Problem Link**: [Xenia and Tree](http://codeforces.com/problemset/problem/342/E?locale=en)
**Source**      : Code Forces
**Code**        : [C++](XeniaAndTree.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 36.Minimum Spanning Tree
**Problem Link**: [Minimum Spanning Tree](https://www.spoj.com/problems/MST/)
**Source**      : Sphere Online Judge
**Code**        : [C++](MinimumSpanningTree.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




## 37.N Meetings in One Room
**Problem Link**: [N Meetings in One Room](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](NMeetingsInOneRoom.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 38.Wilbur and Array
**Problem Link**: [Wilbur and Array](http://codeforces.com/problemset/problem/596/B?locale=en)
**Source**      : Code Forces
**Code**        : [C++](WilburAndArray.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 39.Alternative Thinking
**Problem Link**: [Alternative Thinking](http://codeforces.com/problemset/problem/603/A?locale=en)
**Source**      : Code Forces
**Code**        : [C++](AlternativeThinking.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity





## 40.Lexicographically Maximum Subsequence
**Problem Link**: [Lexicographically Maximum Subsequence](http://codeforces.com/problemset/problem/196/A?locale=en)
**Source**      : Code Forces
**Code**        : [C++](LexicographicallyMaximumSubsequence.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity






## 41.Woodcutters
**Problem Link**: [Woodcutters](http://codeforces.com/contest/545/problem/C?locale=en)
**Source**      : Code Forces
**Code**        : [C++](Woodcutters.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 42.Queue
**Problem Link**: [Queue](http://codeforces.com/problemset/problem/141/C?locale=en)
**Source**      : Code Forces
**Code**        : [C++](Queue.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 43.Longest Common Subsequence
**Problem Link**: [Longest Common Subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](LongestCommonSubsequence.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 44. 0 - 1 Knapsack Problem
**Problem Link**: [0 - 1 Knapsack Problem](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](KnapsackProblem)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 45.Longest Increasing Subsequence
**Problem Link**: [Longest Increasing Subsequence](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](LongestIncreasingSubsequence.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 46.Minimum Number of Jumps
**Problem Link**: [Minimum Number of Jumps](https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](MinimumNumberOfJumps.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity



## 47.Edit Distance
**Problem Link**: [Edit Distance](https://practice.geeksforgeeks.org/problems/edit-distance/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](EditDistance.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




## 48.Longest Bitonic Subsequence
**Problem Link**: [Longest Bitonic Subsequence](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](LongestBitonicSubsequence.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




## 49.Subset Sum Problem
**Problem Link**: [Subset Sum Problem](https://practice.geeksforgeeks.org/problems/subset-sum-problem/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](SubsetSumProblem.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




## 50.Vertex Cover
**Problem Link**: [Vertex Cover](https://www.spoj.com/problems/PT07X/)
**Source**      : Sphere Online Judge
**Code**        : [C++](VertexCover.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity





## 51.Longest Palindromic Subsequence
**Problem Link**: [Longest Palindromic Subsequence](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](LongestPalindromicSubsequence.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity




## 52.Longest Prefix Suffix
**Problem Link**: [Longest Prefix Suffix](https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0)
**Source**      : Geeks for Geeks
**Code**        : [C++](LongestPrefixSuffix)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity


## 53.Shift The String
**Problem Link**: [Shift The String](https://www.codechef.com/problems/TASHIFT)
**Source**      : Code Chef
**Code**        : [C++](ShiftTheString.cpp)    
**Time Complexity** :   
**Space Complexity**:

### Description


### Explanation of Time Complexity
```c++

```   

### Explanation of Space Complexity
