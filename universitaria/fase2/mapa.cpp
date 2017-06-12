#include <iostream>
#include <vector>

using namespace  std;

int * buscarFim(vector<vector<char> > mapa, int xInicial, int yInicial);

int main(int argc, char *argv[])
{
    // Variáveis
    vector<vector<char> > mapa;
    int cordInicial[2];
    int linhas, colunas;
    int x, y;
    char carac;

    // Ler dados (quantidade de linhas e colunas)
    cin >> linhas >> colunas;

    mapa.resize(linhas);

    // Ler mapa
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            // Ler caractere
            cin >> carac;

            // Salvar coordenada inicial
            if(carac == 'o'){
                x = i;
                y = j;
            }

            // Salvar caractere na matriz
            mapa[i].push_back(carac);
        }
    }

    // Procurar rota da Hermione
    int * coord;
    coord = buscarFim(mapa, x, y);

    // Exibir coordenada final
    cout << coord[0] << " " << coord[1] << endl;

    return 0;
}

int * buscarFim(vector<vector<char> > mapa, int xInicial, int yInicial){

    // Flag de busca
    bool buscando = true;

    // Coordenadas Iniciais
    int xAnterior = -1;
    int yAnterior = -1;
    int xAtual = xInicial;
    int yAtual = yInicial;
    int * coordenadaFinal = (int *) malloc(sizeof(int) * 2);

    // Buscar até que não haja proximo indício de H
    while(buscando){
        //cout << "Coord atual: " << xAtual << ", " << yAtual << endl;

        // Se o próximo indício estiver em cima e não for um visitado (verifica se é uma rota possível, se é diferente do lugar de onde veio e se é uma coordenada existente
        if(mapa[xAtual - 1][yAtual] == 'H' && xAtual - 1 != xAnterior && (xAtual - 1) >= 0 ){
            xAnterior = xAtual;
            yAnterior = yAtual;
            xAtual = xAtual  - 1;
            continue;
        }
        // Se o proximo indício estiver em baixo e não for visitado
        else if(mapa[xAtual + 1][yAtual] == 'H' && xAtual + 1 != xAnterior && (xAtual + 1) < mapa.size() ){
            xAnterior = xAtual;
            yAnterior = yAtual;
            xAtual = xAtual + 1;
            continue;
        }
        // Se o proximo indício estiver na esquerda e não for visitado
        else if(mapa[xAtual][yAtual - 1] == 'H' && yAtual - 1 != yAnterior && (yAtual - 1) >= 0){
            xAnterior = xAtual;
            yAnterior = yAtual;
            yAtual = yAtual - 1;
            continue;
        }
        else if(mapa[xAtual][yAtual + 1] == 'H' && yAtual + 1 != yAnterior &&  (yAtual + 1) < mapa[xAtual].size() ){
            xAnterior = xAtual;
            yAnterior = yAtual;
            yAtual = yAtual + 1;
            continue;
        }

        // Não encontrou mais nenhum indício, para a busca
        buscando = false;
    }

    // Atualizar coordenada final (normalizar, o problema conta a partir de 1)
    coordenadaFinal[0] = xAtual +1;
    coordenadaFinal[1] = yAtual + 1;

    return coordenadaFinal;
}
