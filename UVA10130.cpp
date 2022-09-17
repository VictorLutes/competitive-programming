#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>



using namespace std;

#define MAX_W 1001
#define MAX_I 31


int T;
int N;
int G;
vector<int> W;
vector<pair<int, int>> P;
int MEMO[MAX_I+1][MAX_W+1];


int saleRecUm (int obj,  int pesoi){
	if (obj == 0)   // nao tem mais troco. retorna 0
		return 0;
    
    if(pesoi-P[obj].second<0) return saleRecUm(obj-1, pesoi);

    return max(saleRecUm(obj-1, pesoi-P[obj].second)+P[obj].first, saleRecUm(obj-1, pesoi));
}

int saleRecPDUm (int obj, int pesoi){
    if (obj == 0) return 0;
    
    if(MEMO[pesoi][obj]!=-1) return MEMO[pesoi][obj];

    if(pesoi-P[obj].second<0){
        MEMO[pesoi][obj]=saleRecPDUm(obj-1, pesoi);
        return MEMO[pesoi][obj];
    }

    MEMO[pesoi][obj]=max(saleRecPDUm(obj-1, pesoi-P[obj].second)+P[obj].first, saleRecPDUm(obj-1, pesoi));
    return MEMO[pesoi][obj];
}

int PD(){
    return 0;
}

int main(int argc, char const *argv[])
{
							
	int T;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N;
        P.resize(N+2);
        for (int j = 1; j <= N; ++j){
            int a, b;
		    cin >> a >> b;
            P[j]=make_pair(a, b);
        }
        cin >> G;
        W.resize(G+1);
        int sum2=0;
        memset(MEMO, -1, sizeof(MEMO));
        for(int j=1; j<=G; ++j){
            cin >> W[j];
            //sum+=saleRecUm(N, W[j]);
            
            sum2+=saleRecPDUm(N, W[j]);
        }
        cout <<  sum2 << endl;
    }
    return 0;
}

