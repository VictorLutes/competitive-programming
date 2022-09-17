#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define VISITADO 1
#define NAO_VISITADO 0
#define INF INT_MAX
#define MAX 101

//Forma eficiente de criar lista de adjacencia:
typedef pair<int, int> ii; //par de <u, peso>
typedef vector<ii> vii; //vetor de pares
typedef vector<int> vi; //vetor de visitados

int M[MAX][MAX];
int rgrafo[MAX][MAX];
int pai[MAX];

int V;
int A;
int s;
int t;

bool bfs(int start, int end){
    queue<int> q;
    q.push(start);
    pai[start]=-1;

    int visitado[V];
    memset(visitado, 0, sizeof(visitado));
    visitado[start]=1;
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<V; ++i){
            if(rgrafo[u][i]>0 && visitado[i]==0){
                pai[i]=u;
                visitado[i]=1;
                q.push(i);
            }
        }
    }
    return visitado[end];
}


int ff(){
    int u;


	// o grafo residual é o inicialmente o grafo original...
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			rgrafo[i][j] = M[i][j];


	int maxFlow = 0;

	while (bfs(s,t)){     // equanto tem augmented path !!!!!
		int gargalo = 100000;
		// calcular o gargalo....
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			gargalo = min(gargalo, rgrafo[u][v]);
		}

		// Atualiza o forward e backward edges...
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			rgrafo[u][v] -= gargalo;  // FORWARD EDGE
			//rgrafo[v][u] += gargalo;  // BACKWARD EDGE !!!
		}
		maxFlow += gargalo;
	}

	return maxFlow;
}

int main(){
    int u, v, w;
    cin >> V;
    for(int i=1; V!=0; ++i){
        memset(M, 0, sizeof(M));
        memset(rgrafo, 0, sizeof(rgrafo));
        cin >> s >> t >> A;
        s=s-1;
        t=t-1;
        for(int j=0; j<A; ++j){
            cin >> u >> v >> w;
            M[u-1][v-1]+=w;
            M[v-1][u-1]+=w;
        }
        cout << "Network " << i << "\nThe bandwidth is ";
        int maxFlow=ff();
        cout << maxFlow << ".\n\n";
        cin >> V;
    }
}