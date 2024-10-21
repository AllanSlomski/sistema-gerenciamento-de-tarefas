#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <windows.h>
#include "usuarios.cpp"
#include "tarefas.cpp"
#include "equipes.cpp"
#include "arquivos.cpp"

using namespace std;
using json = nlohmann::json;

// criar equipes e designar ujsuarios e tarefas a elas por id
// impedir de criar usuarios se não existirem equipes

int main() {
    string caminhoUsuarios = "usuarios.json";
    string caminhoTarefas = "tarefas.json";
    string caminhoEquipes = "equipes.json";
    json usuarios = carregarArquivo(caminhoUsuarios);
    json tarefas = carregarArquivo(caminhoTarefas);
    json equipes = carregarArquivo(caminhoEquipes);
    int diaAtual = 1;

    int opcao;

    do {
        system("cls");
        cout << "Dia: " << diaAtual << endl << endl;        
        cout << "1 - Usuários" << endl
             << "2 - Tarefas" << endl
             << "3 - Equipes" << endl 
             << "4 - Passar dia" << endl;
        cin >> opcao;

        switch(opcao){
        // Opção Geral 1
            case 1: {
                system("cls");
                cout << "1 - Criar usuário" << endl
                     << "2 - Listar usuários" << endl
                     << "3 - Modificar usuário" << endl
                     << "4 - Deletar usuário" << endl
                     << "0 - Sair" << endl;
                cin >> opcao;
                
                switch(opcao){
                    
                    case 1: {
                    system("cls");
                    
                    bool teste;
                    int id;
                    string nome, equipe, funcao;
                    
                    cout << "ID do Usuário: ";
                    cin >> id;
                    
                    cin.ignore();
                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Equipe: ";
                    getline(cin, equipe);
                    teste = checarEquipe(equipe, equipes);
                    while (!teste){
                        cout << "Equipe não encontrada. Digite novamente: ";
                        getline(cin, equipe);
                        teste = checarEquipe(equipe, equipes);                           
                    }
                    cout << "Função: ";
                    getline(cin, funcao);

                    usuarios.push_back(criarUsuario(id, nome, equipe, funcao));
                    salvarArquivo(caminhoUsuarios, usuarios);
                    
                    system("cls");
                    break;
                }
                    case 2:
                    
                    system("cls");
                    
                    imprimirUsuarios(usuarios);
                    system("pause");
                    
                    break;

                case 3: {
                    system("cls");
                    
                    int id;

                    cout << "ID do Usuário a modificar: ";
                    cin >> id;

                    modificarUsuario(id, usuarios);
                    salvarArquivo(caminhoUsuarios, usuarios);
                    
                    system("pause");
                    break;
                }
                case 4: {
                    system("cls");

                    int id;
                    
                    cout << "ID do Usuário a deletar: ";
                    cin >> id;
                    
                    usuarios = deletarUsuario(id, usuarios);
                    salvarArquivo(caminhoUsuarios, usuarios);
                    
                    system("pause");
                    break;
                }
                }
                break;
            }
            // Opção Geral 2
            case 2: {
                system("cls");
                cout << "1 - Criar tarefa" << endl
                     << "2 - Listar tarefas" << endl
                     << "3 - Modificar tarefa" << endl
                     << "4 - Deletar tarefa" << endl
                     << "5 - Listar tarefas por prioridade" << endl
                     << "6 - Modificar Status da Tarefa" << endl;
                cin >> opcao; 
                switch(opcao){
                    case 1: {
                    system("cls");
                    bool teste;
                    int id, prioridade;
                    string nome, equipe, prazo, status;
                    cout << "ID da Tarefa: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Nome da Tarefa: ";
                    getline(cin, nome);
                    cout << "Equipe designada: ";
                    getline(cin, equipe);
                    teste = checarEquipe(equipe, equipes);
                    while (!teste){
                        cout << "Equipe não encontrada. Digite novamente: ";
                        getline(cin, equipe);
                        teste = checarEquipe(equipe, equipes);                           
                    }
                    cout << "Prioridade (1-5, sendo 5 a mais urgente): ";
                    cin >> prioridade;
                    cin.ignore();
                    cout << "Prazo (DD-MM-AAAA): ";
                    getline(cin, prazo);
                    cout << "Status: ";
                    getline(cin, status);
                    tarefas.push_back(criarTarefa(id, nome, equipe, prioridade, prazo, status));
                    salvarArquivo(caminhoTarefas, tarefas);
                    system("pause");
                    break;
                }
                case 2:{
                    system("cls");
                    imprimirTarefas(tarefas);
                    system("pause");
                    break;
                }
                case 3: {
                    system("cls");
                    int id;
                    cout << "ID da Tarefa a modificar: ";
                    cin >> id;
                    modificarTarefa(id, tarefas);
                    salvarArquivo(caminhoTarefas, tarefas);
                    system("pause");
                    break;
                }
                case 4: {
                    system("cls");
                    int id;
                    cout << "ID da Tarefa a deletar: ";
                    cin >> id;
                    tarefas = deletarTarefa(id, tarefas);
                    salvarArquivo(caminhoTarefas, tarefas);
                    system("pause");
                    break;
                }
                case 5: {
                    system("cls");
                    int prioridade;
                    cout << "Prioridade (1-5): ";
                    cin >> prioridade;
                    cin.ignore();
                    listarTarefasPorPrioridade(prioridade, tarefas);
                    system("pause");
                    break;
                }
                case 6: {
                    system("cls");
                    modificarStatus(tarefas);
                    salvarArquivo(caminhoTarefas, tarefas);
                    system("pause");
                    break;
                }
                }
                break;
            }
            // Opção geral 3
            case 3: {
                system("cls");
                cout << "1 - Criar equipe" << endl;
                cin >> opcao;
                switch(opcao){
                case 1: {
                    system("cls");
                    int id;
                    string nome;
                    cout << "ID da equipe: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Nome da equipe: ";
                    getline(cin, nome);
                    cout << "ID usuário: ";
                    equipes.push_back(criarEquipe(id, nome));
                    salvarArquivo(caminhoEquipes, equipes);
                    system("pause");
                    break;
                }
                case 2:{
                    system("cls");
                    string responsavel;
                    cout << "Digite o nome da equipe: ";
                    cin.ignore();
                    getline(cin, responsavel);
                    pesquisarPorResponsavel(responsavel, equipes, tarefas);
                    system("pause");
                    break;
                }
                }
                break;
            }

            // Opção geral 4
            case 4: {
                diaAtual++;
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}