#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(true) {
        cin >> n;
        if(n==0) return 0;
        map<long long, int> m;
        int maxm=1;
        for(int i=0; i<n; ++i){
            long long sum=0;
            vector<int> v;
            for(int j=0; j<5; ++j){
                int val;
                cin >> val;
                v.push_back(val);
            }
            sort(v.begin(), v.end());
            for(int j=0; j<5; ++j){
                sum=sum*1000+v[j];
            }
            if(m.find(sum)==m.end()) m[sum]=1;
            else m[sum]++;
            if(m[sum]>maxm) maxm=m[sum];
        }
        int count=0;
        for(auto it=m.begin(); it!=m.end(); ++it){
            if(it->second==maxm){
                count+=it->second;
            }
        }
        cout << count << endl;
    }

    return 0;
}