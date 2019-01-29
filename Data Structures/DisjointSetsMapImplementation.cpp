#include <unordered_map>
#include <iostream>

using namespace std;

class DisjointSet
{
    unordered_map<char,char> PARENT;
    unordered_map<char,int> RANK;
    
public:
    DisjointSet()
    {
        char universe[] = {'a','b','c','d','e'};
        for(char x: universe)
        {
            PARENT[x] = x;
            RANK[x] = 0 ;
        }
        
    }
    char find(char item)
    {
        if(PARENT[item] == item)
        {
            return item;
        }
        else
        {
            return find(PARENT[item]);
        }
    }
    
    void unionSets(char set1, char set2)
    {
        if(RANK[set1] > RANK[set2])
        {
            PARENT[set2] = set1;
        }
        else if(RANK[set2] > RANK[set1])
        {
            PARENT[set1] = set2;
        }
        else{
             PARENT[set1] = set2;
             RANK[set2]++;
        }
       
    }
};

int main()
{
    DisjointSet ds;

    cout<< ds.find('a')<<endl;
    cout<< ds.find('b')<<endl;
    cout<< ds.find('c')<<endl;
    cout<< ds.find('d')<<endl;
    cout<< ds.find('e')<<endl;
    
    ds.unionSets('b', 'a');
    ds.unionSets('c', 'b');
    ds.unionSets('d', 'b');
    ds.unionSets('e', 'b');
    
    cout<< ds.find('a')<<endl;
    cout<< ds.find('b')<<endl;
    cout<< ds.find('c')<<endl;
    cout<< ds.find('d')<<endl;
    cout<< ds.find('e')<<endl;
    
    
    return 0;
}
