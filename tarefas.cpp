#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "tarefas.hpp"
using namespace std;
//tranferir tarefas de uma equipe para outra atraves do id da equipe no array de tarefa

// Função para criar uma nova tarefa
json criarTarefa(int id, string nome, string equipe, int prioridade, string prazo, string status) {
    json tarefa;
    tarefa["id"] = id;
    tarefa["nome"] = nome;
    tarefa["equipe"] = equipe; // pesquisar id ou nome da equipe qnd for adicionar a tarefa, como no trabalho da biblioteca
    tarefa["prioridade"] = prioridade;
    tarefa["prazo"] = prazo;
    tarefa["status"] = status;
    return tarefa;
}

// Função para deletar uma tarefa pelo ID
json deletarTarefa(int id, json& tarefas) {
    json tarefasAtualizadas = json::array();
    for (auto& tarefa : tarefas) {
        if (tarefa["id"] != id) {
            tarefasAtualizadas.push_back(tarefa);  // Mantém as outras tarefas
        }
    }
    return tarefasAtualizadas;
}

// Função para modificar uma tarefa
void modificarTarefa(int id, json &tarefas) {
    for (auto& tarefa : tarefas) {
        if (tarefa["id"] == id) {
            cout << "Novo nome da tarefa: ";
            string novoNome;
            cin.ignore();
            getline(cin, novoNome);
            cout << "Nova equipe designada: ";
            string novaEquipe;
            getline(cin, novaEquipe);
            cout << "Nova prioridade (1-5): ";
            int novaPrioridade;
            cin >> novaPrioridade;
            cout << "Novo prazo (YYYY-MM-DD): ";
            string novoPrazo;
            cin.ignore();
            getline(cin, novoPrazo);
            cout << "Novo status: ";
            string novoStatus;
            getline(cin, novoStatus);
            // Atualizando os dados da tarefa
            tarefa["nome"] = novoNome;
            tarefa["equipe"] = novaEquipe;
            tarefa["prioridade"] = novaPrioridade;
            tarefa["prazo"] = novoPrazo;
            tarefa["status"] = novoStatus;
            cout << "Tarefa atualizada com sucesso!" << endl;
            return;
        }
    }
    cout << "Tarefa não encontrada!" << endl;
}

// Função para imprimir todas as tarefas
void imprimirTarefas(json &tarefas) {
    cout << "Lista de Tarefas: " << endl;
    for (const auto& tarefa : tarefas) {
        cout << "ID: " << tarefa["id"] << ", Nome: " << tarefa["nome"]
             << ", Equipe: " << tarefa["equipe"] << ", Prioridade: " << tarefa["prioridade"]
             << ", Prazo: " << tarefa["prazo"] << ", Status: " << tarefa["status"] << endl;
    }
}

void pesquisarPorResponsavel(string &equipeResponsavel, json &equipes, json &tarefas) {
    bool encontrado = false;
    for (auto& equipe : equipes) {
        if (equipe["nome"] == equipeResponsavel) {
            encontrado = true;
            cout << "Equipe: " << equipe["nome"] << endl;

            cout << "Tarefas designadas: " << endl;
            for (auto& tarefa : tarefas) {
                if (tarefa["equipe"] == equipe["nome"]) {
                    cout << "ID: " << tarefa["id"] << ", Nome: " << tarefa["nome"]
                         << ", Status: " << tarefa["status"] << endl;
                }
            }
            break;
        }
    }
    if (!encontrado) {
        cout << "Equipe responsável não encontrada!" << endl;
    }
}


void listarTarefasPorPrioridade(int prioridade, json &tarefas) {
    cout << "Tarefas com prioridade " << prioridade << ":" << "\n";
    bool encontrado = false;
    for (auto& tarefa : tarefas) {
        if (tarefa["prioridade"] == prioridade) {
            encontrado = true;
            cout << "ID: " << tarefa["id"] << ", Nome: " << tarefa["nome"]
                 << ", Equipe: " << tarefa["equipe"] << ", Prazo: " << tarefa["prazo"]
                 << ", Status: " << tarefa["status"] << "\n";
        }
    }
    if (!encontrado) {
        cout << "Nenhuma tarefa encontrada." << endl;
    }
    
}

void modificarStatus(json &tarefas){
    cout << "Lista de Tarefas: " << endl;
    for (auto& tarefa : tarefas) {
        cout << "ID: " << tarefa["id"] << ", Nome: " << tarefa["nome"]
             << ", Equipe: " << tarefa["equipe"] << ", Prioridade: " << tarefa["prioridade"]
             << ", Prazo: " << tarefa["prazo"] << ", Status: " << tarefa["status"] << endl;
    }
    int escolha; 
    cout<<"Digite o ID da tarefa que deseja alterar o status:" << endl;
    cin >> escolha;
    for (auto& tarefa : tarefas){
        if(tarefa["id"] == escolha){
            string status;
            cout << "Digite o novo status(Completa/Incompleta):"<< endl;
            cin >> status;
            tarefa["status"] = status;
        }
    }
}
