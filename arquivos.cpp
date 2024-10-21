#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include "arquivos.hpp"

using namespace std;
using json = nlohmann::json;

// Função para salvar os dados em um arquivo JSON
void salvarArquivo(string &caminho, json &dados) {
    ofstream arquivoSaida(caminho);
    if (arquivoSaida.is_open()) {
        if (caminho == "equipes.json"){
            arquivoSaida << dados.dump(2);
        }else {
            arquivoSaida << dados.dump(4);  // Salva o JSON com indentação de 4 espaços
            arquivoSaida.close();
            }
    } else {
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
    }
}

// Função para carregar os dados de um arquivo JSON
json carregarArquivo(string &caminho) {
    ifstream arquivoEntrada(caminho);
    json dados;
    if (arquivoEntrada.is_open()) {
        arquivoEntrada >> dados;
        arquivoEntrada.close();
    } else {
        cout << "Arquivo não encontrado ou erro ao abrir!" << endl;
    }
    return dados;
}