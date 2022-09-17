#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<iostream>
#include<map>

using namespace std;

//map song number to start time

int main(){
    int m, n, ci, ti, vi, cur=0, sum=0;
    cin >> m >> n;
    vector<int> times, songs;
    for(int i=0; i<m; ++i){
        cin >> ci >> ti;
        sum+=ci*ti;
        times.push_back(sum);
    }
    for(int i=0; i<n; ++i){
        cin >> vi;
        songs.push_back(vi);
    }
    for(int i=0; cur<n && i<m; ++i){
        while(cur<n && songs[cur]<=times[i]){
            cout << i+1 << endl;
            cur++;
        }
    }
    return 0;
}