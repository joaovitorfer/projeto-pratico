#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct lol {
    int identificador;
    string nome;
    string apelido;
    string rota;
    string funcao;
    bool removido = false;
};

int buscaBinariaID(lol v[], int inicio, int fim, int ID) {
    if (inicio > fim)
        return -1;

    int meio = (inicio + fim) / 2;

    if (v[meio].identificador == ID)
        return meio;

    if (v[meio].identificador > ID)
        return buscaBinariaID(v, inicio, meio - 1, ID);

    return buscaBinariaID(v, meio + 1, fim, ID);
}

int buscaBinariaNome(lol v[], int inicio, int fim, string nome) {
    if (inicio > fim)
        return -1;

    int meio = (inicio + fim) / 2;

    if (v[meio].nome == nome)
        return meio;

    if (v[meio].nome > nome)
        return buscaBinariaNome(v, inicio, meio - 1, nome);

    return buscaBinariaNome(v, meio + 1, fim, nome);
}

int main() {

    int N = 40;
    int M = N;
    lol *V = new lol[N];

    ifstream arquivo("personagens.csv");

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        arquivo >> V[i].identificador;
        arquivo.ignore(1, ',');

        getline(arquivo, V[i].nome, ',');
        getline(arquivo, V[i].apelido, ',');
        getline(arquivo, V[i].rota, ',');
        getline(arquivo, V[i].funcao, ',');
    }

    int ID;
    cout << "Digite o ID: ";
    cin >> ID;

    int posID = buscaBinariaID(V, 0, M - 1, ID);

    if (posID == -1 or V[posID].removido == true) {
        cout << "ID nao encontrado." << endl;
    } else {
        cout << "ID: " << V[posID].identificador << endl;
        cout << "Nome: " << V[posID].nome << endl;
        cout << "Apelido: " << V[posID].apelido << endl;
        cout << "Rota: " << V[posID].rota << endl;
        cout << "Funcao: " << V[posID].funcao << endl;
    }

    string nome; 
    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, nome);

    int posNome = buscaBinariaNome(V, 0, M - 1, nome);

    if (posNome == -1 or V[posNome].removido == true) {
        cout << "Nome nao encontrado." << endl;
    } else {
        cout << "ID: " << V[posNome].identificador << endl;
        cout << "Nome: " << V[posNome].nome << endl;
        cout << "Apelido: " << V[posNome].apelido << endl;
        cout << "Rota: " << V[posNome].rota << endl;
        cout << "Funcao: " << V[posNome].funcao << endl;
    }

    char res = 's';
    bool continuar = true;

    while (continuar) {

        cout << "Deseja acrescentar algum personagem? ";
        cin >> res;

        if (res == 's' or res == 'S') {

            M++;

            lol *novo = new lol[M];

            for (int i = 0; i < M - 1; i++)
                novo[i] = V[i];

            delete[] V;
            V = novo;

            V[M - 1].identificador = M;

            cin.ignore(1, '\n');
            cout << "nome: ";
            getline(cin, V[M - 1].nome);

            cout << "apelido: ";
            getline(cin, V[M - 1].apelido);

            cout << "rota: ";
            getline(cin, V[M - 1].rota);

            cout << "funcao: ";
            getline(cin, V[M - 1].funcao);

        } else if (res == 'n' or res == 'N') {
            continuar = false;
        }
    }

    for (int i = 0; i < M; i++) {
        cout << V[i].identificador << endl;
        cout << V[i].nome << endl;
        cout << V[i].apelido << endl;
        cout << V[i].rota << endl;
        cout << V[i].funcao << endl;
    }

    delete[] V;

    return 0;
}
