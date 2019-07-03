#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

void makeEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
        << v+1 << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x+1;
        printf("\n");
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    int m = 0;
    
    cin>>n>>m;
    
    vector<int> adj[n];

    for(int i = 0; i<n; i++){
        string line;
        cin.ignore();
        getline(cin, line);
        
        istringstream myStream( line );
        istream_iterator<int> begin(myStream), eof;
        vector<int> numbers(begin, eof);
        
        for(int j = 0; j<numbers.size(); j++){
            makeEdge(adj, i, numbers.at(j)-1);
        }
        numbers.clear();
    }
    printGraph(adj, n);

    return 0;
}
