#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS Algorithm
void DepthFirstSearch(int CurrentNode, int SearchFor, vector <vector <int>> Graph, bool visited[]) {
    visited[CurrentNode] = true;
    if (CurrentNode == SearchFor) return;
    cout << CurrentNode << " -> ";
    for (int i = 0 ;i < Graph[CurrentNode].size() ; i++) {
        int Child = Graph[CurrentNode][i];
        if (!visited[Child])
           DepthFirstSearch(Child, SearchFor, Graph, visited);
    }

}

// BFS Algorithm
void Breadth-firstSearch(int CurrentNode, int SearchFor, vector <vector <int>> Graph, bool visited[]) {
    visited[CurrentNode] = true;
    if (CurrentNode == SearchFor) return;

    queue<int>q;
    q.push(CurrentNode);

    while (!q.empty()) {
        CurrentNode = q.front();
        cout << q.front() << " ==> ";
        for ()
    }
}
                                  //  Not completed   \\
int main() {

    //Graph Modeling
    int Nodes, Edges;

    cout << "Enter The number of Nodes: " << endl;
    cin >> Nodes;

    cout << "Enter The number of Edges: " << endl;
    cin >> Edges;

    vector <vector <int>> Graph(Nodes +1);

    int StartNode, EndNode;
    for (int i =1 ; i<=Nodes ; i++) {
        cout << "enter the start & end Nodes of Edges: " << endl;
        cin >> StartNode >> EndNode;
        Graph[StartNode].push_back(EndNode); //DirectedGraph
        Graph[EndNode].push_back(StartNode); //UNDirectedGraph
    }

    // Graph Printing
        // Method 1
        /*
        for (int i = 1; i < Nodes; i++) {
        cout << i << " ==>> "
        for (int j = 0 ; j < Graph[i].size(); j++)
            cout << Graph[i][j] << " | ";
        cout << endl;
    }    
        */
    
        // Method 2 | Traverse => DFS Algorithm (Depth First Search) ^

        bool* visited = new bool[Nodes+ 1]; 

        DepthFirstSearch(1,-1,Graph,visited);



}