#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;


int n;
int m;
char str1[1002];
char str2[1002];

int MEMO[1002][1002];


int lisREC(int i, int J, int &maxl){
	if (i == 0 || J==0)
		return 0;

	int maior = lisREC(i-1, J, maxl);
	for (int j = J; j>=1; j--){
		int res = lisREC(i-1, j-1, maxl);

		if (str1[i]==str2[j]){
			maior = max(res+1, maior);
		}
	}
	if (maior > maxl)
		maxl = maior;

	return maior;
}


int lisRECPD(int i, int J, int &maxlis){
	if (i == 0 || J==0)
		return 0;

	if(MEMO[i][J]!=-1) return MEMO[i][J];
	int maior = lisRECPD(i-1, J, maxlis);
	for (int j = J; j>=1; j--){
		int res = lisRECPD(i-1, j-1, maxlis);

		if (str1[i]==str2[j]){
			maior = max(res+1, maior);
		}
	}
	MEMO[i][J]=maior;

	if (maior > maxlis)
		maxlis = maior;

	return MEMO[i][J];
}


int lisPD(){
    for(int i=0; i<n; ++i){
        MEMO[0][i]=0;
        MEMO[i][0]=0;
    }
	int maxlis = 1;
	for (int i = 1; i <n; ++i) { // para todo elemento i do vetor
		int maior = 0;
		for (int j = 1; j<m; j++) { // para todo j [i-1 ... 0]
			int res = MEMO[i-1][j];
            maior=max(maior, res);
			if (str2[j]==str1[i]){
				maior = max(MEMO[i-1][j-1]+1, maior);
			}
            MEMO[i][j] = maior;
		}

		

		if (maxlis < maior){
			maxlis = maior;

		}
	}

	return maxlis;
}

int main(int argc, char const *argv[]){
    char c;
    while(scanf("%c", &c)!=EOF){
        for(n=1; c!='\n'  && c!='\r'  && c!=EOF; ++n){
            str1[n]=c;
            c=fgetc(stdin);
        }
		c=fgetc(stdin);
        for(m=1; c!='\n'  && c!='\r' && c!=EOF; ++m){
            str2[m]=c;
            c=fgetc(stdin);
        }
		int max=0;
		//memset(MEMO, -1, sizeof(MEMO));
        //lisRECPD(n-1, m-1, max);
        max=lisPD();
		cout << max << endl;
    }


	return 0;
}
