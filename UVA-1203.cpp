#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
    if(a.first==b.first){
        if(a.second>b.second) return true;
        return false;
    }
    if(a.first>b.first) return true;
    return false;
};

int main(){
    string s, p, num;
    cin >> s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    map<int, int> m;
    while(s[0]!='#'){
        cin >> p >> num;
        pq.emplace(make_pair(stoi(num), stoi(p)));
        m[stoi(p)]=stoi(num);
        cin >> s;
    }
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cout << pq.top().second << endl;
        pair<int, int> p=pq.top();
        pq.pop();
        p.first+=m[p.second];
        pq.emplace(p);
    }
    return 0;
}