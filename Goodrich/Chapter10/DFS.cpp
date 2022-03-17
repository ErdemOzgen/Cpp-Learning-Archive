#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<list>

using namespace std;

// The class below is a simple Graph class that contains the number of Nodes, and a list of Nodes,
// as well as the other Nodes that it points to in the Graph. We designated the value as an int,
// but the value of the Node can be anything, as it varies from Graph to Graph.
class Graph{
    
    public:
        int numVertices;  // Total number of Vertices in the Graph
        vector<int> *edges; // A list of all nodes the Node in a current position points to
        vector<bool> visited; // This will keep track of which Node we have already visited during the traversal.

        Graph(int numVertices); // Constructor
        void addEdge(int parent, int child); // Adds an Edge
};

// This is a constructor for the Node class where we are supplying the integer.
Graph::Graph(int numVertices){
    this->numVertices = numVertices;
    edges = new vector<int>[numVertices];
    // We first initialize the vector, then fill it all with false because we haven't visted a Node yet
    for(int i = 0; i < numVertices; i++) visited.push_back(false);
}

// This function adds an edge in our Graph to the list of vectors that stores it.
void Graph::addEdge(int parent, int child){
    edges[parent].push_back(child);
}

// This is our DFS method. It will take in our Graph, and also the Node that we are currently
// looking at in our DFS traversal
void DFS(Graph& graph, int startingNode){
    // We declare that the Node we are currently at is now visited
    graph.visited[startingNode] = true;
    cout << startingNode << " ";

    // We look through all the Nodes the current Node we are at is pointing too. If a child Node
    // has been visited, then we will ignore it. But once we see the first Node that hasn't been visited
    // we perform a recursive DFS call
    for(int childrenNode : graph.edges[startingNode]){
        if(!graph.visited[childrenNode]){
            DFS(graph, childrenNode);
        }
    }
}

// We are now testing the DFS method. We initialize our Graph class and state the edges to create our Graph
// Once we have our Graph completely set up, we then begin the DFS starting at the initial Node.
// The output should be: 0 1 3 6 5 2 4
int main(){
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);

    DFS(graph, 0);
}