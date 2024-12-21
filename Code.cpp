#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<fstream>
using namepspace std;
const int MAX_NODES=1000;
const int MAX_EDGES=1000;
struct AVLNode {
    int data;
    bool exists;
    AVLNode *left, *right;
    int height;
    
    AVLNode(int d) : data(d), exists(true), left(nullptr), right(nullptr), height(1) {}
};
void optimizeBandwidth(int totalBandwidth, vector<Task> &tasks) {
    // Sort tasks using the comparator
    sort(tasks.begin(), tasks.end(), compareTasks);

struct Task {
    string name;
    int bandwidth;  // Bandwidth required
    int priority;   // Higher number means higher priority
};
bool compareTasks(const Task &a, const Task &b) {
    if (a.bandwidth == b.bandwidth) {
        return a.priority > b.priority;
    }
    return a.bandwidth < b.bandwidth;
}

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
bool isEmpty() {
        return front == nullptr;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }


};


//making edges in linkedlist 
struct egde
{
int source ;
int destination;
int bandwidth;
edge* next;
egde(int sour,int dest,int btw)
{
source=sour;
destination=dest;
bandwidth=btw;
next=nullptr;
}
};
vector<Request> requests(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter bandwidth and priority for request " << i + 1 << ": ";
        cin >> requests[i].bandwidth >> requests[i].priority;
        requests[i].id = i + 1;
    }

void allocate_bandwidth(vector<Request>& requests, int total_bandwidth) {
    priority_queue<Request> pq;

    // Push all requests into the priority queue
    for (const auto& req : requests) {
        pq.push(req);
    }
     cout << "Allocating bandwidth:\n";
    while (!pq.empty() && total_bandwidth > 0) {
        Request top = pq.top();
        pq.pop();

        if (top.bandwidth <= total_bandwidth) {
            cout << "Request " << top.id << " allocated " << top.bandwidth << " units.\n";
            total_bandwidth -= top.bandwidth;
        } else {
            cout << "Request " << top.id << " partially allocated " << total_bandwidth << " units.\n";
            total_bandwidth = 0;
        }
    }

    if (total_bandwidth > 0) {
        cout << "Remaining bandwidth: " << total_bandwidth << " units\n";
    } else {
        cout << "All bandwidth allocated!\n";
    }
}

struct node
{
int id;
string info;
egde* egdelist;
node()
{
egdelist=nullptr;
}
};
class networkgraph
{
private:
node nodes[MAX_NODES];
int nodecount;
bool visited[MAX_NODES];
int path[MAX_NODES];
int pathlength;
int **adjacencymatrix;

public:
networkgraph(){
 adjacencymatrix=new int*[MAX_NODES];
 for(int i=0;i<MAX_NODES;i++){
adjacencymatrix[i]=new int[MAX_NODES];
 }
nodecount=0;
pathlength=0;
for(int i=0;i<MAX_NODES;i++)
{
visited[i]=false;
nodes[i].edgelist=nullptr;
}
}

void addnode(int id,const string &info)
{
 if (nodecount>=MAX_NODE || nodecount<0){
throw invalid_argument("Node ID out of range");
  return ;
 }
 nodes[MAX_NODES].id=id;
 nodes[nodeount].info=info;
 nodecount++;
 cout<<"Node ID successfully added!";
}
void addegde(int sour,int dest,int bandwidth)
{
 if(sour>=nodecount||dest>=nodecount)
 {
//exception handling
throw invalid_argument("Invalid Node");
  return;
 }
 egde*newegde=new egde(sour,dest,bandwith);
 newegde->next=nodes[sour].edgelist=newegde;
}
int calculatenodetraffic(int nodeid)
{
int totaltraffic=0;
egde*current=nodes[nodeid].egdelist;
while(current!=nullptr)
{
totaltraffic+=current->bandwidth;
current=current->next;
}
return totaltraffic;
}
 struct SortedEdge {
        int source;
        int destination;
        int bandwidth;
    };

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // Size of the first half
    int n2 = right - mid;       // Size of the second half

