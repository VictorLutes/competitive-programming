#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpfnc(pair<int, string> a, pair<int, string> b){
    if(a.first!=b.first) return a.first>b.first;
    else return a.second.compare(b.second)<0;
}

int main(){
    string proj, aluno;

    getline(cin, proj);
    while(proj!="0"){
        vector<pair<int, string>> vetorProjetos;
        map<string, set<int>> mapaAlunosToProj;
        int counter=0;
        while(proj!="1"){
            vetorProjetos.push_back(make_pair(0, proj));
            getline(cin, aluno);
            while(aluno[0]>96){
                mapaAlunosToProj[aluno].insert(counter);
                getline(cin, aluno);
            }
            proj=aluno;
            counter++;
        }
        for(auto it=mapaAlunosToProj.begin(); it!=mapaAlunosToProj.end(); it++){
            if((*it).second.size()<2){
                int posProj=(*(*it).second.begin());
                vetorProjetos[posProj].first++;
            }
        }
        sort(vetorProjetos.begin(), vetorProjetos.end(), cmpfnc);
        for(int i=0; i<(int) vetorProjetos.size(); ++i){
            cout << vetorProjetos[i].second << " " << vetorProjetos[i].first << endl;
        }
        getline(cin, proj);
    }
    
    return 0;
}
