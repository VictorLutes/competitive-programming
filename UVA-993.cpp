#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include<bitset>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int fatoresPrimos[8]={2,3,4,5,6,7,8,9};

vector<ll> primeFactor(ll n){
    vector<ll> fatores;
    ll ind=7;
    ll PF=fatoresPrimos[ind];
    while(ind>=0){
        while(n%PF==0){
            fatores.push_back(PF);
            n=n/PF;
        }
        PF=fatoresPrimos[--ind];
    }
    if(n!=1) fatores.clear();
    return fatores;
}

int main(){
    int m;
    ll n;
    cin >> m;
    for(int i=0; i<m; ++i){
        cin >> n;
        if(n==0) cout << 0 << endl;
        else if(n==1) cout << 1 << endl;
        else{
            vector<ll> lista=primeFactor(n);
            if(lista.empty()) cout << -1 << endl;
            else{
                for(int j=(int) lista.size()-1; j>=0; --j){
                    cout << lista[j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}