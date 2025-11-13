#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct lol{
    int identificador;
    string nome;
    string apelido;
    string rota;
    string funcao;
};



int main(){
    int N = 40;
    lol *V = new lol[N];
   
    ifstream arquivo("personagens.csv");
    
    if(!arquivo){
		cout << "Erro ao abrir o arquivo";
	}else if(arquivo){
        for(int i = 0;i < N;i++){
            arquivo >> V[i].identificador;
            arquivo.ignore(1,',');

            getline(arquivo, V[i].nome, ',');
            getline(arquivo, V[i].apelido,',');
            getline(arquivo, V[i].rota,',');
            getline(arquivo, V[i].funcao, ',');   
    }
    
   
    char res = 's';
    bool continuar = true;
    int M = N;
    while(continuar){
	 cout << "deseja acrecentar algum personagem?" << endl;
	 cin >> res;
	 if(res == 's' or res == 'S'){
	 M ++;
	 lol *novo = new lol[M];
	 for(int i = 0;i < M-1;i++){
		 novo[i] = V[i];
	 }
	 delete[] V;
	 V = novo;
	 V[M-1].identificador = M;
	 cin.ignore(1,'\n');
	 cout << "nome: ";
	 getline(cin, V[M-1].nome);
	 cout << "apelido: ";
     getline(cin, V[M-1].apelido);
     cout << "rota: ";
     getline(cin, V[M-1].rota);
     cout << "funcao: ";
     getline(cin, V[M-1].funcao); 
 }else if(res == 'n' or res == 'N'){
		continuar = false;
	}
  
}
      
   
	
	for(int i = 0; i < M;i++){
			cout << V[i].identificador<<endl;
			cout << V[i].nome << endl;
			cout << V[i].apelido << endl;
			cout << V[i].rota << endl;
			cout << V[i].funcao << endl;
		}
}
    
    delete[] V;
    
 return 0;
}
