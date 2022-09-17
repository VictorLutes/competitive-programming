#include <iostream>
#include <cstdio>
#include <iomanip>

#define ERRO 0.001

using namespace std;

int f (int x, int *vessel, int n, int m){
    int ves=0;
    int bucket=x, nbuckets=1;
    while(ves<n){
        //printf("%d %d\t", nbuckets, bucket);
        if(x<vessel[ves]) return -1;
        if(nbuckets>m) return -1;
        if(bucket>=vessel[ves]){
            bucket-=vessel[ves];
            ++ves;
        }
        else{
            ++nbuckets;
            bucket=x-vessel[ves];
            ++ves;
        }
    }
    if(nbuckets>m) return -1;
	return 1;
}


// versao iterativa....
int bisecao(int min, int max, int *vessel, int n, int m){
	int mid = min, r=-1;
	while (max-min>1){
		mid = (max+min)/2;
		//printf("min = %d *** max = %d **** mid = %d \n", min, max, mid);
        r=f(mid, vessel, n, m);
        //cout << "\nresult: " << r << endl;
		if (r  > 0  )  // AQUI SIM.. FUnciona para  QQ função...
			max = mid;      // o valor está muito grande... diminui !!!!
		else min =  mid;    // o valor esta muito baixo... aumenta !!!!
	}

	return max;
}



int main(int argc, char const *argv[]){
    int max, n, m;
	while(scanf("%d", &n)!=EOF){
        cin >> m;
        int vessel[n];
        max=0;
        for(int j=0; j<n; ++j){
            cin >> vessel[j];
            max+=vessel[j];
        }

        cout << bisecao(0, max, vessel, n, m) << endl;
    }

	

	return 0;
}