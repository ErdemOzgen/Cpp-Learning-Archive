#include<iostream>
#include<string>
#include<queue>
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

        Graph(int numVertices); // Constructor
        void addEdge(int parent, int child); // Adds an Edge
};

// This is a constructor for the Node class where we are supplying the integer.
Graph::Graph(int numVertices){
    this->numVertices = numVertices;
    edges = new vector<int>[numVertices];
}

// This function adds an edge in our Graph to the list of vectors that stores it.
void Graph::addEdge(int parent, int child){
    edges[parent].push_back(child);
}

// This is our BFS method. It will take in our Graph, and also the Node that we will
// be starting our BFS traversal.
void BFS(Graph& graph, int startingNode){
    // This will keep track of which Node we have already visited during the traversal.
    // We first initialize the vector, then fill it all with false because we haven't visted a Node yet
    vector<bool> visited;
    for(int i = 0; i < graph.numVertices; i++) visited.push_back(false);

    // This will keep track of the Nodes we have seen that haven't been visited, as well as the order
    // we will be visiting each of these Nodes
    queue<int> nodesToVisit;

    // We are now starting at the Node stated, so we assign it as visited and add it to the queue
    visited[startingNode] = true;
    nodesToVisit.push(startingNode);

    // We stop the BFS when we have no more Nodes waiting in line to be visited
    while(!nodesToVisit.empty()){
        int currentNode = nodesToVisit.front(); // Lets us temporarily store which Node is in front
        cout << currentNode << " ";
        nodesToVisit.pop(); // In order to make room for the Nodes we have to visit, we will remove the current Node from the queue

        // This will go through the graph, and look at all the nodes that have an edge connected to our current Node.
        // If a Node that is connected hasn't been visited yet, then we add it to our queue to visit, and say we have visited it.
        // This avoids repeats.
        for(int childrenNode : graph.edges[currentNode]){
            if(!visited[childrenNode]){
                visited[childrenNode] = true;
                nodesToVisit.push(childrenNode);
            }
        }
    }
    cout << endl << endl;
}

// We are now testing the BFS method. We initialize our Graph class and state the edges to create our Graph
// Once we have our Graph completely set up, we then begin the BFS starting at the initial Node.
// The output should be: 0 1 2 3 5 4 6
int main(){
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);

    BFS(graph, 0);
}