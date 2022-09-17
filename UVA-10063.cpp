#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

char newS[11];
        
void permutations(string orig, int j, int n){
    if(j==n){
        cout << newS << endl;
        return;
    }
    
    for(int i = j; i >= 1; i--)
        newS[i] = newS[i-1];
    for(int i = 0; i <= j; i++) {
        newS[i] = orig[j];
        permutations(orig, j+1, n);
        newS[i] = newS[i+1];
    }
}

int main(){
    string s;
    bool newL=false;
    while(cin >> s){
        if(newL) cout<<endl;
        newL=true;
        memset(newS, '\0', sizeof(newS));
        permutations(s, 0, s.length());
    }
    return 0;
}