#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int M = 1e5;


//####################IMPORTATN suitbale ranges
//Dijkstra heap version, better for adjancy list.


struct Edge {
    int v;
    int w;
    int next;

    Edge() {}
    Edge(int _v, int _w, int _next) : v(_v), w(_w), next(_next) {}
};

Edge e[M * 2];
int HEAD[N], size;

void init() {
    memset(HEAD, -1, sizeof(HEAD));
    size = 0;
}

void insertD(int u, int v, int w) {
    e[size] = Edge(v, w, HEAD[u]);	// IMPORTANT 'e[size]' : create new node
    HEAD[u] = size++;
}

void insertUD(int u, int v, int w) {
    insertD(u, v, w);
    insertD(v, u, w);
}

// Heap Dijkstra
using PII = pair<int, int>; // stroage node information, first: edge weight, second: adjoinging node.
priority_queue<PII, vector<PII>, greater<PII>> q;

int dis[N];
bool vis[N];

void Dijkstra(int src) {
    // initial
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));

    dis[src] = 0;
    q.push({0, src});
    
    while (!q.empty()) {
        PII t = q.top();
        q.pop();

        if (vis[t.second]) {
            continue;
        }

        vis[t.second] = true;
        for (int i = HEAD[t.second]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;

            if (dis[v] > dis[t.second] + w) {
            	
                dis[v] = dis[t.second] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    init();
    int n, m;
    int u, v, w;

    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        insertUD(u, v, w);
    }

    Dijkstra(1);
   
   	for(int i=1; i<=n;i++){
   		cout<<dis[i]<<" ";
	   }

    return 0;
}
