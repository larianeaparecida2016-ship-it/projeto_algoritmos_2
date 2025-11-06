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
    string idCliente; // Para guarda o id do cliente que alugou o filme

};

void cadastrarCliente(Cliente clientes[], &totalClientes) {
Cliente c;
cout << "ID do cliente: ";
cin >> c.id;

for (int i = 0; i < totalClientes; i++) { //Verificar se já consta o ID cadastrado de cliente
    if (clientes[i].id == c.id) {
        cout << "ID j[a consta como cadastrado!\n";
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


void CadastrarCliente(Cliente *c){
    cout << "Cadastro de cliente";
    cout << "ID do cliente: ";
    getline(cin, c->id);
    cout << "Nome: ";
    getline(cin, c->nome);
    cout << "Telefone: ";
    getline(cin, c->telefone);
}

void CadastrarFilme(Filme *f){
    cout << "Cadastro de filmes";
    cout << "Codigo: ";
    getline (cin, f->codigo);
    cout << "Nome do filme: ";
    getline(cin, f->titulo);
    cout << "Genero do filme: ";
    getline(cin, f->genero);
    cout << "Ano: ";
    getline(cin, f->ano);
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
















