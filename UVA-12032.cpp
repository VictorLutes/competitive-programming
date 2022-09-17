#include <iostream>
#include <cstdio>
#include <iomanip>

#define ERRO 0.001

using namespace std;

int f (int x, int *ladder, int n){
    int rung=-1;
    int dist=ladder[0];
    while(rung<n-1){
        if(dist>x) return -1;
        else if(dist==x) x--;
        ++rung;
        dist=ladder[rung+1]-ladder[rung];
    }
	return x;
}


// versao iterativa....
int bisecao(int min, int max, int *ladder, int n){
	int mid = min;
	while (max-min>1){
		mid = (max+min)/2;
		//printf("min = %d *** max = %d **** mid = %d *** result = %d\n", min, max, mid, f(mid, ladder, n));
		if ( f(mid, ladder, n) > 0  )  // AQUI SIM.. FUnciona para  QQ função...
			max = mid;      // o valor está muito grande... diminui !!!!
		else min =  mid;    // o valor esta muito baixo... aumenta !!!!
	}

	return max;
}



int main(int argc, char const *argv[])
{
	int t;

	cin >> t;

    int n, max;
	for(int i=0; i<t; ++i){
        cin >> n;
        int ladder[n];
        for(int j=0; j<n; ++j){
            cin >> ladder[j];
        }
        max=ladder[n-1];

        cout << "Case " << i+1 << ": " << bisecao(1, max, ladder, n) << endl;
    }

	

	return 0;
}