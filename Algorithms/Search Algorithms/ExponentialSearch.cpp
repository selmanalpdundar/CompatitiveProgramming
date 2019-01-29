#include<iostream>
using namespace std;

int binarySearch(int array[], int low , int high, int element)
{
    while(low <= high)
    {
        int middle = low + ((high - low ) / 2);
        
        if(array[middle] == element)
        {
            return middle;
        }
        
        if(array[middle] < element)
        {
            low = middle + 1;
        }
        else
        {
            high = middle -1;
        }
    }
    
    return -1;
}

int exponentialSearch(int array[], int start, int end, int key)
{
    if((end - start) <= 0)
        return -1;
    int i = 1; // as 2^0 = 1
    while(i < (end - start))
    {
        if(array[i] < key)
            i *= 2;
        else
            break; 
    }
    return binarySearch(array, i/2, i, key); 
}

int main()
{
    int n, searchKey, loc;
    cout << "Enter number of items: ";
    cin >> n;
    int arr[n]; 
    cout << "Enter items: " << endl;
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
    }
    cout << "Enter search key to search in the list: ";
    cin >> searchKey;
    if((loc = exponentialSearch(arr, 0, n, searchKey)) >= 0)
        cout << "Item found at location: " << loc << endl;
    else
        cout << "Item is not found in the list." << endl;
}
