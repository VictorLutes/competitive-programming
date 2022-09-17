#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 1001

int cartas[MAX];
int MEMO[MAX];

int n;

int lisPD(){
	int maxlis = 1;
	for (int i = 1; i <=n; ++i) { // para todo elemento i do vetor
		int maior = 1;
		for (int j = i-1; j>=0; j--) { // para todo j [i-1 ... 0]
			//int res = MEMO[j];
			if (cartas[j] < cartas[i]){
				maior = max(MEMO[j]+1, maior);
			}
		}

		MEMO[i] = maior;

		if (maxlis < maior){
			maxlis = maior;

		}
	}

	return maxlis;
}



int main(int argc, char const *argv[]){
    cin >> n;
    

    for(int i=1; i<=n; ++i){
        cin >> cartas[i];
    }
	int max=lisPD();
	cout << n-max << endl;
	return 0;
}
