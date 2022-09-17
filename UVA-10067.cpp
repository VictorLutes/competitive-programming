#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

/*
Backtracking com graphos implícitos
*/

using namespace std;

#define MAX 10

typedef struct{
    int tab[4];
    int cont;
}ITEM;

int movimentos[8][4]={
    1, 0, 0, 0,
    -1, 0, 0, 0,
    0, 1, 0, 0,
    0, -1, 0, 0, 
    0, 0, 1, 0, 
    0, 0, -1, 0, 
    0, 0, 0, 1, 
    0, 0, 0, -1
};
int k;

bool visitados[10001];

int getPos(int tab[4]){
    return tab[0]+tab[1]*10+tab[2]*100+tab[3]*1000;
}

bool valido(int tab[4], int **invalidos){
    //cout << getPos(tab) << "\n";
    if(visitados[getPos(tab)]) return false;
    for(int i=0; i<k; ++i){
        if(tab[0]==invalidos[i][0] && tab[1]==invalidos[i][1] && tab[2]==invalidos[i][2] && tab[3]==invalidos[i][3]) return false;
    }
    return true;
}

int bfs(int tab[4], int target[4], int **invalidos, int cont){
    visitados[getPos(tab)]=true;
    queue<ITEM> q;
    ITEM i;
    i.tab[0]=tab[0];
    i.tab[1]=tab[1];
    i.tab[2]=tab[2];
    i.tab[3]=tab[3];
    i.cont=0;
    q.push(i);

    while(!q.empty()){
        ITEM t;
        t = q.front();
       
        q.pop();
        if(t.tab[0]==target[0] && t.tab[1]==target[1] && t.tab[2]==target[2] && t.tab[3]==target[3]){
            return t.cont;
        }
        for(int i=0; i<8; ++i){
            ITEM newT;

            newT.tab[0]=(t.tab[0]+movimentos[i][0])%10;
            if(newT.tab[0]<0) newT.tab[0]=9;
            newT.tab[1]=(t.tab[1]+movimentos[i][1])%10;
            if(newT.tab[1]<0) newT.tab[1]=9;
            newT.tab[2]=(t.tab[2]+movimentos[i][2])%10;
            if(newT.tab[2]<0) newT.tab[2]=9;
            newT.tab[3]=(t.tab[3]+movimentos[i][3])%10;
            if(newT.tab[3]<0) newT.tab[3]=9;
            newT.cont=t.cont+1;
            //cout << newT.tab[0] << " " << newT.tab[1] << " " << newT.tab[2] << " " << newT.tab[3] << "\n";
            if(valido(newT.tab, invalidos)){
                visitados[getPos(newT.tab)]=true;
                q.push(newT);
            }
        }
    }
    return -1;
}

int main(){
    int n, tab[4], target[4];

    cin >> n;    
    for(int i=0; i<n; ++i){
        memset(visitados, false, sizeof(visitados));
        
        cin >> tab[0] >> tab[1] >> tab[2] >> tab[3];
        cin >> target[0] >> target[1] >> target[2] >> target[3];

        cin >> k;
        int *invalidos[k];
        for(int j=0; j<k; ++j){
            invalidos[j]=new int[4];
            cin >> invalidos[j][0] >> invalidos[j][1] >> invalidos[j][2] >> invalidos[j][3];
        }
        int ret=bfs(tab, target, invalidos, 0);
        cout << ret << "\n"; 

        for(int j=0; j<k; ++j){
            delete[] invalidos[j];
        }
        fgetc(stdin);
    }

    
    
    return 0;
}