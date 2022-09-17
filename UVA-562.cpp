#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <climits>
#include <cstring>
#include <vector>
#include <cmath>


using namespace std;

#define MAX_W 1000
#define MAX_I 100


int M;
int W;
vector<int> P;
int MEMO[MAX_I+2][MAX_W+2];

int pick(int a, int b){
    if(abs(a)<abs(b)) return a;
    return b;
}

int divRec (int i, int dif){
	if (i ==0) return dif;
    if(P[i]+dif>500) return divRec(i-1, dif-P[i]);
    else if(dif-P[i]<-500) return divRec(i-1, dif+P[i]);
	return pick(divRec(i-1, dif+P[i]), divRec(i-1, dif-P[i]));
}

int divRecPD (int i, int dif){
    if (i ==0) return dif;

    if(MEMO[i][dif]!=-1) return MEMO[i][dif];

    if(P[i]+dif>500){
        MEMO[i][dif]=divRecPD(i-1, dif-P[i]);
        return MEMO[i][dif];
    }
    else if(dif-P[i]<-500){
        MEMO[i][dif]=divRecPD(i-1, dif+P[i]);
        return MEMO[i][dif];
    }

	MEMO[i][dif+500]=pick(divRecPD(i-1, dif+P[i]), divRecPD(i-1, dif-P[i]));
    return MEMO[i][dif+500];
}

int PD (){
    for(int w=0; w <= W/2; ++w){
        MEMO[0][w]=0;
    }
    int min=INT_MAX;
	for (int i = 1; i <= M; ++i){
		for(int w=-500; w <= 500; ++w){
            if(w+P[i]>500)
                MEMO[i][w+500]=MEMO[i-1][w-P[i]+500]-P[i];
            else if(w-P[i]<-500)
                MEMO[i][w+500]=P[i]+MEMO[i-1][w+P[i]+500];
            else{
                MEMO[i][w+500]=pick(MEMO[i-1][w+P[i]+500], MEMO[i-1][w-P[i]+500]);
                if(i==M && abs(MEMO[M][w])<min) min=MEMO[M][w];
            }
        }
	}
	return min;
}


int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> M;
        P.resize(M+1);
        for (int j = 1; j <= M; ++j){
		    cin >> P[j];
        }
        W=500;
        //cout <<abs(divRec(M, 0)) << endl;

        memset(MEMO, -1, sizeof(MEMO));
        cout <<abs(divRecPD(M, 0)) << endl;
        
        //cout <<abs(PD()) << endl;
    }
}

