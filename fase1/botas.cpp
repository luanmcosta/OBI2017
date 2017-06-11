#include <iostream>

int main()
{
    // Variáveis
    int TAMANHOS_BOTAS = 31; // Pra truncar o tamanho
    int n, tamanho;
    char pe;
    int pares = 0;

    int botasE[TAMANHOS_BOTAS];
    int botasD[TAMANHOS_BOTAS];

    // Zerar vetores
    for (int i = 0; i < 30; ++i)
        botasE[i] = botasD[i] = 0;

    // Ler dados (quantidade de botas)
    cin >> n;

    // Ler dados das botas
    for (int i = 0; i < n; ++i) {
        cin >> tamanho >> pe;

        // Armazenar dados no vetor de botas específico
        pe == 'D' ? botasD[tamanho - TAMANHOS_BOTAS-1]++ :  botasE[tamanho - TAMANHOS_BOTAS-1]++;
    }

    // Contar pares
    for (int i = 0; i < TAMANHOS_BOTAS; ++i) {
        // Contar pares enquanto exister botas de ambos os pés
        while(botasD[i]-- > 0 && botasE[i]-- > 0){
            pares++;
        }
    }

    // Imprimir pares
    cout << pares << endl;

    return 0;
}
