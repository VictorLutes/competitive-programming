#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

bool canPlace(int posx, int posy, int **tabuleiro){
    for(int i=0; i<8; ++i){
        if(tabuleiro[posx][i]==-1 || tabuleiro[i][posy]==-1) return false;
    }
    for(int i=(posx*8+posy)%9, j=0; i<64 && j<8-(posx*8+posy)%9; i+=9, ++j){
        if(tabuleiro[i/8][i%8]==-1) return false;
    }
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            if(posx+posy==i+j && tabuleiro[i][j]==-1) return false;
            if(posx-posy==i-j && tabuleiro[i][j]==-1) return false;
        }
    }
    return true;
}

void permutacao(int *max, int nroRainha, int **tabuleiro, int soma){
    if(nroRainha==8){
        if(soma>*max) *max=soma;
    }
    else{
        for(int i=0; i<8; ++i){
            if(tabuleiro[i][nroRainha]!=-1 && canPlace(i, nroRainha, tabuleiro)){
                int tmp=tabuleiro[i][nroRainha];
                soma+=tmp;
                tabuleiro[i][nroRainha]=-1;
                permutacao(max, nroRainha+1, tabuleiro, soma);
                tabuleiro[i][nroRainha]=tmp;
                soma-=tmp;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int k, max=0;
    int *matriz[8];
    cin >> k;
    for(int i=0; i<k; ++i){
        for(int j=0; j<8; ++j){
            matriz[j]=new int[8];
            for(int l=0; l<8; ++l){
                cin >> matriz[j][l];
            }
        }
        permutacao(&max, 0, matriz, 0);
        cout << setw(5);
        cout << max << endl;
        for(int j=0; j<8; ++j){
            delete[] matriz[j];
        }
        max=0;
    }
    if(k==1) cout << endl;
}