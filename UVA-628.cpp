#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void permutacao(string regras, int size, int pos, string *dic, int nroDic, string palavra){
    if(pos==size){
        palavra.append("\0");
        cout << palavra << "\n";
        return;
    }
    else{
        if(regras[pos]=='0'){
            for(int i=0; i<10; ++i){
                palavra.append(to_string(i));
                permutacao(regras, size, pos+1, dic, nroDic, palavra);
                palavra.pop_back();
            }
        }
        else{
            for(int i=0; i<nroDic; ++i){
                palavra.append(dic[i]);
                permutacao(regras, size, pos+1, dic, nroDic, palavra);
                palavra.erase(palavra.end()-dic[i].size(), palavra.end());
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int k;
    cin >> k;
    for(int i=0; i<k; ++i){
        cout << "--\n";
        int nroDic=k, nroRegras;
        if(i!=0) cin >> nroDic;
        fgetc(stdin);
        //cout << nroDic << "\n";
        string dictionary[nroDic], regras(""), palavra("");
        for(int j=0; j<nroDic; ++j){
            getline(cin, dictionary[j]);
            //cout << "\t" << j << " " << dictionary[j] << "\n";
        }
        cin >> nroRegras;
        fgetc(stdin);
        //cout << nroRegras << "\n";
        for(int j=0; j<nroRegras; ++j){
            getline(cin, regras);
            //cout << "\t" << regras << "\n";
            permutacao(regras, regras.size(), 0, dictionary, nroDic, palavra);
        }
    }
}