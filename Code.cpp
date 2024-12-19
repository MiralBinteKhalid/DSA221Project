#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<fstream>
using namepspace std;
const int MAX_NODES=1000;
const int MAX_EDGES=1000;
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
          
        
    }}
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
}

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

        
    
