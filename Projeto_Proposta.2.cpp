#include <iostream>
#include <string>

using namespace std;

struct Cliente {
    string id;
    string nome;
    string telefone;
};

struct Filme {
    string codigo;
    string titulo;
    string genero;
    string ano;
    string idCliente; 

};

void cadastrarCliente(Cliente clientes[], &totalClientes) {
Cliente c;
cout << "ID do cliente: ";
cin >> c.id;

for (int i = 0; i < totalClientes; i++) { //Verificar se já consta o ID cadastrado de cliente
    if (clientes[i].id == c.id) {
        cout << "ID ja consta como cadastrado!\n";
        return;
    }
}

void cadastrarFilme(Filme filmes[], int &qtdFilmes, Cliente clientes[], int qtdClientes) {
    Filme f;
    cout << "Codigo do filme: ";
    cin >> f.codigo;
for (int i = 0; i < qtdFilmes; i++) {
        if (filmes[i].codigo == f.codigo) {
            cout << "Codigo ja cadastrado!\n";
            return;
        }
    }

//Continuar a partir daqui .........



void mostrar(Cliente vet[]) {
    for(int i=0; i<pos; i++) {
        cout << "Informacoes cadastro de cliente: " << i+1 << endl;;
        cout << "ID: " << vet[i].id << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Telefone: " << vet[1].telefone << endl;
    }
}

void mostrar(Filme vet[]) {
    for(int i=0; i<=pos; i++) {
        cout << "Informacoes cadastro de filmes: " << i+1 << endl;;
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Nome do filme: " << vet[i].titulo << endl;
        cout << "Genero do filme: " << vet[1].genero << endl;
        cout << "Ano: " << vet[1].ano << endl;
    }
}

int main() {
    Cliente esteCliente;
    Cliente vetorCliente[N];
    Filme esteFilme;
    Filme vetorFilme;

    int opcao;


    mostraMenu();
    cin >> opcao;
    while (opcao != 0) {
        switch(opcao) {
        case 1:
            cadastrar (&esteCliente)
            adicionarCliente (vetorCliente, esteCliente);
            break;
        case 2:
            cadastrar (&esteFilme)
            adicionarFilme (vetorFilme, esteFilme);
            break;
        case 3:
            mostrar (vetorCliente);
            break;
        case 4:
            mostrar (vetorFilme);

        }
    }


return 0;

}



















