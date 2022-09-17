#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include<vector>

using namespace std;

char text[100000];
char patt[1000];

void kmpPreProcessamento(int *b, string pat){
    int tamp=pat.length();
    int i=0;
    int j=-1;
    b[0]=-1;
    while(i<tamp){
        while(j>=0 && pat[i]!=pat[j]){
            j=b[j];
        }
        i++;
        j++;
        b[i]=j;
    }
    b[0]=0;
}

void kmp(int *b, string text, string pat){
    int i=0, j=0, tamt=text.length(), tamp=pat.length();
    while(i<tamt){
        if(text[i]!=pat[j]){
            j=b[j];
        }
        
        j++;
        i++;
        if(j==tamp){
            cout << "y\n";
            return;
        }
    }
    cout << "n\n";
}

int main(){
    int n;
    int b[1001];
    
    scanf("%d ", &n);
    for(int i=0; i<n; ++i){
        cin >> text;
        int q;
        scanf("%d ", &q);
        for(int j=0; j<q; ++j){
            cin >> patt;
            kmpPreProcessamento(b, patt);
            kmp(b, text, patt);
        }
    }
    return 0;
}