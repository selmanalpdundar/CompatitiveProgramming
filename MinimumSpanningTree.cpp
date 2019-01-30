#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge{
    int vertex1;
    int vertex2;
    int weight;
    Edge(int v1, int v2, int w): vertex1(v1), vertex2(v2), weight(w){}
};

struct Graph{
    vector<int> vertices;
    vector<Edge> edges;
};


class DisjointSet
{
    unordered_map<int,int> PARENT;
    unordered_map<int,int> RANK;
    
public:
    char find(int item)
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
    
    void unionSets(int set1, int set2)
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
    
    void makeSet(int vertex)
    {
        PARENT[vertex] = vertex;
        RANK[vertex] = 0;
    }
    
    
};

void Kruskal(Graph &g){
    vector<Edge> A;
    DisjointSet ds;
    
    for(auto c: g.vertices)
    {
        ds.makeSet(c);
    }
    
    sort(g.edges.begin(),g.edges.end(),[](Edge x, Edge y){return x.weight < y.weight;});
    
    for(Edge e : g.edges)
    {
        int root1 = ds.find(e.vertex1);
        int root2 = ds.find(e.vertex2);
        
        if(root1 != root2){
            A.push_back(e);
            ds.unionSets(root1, root2);
        }
    }
    int sum = 0;
    for(Edge e:A){
        sum += e.weight;
    }
    
    cout <<sum<<endl;
}


int main()
{
    
    char t[] = {'a','b','c','d','e','f'};
    
    Graph g;
    g.vertices = vector<int>(t,t+sizeof(t)/ sizeof(t[0]));
    
    
    int numberOfVertex = 0 , numberOfEdge = 0;
    cin>>numberOfVertex>>numberOfEdge;
    
    for(int i = 0; i<numberOfVertex; i++){
        g.vertices.push_back(i+1);
    }
    
    for(int i = 0; i<numberOfEdge; i++)
    {

        int vertext1 = 0, vertext2 = 0, weight = 0;
        cin>>vertext1>>vertext2>>weight;
        g.edges.push_back(Edge(vertext1,vertext2,weight));
    }
    
    Kruskal(g);
    
    return 0;
}
