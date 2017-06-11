#include <iostream>

using namespace std;

int main()
{
    // Variáveis
    int n, d, a, v = 0;

    // Ler dados (posicoes, disco, aviao)
    cin >> n >> d >> a;

    // Verificar se o avião está além do disco nas posições
    if(a > d)
        for(; a%n != d; a++, v++);
    else
        v = d - a;

    // Imprimir resultado
    cout << v << endl;

    return 0;
}
