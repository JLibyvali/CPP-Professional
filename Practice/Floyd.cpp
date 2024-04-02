#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int N = 110;

int G[N][N];

void Floyd(int n){
	// Only be suitable for graph without negative loop, it's ok to use for negative weight.
	// suitbale for adjancy matrix.
	
	for(int k = 1 ;k<=n;k++){
		for(int i= 1; i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
}

int main(){
	
	int n,m;
	memset(G,0x3f,sizeof(G));
	for(int i=0; i<N;i++){
		G[i][i] = 0;
	}	// adjancy matrix initialize.
	
	cin>>n>>m;
	int u,v,w;
	while(m--){
		cin>>u>>v>>w;
		G[u][v] = G[v][u] = w;
	}
	
	Floyd(n);
	// After floyd, the adjancy matrix storaged minium distance from one node to another node.
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	return 0;
}