#include <iostream>
#include <cstdio>
#include <string>
#include<vector>

using namespace std;

void game(string s){
    for(int i=0; i<(int) s.length(); ++i){
        if(i%2==0){
            if(s[i]=='a') s[i]='b';
            else s[i]='a';
        }
        else{
            if(s[i]=='z') s[i]='y';
            else s[i]='z';
        }
    }
    cout << s << endl;
}

int main(){
    int n;
    cin >> n;
    string a;
    for(int i=0; i<n; ++i){
        cin >> a;
        game(a);
    }
    
    return 0;
}