#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>



using namespace std;

class Heap
{
private:
    vector<int> heap;
    
public:
    Heap(int *array, int size);
    void Insert(int element);
    void Max();
    int ExtractMax();
    void DisplayHeap();
    void Build();
    void Heapify(vector<int> &heap, int i);
    int Size();

};



Heap::Heap(int *array, int size)
{
    heap.reserve(size);
    
    for(int i=0; i<size; i++)
    {
        heap.push_back(array[i]);
    }
    Build();
}


void Heap::Heapify(vector<int> & heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if((left <= Size()-1) && (heap.at(left) > heap.at(largest)))
    {
        largest = left;
    }
    
    if((right <= Size() - 1) && (heap.at(right) > heap.at(largest)))
    {
        largest = right;
    }
    
    if(largest != i)
    {
        swap(heap.at(i), heap.at(largest));
        Heapify(heap,largest);
        
    }
    
}

int Heap::Size()
{
    return (int)heap.size();
}

void Heap::Insert(int element)
{
    
}

void Heap::Build()
{

    for(int i= Size() / 2 - 1; i>=0; i--)
    {
        Heapify(heap,i);
        
    }
}

int Heap::ExtractMax()
{
    return 0;
}



void Heap::DisplayHeap()
{
    vector<int>::iterator pos = heap.begin();
    cout<<" <-- Heap Print Begin ----> "<<endl;
    while(pos != heap.end())
    {
        cout<< *pos <<" ";
        pos++;
    }
    cout<<"\n <-- Heap Print end ----> "<<endl;

}

void Heap::Max()
{
    if(Size() != 0 ){
        
        cout<<heap.front()<<endl;
    }
}



int main()
{
    
    int array[] = {5,12,7,78,32,15,87,56,90,67};
    
    
    
    Heap heap(array,10);
    
    heap.DisplayHeap();
    
    heap.Max();
    return 0;
}
