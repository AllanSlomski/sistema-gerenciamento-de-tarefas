#ifndef EQUIPES_HPP
#define EQUIPES_HPP
#include <string>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

json criarEquipe(int &id, /*int &idTarefa, */string &nome/*, json &tarefas, json &usuarios*/);
json deletarEquipe(int &id);
void pesquisarEquipe(int &id, string &nome, json &equipes, string &parametro);
json atualizarEquipe(int &id, json &usuarios);
void imprimirEquipes(json &equipes);
bool checarEquipe(string &nome, json equipes);

#endif