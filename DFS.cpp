#include <iostream> 
#include <list> 
using namespace std; 

class DFSGraph 
{ 
    int V;    
    list<int> *adjList;    
    void DFS_util(int v, bool visited[], list<int>& path); 
public: 
    DFSGraph(int V)
    {
        this->V = V; 
        adjList = new list<int>[V]; 
    }
    void addEdge(int v, int w){
        adjList[v].push_back(w);
    }
     
    void DFS(); 
}; 

void DFSGraph::DFS_util(int v, bool visited[], list<int>& path) 
{ 
    visited[v] = true; 
    path.push_back(v); 
   
    list<int>::iterator i; 
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i) {
        if(!visited[*i]) {
            DFS_util(*i, visited, path); 
        }
    }
   
    if (i == adjList[v].end()) {
        path.pop_back(); 
    }
} 
   
void DFSGraph::DFS() 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) {
        visited[i] = false; 
    }
    
    list<int> path;
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            DFS_util(i, visited, path);
        }
    }
    
    cout << "Correct path in the maze:" << endl;
    for (int vertex : path) {
        cout << vertex << " ";
    }
} 

int main() 
{ 
    DFSGraph gdfs(21); 
    gdfs.addEdge(1, 2); 
    gdfs.addEdge(2, 3); 
    gdfs.addEdge(3, 4);
    gdfs.addEdge(3, 8);
    gdfs.addEdge(6, 7);
    gdfs.addEdge(6, 11);
    gdfs.addEdge(7, 12);
    gdfs.addEdge(11, 12);
    gdfs.addEdge(11, 16);
    gdfs.addEdge(12, 13);
    gdfs.addEdge(13, 14);
    gdfs.addEdge(13, 18);
    gdfs.addEdge(14, 19);
    gdfs.addEdge(19, 20);
    gdfs.addEdge(9,10);
    gdfs.addEdge(10, 15);

    cout << "Depth-first traversal for the given graph:" << endl; 
    gdfs.DFS(); 
   
    return 0; 
}
