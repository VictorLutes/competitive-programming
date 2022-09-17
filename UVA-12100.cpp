#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <queue>

using namespace std;

void findTime(int pos, queue<pair<int, int>> q, priority_queue<pair<int, int>> pq){
    int time=1;
    while(!pq.empty()){
        if(q.front().first>=pq.top().first){
            if(q.front().second==pos){
                cout << time << endl;
                return;
            }
            time++;
            q.pop();
            pq.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    cout << time << endl;
}

int main(){
    int cases, n, pos, val;
    cin >> cases;
    for(int i=0; i<cases; ++i){
        cin >> n >> pos;
        queue<pair<int, int>> q;
        priority_queue<pair<int, int>> pq;
        for(int j=0; j<n; ++j){
            cin >> val;
            q.push(make_pair(val, j));
            pq.emplace(make_pair(val, j));
        }
        findTime(pos, q, pq);
    }
    
    return 0;
}


/*
int main(){
    int cases, n, pos, val;
    cin >> cases;
    for(int i=0; i<cases; ++i){
        cin >> n >> pos;
        priority_queue<pair<int, int>> pq;
        for(int j=0; j<n; ++j){
            cin >> val;
            pq.emplace(make_pair(val, j));
        }
        int time;
        for(time=1; !pq.empty() && pq.front().second!=pos; ++time){
            pq.pop();
        }
        cout << time << endl;
    }
    
    return 0;
}
*/