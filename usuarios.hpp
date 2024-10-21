#ifndef USUARIOS_HPP
#define USUARIOS_HPP

#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

json criarUsuario(int id, string nome, string equipe, string funcao);
json deletarUsuario(int id, json& usuarios);
void modificarUsuario(int id, json& usuarios);
void imprimirUsuarios(const json& usuarios);

#endif