    int leftArray[n1], rightArray[n2]; // Temporary arrays for the two halves

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the two halves back into the original array in sorted order
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArray, if any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArray, if any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

//sorting the nodes
void merge(vector<SortedEdge>& edges, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
 vector<SortedEdge> L(n1), R(n2);
 for (int i = 0; i < n1; i++)
            L[i] = edges[left + i];
 for (int i = 0; i < n2; i++)
            R[i] = edges[mid + 1 + i];
 int i = 0, j = 0, k = left;
 while (i < n1 && j < n2) {
 if (L[i].bandwidth <= R[j].bandwidth) {
                edges[k] = L[i];
                i++;
            } else {
                edges[k] = R[j];
                j++;
            }
            k++;
        }
  while (i < n1) {
            edges[k] = L[i];
            i++;
            k++;
        }
 while (j < n2) {
            edges[k] = R[j];
            j++;
            k++;
 }
    }
}
void mergeSort(vector<SortedEdge>& edges, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(edges, left, mid);
            mergeSort(edges, mid + 1, right);
            merge(edges, left, mid, right);
          }
}

    

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calculate the midpoint

        // Recursively divide and sort both halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}


 void sortEdgesByBandwidth() {
        vector<SortedEdge> edges;
        for (int i = 0; i < nodecount; i++) {
            edge* current = nodes[i].edgelist;
            while (current != nullptr) {
                edges.push_back({current->source, current->destination, current->bandwidth});
                current = current->next;
            }
        }
        mergeSort(edges, 0, edges.size() - 1);
        
        cout << "Edges sorted by bandwidth:\n";
        for (const auto& e : edges) {
            cout << "Source: " << e.source << ", Destination: " << e.destination << ", Bandwidth: " << e.bandwidth << endl;
        }
       cout << "Edges sorted by bandwidth:\n";
        for (const auto& e : edges) {
            cout << "Source: " << e.source << ", Destination: " << e.destination << ", Bandwidth: " << e.bandwidth << endl;
        }
       
    }

   // File handling: Save and load graph structure
    void saveGraphToFile(const string& filename) {
       ofstream file(filename);
     if (!file.is_open()) {
       cerr << "Error opening file!" << endl;
            return;
        }
      file << nodecount << endl;
        for (int i = 0; i < nodecount; i++) {
          file << nodes[i].id << " " << nodes[i].info << endl;
            edge* current = nodes[i].edgelist;
            while (current != nullptr) {
                file << current->source << " " << current->destination << " " << current->bandwidth << endl;
             current = current->next;
            }
        }
        file.close();
        cout << "Graph saved to file successfully!" << endl;
    }

 void loadGraphFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
  file >> nodecount;
        for (int i = 0; i < nodecount; i++) {
            int id;
            string info;
            file >> id >> info;
            nodes[i].id = id;
            nodes[i].info = info;
            nodes[i].edgelist = nullptr;
        }

   int source, destination, bandwidth;
        while (file >> source >> destination >> bandwidth) {
            edge* newEdge = new edge(source, destination, bandwidth);
            newEdge->next = nodes[source].edgelist;
            nodes[source].edgelist = newEdge;
        }
    file.close();
        cout << "Graph loaded from file successfully!" << endl;
        
    }


void exportToDOT(const string& filename) {
        ofstream file(filename);
       if (!file.is_open()) {
         cerr << "Error opening file!" << endl;
         return;
        }

        file << "digraph Graph {\n";
        for (int i = 0; i < nodecount; i++) {
         edge* current = nodes[i].edgelist;
         while (current != nullptr) {
           file << "  " << current->source << " -> " << current->destination
            << " [label=\"" << current->bandwidth << "\"];\n";
            current = current->next;
             }
        }
        file << "}";
         file.close();
            cout << "Graph exported to DOT file successfully!" << endl;        
    }
// Search for nodes based on ID or info
    void searchNode(int nodeId, const string& nodeInfo = "") {
        bool found = false;
        for (int i = 0; i < nodecount; i++) {
          if (nodes[i].id == nodeId || (!nodeInfo.empty() && nodes[i].info.find(nodeInfo) != string::npos)) {
                cout << "Node found: ID = " << nodes[i].id << ", Info = " << nodes[i].info << endl;
           found = true;
                break;
             }
        }
        if (!found) {
            cout << "Node not found." << endl;
        }
           
    }
