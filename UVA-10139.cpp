#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include<bitset>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

#define SIZE 46350
bitset<SIZE> MEMO;
vector<ll> fatoresPrimos;
int montarMemo(){
    MEMO.set();
    MEMO[0]=0;
    MEMO[1]=0;

    for(ll i=2; i<SIZE; ++i){
        if(MEMO[i]==1){//para cada primo elimina os seus multiplos
            for(ll j=i+i; j<SIZE; j+=i){
                MEMO[j]=0;
            }
            fatoresPrimos.push_back(i);
        }
    }
    return true;
}

int checkDiv(ll n, ll m){
    for(int i=0; i<(int) fatoresPrimos.size() && fatoresPrimos[i]*fatoresPrimos[i]<=m; ++i){
        if(m%fatoresPrimos[i]==0){
            ll fatoresEmM=0, fatoresEmN=0, tmpN=1;
            while(m%fatoresPrimos[i]==0){
                ++fatoresEmM;
                m=m/fatoresPrimos[i];
            }
            while(tmpN*fatoresPrimos[i]<=n && fatoresEmN<fatoresEmM){
                ++fatoresEmN;
                if(tmpN%fatoresPrimos[i]==0) fatoresEmN+=tmpN/fatoresPrimos[i];
                ++tmpN;
            }
            if(fatoresEmM>fatoresEmN) return 0;
            if(m==1) return 1;
        }
    }
    if(m==1 || n>=m) return 1;
    return 0;
}

int main(){
    montarMemo();
    ll n, m;
    while(scanf("%lld %lld ", &n, &m)==2){
        if(m==n || (n==0 && m==1)) cout << m << " divides " << n << "!\n";
        else if(n==0) cout << m << " does not divide " << n << "!\n";
        else{
            int divides=checkDiv(n, m);
            if(divides) cout << m << " divides " << n << "!\n";
            else cout << m << " does not divide " << n << "!\n";
        }
    }
    return 0;
}