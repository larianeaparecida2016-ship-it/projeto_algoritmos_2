#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


struct Cliente {
    int id;
    char nome[50];
    char telefone[50];
};


struct Filme {
    int codigo;
    char titulo[50];
    char genero[50];
    int ano;
    int idCliente;
};

struct Ator {
    char nomeAtor[50];

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
    cin >> c.nome;
    cin.ignore();
    cout << "Telefone: ";
    cin >> c.telefone;
    cin.ignore();
    clientes[qtdClientes] = c; // Adiconar o cliente na qtdClientes
    qtdClientes++;
}

void salvar(Cliente clientes[], int qtdClientes, Filme filmes[], int qtdFilmes, Ator atores[], int qtdAtor) {

    fstream meuArquivo;
    meuArquivo.open("cliente.bin", ios::out | ios::binary);

    if (meuArquivo.is_open()) {

        meuArquivo.write(reinterpret_cast<char*>(&qtdClientes),sizeof(int));
        meuArquivo.write(reinterpret_cast<char*>(&qtdFilmes),sizeof(int));
        meuArquivo.write(reinterpret_cast<char*>(&qtdAtor),sizeof(int));
        meuArquivo.write(reinterpret_cast<char*>(clientes),sizeof(Cliente) * qtdClientes);
        meuArquivo.write(reinterpret_cast<char*>(filmes),sizeof(Filme) * qtdFilmes);
        meuArquivo.write(reinterpret_cast<char*>(atores),sizeof(Ator) * qtdAtor);

        meuArquivo.close();
        cout << "Informacoes salvas.\n";
    } else {
        cout << "Falha ao salvar informacoes.\n";
    }
}

void carregar(Cliente clientes[], int &qtdClientes,Filme filmes[], int &qtdFilmes, Ator atores[], int &qtdAtor) {

    fstream meuArquivo;
    meuArquivo.open("cliente.bin", ios::in | ios::binary);

    if (meuArquivo.is_open()) {

        meuArquivo.read(reinterpret_cast<char*>(&qtdClientes),sizeof(int));
        meuArquivo.read(reinterpret_cast<char*>(&qtdFilmes),sizeof(int));
        meuArquivo.read(reinterpret_cast<char*>(&qtdAtor),sizeof(int));
        meuArquivo.read(reinterpret_cast<char*>(clientes),sizeof(Cliente) * qtdClientes);
        meuArquivo.read(reinterpret_cast<char*>(filmes),sizeof(Filme) * qtdFilmes);
        meuArquivo.read(reinterpret_cast<char*>(atores),sizeof(Ator) * qtdAtor);

        meuArquivo.close();
        cout << "Informacoes carregadas com sucesso!!\n";
    } else {
        cout << "Falha ao carregar informacoes.\n";
    }
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
    cin >> f.titulo;
    cin.ignore();
    cout << "Genero: ";
    cin >> f.genero;
    cin.ignore();
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

void cadastrarAtor(Ator atores[], int &qtdAtor) {
    Ator a;

    cout << "Nome do ator: ";
    cin >> a.nomeAtor;
    cin.ignore();
    atores[qtdAtor] = a;
    qtdAtor++;
}

void listarAtor (Ator atores[], int qtdAtor){
    if(qtdAtor == 0){
        cout << "Nenhum cliente cadastrado.\n";
        return;
    }
    for (int i = 0; i < qtdAtor; i++){
        cout << "Nome do ator: " << atores[i].nomeAtor << endl;
    }

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
    cout << "7. Cadastrar Ator.\n";
    cout << "8. Listar atores.\n";
    cout << "9. Salvar informacoes de um arquivo.\n";
    cout << "10. Carregar informacoes do arquivo.\n";
    cout << "11. Sair.\n";
}


int main() {
    Cliente clientes[50];
    Filme filmes[50];
    Ator atores [50];
    int qtdClientes = 0;
    int qtdFilmes = 0;
    int qtdAtor = 0;
    int opcao;




    while(true) {
        mostraMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 11)
            break;


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
                cadastrarAtor(atores, qtdAtor);
                break;
            case 8 :
                listarAtor(atores, qtdAtor);
                break;
            case 9:
                salvar(clientes, qtdClientes, filmes, qtdFilmes, atores, qtdAtor);
                break;
            case 10:
                carregar(clientes, qtdClientes, filmes, qtdFilmes, atores, qtdAtor);
                break;

        }

    }

    return 0;
}

