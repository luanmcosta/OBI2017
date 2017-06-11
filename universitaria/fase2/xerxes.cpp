#include<iostream>

int main(int argc, char *argv[])
{
    // Variáveis
    int n;
    int vDario = 0;
    int vXerxes = 0;
    int d, x;

    // Ler dados (rodadas)
    cin >> n;

    // Ler dados das rodadas (dario e xerxes)
    for (int i = 0; i < n; ++i) {
        cin >> d >> x;

        // Comparar (regra de jogo) se os dois próximos numeros são coincidentes ao oponente
        ((d + 1) % 5 == x || (d + 2) % 5 == x) ? vDario++ : vXerxes++;
    }

    // Imprimir vencedor da partida
    cout << (vDario > vXerxes ? "dario" : "xerxes") << endl;

    return 0;
}
