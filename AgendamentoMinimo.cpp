/*
Algoritmos Gulosos (greedy):

A=[10,7,3,5,8,2,9]
1)Encontre o maior e menor elemento: 
    percorre o vetor trocando se o valor é menor ou maior->Força bruta, O(N)
2)Encontre o nth menor elemento: 
    guloso: percorre pegando o menor e trocando o menor por inf k-1 vezes, na késima vez pega a menor->O(kn), k médio é n/2, O(n²)
3)Encontre o maior G, G=|x-y|, x e y E A: 
    força bruta: vai elemento por elemento calculanto o G com os outros e vê o maior, O(n²)
    divisão e conquista: ordena e depois pega o maior e o menor, O(nlogn)
    guloso: percorre o vetor, pega o maior e o menor, calcula o G, O(n)
4)Encontre a subsequencia crescente mais longa:
    não tem solução gulosa
    força bruta: cobinação de todas as subcadeias O(2^n)


Um algoritmo é guloso se este constrói uma solução em pequenos passos, 
tomando uma decisão “ótima” em cada passo, com o objetivo de atingir 
uma solução ótima globalmente.
Como saber se a estratégia gulosa funciona?
    ● Um problema deve exibir as seguintes propriedades
    1. Ele tem estruturas sub-ótimas: existe solução ótima para o 
    problema se este contém soluções ótimas para os 
    sub-problemas
    2. Ele tem propriedade gulosa: Se fizermos o que parece ser 
    melhor naquele momento, terminaremos com a solução ótimas -> 
    Nunca será preciso reconsiderar escolhas passadas !

O problema das Moedas:
    começa nas moedas de maior valor e vê se cabe, subtrai, continua fazendo isso com as outras moedas
    Falha em alguns casos: V=6, moedas=[4,3,1], vai retornar 4,1,1

Agendamento de Intervalos:
    encontrar o subconjunto maximo de tarefas mutuamente compatíveis
        Tarefa j começa em s_j e termina em f_j
        Duas tarefas são compatíveis se não há sobreposição

    Solução Gulosa:
        Considere tarefas em alguma ordem. Cada tarefa é escolhida obedecendo-se o mesmo critério utilizado nas escolhas prévias.
        ● [Tempo de início mais cedo]  Considere tarefas em ordem ascendente de tempo de início sj. X
        ● [Tempo de fim mais cedo]  Considere tarefas em ordem ascendente em tempo de fim fj.
        ● [Menor intervalo]  Considere tarefas em ordem ascendente de tamanho de intervalo fj - sj. X
        ● [Menor número de conflitos]  Para cada tarefa, conte o número de tarefas em conflito cj. Agende em ordem ascendente de conflitos cj. X

        -> [Tempo de fim mais cedo] O(nlogn)
        Sort jobs by finish times so that f1 ≤ f2 ≤ ... ≤ fn.
        A ← φ
        for j = 1 to n {
        if (job j compatible with A) //usando o ultimo tempo de fim na minha lista de jobs adicionados
            A ← A ∪ {j}
        }
        return A


Particionamento de intervalos:
    encontrar o numero minimo de recursos para agendar todas as tarefas

    Considere palestras em ordem crescente de tempo de início: atribua uma palestra para qualquer sala compatível.
    Sort intervals by starting time so that s1 ≤ s2 ≤ ... ≤ sn.
    d ← 0
    for j = 1 to n {
    if (lecture j is compatible with some classroom k)
        schedule lecture j in classroom k
    else
        allocate a new classroom d + 1
        schedule lecture j in classroom d + 1
        d ← d + 1 
    }
    O(n log n)

Colocando as feras na jaula (load balancing):
    Sejam C jaulas, cada qual podendo armazenar 0, 1 ou 2 animais.
    Existem S animais (1 ≤ S ≤ 2C) e uma lista M das massas dos S animais.
    Determine qual jaula deve conter cada animal tal que o desbalanceamento seja mínimo.

    ○ obs 1: se houver uma jaula vazia será normalmente benéfico (e nunca pior) mover um animal 
      de uma jaula com 2, para uma vazia. (jaula vazia aumenta o desbalanceamento)
    ○ obs 2: Se S > C, então S - C animais devem ser colocados aos pares numa jaula que já 
      contém um animal (o princípio do escaninho!)

    Ordena por peso e coloca o maior animal na jaula com menor peso

    Se falta animais completo com 0
    ordene o conjunto: M = {0,0,1,2,5,7}
    ○ Temos finalmente uma estratégia gulosa neste ponto
    ■ forme um par em C1 com as massas M[1] e M[2C]
    ■ forme um par em C2 com as massas M[2] e M[2C-1],  e assim por diante
*/  

#include <iostream>
#include <algorithm>

using namespace std;

//Ordena os jobs por diferença ou razão de duração e peso  
//depois fica simples

//pensar qual vai dar sempre certo

typedef struct{
    int d;
    int p;
}JOB;

bool cmpfnc(JOB a, JOB b){
    return (a.d/(double)a.p<b.d/(double)b.p);
}

int main(){
    int t, n;
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n;
        JOB jobs[n];
        for(int j=0; j<n; ++j){
            cin >> jobs[j].d;
            cin >> jobs[j].p;
        }

        sort(jobs, jobs+n, cmpfnc);

        int sum=0, c=0;
        for(int j=0; j<n; ++j){
            c+=jobs[j].d;
            sum+=jobs[j].p*c;
        }
        cout << sum << "\n";
    }
}