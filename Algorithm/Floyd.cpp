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

//#include<bits/stdc++.h>
//
//using namespace std;
//using ll = long long ;
//
//ll G[410][410];
//ll  N,M,Q,u,v,w;
//
//
//int main() {
//    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
//    memset(G,0x3f,sizeof(G));
//
//    cin>>N>>M>>Q;
//
//    for(int i=1;i<=N;i++){
//        G[i][i] = 0;
//    }
//    for(int i=1;i<=M;i++){
//        cin>>u>>v>>w;
//        G[u][v] = G[v][u] = min(G[u][v],w); // prevent duplicate edges
//    }
//
//    // floyd
//    for(int k=1;k<=N;k++){
//        for(int i=1;i<=N;i++){
//            for(int j=1;j<=N;j++){
//                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
//            }
//        }
//    }
//    int s, t;
//    for(int i=0;i<Q;i++){
//        cin>>s>>t;
//        ll ans = (G[s][t] == 0x3f3f3f3f3f3f3f3f) ? -1 : G[s][t];
//        cout<<ans<<endl;
//    }
//
//    return 0;
//}
