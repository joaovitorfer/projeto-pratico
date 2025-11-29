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
            int j = i;

            while (j >= gap && v[j - gap].identificador > temp.identificador) {
                v[j] = v[j - gap];
                j -= gap;
            }
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
void Procurar(lol V[], int M){
	char res = 's';
	    cout << "Escolha como deseja procurar o personagem: " << endl << "1-ID" << endl << "2-Nome" << endl;
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
        V[posID].removido = true;
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

        cout << "Deseja deletar esse personagem?" << endl << "S/s" << endl << "N/n" << endl;
        cin >> res;
        if(res ==  'S' or res == 's'){
            V[posNome].removido = true;
            }
    }
}
}
void adicionar(lol *&V, int &M, int &N){
	   char res = 's';
	   bool continuar = true;
	   

    while (continuar) {

        cout << "Deseja acrescentar algum personagem? " << endl << "S/s" << endl << "N/n" << endl;
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
            cin.ignore();
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
 
}
void mostrar(lol V[],int N){
	 for (int i = 0; i < N; i++) {
		if(V[i].removido == false){
        cout << "ID: " << V[i].identificador << endl;
        cout << "Nome: " << V[i].nome << endl;
        cout << "Apelido: " << V[i].apelido << endl;
        cout << "Rotas: " << V[i].rota << endl;
        cout << "Posto: " << V[i].funcao << endl;
    
	}
    }
}
void Menu(lol *&V,int &N, int &M){
	char R;
	while(true){
	cout << endl;
	cout << "         " << "MENU"<< endl;
	cout << "O que voce deseja fazer? (digite o numero)" << endl;
	cout << "1: Adicionar" << endl;
	cout << "2: Procurar" << endl;
	cout << "3: mostrar todos os personagens" << endl;
	cin >> R;
	switch(R){
		case '1':
		adicionar(V,M,N);
		break;
		case '2':
		Procurar(V,N);
		break;
		case '3':
		mostrar(V,N);
		break;
	}
}
	
	
}

int main() {

    int N = 40;
    lol *V = new lol[N];
    int M = N;

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
    Menu(V,N,M);
    

 

    delete[] V;

    return 0;
}
