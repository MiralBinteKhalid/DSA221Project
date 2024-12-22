#include<iostream>
#inlude<string>
#include<limits>
#include <stdexcept>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() in srand() 
#include <utility> // For std pair
#include<list>
using namespace std;

//Queue class
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
            throw runtime_error("Queue is empty");  //exception
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

//destructor
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


//Main class showing all functionalities
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
AVLNode* insertAVL(AVLNode* node, int data) {
    // Standard AVL insertion with balancing
    if (!node) return new AVLNode(data);
    if (data < node->data)
        node->left = insertAVL(node->left, data);
    else if (data > node->data)
        node->right = insertAVL(node->right, data);
     else {
        node->exists = true;
        return node;
    }
    
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    // Balance cases
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
        if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
     if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
    
}
AVLNode* findNode(AVLNode* node, int data) {
    if (!node) return nullptr;
   
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
    //if node is out of range error thrown
        if (nodeId < 0 || nodeId >= numNodes) {
            throw invalid_argument("Node ID out of range");
        }
    //finding root to delete
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
        //showing node doesn't exist
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

    void DFS(int startNode) {
        if (!nodeExists(startNode)) {
            throw invalid_argument("Start node does not exist");
        }
        bool* visited = new bool[numNodes]();
        DFSUtil(startNode, visited);
        delete[] visited;
        cout << endl;
    }

    //to find best bandwidth through highest weighted edge
pair<int,int> findBestBandwidth(){
    //random dynamically
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

//BFS for graphs and trees
void BFS(int startNode) {
    if (!nodeExists(startNode)) {
        throw invalid_argument("Start node does not exist");
    }

    if (hasEdges()) {
        // Graph BFS
        cout << "BFS traversal starting from node " << startNode << ": ";
        bool* visited = new bool[numNodes]();
        Queue graphQueue;
        
        visited[startNode] = true;
        graphQueue.enqueue(startNode);
        
        while (!graphQueue.empty()) {
            int currentNode = graphQueue.dequeue();
            cout << currentNode << " ";
            
            // Check adjacency matrix for neighbors
            for (auto i = adj[currentNode].begin(); i != adj[currentNode].end(); ++i) {
                if (!visited[*i] && nodeExists(*i)) {
                    visited[*i] = true;
                    graphQueue.enqueue(*i);
                }
            }

        }
        delete[] visited;
    } else {
        // AVL Tree BFS
        cout << "BFS traversal: ";
        if (root != nullptr) {
            Queue queue;
            queue.enqueue(root->data);
            AVLNode* current = root;
            
            while (!queue.empty()) {
                int currentValue = queue.dequeue();
                cout << currentValue << " ";
                
                current = findNode(root, currentValue);
                if (current->left != nullptr) {
                    queue.enqueue(current->left->data);
                }
                if (current->right != nullptr) {
                    queue.enqueue(current->right->data);
                }
            }
        }
    }
    cout << endl;
}

};



//Interactive Menus
void viewerMenu(Graph& graph);  // Forward declaration

void adminMenu(Graph& graph) {




    

}

void viewerMenu(Graph& graph) {
    int choice;
    do {
        cout << "\nViewer Menu:\n"
             << "1. Find Best Bandwidth\n"
             << "2. Display Graph\n"
             << "3. Perform DFS\n"
             << "4. Switch to Admin Menu\n"
             << "5. Sort Nodes\n"
             << "6. Perform BFS\n"
             << "7. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input\n";
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    auto [node1, node2] = graph.findBestBandwidth();
    if (node1 != -1) {
        cout << "Best bandwidth between nodes " << node1 << " and " << node2 
             << " with weight " << graph.adjacencyMatrix[node1][node2] << "\n";
    } else {
        cout << "No valid edges found\n";
    }
    break;
                }
                case 2:
                    graph.displayGraph();
                    break;
                case 3: {
                    int startNode;
                    cout << "Enter start node for DFS: ";
                    if (cin >> startNode) {
                        graph.DFS(startNode);
                    }
                    break;
                }
                case 4:
                    adminMenu(graph);
                    return;
                case 5:{
                    graph.SortNodes();
                    break;
                }
                case 6:{
                    int startNode;
                    cout << "Enter start node for BFS: ";
                    if (cin >> startNode) {
                        graph.BFS(startNode);
                    }
                    break;
                }
                case 7:
                cout<<"Exiting viewer menu\n";
                    return;
                default:
                    cout << "Invalid choice\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 7);
}

//main menu
int main() {
    try {
        cout << "Enter maximum number of nodes: ";
        int n;
        if (!(cin >> n)) {
            throw invalid_argument("Invalid input for number of nodes");
        }
        
        Graph graph(n);
        string role;
        
        do {
            cout << "Enter role (admin/viewer): ";
            cin >> role;
            
            if (role == "admin") {
                adminMenu(graph);
                break;
            } else if (role == "viewer") {
                viewerMenu(graph);
                break;
            } else {
                cout << "Invalid role. Please enter 'admin' or 'viewer'\n";
            }
        } while (true);
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;  //Error displyed after catching if occurs
    }
    
    return 0;
}




        
    
