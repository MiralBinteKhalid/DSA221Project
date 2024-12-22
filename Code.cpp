#include<iostream>
#inlude<string>
#include<limits>
#include <stdexcept>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <utility> // For std::pair
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
    





};




        
    
