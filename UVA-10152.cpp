#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>

using namespace std;


int main(){
    int k;
    cin >> k;
    for(int i=0; i<k; ++i){
        int n;
        cin >> n;
        vector<string> vs(n);
        vector<int> v(n);
        map<int, string> mItoS;
        map<string, int> mStoI;
        string s;
        getline(cin, s);
        for(int j=0; j<n; ++j){
            getline(cin, s);
            vs[n-j-1]=s; 
        }
        for(int j=0; j<n; ++j){
            getline(cin, s);
            mItoS[n-j-1]=s;
            mStoI[s]=n-j-1;
        }
        for(int j=0; j<n; ++j){
            v[j]=mStoI[vs[j]]; 
        }
        //start from the bottom, for every name thats not in order move the lowest to the top
        vector<int> toSwap;
        int mini=0;
        for(int j=0; j<n; ++j){
            if(v[j]!=mini) toSwap.push_back(v[j]);
            else mini++;
        }
        sort(toSwap.begin(), toSwap.end());
        for(int j=0; j<(int) toSwap.size(); j++){
            cout << mItoS[toSwap[j]] << endl;
        }
        cout << endl;
    }
    return 0;
}