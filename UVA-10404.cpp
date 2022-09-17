#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

#define MAX 10

using namespace std;


int n;
int m;
int moedas[MAX];


void printVet(int *v, int tam){
	for (int i = 0; i <= tam; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

int solve (int v){
	if (v == 0)   // nao tem mais troco. retorna 0
		return 0;
	if (v < 0)  // nao tem sentido trocar por uma moeda maior. descarta.
		return INT_MAX-1;
	// para todas as moedas, encontre a que retorna a qtd minima para o valor v
	int minimo = INT_MAX;
	for (int i = 0; i < m; ++i)
		minimo = min (minimo, solve(v-moedas[i])+1);
		
	return minimo;
}


int solvePD (int v, int  *MEMO){
	if (v == 0)   // nao tem mais troco. retorna 0
		return 0;
	if (v < 0)  // nao tem sentido trocar por uma moeda maior. descarta.
		return INT_MAX-1;
	// verifica se já existe o resultado para este valor de v !!!!
	if (MEMO[v] != -1)
		return MEMO[v];

	// para todas as moedas, encontre a que retorna a qtd minima para o valor v
	MEMO[v] = INT_MAX;
	for (int i = 0; i < m; ++i) // ara todas as moedas
		MEMO[v] = min(MEMO[v], solvePD(v-moedas[i], MEMO)+1); // aplica a memoizacao !!
	
	return MEMO[v];
}

int PD (int *MEMO){
	// PARA todo j de 1 ate V (inclusive!)
	for (int j = 1; j <=n; ++j){
		// para todas as moedas, encontre a que retorna a qtd minima para o valor v
		MEMO[j] = INT_MAX;
		for (int i = 0; i < m; ++i) // para todas as moedas
			if (j>=moedas[i])
				MEMO[j] = min (MEMO[j], (MEMO[j-moedas[i]]+1)%2); // aplica a memoizacao !!
        //cout << j << " " << MEMO[j] << endl;
	}

	return MEMO[n];
}


int main(int argc, char const *argv[]){
    while(scanf("%d", &n)!=EOF){
        cin >> m;
        for(int i=0; i<m; ++i){
            cin >> moedas[i];
        }
        int MEMO[n+1]; 
        MEMO[0]=-1;
        int rounds=PD(MEMO);
        if(rounds%2==0) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }


	return 0;
}

