
#include <iostream>
#include <cstdio>

using namespace std;

//faz o merge das duas sub listas usando o vetor temp para armazenar os dados ordenados para contar o número de inversões
long merge(int *vet, int *temp, int l, int mid, int r){
    //printf("%d - %d - %d \n", l, mid, r);
    //defina um contador
    int i=l;
    int j=mid+1;
    int k=0;//indice do temp
    long count=0;
    //enquanto tem elementos em ambas as listas
    while(i<=mid && j<=r){
        if(vet[i]<vet[j]){
            temp[k++]=vet[i++];
        }
        else{//inversão
            count+=mid+1-i;//incrementa count com o tamanho do restante da lista A
            temp[k++]=vet[j++];
        }
    }
    //completa os valores que faltam
    while (i<=mid){
        temp[k++]=vet[i++];
    }
    while (j<=r){
        temp[k++]=vet[j++];
    }
    
    //copia de temp para vet
    for(int i=l; i<=r; ++i){
        vet[i]=temp[i-l];
    }
    return count;
}

//Função recursiva que calcula o número de inversões
long inv(int *vet, int inf, int sup){
    //se a çosta tiver só um elemento, retorna 0
    if(inf==sup) return 0;

    int mid=(sup+inf)/2;
    int temp[sup-inf+1];

    long qtdinf=inv(vet, inf, mid);
    long qtdsup=inv(vet, mid+1, sup);
    long qtdmerge=merge(vet, temp, inf, mid, sup);

    return qtdinf+qtdsup+qtdmerge;
}

int main(){
    int n;
    cin >> n;
    
    while(n!=0){
        int vet[n];
        for(int i=0; i<n; ++i){
            cin >> vet[i];
        }
        cout << inv(vet, 0, n-1) << endl;
        cin >> n;
    }
    

    return 0;
}