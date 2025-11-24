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


void shellSortID(lol v[], int n) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            lol temp = v[i];
            v[j] = temp;
        }
        gap /= 2;
    }
}


void shellSortNome(lol v[], int n) {
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            lol temp = v[i];
            int j = i;

            while (j >= gap && v[j - gap].nome > temp.nome) {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = temp;
        }
        gap /= 2;
    }
}
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

    char res = 's';
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

    cout << "Deseja procurar algum personagem?" << endl << "1-ID" << endl << "2-Nome" << endl;
    int resposta;
    cin >> resposta;

    shellSortID(V, M);

    int ID;
    if(resposta == 1){
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

        cout << "Deseja deletar esse personagem?" << endl << "S/s" << endl << "N/n" << endl;
        cin >> res;
        if(res ==  'S' or res == 's'){
        V[ID-1].removido = true;
            }
        }
    }


    if(resposta == 2){
    shellSortNome(V, M);
    
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

        cout << "Deseja deletar esse personagem?" << endl << "S/s" << endl << "N/n" << endl  ;
        cin >> res;
        if(res ==  'S' or res == 's'){
            V[ID-1].removido = true;
            }
    }
}
    bool continuar = true;

    while (continuar) {

        cout << "Deseja acrescentar algum personagem? ";
        cin >> res;

        if (res == 's' or res == 'S') {
			if(N == M){
				M += 5;

            lol *novo = new lol[M];

            for (int i = 0; i < N; i++)
                novo[i] = V[i];

            delete[] V;
            V = novo;
}
            cin.ignore();// tem como tirar essa quebra de linha aqui não? 
            V[N].identificador = N+1;

            cout << "nome: ";
            getline(cin, V[N].nome);

            cout << "apelido: ";
            getline(cin, V[N].apelido);

            cout << "rota: ";
            getline(cin, V[N].rota);

            cout << "funcao: ";
            getline(cin, V[N].funcao);
            N++;

        } else if (res == 'n' or res == 'N') {
            continuar = false;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << V[i].identificador << endl;
        cout << V[i].nome << endl;
        cout << V[i].apelido << endl;
        cout << V[i].rota << endl;
        cout << V[i].funcao << endl;
    }

    delete[] V;

    return 0;
}
