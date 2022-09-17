#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <limits.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

//if later value>=earlier value add one
void cross(vector<int> v, int n){
    long long val=0;
    ordered_set mySet;
    for(int i=0; i<n; ++i){
        long long numsAhead=mySet.order_of_key({v[i], INT_MIN});
        val+=mySet.size()-numsAhead;
        mySet.insert({v[i], i});
    }
    cout << val << endl;
}

int main(){
    int t, n;
    cin >> t;
    for(int j=0; j<t; ++j){
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
        }
        cross(v, n);
    }
    return 0;
}