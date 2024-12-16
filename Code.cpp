#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<stack>
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

public:
networkgraph(){
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
 if (nodecount>=MAX_NODE){
cout<<"node limit reached"<<endl;
  return ;
 }
 nodes[MAX_NODES].id=id;
 nodes[nodeount].info=info;
 nodecount++;
 
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
   void saveGraphToFile(const string& filename) {
    
   }

int main(){



 return 0;
}

        
    
