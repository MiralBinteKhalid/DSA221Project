
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<stack>
using namepspace std;
const int MAX_NODES=1000;
const int MAX_EDGES=1000;
//making edges in linkedlist 
struct egde{
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
struct node{
int id;
string info;
egde* egdelist;
node()
{
egdelist=nullptr;
}
};
class networkgraph{
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


}


