#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, bool> mapa;

//simula uma vez e salva todos os valors
//em cada query ve se o valor ja foi gerado
int myMin(vector<int> v){
    int mini=v[0];
    for(int i=1; i<(int) v.size(); ++i){
        if(v[i]<mini){
            mini=v[i];
        }
    }
    return mini;
}
int myMax(vector<int> v){
    int maxi=v[0];
    for(int i=1; i<(int) v.size(); ++i){
        if(v[i]>maxi){
            maxi=v[i];
        }
    }
    return maxi;
}

void divAndSum(vector<int> v){
    if(v.empty()){
        return;
    }
    if(v.size()==1){
        mapa[v[0]]=true;
        return;
    }
    /*checar se é tudo igual*/
    int sumV=v[0];
    bool tudoIgual=true;
    for(int i=1; i<(int) v.size(); ++i){
        sumV+=v[i];
        if(v[i]!=v[0]) tudoIgual=false;
    }
    mapa[sumV]=true;
    if(tudoIgual){
        return;
    }
    
    int mid=(myMax(v)+myMin(v))/2;
    vector<int> menor;
    vector<int> maior;
    for(int i=0; i<(int) v.size(); ++i){
        if(v[i]<=mid) menor.push_back(v[i]);
        else maior.push_back(v[i]);
    }
    if(!maior.empty())
        divAndSum(maior);
    if(!menor.empty())
        divAndSum(menor);
}

int main(int argc, char const *argv[]){
	int t;
    cin >> t;
    
    for(int j=0; j<t; ++j){
        int n, q, s, val;
        cin >> n >> q;
        vector<int> v;
        for(int i=0; i<n; ++i){
            cin >> val;
            v.push_back(val);
        }
        //executa uma vez a simulacao e guarda todos os resultados
        mapa.clear();
        divAndSum(v);
        for(int i=0; i<q; ++i){
            cin >> s;
            if(mapa[s]==true) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

	return 0;
}