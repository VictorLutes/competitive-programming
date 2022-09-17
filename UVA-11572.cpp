#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <set>
#include <map>


using namespace std;

int main(){
    int m, n, max, sum;
    
    cin >> m;
    for(int i=0; i<m; ++i){
        cin >> n;
        int val[n];
        set<int> s;
        map<int, int> mapa;
        max=0;
        sum=0;
        for(int j=0; j<n; ++j){
            cin >> val[j];
        }
        for(int j=0; j<n; ++j){
            if(mapa.find(val[j]) != mapa.end()){
                if(sum > max) max=sum;
                sum=0;
                j=mapa[val[j]];
                mapa.clear();
                mapa.erase(val[j]);
            }
            else{
                ++sum;
                if(sum > max) max=sum;
                mapa.insert(make_pair(val[j], j));
            }
        }
        cout << max << endl;
    }
    return 0;
}
