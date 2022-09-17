#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, val, a, b;
    cin >> n;
    while (n!=0){
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum=0;
        for(int i=0; i<n; ++i){
            cin >> val;
            pq.emplace(val);
        }
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            sum+=a+b;
            pq.emplace(a+b);
        }
        cout << sum << endl;
        cin >> n;
    }
    return 0;
}