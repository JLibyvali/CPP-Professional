#include <iostream>

using namespace std;

// use the linked list
// IMPORTANT:
// this struct to express linked list is called "chain forward star", don't use 'vector' which const num was too big.


// using the adjacency list to describe graph
// edge is the num of every node's linked-list edges
const int N = 1001;
const int M = 10001;


struct edge {
	int v;	//	edge's destination
	int w;	// edge's weight
	int next;	// point to next edge serial number , '-1' means end .

	edge() {}

	edge(int _v,int _w,int _next ) {
		v = _v;
		w = _w;
		next = _next;
	}

} e[ M*2 ];	//every edge, zero-initialized.

// 'head' index and its value consist of one pointer, usually point to the FIRST node in linked list.
int head[N];	// use '-1' as end flag. 'head[i]' means: the i-th node's adjoining  node  and edge weight, index was node's order,

// the thought:
// 'size' is also one count variable, only in func "insertX()' will update its value,
// it always point to one new and didn't used node, also one new node.

int size;	// total graph edge numbers.

void init() {
	memset(head,-1,sizeof(head));	// no node has edges, must initial '-1'
	size = 0;
}
void insertD(int u, int v,int w) {
// It's equal with the linked-list node insert at 'HEAD'.

	e[size] = edge(v,w,head[u]);	// 'head[i]' point to first node in linked-list, it expressed the 'insert()' that always inserting in first node.
	// first assign the 'size' to head[u], second '++'.
	head[u] = size++;	// "struct edge" initialize one, in that linked list , the edges num upper.
	
}

void insertUD(int u,int v,int w) {
	insertD(u,v,w);
	insertD(v,u,w);
}

int n,m;


int dis[N];	// Dijkstra's src node to every node's destinction
bool vis[N];	// ndoe has marked or not

void Dijkstra(int src) {

	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));	// by bytes order to write, every bytes maxnum with +- bit : 0x7f.
	// we can use the '0x3f' to express giantic.


	dis[src] = 0;	// first node to itself distance: 0

	for(int i=0; i<n; i++) {

		int mind = 1e10, minj = -1;

		for(int j=1; j<=n; j++) {	// node index start from '1'

			if(!vis[j]&& dis[j]<mind) {	// find one node that has not been marked , and the distance is minium from current node.
				minj = j;
				mind = dis[j];
			}
		}

		if(minj == -1) return;	// if still no node satified, the graph isn't connected graph.

		vis[minj] = true;	// mark the node that we confirmed.

		for(int j=head[minj]; ~j; j = e[j].next) {	// traverse the "chain forward star",  also the adjancy list. 
			// ~j: also and only means j != -1;
			// When j==1, also j==0xffffffffffffffff, so ~j == 0==false;

			int v = e[j].v;
			int w = e[j].w;

			if(!vis[v] && (dis[v] > dis[minj] + w) ) {	// if it's not marked, and
				// the dis(current node to v) bigger than the 'minj' nodes distance plus the edge-weight.
				dis[v] = dis[minj] + w;	// update dis[v]
			}

		}
	}


}
int  main() {

	// but use this way, the 'vector' const-num was too big, so usually use linked-list .
	
	//###########################################IMPORTANT##################################################
	// This is Standard version Dijkstra, it's suitable for graph without negative weight,
	// When the graph is huge, we can consider using the Heap-Dijkstra
	
	init();

	cin>>n>>m;
	while(m--) {

		int u,v,w;
		cin>>u>>v>>w;
		insertUD(u,v,w);
	}

	Dijkstra(1);	// src also the 'u'

	return 0;
}
