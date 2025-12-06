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

void compactar(lol V[], int &N) {
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (!V[i].removido) {
            V[j] = V[i];
            j++;
        }
    }
    N = j;
}

void salvar(const string nomeA, lol V[], int &n) {
    ofstream arquivo(nomeA);

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo para Salvar!!" << endl;
    }else{
    compactar(V, n);
    for (int i = 0; i < n; i++) {
        if (!V[i].removido) {

            arquivo << V[i].identificador << ";"
                    << V[i].nome << ";"
                    << V[i].apelido << ";"
                    << V[i].rota << ";"
                    << V[i].funcao << "\n";
        }
    }

}
    arquivo.close();
}

void mostrarAlguns(lol V[],int n){
	int p1 = 0,p2 = 0;
	cout << "digite a primeira posicao que voce quer exibir"<< endl;
	while(p1 <=0){
	cin >> p1;
}
    p1 -= 1;
    cout << "digite a ultima posicao que voce quer exibir"<< endl;
    while(p2 > n || p2<=0 || p1 >=p2){
	cin >> p2;
	}
	 for (int i = p1; i < p2; i++) {
		if(V[i].removido == false){
        cout << "ID: " << V[i].identificador << endl;
        cout << "Nome: " << V[i].nome << endl;
        cout << "Apelido: " << V[i].apelido << endl;
        cout << "Rotas: " << V[i].rota << endl;
        cout << "Posto: " << V[i].funcao << endl;
}
}
}
void insertionSortID(lol v[], int n)  {
    for (int i = 1; i < n; i++) {
        lol temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j].identificador > temp.identificador) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
    }
}


void insertionSortNome(lol v[], int n) {
    for (int i = 1; i < n; i++) {
        lol temp = v[i];
        int j = i - 1;

        while (j >= 0 && v[j].nome > temp.nome) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
    }
}
void insertionSortApelido(lol v[], int n) {
    for (int i = 1; i < n; i++) {
        lol temp = v[i];
        int j = i - 1;

        while (j >= 0 && v[j].apelido > temp.apelido) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
    }
}
void insertionSortRota(lol v[], int n) {
    for (int i = 1; i < n; i++) {
        lol temp = v[i];
        int j = i - 1;

        while (j >= 0 && v[j].rota > temp.rota) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
    }
}
void insertionSortFuncao(lol v[], int n) {
    for (int i = 1; i < n; i++) {
        lol temp = v[i];
        int j = i - 1;

        while (j >= 0 && v[j].funcao > temp.funcao) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = temp;
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

    insertionSortID(V, M);

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
    insertionSortNome(V, M);
    
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
void adicionar(lol *&V, int &M, int &N,int &D){
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
            D++;
            V[N].identificador = D;

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
        cout << "Funcao: " << V[i].funcao << endl;
    
	}
    }
}
void Ordenar(lol V[],int N){
	cout << "escolha como voce deseja ordenar" << endl;
	cout << "1: ID" << endl;
	cout << "2: Nome" << endl;
	cout << "3: Apelido" << endl;
	cout << "4: Rota" << endl;
	cout << "5: funcao" << endl;
	
	char R;
	cin >> R;
	switch(R){
		case '1':
		insertionSortID(V,N);
		break;
		case '2':
		insertionSortNome(V,N);
		break;
		case '3':
	    insertionSortApelido(V,N);
		break;
		case '4':
		insertionSortRota(V,N);
		break;
		case '5':
		insertionSortFuncao(V,N);
		break;
		
	}
	
	
}
void Menu(lol *&V,int &N, int &M, int &D){
	char R;
	while(true){
	cout << endl;
	cout << "         " << "MENU"<< endl;
	cout << "O que voce deseja fazer? (digite o numero)" << endl;
	cout << "1: Adicionar" << endl;
	cout << "2: Procurar" << endl;
	cout << "3: Ordenar" << endl;
	cout << "4: Selecionar personagens para exibir" << endl;
	cout << "5: Exibir todos" << endl;
	cout << "6: Salvar" << endl;
	cout << "7: Sair" << endl;
	cin >> R;
	switch(R){
		case '1':
		adicionar(V,M,N,D);
		break;
		case '2':
		Procurar(V,N);
		break;
		case '3':
		Ordenar(V,N);
		break;
		case '4':
		mostrarAlguns(V,N);
		break;
		case '5':
		mostrar(V,N);
		break;
		case '6':
		salvar("personagens.csv",V,N);
		break;
		case '7':
		return;
		break;
		
	}
}
	
	
}

int main() {

    int N = 40;
    lol *V = new lol[N];
    int M = N;
    N = 0;
    int D = 0;
    ifstream arquivo("personagens.csv");

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo";
        return 0;
    }
    bool continuar = true;
    while (continuar) {
    if (!(arquivo >> V[N].identificador)){
        continuar = false;
	}
        if(continuar){
        arquivo.ignore();

        getline(arquivo, V[N].nome, ';');
        getline(arquivo, V[N].apelido, ';');
        getline(arquivo, V[N].rota, ';');
        getline(arquivo, V[N].funcao);
        N++;
  
    if (N == M) {
        M += 5;
        lol *novo = new lol[M];
        for (int i = 0; i < N; i++)
            novo[i] = V[i];
        delete[] V;
        V = novo;
    }
}
}

   for (int i = 0; i < N; i++) {
    if (V[i].identificador > D)
        D = V[i].identificador;
   }
    Menu(V,N,M,D);
    

 

    delete[] V;

    return 0;
}
