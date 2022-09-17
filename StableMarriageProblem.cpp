/*Casamento Estavel, Victor Lutes 11795512

    homens solteiros, mulheres solteiras
    while tem homem solteiro e que nao propos para todas mulheres{
        m seleciona mulher w 1a da preferencia para propose
        se w esta solteira,
            engage(m,w)
        else if w prefere m a m1, o ja engaged,
            engage(m, w)
            m1 fica solteiro
    }
    return conjunto s;
complexidade é n^2
*/


#include <iostream>
#include <list>

using namespace std;

bool prefereMais(int n, int *w, int m, int m1){
    for(int i=0; i<n; ++i){
        if(w[i]==m) return true;
        else if(w[i]==m1) return false;
    }
    return false;
}

void casamentoEstavel(int n, int **w, int **m){
    int casamentosW[n], casamentosM[n];
    list<int> homensSolteiros;
    for(int i=0; i<n; i++){
        homensSolteiros.push_back(i);
        casamentosW[i]=-1;
        casamentosM[i]=-1;
    }
    int homem;
    while (!homensSolteiros.empty()){
        homem=homensSolteiros.front();
        for(int i=0; i<n; ++i){
            int preferencia=m[homem][i];
            if(casamentosW[preferencia]==-1){
                casamentosW[preferencia]=homem;
                casamentosM[homem]=preferencia;
                homensSolteiros.pop_front();
                break;
            }
            else if(prefereMais(n, w[preferencia], homem, casamentosW[preferencia])){
                int largado=casamentosW[preferencia];
                casamentosW[preferencia]=homem;
                casamentosM[homem]=preferencia;
                homensSolteiros.pop_front();
                casamentosM[largado]=-1;
                homensSolteiros.push_back(largado);
                break;
            }
        }
    }
    for(int i=0; i<n; ++i){
        cout << i+1 << " " << casamentosM[i]+1 << "\n";
    }
}

int main(){
    int t, n;
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n;
        int *w[n], *m[n];
        for(int j=0; j<n; ++j){
            w[j]=new int[n];
            scanf("%*d ");
            for(int k=0; k<n; ++k){
                cin >> w[j][k];
                --w[j][k];
            }
        }
        for(int j=0; j<n; ++j){
            m[j]=new int[n];
            scanf("%*d ");
            for(int k=0; k<n; ++k){
                cin >> m[j][k];
                --m[j][k];
            }
        }

        casamentoEstavel(n, w, m);

        for(int j=0; j<n; ++j){
            delete[] w[j];
            delete[] m[j];
        }
    }
}