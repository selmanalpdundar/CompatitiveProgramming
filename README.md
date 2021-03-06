# Competitive Programming and Contests

## 1.Leaders in an array  
**Problem Link**: [Leaders in an array](https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0)  
**Source**      : Geeks for Geeks  
**Code**        : [C++](LeadersInArray.cpp)  
**Time Complexity**  : O(N)  
**Space Complexity**: O(N) 

### Description
We will take the last element as a maximum and start to go left-forward and check each element witch this maximum if any of them bigger then current maximum push it to leaders and change current maximum with this number.
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
We start with taking the first element from given array as sum and max at the beginning and start loop from index 1. we look current sum is positive or not. If it is positive add current element of array to sum. If it is negative assign current element to sum. After checking current sum we will check maximum  because  maximum represents pervious maximum contiguous sub-array, if our sum is bigger than maximum assign it to maximum.
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
Instead of checking all number in array first calculate total sum from 1 to N with Gauss summation formula. Then subtract all the element of array from it. The number that will remain will be the missing one.
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
We start with calculating maximum number of both side and we follow it with getting maximum of left and right with us while iterating on array. After that we just check which side is smallar for given index and calculate it by subracting current element.

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
for(int k=n-2; k>=0; k--)                                        // T = 2(n - 1) + 1
{  
    if((numbers[k] < numbers[k + 1]) & (rMax < numbers[k+1]))    // T = 2(n - 1)
    {
        rightMax[k] = numbers[k+1];                              // T = n - 1
        rMax = numbers[k];                                       // T = n - 1
    }
    else
    {
        rightMax[k] = rMax;                                     // T = n - 1
    }
 }

// Total = 2(n-2) + 1 + 2(n-1) + n-1 + n -1 + n -1
// Total = 2n-2+1 + 2n -2 +3n -3 = 7n-6 = O(7n-6) = N
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
The logic of finding window maximum keeping calculation of previous slides in queue. Each time windows move we remove one elment from windows and new one to window. We use dequeue to have linear time solution. We check first front element is in index or not because in the queue front element is maximum for windows. After that we check new element that we add with back of the queue If it is smaller then current element pop it from queue and and new element to queue. Finally, we report front element of the qeueu as a maximum of the current window.

### Explanation of Time Complexity
```c++
for(int i =0; i<n; i++) { 
    
    if(!deque.empty() && deque.front() == i - k) {
            deque.pop_front();
    }

    while (!deque.empty() && numbers[deque.back()] < numbers[i]){
           deque.pop_back();
    }
    
    deque.push_back(i);

    if(i >= k-1) {
       result.push_back(numbers[deque.front()]);
    }

 }
```
The time complexity is linear because we only  pop or push once each element. All operation of pushing and poping are constant time operation..We start to check queue fron back if there is a small number then current element pop until there is no element or there is bigger. Then push back current element.
### Explanation of Space Complexity
We will have n more space for deque.

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
**Time Complexity** : O(n)      
**Space Complexity**: O(n)      

### Description
We need to store first pair of the i j with stregths of them to be able to loop best  combination. I have used a priority queue to be ables to  list all the pair incrementally. We just need to check pairs if they are seen before or not. If they are seen mark them as a seen one then go on. After iteration is done we will have answers for best pairs to create teams.


### Explanation of Time Complexity
```c++
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
```   
The time complexty of the algorithm is O(n) becuase we are using piority queue to keep pair and it give us opportunity to itarate once on the queue to find 
the higher score pairs.
### Explanation of Space Complexity
There no need extra space for the hangling it is O (N).

