#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    char vertex1;
    char vertex2;
    int weight;
    Edge(char v1, char v2, int w): vertex1(v1), vertex2(v2), weight(w){}
};

struct Graph{
    vector<char> vertices;
    vector<Edge> edges;
};


class DisjointSet
{
    unordered_map<char,char> PARENT;
    unordered_map<char,int> RANK;
    
public:
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
    
    void makeSet(char vertex)
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
        char root1 = ds.find(e.vertex1);
        char root2 = ds.find(e.vertex2);
        
        if(root1 != root2){
            A.push_back(e);
            ds.unionSets(root1, root2);
        }
    }
    for(Edge e:A){
        cout<< e.vertex1 << "--" << e.vertex2 << " : "<< e.weight<<endl;
    }
}


int main()
{
  
    char t[] = {'a','b','c','d','e','f'};
    
    Graph g;
    g.vertices = vector<char>(t,t+sizeof(t)/ sizeof(t[0]));
    g.edges.push_back(Edge('a','b',4));
    g.edges.push_back(Edge('a','f',2));
    g.edges.push_back(Edge('f','b',5));
    g.edges.push_back(Edge('c','b',6));
    g.edges.push_back(Edge('c','f',1));
    g.edges.push_back(Edge('f','e',4));
    g.edges.push_back(Edge('d','e',2));
    g.edges.push_back(Edge('d','c',3));
    
    Kruskal(g);
    
    return 0;
}
