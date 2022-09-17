#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

double calcLen(double r, double w){
    double len=r*r-(w/2)*(w/2);
    return sqrt(len);
}

bool cmpfnc(pair<double, double> a, pair<double, double> b){
    if(a.first==b.first)
        return (a.second<b.second);
    return (a.first<b.first);
}

int main(){
    double n, l, w;
    while(cin >> n >> l >> w){
        vector<pair<double, double>> v;
        for(int i=0; i<n; ++i){
            double a, b;
            double r;
            cin >> a >> b;
            if(b>w/2){
                r=calcLen(b, w);
                v.push_back(make_pair(a-r, a+r));
            }
        }
        bool canFill=true;
        if(v.empty()) canFill=false;
        int numS=0;
        double latestFit=-1, latestFitRight=0, start=0;
        sort(v.begin(), v.end(), cmpfnc);
        for(int i=0; l>latestFitRight && canFill && i<(int) v.size();){
            latestFit=-1;
            while(i<(int) v.size() && v[i].first<=start){
                if(latestFit==-1){
                    latestFit=i;
                    latestFitRight=v[i].second;
                }
                else if(v[i].second>latestFitRight){
                    latestFit=i;
                    latestFitRight=v[i].second;
                }
                
                ++i;
            }
            if(latestFit==-1){
                canFill=false;
            }
            else{
                numS++;
                start=latestFitRight;
                i=latestFit+1;
            }
        }

        if(canFill && l<=latestFitRight) cout << numS << endl;
        else cout << -1 << endl;
    }
    return 0;
}