#include <iostream>
#include <string>
using namespace std;


struct Cliente {
    int id;
    string nome;
    string telefone;
};


struct Filme {
    int codigo;
    string titulo;
    string genero;
    int ano;
    int idCliente;
};

void mostraMenu(){
    cout << "Menu de opcoes:\n";
    cout << "1. Cadastrar cliente.\n";
    cout << "2. Cadastra filme.\n";
    cout << "3. Listar clientes.\n";
    cout << "4. Listar filmes.\n";
    cout << "5. Buscar filmes por clientes.\n";
    cout << "6. Relatorio geral.\n";
    cout << "7. Sair.\n";
}


void cadastrarCliente(Cliente clientes[], int &qtdClientes) {
    Cliente c;
    cout << "ID do cliente: ";
    cin >> c.id;

    // verifica se já tem esse id
    for (int i = 0; i < qtdClientes; i++) {
        if (clientes[i].id == c.id) {
            cout << "ID ja cadastrado!\n";
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, c.nome);
    cout << "Telefone: ";
    getline(cin, c.telefone);
    clientes[qtdClientes] = c; // Adiconar o cliente na qtdClientes
    qtdClientes++;
}

// COntinuar daqui .... (cadastrar filme)


















