#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>



using namespace std;


int n;
int m;
int t;

void PD (pair<int,int> *MEMO){
	for (int j = 1; j <=t; ++j){
		MEMO[j].first = 0;
        MEMO[j].second = j;
        if(j>=m && j>=n){
            if(MEMO[j-m].second==MEMO[j-n].second){
                if(MEMO[j-m].first+1>MEMO[j-n].first+1){
                    MEMO[j].first=MEMO[j-m].first+1;
                    MEMO[j].second=MEMO[j-m].second;
                }
                else{
                    MEMO[j].first=MEMO[j-n].first+1;
                    MEMO[j].second=MEMO[j-n].second;
                }
            }
            else if(MEMO[j-m].second<MEMO[j-n].second){
                MEMO[j].first=MEMO[j-m].first+1;
                MEMO[j].second=MEMO[j-m].second;
            }
            else{
                MEMO[j].first=MEMO[j-n].first+1;
                MEMO[j].second=MEMO[j-n].second;
            }
        }
        else if(j>=m){
            MEMO[j].first=MEMO[j-m].first+1;
            MEMO[j].second=MEMO[j-m].second;
        }
        else if(j>=n){
            MEMO[j].first=MEMO[j-n].first+1;
            MEMO[j].second=MEMO[j-n].second;
        }
        //cout << j<< " " << MEMO[j] << endl;
	}
    cout << MEMO[t].first;
    if(MEMO[t].second!=0) cout << " " << MEMO[t].second;
    cout<< endl;
}

int main(int argc, char const *argv[]){
	while(scanf("%d", &m)!=EOF){
        cin >> n;
        cin >> t;
        pair<int,int> MEMO[t+1]; 
        MEMO[0].first=0;
        MEMO[0].second=0;
        PD(MEMO);
    }
	return 0;
}