// Filter edges based on bandwidth threshold
    void filterEdgesByBandwidth(int threshold) {
        cout << "Edges with bandwidth greater than " << threshold << ":\n";
        for (int i = 0; i < nodecount; i++) {
            edge* current = nodes[i].edgelist;
             while (current != nullptr) {
              if (current->bandwidth > threshold) {
              cout << "Source: " << current->source << ", Destination: " << current->destination
                           << ", Bandwidth: " << current->bandwidth << endl;
                }
                current = current->next;
                  }
        }
             
void printPath() {
        if(pathLength == 0) {
        cout << "No path exists\n";
            return;
        }
 cout << "Path found: ";
        for(int i = 0; i < pathLength; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
       
//adding weights to edges
void updateEdgeWeights() {
        // logic to update edge weights randomly
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, 100); // Adjust range as needed
        for (int i = 0; i < numNodes; ++i) {
            for (int j = i + 1; j < numNodes; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    adjacencyMatrix[i][j] = distrib(gen);
                    adjacencyMatrix[j][i] = adjacencyMatrix[i][j];
                }
            }
        }
}
int findHighestWeightEdgeInCluster(const vector<int>& cluster) {
        int maxWeight = 0;
        for (int i = 0; i < cluster.size(); ++i) {
            for (int j = i + 1; j < cluster.size(); ++j) {
                int weight = adjacencyMatrix[cluster[i]][cluster[j]];
                maxWeight = max(maxWeight, weight);
            }
        }
        return maxWeight;
    }
//getting min node value for delete function
Location* getMinValueNode(Location* node) {
        Location* current = node;
        while (current->left)
            current = current->left;
        return current;
    }


    }

DFSdisplay(int startNode,bool visited[]){
 visited[node]=true;
 cout<<node<<" ";

 for(int i=0;i<MAX_NODES;i++){
if(adjacencymatrix[node][i] && !visited[i]){
dfsdisplay(i,visited);
}
 }

}

void dfs(int startNode){
if(startNode<0 || startNode>=numNodes){
throw invalid_argument("Start Node does not exist.")
}
 bool*visited=new bool[numNodes];
 for(int i=0;i<numNodes;++i){
  visited[i]=false;
 }
 
 cout<<"DFS starting from Node "<<startNode<<":";
 DFSdisplay(startNode,visited)
 cout<<endl;
}

//admin menu
void adminMenu(networkgraph &graph){
int choice;
do{
 cout<<"Admin menu:\n"
  <<"1.Add node\n"
  <<"2.Delete node\n"
  <<"3.Switch to viewer menu\n"
  <<"4.Exit\n"
  <<"5.sort nodes\n"
  <<"Enter choice:\n";
 if(!(cin>>choice)){
  cin.clear();
  cout<<"Invalid input!\n";
  continue;
 }
     switch (choice) {
            case 1: {
                int u, v, w;
                cout << "Enter nodes (u, v) and weight: ";
                cin >> u >> v >> w;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Invalid input! Please enter valid integers." << endl;
                    continue;
                }
                graph.addEdge(u, v, w);
                break;
            }
            case 2:
                graph.updateEdgeWeights();
                break;
         
            case 3:
                graph.addNode();
                break;
            case 4:
                graph.displayGraph();
                break;
            case 5:
                cout << "Exiting Admin Menu..." << endl;
                break;
            default:
                cerr << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);
}
            default:
                cerr << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);
}
}

//viewer menu
 void viewer menu(networkgraph &graph){
int choice;
 do{
cout<<"viewer menu\n"
 <<"1.Find Best bandwidth\n"
 <<"2.display graph\n"
 <<"3.Perform dfs\n"
 <<"4.Switch to admin menu\n"
 <<"5.Sort Nodes\n"
 <<"6.Exit\n
 <<"Enter choice:\n";
 }
  if(!(cin>>choice)){
  cin.clear();
 }
}


int main(){



 return 0;
}

        
    
