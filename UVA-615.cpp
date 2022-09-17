#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

#define VISITADO 1
#define NAO_VISITADO 0
#define INF INT_MAX
//Forma eficiente de criar lista de adjacencia:
typedef pair<int, int> ii; //par de <u, peso>
typedef vector<ii> vii; //vetor de pares
typedef vector<int> vi; //vetor de visitados

//lista de adjacencia é um vetor de vetor de pares
vector<vi> AdjList;
//lista de arestas é um vetor de (peso, (u, v))
vector<int> nos;
vector<int> notRaiz;

int V;
int A;
vi visitado;

int naoContado(int u){
    for(int i=0; i<(int) nos.size(); ++i){
        if(nos[i]==u) return i;
    }
    return -1;
}

int bfs(int u){
    queue<int> q;
    q.push(u);
    vi dist(nos.size(), INF);
    dist[u]=0;
    while(!q.empty()){
        int ul=q.front();
        q.pop();
        for(int i=0; i<(int) AdjList[ul].size(); ++i){
            int v=AdjList[ul][i];
            //se dist até v for infinito, atualiza a dist e poe na fila
            if(dist[v]==INF){
                dist[v]=dist[ul]+1;
                q.push(v);
            }
        }
    }
    for(int i=0; i<(int) nos.size(); ++i){
        if(dist[i]==INF) return 0;
    }
    return 1;
}

int isTree(){
    vector<int> edges(100);
    vector<int> raiz;
    fill(edges.begin(), edges.end(), 0);

    for(int i=0; i<(int) nos.size(); ++i){
        for(int j=0; j<(int) AdjList[i].size(); ++j){
            ++edges[AdjList[i][j]];
            if(edges[AdjList[i][j]]>1) return 0;
        }
        int ehraiz=1;
        for(int j=0; j<(int) notRaiz.size(); ++j){
            if(i==notRaiz[j]) ehraiz=0;
        }
        if(ehraiz==1) raiz.push_back(i);
    }
    if(raiz.size()!=1) return 0;

    return bfs(raiz[0]);
}

int main(){
    int u1=0, v1=0, u, v;
    
    int i=0;
    cin >> u1;
    cin >> v1;
    while(u1>-1 && v1>-1){
        ++i;
        AdjList.resize(100);
        while(u1!=-0 && v1!=0){
            u=naoContado(u1);
            if(u==-1){
                u=nos.size();
                nos.push_back(u1);
            }
            v=naoContado(v1);
            if(v==-1){
                v=nos.size();
                nos.push_back(v1);
            }
            AdjList[u].push_back(v);
            notRaiz.push_back(v);

            cin >> u1;
            cin >> v1;
        }
        int arvore=isTree();
        if(arvore || nos.empty()) cout << "Case " << i << " is a tree." << endl;
        else cout << "Case " << i << " is not a tree." << endl;
        
        notRaiz.clear();
        AdjList.clear();
        nos.clear();
        cin >> u1;
        cin >> v1;
    }
}