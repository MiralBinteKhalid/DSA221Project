#include<iostream>
#inlude<string>
#include<limits>
#include <stdexcept>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() in srand() 
#include <utility> // For std pair
#include<list>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };
  Node *front, *rear;
    int size;
    
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {} 
    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == nullptr) {
            front = rear = temp;
            size++;
            return;
        }
      rear->next = temp;
        rear = temp;
        size++;
    }
 int dequeue() {
        if (front == nullptr) {
            throw runtime_error("Queue is empty");
        }
        Node* temp = front;
        int value = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
     delete temp;
        size--;
        return value;
    }
  int peek() {
    if (front == nullptr) {
        throw runtime_error("Queue is empty");
    }
    return front->data;
      }
 bool isEmpty() {
        return front == nullptr;
    }
bool empty() {
    return isEmpty();
}
   
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};


struct AVLNode {
    int data;
    bool exists;
    AVLNode *left, *right;
    int height;
    
    AVLNode(int d) : data(d), exists(true), left(nullptr), right(nullptr), height(1) {}
};


class Graph {
    public:
     int** adjacencyMatrix;//public so that it can be displayed in bandwidth
private:
    int numNodes;
    int* SortMatrix;
    int i;
    AVLNode* root;
    list<int>* adj;
     int height(AVLNode* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
      AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
public:
    Graph(int n) : numNodes(n), root(nullptr) {
        if (n <= 0) throw invalid_argument("Number of nodes must be positive");
        adjacencyMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            adjacencyMatrix[i] = new int[n]();
        }
         i=0;
      SortMatrix=new int[numNodes];
      for (int i = 0; i < n; i++) {
            SortMatrix[i]=0;
        }
         adj = new list<int>[numNodes];
        
    }

    ~Graph() {
        for (int i = 0; i < numNodes; i++) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
        // Clean up AVL tree (implement recursive deletion)
        delete[] SortMatrix;
        delete[] adj;
    }
   void addNode(int nodeId) {
        if (nodeId < 0 || nodeId >= numNodes) {
            throw invalid_argument("Node ID out of range");
            
        }
        SortMatrix[i]=nodeId;
        root = insertAVL(root, nodeId);
        i++;
    }
void deleteNode(int nodeId) {
        if (nodeId < 0 || nodeId >= numNodes) {
            throw invalid_argument("Node ID out of range");
        }
        AVLNode* node = findNode(root, nodeId);
        if (!node || !node->exists) {
            throw invalid_argument("Node does not exist");
        }
        node->exists = false;
    void deleteNode(int nodeId) {
        if (nodeId < 0 || nodeId >= numNodes) {
            throw invalid_argument("Node ID out of range");
        }
        AVLNode* node = findNode(root, nodeId);
        if (!node || !node->exists) {
            throw invalid_argument("Node does not exist");
        }
        node->exists = false;
            // Clear adjacency matrix rows and columns
        for (int i = 0; i < numNodes; i++) {
            adjacencyMatrix[nodeId][i] = 0;
            adjacencyMatrix[i][nodeId] = 0;
        }
    }
 void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";
        for (int i = 0; i < numNodes; i++) {
            if (adjacencyMatrix[node][i] && !visited[i] && nodeExists(i)) {
                DFSUtil(i, visited);
            }
        }
    }



    public:
    void DFS(int startNode) {
        if (!nodeExists(startNode)) {
            throw invalid_argument("Start node does not exist");
        }
        bool* visited = new bool[numNodes]();
        DFSUtil(startNode, visited);
        delete[] visited;
        cout << endl;
    }

pair<int,int> findBestBandwidth(){
    srand(static_cast<unsigned>(time(0)));
    int maxWeight = 0;
    pair<int, int> bestPair(-1, -1);
    
    // Count existing nodes first
    int* existingNodes = new int[numNodes];
    int nodeCount = 0;
    
    for (int i = 0; i < numNodes; i++) {
        if (nodeExists(i)) {
            existingNodes[nodeCount++] = i;
        }
    }
    //there should be at least 2 nodes to find bandwidth
    if (nodeCount >= 2) {
        // Assign random weights between existing nodes
        for (int i = 0; i < nodeCount; i++) {
            for (int j = i + 1; j < nodeCount; j++) {
                int node1 = existingNodes[i];
                int node2 = existingNodes[j];
                
                int weight = rand() % 100 + 1;  // Random weight 1-100
                adjacencyMatrix[node1][node2] = weight;
                adjacencyMatrix[node2][node1] = weight;

                if (weight > maxWeight) {
                    maxWeight = weight;
                    bestPair = {node1, node2};
                }
            }
        }
    }
    
    delete[] existingNodes;
    return bestPair;
}

//adding edges to make a graph
 void addEdge(int v, int w) { 
    if (v >= 0 && v < numNodes && w >= 0 && w < numNodes) {
        // Update both adjacency list and matrix
        //using list to add edges
        adj[v].push_back(w);
        adj[w].push_back(v);
        
        // Setting default weight of 1 in adjacency matrix
        adjacencyMatrix[v][w] = 1;
        adjacencyMatrix[w][v] = 1;
        
        cout << "Edge added between " << v << " and " << w << endl;
    } else {
        //exception handling
        throw invalid_argument("Invalid edge vertices");
    }
}   

//To check if it is a graph or avl tree 
bool hasEdges() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (adjacencyMatrix[i][j] > 0) {
                return true;
            }
        }
    }
    return false;
}





};




        
    