## 9.Inversion Count
**Problem Link**: [Inversion Count](https://www.spoj.com/problems/INVCNT/)   
**Source**      : Sphere Online Judge    
**Code**        : [C++](InversionCount.cpp)     
**Time Complexity** : O(NLogN)    
**Space Complexity**:  O(N)  

### Description
Instead of couting every inversion as one piece we dive them in to sub problems. We know number of inversion in left and right side of the array
an while merging we are counting inversions. Therefore to get number of inversions we need to add number of inversions in left and rigt subarray and merge.

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
The problems solution comes from counting sort we have limited digit range like 0-9. First we sort all input array with counting sort. First pass will find smallest even number and number of its occurence. Second pass will print out starting from biggest and check even number count if it is bigger than 1 it will also printed. End of the two pass we have print out a number finally we need to print smallest even number one more time to make even given input.

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
**Time Complexity** : O(n) + O(nlogn) for sorting   
**Space Complexity**: O(n)    

### Description
First we get inputs and while getting input we calculate cumulative sum of the population.
We first check it is equal or over a million. If it is not equal or over a million return -1;
While taking value of the coordinates we calculate x^2+y^2 to use later for finding radius.
We iterate on neighbor and take sum of the population when we are over 1 million take the square root of x^2 + y^2  

### Explanation of Time Complexity
```c++

sort(location.begin(),location.end());

for(int i=0; i<NumberOfLocations; i++)
{
    population+=location[i][1];

    if(population>=pow(10,6))
    {
        cout<<setprecision(8)<<sqrt((long double)location[i][0])<<endl;
        break;
    }
}
```   
In here dominant time complexity is the sorting. It will depend on the sorting algorithm.
Also, for checking locations and population will take at most O(n) time.
### Explanation of Space Complexity
There is no need extra memory.


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
**Time Complexity** : O(ROW * COLUMN)        
**Space Complexity**: O(ROW * COLUMN)      

### Description
For solving this problem I got help from a few differen web site. 

### Explanation of Time Complexity
```c++
   for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (inputs[i][j] == 'X' && !visited[i][j]) {
                DFS(i, j, row, column);
                number++;
            }
        }
    }
```   
We just visit each vertex and check if it is 'X' and unvisited vertex. If it is we increase number and call DFS.
### Explanation of Space Complexity
It uses only  2(row * coloumn) because we are also tracing information about vertex to see it is visited or not.

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
**Time Complexity** : O(|E|+|V|log|V|)     
**Space Complexity**:   

### Description
This had been explained in class notes.

### Explanation of Time Complexity
This had been explained in class notes.

### Explanation of Space Complexity

This had been explained in class notes.



## 37.N Meetings in One Room
**Problem Link**: [N Meetings in One Room](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0)    
**Source**      : Geeks for Geeks    
**Code**        : [C++](NMeetingsInOneRoom.cpp)         
**Time Complexity** : O(nlogn)     
**Space Complexity**: O(n)    

### Description
We sort given meetings by finis time and compare If the next start time of meeting is grater than end time of previous.
### Explanation of Time Complexity
```c++
        struct meeting temp= meeting[0];
        
        outputs[i].push_back(temp.id);
        
        int prev=temp.finish;
        
        for(int k=1;k<numberOfItem;k++)
        {
            temp=meeting[k];
            if(temp.start>prev)
            {
                outputs[i].push_back(temp.id);
                prev=temp.finish;
            }
        }
        
```   
Time complexity rely on sort algorithm otherwise we are just scanning given input array.
### Explanation of Space Complexity
There is no need to extra space.

## 38. Magic Number
**Problem Link**: [Magic Number](http://codeforces.com/problemset/problem/320/A)   
**Source**      : Geeks for Geeks    
**Code**        : [C++](MagicNumber.cpp)       
**Time Complexity** : O(N)       
**Space Complexity**: O(N)      

### Description
We are checking three condition to understand it is magic or not.

### Explanation of Time Complexity
```c++
    for(int i = 0; i<input.size(); i++){
        
        if( input[i] == '1' ||
           ( input[i] == '4' && i>0 && input[i-1] == '1')
           || (input[i] == '4' && i > 1 && input[i - 1] == '4' && input[i - 2] == '1')){
        } else{
            isMagic = false;
        }
        
    }
```   
The time complexity is number of character. It is linear
### Explanation of Space Complexity
We do not use any other extra space.

## 39.Wilbur and Array
**Problem Link**: [Wilbur and Array](http://codeforces.com/problemset/problem/596/B?locale=en)  
**Source**      : Code Forces   
**Code**        : [C++](WilburAndArray.cpp)      
**Time Complexity** : O(N)     
**Space Complexity**: O(N)   

### Description
The minimum number of operations equals the sum of the absolute values of differences between consecutive elements of b.

### Explanation of Time Complexity
```c++
    for(int i = 1; i <= n; i++)
    {
        int number = 0;
        cin>>number;
        inputs[i] = number;
        result += abs(inputs[i] - inputs[i-1]);
    }

```   
We are calculating absulute value of differences It takes linear time.
### Explanation of Space Complexity
There is no need extra space.


## 40.Alternative Thinking
**Problem Link**: [Alternative Thinking](http://codeforces.com/problemset/problem/603/A?locale=en)    
**Source**      : Code Forces    
**Code**        : [C++](AlternativeThinking.cpp)       
**Time Complexity** : O(N)    
**Space Complexity**: O(N)    

### Description
We are iterating in given binary string and counting longest 

### Explanation of Time Complexity
```c++
    for(int i=0;i<numberOfItem;i++){
        if(scores[i]!=scores[i+1])
            count++;
    }
    
    cout<< (count+2>numberOfItem ? numberOfItem: count+2 );
```   
It is linear time we just need to iterate once on given binary string.
### Explanation of Space Complexity
There is no need for extra space.


## 41.Lexicographically Maximum Subsequence
**Problem Link**: [Lexicographically Maximum Subsequence](http://codeforces.com/problemset/problem/196/A?locale=en)      
**Source**      : Code Forces    
**Code**        : [C++](LexicographicallyMaximumSubsequence.cpp)      
**Time Complexity** : O(n)     
**Space Complexity**: O(n)     

### Description
Take last element char and create a local maximum string then go on from right to left and if the current char equal or bigger take it.

### Explanation of Time Complexity
```c++
 for(int i=size; i>=0; i--){
       
        if(text.at(i)>=current){
            
            localMax = text.at(i) + localMax;
            current = text.at(i);
        }
    }
```   
It is just scanning given string from right to left.
### Explanation of Space Complexity
There is no need any extra space.






## 42.Woodcutters
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



## 43.Queue
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



## 44.Longest Common Subsequence
**Problem Link**: [Longest Common Subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0)   
**Source**      : Geeks for Geeks   
**Code**        : [C++](LongestCommonSubsequence.cpp)        
**Time Complexity** : O(n*m)      
**Space Complexity**: O(n*m)     

### Description
This had been explained in class notes.    


### Explanation of Time Complexity
This had been explained in class notes.    
 

### Explanation of Space Complexity
This had been explained in class notes.    


## 45. 0 - 1 Knapsack Problem
**Problem Link**: [0 - 1  Knapsack Problem](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0)      
**Source**      : Geeks for Geeks      
**Code**        : [C++](KnapsackProblem.cpp)      
**Time Complexity** : O(nW) with dynamic programming     
**Space Complexity**: O(nW)     

### Description
This had been explained in class notes.    

### Explanation of Time Complexity
This had been explained in class notes.      

### Explanation of Space Complexity
This had been explained in class notes.    

## 46.Longest Increasing Subsequence
**Problem Link**: [Longest Increasing Subsequence](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0)  
**Source**      : Geeks for Geeks       
**Code**        : [C++](LongestIncreasingSubsequence.cpp)           
**Time Complexity** : O(n*n)      
**Space Complexity**: O(n)  

### Description
This had been explained in class notes.    


### Explanation of Time Complexity
This had been explained in class notes.    


### Explanation of Space Complexity
This had been explained in class notes.    



## 47.Minimum Number of Jumps
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



## 48.Edit Distance
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




## 49.Longest Bitonic Subsequence
**Problem Link**: [Longest Bitonic Subsequence](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0)    
**Source**      : Geeks for Geeks    
**Code**        : [C++](LongestBitonicSubsequence.cpp)       
**Time Complexity** : O(n*n) It is dependent on lis complexity   
**Space Complexity**: O(n)   

### Description
This had been explained in class notes.    


### Explanation of Time Complexity
This had been explained in class notes.    


### Explanation of Space Complexity
This had been explained in class notes.    




## 50.Subset Sum Problem
**Problem Link**: [Subset Sum Problem](https://practice.geeksforgeeks.org/problems/subset-sum-problem/0)      
**Source**      : Geeks for Geeks          
**Code**        : [C++](SubsetSumProblem.cpp)            
**Time Complexity** : O(n*subsetsum)    
**Space Complexity**: O(n*subsetsum)     

### Description
This had been explained in class notes.    

### Explanation of Time Complexity
This had been explained in class notes.     

### Explanation of Space Complexity
This had been explained in class notes.    



## 51.Vertex Cover
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





## 52.Longest Palindromic Subsequence
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




## 53.Longest Prefix Suffix
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


## 54.Shift The String
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
