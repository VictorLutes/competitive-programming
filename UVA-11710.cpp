#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;


//Forma eficiente de criar lista de adjacencia:
typedef pair<int, int> ii; //par de <u, peso>
typedef vector<ii> vii; //vetor de pares
typedef vector<int> vi; //vetor de visitados

//lista de adjacencia é um vetor de vetor de pares
vector<vii> AdjList;
vector<pair<int, ii>> EdgeList;
//lista de arestas é um vetor de (peso, (u, v))
char nos[400][100];

int V;
int A;

int prim(int inicio){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaDePrioridade;
    int pesoPaiAteFilho[V];
    bool verticesNaArvore[V];
    for(int i=0; i<V; i++){
        verticesNaArvore[i]=false;
        pesoPaiAteFilho[i]=INT_MAX;
    }
    filaDePrioridade.emplace(0, inicio);
    
    while(!filaDePrioridade.empty()){
        pair<int, int> u=filaDePrioridade.top();//leio o topo da pq
        int vertice=u.second;//separo o vertice
        int peso=u.first;//separo o peso do vertice ate seu pai
        filaDePrioridade.pop();//tiro da pq esse elemento

        if(verticesNaArvore[vertice]==false){//se esse vertice ainda nao foi adcionado na arvore com um peso menos
            pesoPaiAteFilho[vertice]=peso;//guardo o peso desse vertice ate seu pai na arvore geradora minima
            verticesNaArvore[vertice]=true;//seto que esse vertice ja foi adicionado na arvore geradora minima

            //itero por todas suas arestas, adicionando o peso da aresta, vertice filho e vertice atual na pq se ele nao foi adicionado na arvore ainda
            for(int i=0; i<(int) AdjList[vertice].size(); ++i){
                int verticeFilho=AdjList[vertice][i].first;
                int pesoFilho=AdjList[vertice][i].second;
                if(verticesNaArvore[verticeFilho]==false){
                    //guardo na pq um elemento ordenado pelo peso, composto de (peso, vertice)
                    filaDePrioridade.emplace(pesoFilho, verticeFilho);
                }
                
            }
        }
    }
    

    int soma=0;
    for(int i=0; i<V; i++){
        if(pesoPaiAteFilho[i]==INT_MAX) return -1;
        soma+=pesoPaiAteFilho[i];
    }
    return soma;
}

int main(){
    int u, v, w, inicio;
    char  u1[100], v1[100], saida[100];
    
    while(true){
        cin >> V >> A;
        if(V==0) break;
        AdjList.resize(401);
        for(int i=0; i<V; ++i){
            cin >> nos[i];
        }
        for(int i=0; i<A; ++i){
            cin >> u1 >> v1 >> w;
            for(int j=0; j<V; ++j){
                if(strcmp(nos[j], u1)==0) u=j;
            }
            for(int j=0; j<V; ++j){
                if(strcmp(nos[j], v1)==0) v=j;
            }
            AdjList[u].push_back(make_pair(v, w));
            AdjList[v].push_back(make_pair(u, w));
        }
        
        cin >> saida;
        for(int j=0; j<V; ++j){
            if(strcmp(nos[j], saida)==0) inicio=j;
        }

        int val=prim(inicio);
        if(val==-1) printf("Impossible\n");
        else printf("%d\n", val);

        AdjList.clear();
    }
    return 0;
}