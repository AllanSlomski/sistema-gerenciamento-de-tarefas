#include <iostream>
#include <nlohmann/json.hpp>
#include "usuarios.hpp"

using namespace std;
using json = nlohmann::json;

// Função para criar um novo usuário
json criarUsuario(int id, string nome, string equipe, string funcao) {
    json usuario;
    usuario["id"] = id;
    usuario["nome"] = nome;
    usuario["equipe"] = equipe;
    usuario["funcao"] = funcao;
    return usuario;
}

// Função para deletar um usuário pelo ID
json deletarUsuario(int id, json& usuarios) {
    json usuariosAtualizados = json::array();
    for (auto& usuario : usuarios) {
        if (usuario["id"] != id) {
            usuariosAtualizados.push_back(usuario);  // Mantém os outros usuários
        }
    }
    return usuariosAtualizados;
}

// Função para modificar um usuário
void modificarUsuario(int id, json& usuarios) {
    for (auto& usuario : usuarios) {
        if (usuario["id"] == id) {
            cout << "Novo nome: ";
            string novoNome;
            cin.ignore();
            getline(cin, novoNome);
            cout << "Nova equipe: ";
            string novaEquipe;
            getline(cin, novaEquipe);
            cout << "Nova função: ";
            string novaFuncao;
            getline(cin, novaFuncao);
            // Atualizando os dados do usuário
            usuario["nome"] = novoNome;
            usuario["equipe"] = novaEquipe;
            usuario["funcao"] = novaFuncao;
            cout << "Usuário atualizado com sucesso!" << endl;
            return;
        }
    }
    cout << "Usuário não encontrado!" << endl;
}

// Função para imprimir todos os usuários
void imprimirUsuarios(const json& usuarios) {
    cout << "Lista de Usuários: " << endl;
    for (const auto& usuario : usuarios) {
        cout << "ID: " << usuario["id"] << ", Nome: " << usuario["nome"]
             << ", Equipe: " << usuario["equipe"] << ", Função: " << usuario["funcao"] << endl;
    }
}
