#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
using namespace std;
using json = nlohmann::json;

// dar um jeito de adicionar os usuarios à equipe no json

json criarEquipe(int &id, /*int &idTarefa,*/ string &nome /*json &tarefas, json &usuarios*/){
    json equipe;
    //tarefas = json::array();
    //usuarios = json::array();
    equipe["id"] = id;
    equipe["nome"] = nome;
    //equipe["tarefas"] = tarefas[idTarefa];
    return equipe;
}

json deletarEquipe(int &id, json &equipes){
    json equipesAtualizadas = json::array();
    for (auto &equipe : equipes){
        if (equipe["id"] != id){
            equipesAtualizadas.push_back(equipe);
        }
    }
    return equipesAtualizadas;
}

void pesquisarEquipe(int &id, string &nome, json &equipes, string &parametro){
    bool encontrado = false;
    cout<<"Digite o nome ou id da equipe que deseja pesquisar: ";
    cin >> parametro;
    json equipePesquisada = json::array(); 
    for(auto &equipe : equipes){
        if(equipe["id"] == stoi(parametro) || equipe["nome"] == parametro){
            cout << "Id: " << equipe["id"] << endl 
                 << "Nome: " << equipe["nome"] << endl
                 << "integrantes: " << equipe["usuarios"] << endl;
        } else{
            cout<< "Equipe não encontrada, por favor verifique o nome ou id!";
        }
    }
}

void imprimirEquipes(json &equipes){
    cout << "Lista de equipes: " << endl;
    for (auto &equipe : equipes){
        cout << "Id: " << equipe["id"] << endl 
             << "Nome: " << equipe["nome"] << endl
             << "integrantes: " << equipe["usuarios"] << endl;
    }
}

bool checarEquipe(string &nome, json &equipes){
    bool encontrado = false;
    for (auto &equipe : equipes){
        if (nome == equipe["nome"]){
            encontrado = true;
        }
    }
    return encontrado;
}