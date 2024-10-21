#ifndef TAREFAS_HPP
#define TAREFAS_HPP

#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

json criarTarefa(int id, string nome, string equipe, int prioridade, string prazo, string status); 
json deletarTarefa(int id, json& tarefas);
void modificarTarefa(int id, json& tarefas); 
void imprimirTarefas(const json& tarefas); 
void pesquisarPorResponsavel(string &equipeResponsavel, json &equipes, json &tarefas);
void listarTarefasPorPrioridade(int prioridade, json &tarefas);
void modificarStatus(json &tarefas);
#endif