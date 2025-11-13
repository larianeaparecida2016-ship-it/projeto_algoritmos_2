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


void cadastrarFilme(Filme filmes[], int &qtdFilmes, Cliente clientes[], int qtdClientes) {
    Filme f;
    cout << "Codigo do filme: ";
    cin >> f.codigo;

    // verifica se já existe esse código
    for (int i = 0; i < qtdFilmes; i++) {
        if (filmes[i].codigo == f.codigo) {
            return;
        }
    }

    cout << "Titulo: ";
    cin.ignore();
    getline(cin, f.titulo);
    cout << "Genero: ";
    getline(cin, f.genero);
    cout << "Ano: ";
    cin >> f.ano;

    cout << "ID do cliente que vai alugar (0 para nenhum): ";
    cin >> f.idCliente;

    if (f.idCliente != 0) {
        bool achou = false;
        for (int i = 0; i < qtdClientes; i++) {
            if (clientes[i].id == f.idCliente) {
                achou = true;
                break;
            }
        }
        if (!achou) {
            cout << "Cliente nao encontrado! Filme nao cadastrado.\n";
            return;
        }
    }

    filmes[qtdFilmes] = f;
    qtdFilmes++;
}

// listar os clientes
void listarClientes(Cliente clientes[], int qtdClientes) {
    if (qtdClientes == 0) {
        cout << "Nenhum cliente cadastrado.\n";
        return;
    }

    for (int i = 0; i < qtdClientes; i++) {
        cout << "ID: " << clientes[i].id << endl;
        cout << "Nome: " << clientes[i].nome << endl;
        cout << "Telefone: " << clientes[i].telefone << endl;
    }
}

//listar os filmes
void listarFilmes(Filme filmes[], int qtdFilmes, Cliente clientes[], int qtdClientes) {
    if (qtdFilmes == 0) {
        cout << "Nenhum filme cadastrado.\n";
        return;
    }

    for (int i = 0; i < qtdFilmes; i++) {
        cout << "Codigo: " << filmes[i].codigo << endl;
        cout << "Titulo: " << filmes[i].titulo << endl;
        cout << "Genero: " << filmes[i].genero << endl;
        cout << "Ano: " << filmes[i].ano << endl;

        if (filmes[i].idCliente != 0) {
            // procura o nome do cliente
            string nomeCliente = "Desconhecido";
            for (int j = 0; j < qtdClientes; j++) {
                if (clientes[j].id == filmes[i].idCliente) {
                    nomeCliente = clientes[j].nome;
                    break;
                }
            }
            cout << "Alugado: " << nomeCliente;
        } else {
            cout << "Nao alugado";
        }
        cout << endl;
    }
}

// buscar filmes e cliente
void buscarFilmesPorCliente(Filme filmes[], int qtdFilmes, int idCliente) {
    bool achou = false;
    for (int i = 0; i < qtdFilmes; i++) {
        if (filmes[i].idCliente == idCliente) {
            cout << "Codigo: " << filmes[i].codigo << endl;
            cout << "Titulo: " << filmes[i].titulo << endl;
            achou = true;
        }
    }
    if (!achou) {
        cout << "Esse cliente nao alugou nenhum filme.\n";
    }
}

// relatório geral
void relatorioGeral(Cliente clientes[], int qtdClientes, Filme filmes[], int qtdFilmes) {
    if (qtdClientes == 0) {
        cout << "Nenhum cliente cadastrado.\n";
        return;
    }

    for (int i = 0; i < qtdClientes; i++) {
        int contador = 0;
        for (int j = 0; j < qtdFilmes; j++) {
            if (filmes[j].idCliente == clientes[i].id) {
                contador++;
            }
        }
        cout << "Cliente: " << clientes[i].nome << endl;
        cout << "Filmes alugados: " << contador << endl;
    }
}

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


int main() {
    Cliente clientes[100];
    Filme filmes[100];
    int qtdClientes = 0;
    int qtdFilmes = 0;
    int opcao;

    do {
        mostraMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarCliente(clientes, qtdClientes);
                break;
            case 2:
                cadastrarFilme(filmes, qtdFilmes, clientes, qtdClientes);
                break;
            case 3:
                listarClientes(clientes, qtdClientes);
                break;
            case 4:
                listarFilmes(filmes, qtdFilmes, clientes, qtdClientes);
                break;
            case 5: {
                int id;
                cout << "ID do cliente: ";
                cin >> id;
                buscarFilmesPorCliente(filmes, qtdFilmes, id);
                break;
            }
            case 6:
                relatorioGeral(clientes, qtdClientes, filmes, qtdFilmes);
                break;
            case 7:
                break;
            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 7);

    return 0;
}




