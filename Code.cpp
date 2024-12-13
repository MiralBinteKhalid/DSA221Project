#include<iostream>
#include<fstream>
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



