#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
vetor D ordenado
vetor C ordenado
por elementos no C, se c>=d tira c e d e avanca e soma c no numero de moedas
se d>c remove c e vai para o proximo
se sobra cavaleiro vence e printa moedas
senao perde
*/
int main(){
    int n, m, moedas=0, val;
    
    
    cin >> n >> m;
    while(n!=0){
        priority_queue<int, vector<int>, greater<int>> cav;
        priority_queue<int, vector<int>, greater<int>> drag;
        moedas=0;
        for(int i=0; i<n; ++i){
            cin >> val;
            drag.emplace(val);
        }
        for(int i=0; i<m; ++i){
            cin >> val;
            cav.emplace(val);
        }

        while(!drag.empty() && !cav.empty()){
            if(cav.top()>=drag.top()){
                moedas+=cav.top();
                cav.pop();
                drag.pop();
            }
            else{
                cav.pop();
            }
        }
        if(!drag.empty()){
            cout <<"Loowater is doomed!" << endl;
        }
        else{
            cout << moedas << endl;
        }
        
        cin >> n >> m;
    }
    return 0;
}