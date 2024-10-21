#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void salvarArquivo(string &caminho, const json &dados);
json carregarArquivo(string &caminho);

#endif