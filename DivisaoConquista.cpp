#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int max3(int a, int b, int c){
    if(a>b){
       if(a>c) return a;
       return c; 
    }
    if(c>b) return c;
    return b;
}

int rec(int *vet, set<pair<int, int>> &s, int i, int j){
    if(i>j || s.empty()) return 0;
    auto it=s.begin();
    pair<int, int> min=*it;
    s.erase(min);
    if(i==j) return min.first;
    int mid=min.second;
    int qtd=min.first*(j-i+1);
    if(s.empty()) return qtd;
    //cout << i << " " << j << "\t"<< min.first << " " << min.second << endl;
    //remove o menor e passa por referencia pra um lado
    //recria so o menor lado
    set<pair<int, int>> c1;
    pair<int, int> a;
    for(int k=i; k<mid; ++k){
        a=make_pair(vet[k], k);
        c1.insert(a);
        s.erase(a);
    }

    int qtdinf=0;
    if(i<=mid-1){
        qtdinf=rec(vet, c1, i, mid-1);
    }
    int qtdsup=0;
    if(mid+1<=j){
        qtdsup=rec(vet, s, mid+1, j);
    }
    return max3(qtdinf, qtdsup, qtd);
}


int main(){
    int n;
    cin >> n;
    int vet[n];
    set <pair<int, int>> s;
    /*
    achar o maior/menor
    remover um elemento
    adicionar um elemento
    O(logn)
    tamanho do set O(1)
    s.insert(3);
    auto it=s.begin();
    int val=*it;//val eh o menor valor
    s.erase(3);
    s.size();
    */
    for(int i=0; i<n; ++i){
        cin >> vet[i];
        s.insert(make_pair(vet[i], i));
    }
    cout << rec(vet, s, 0, n-1) << endl;    

    return 0;
}