#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include<vector>

using namespace std;

typedef long long ll;

int bin[10001];
int divi=131071;
int n;

ll isDivisible(){
    ll res=0;
    ll y=n-1;
    ll x=1;
    while(y>=0){
        if(bin[y]==1)
            res=(res+x)%divi;
        x=(x*2)%divi;
        --y;
    }
    return res%divi;
}

int main(){
    char c;
    while(scanf(" %c", &c)==1){
        n=0;
        while(c!='#'){
            bin[n]=(int) (c-48);
            ++n;
            scanf("%c", &c);
        }
        bin[n]=0;
        ++n;
        ll ret=isDivisible();
        if(ret) cout << "NO\n";
        else cout << "YES\n";
    }
}