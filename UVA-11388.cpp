#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include<vector>

using namespace std;

typedef long long ll;


int n;
int G;
int L;

ll mdc(ll x, ll y){
    if(y==0) return x;
    return mdc(y, x%y);
}

ll mmc(ll a, ll b){
    return a*b/mdc(a, b);
}



int main(){
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> G >> L;
        int found=1;
        for(int a=G; a<=L && found; ++a){
            if((G*L)%a==0){
                int b=G*L/a;
                if(mdc(a, b)==G && mmc(a, b)==L){
                    cout << a << " " << b << endl;
                    found=0;
                }
            }
        }
        if(found) cout << -1 << endl;
    }
}