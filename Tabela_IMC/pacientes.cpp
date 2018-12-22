#include "pacientes.h"

Pacientes::Pacientes(QObject *parent) : QObject(parent){}

void Pacientes::inserirPessoa(const Pessoa a){pacientes.push_back(a);}

int Pacientes::size(){return pacientes.size();}

void Pacientes::clear(){pacientes.clear();}

Pessoa Pacientes::operator[](int i){return pacientes[i];}

float Pacientes::mediaDosPacientes()
{
    return std::accumulate(pacientes.begin(),pacientes.end(),0.0, [](float acc, Pessoa a){return acc+=a.CalcularIMC();})/pacientes.size();
}

float Pacientes::maiorIMC()
{
Pessoa *maior = std::max_element(pacientes.begin(),pacientes.end(),[](Pessoa a, Pessoa b){ return a.CalcularIMC() < b.CalcularIMC();});
    return maior->CalcularIMC();
}

float Pacientes::menorIMC()
{
    Pessoa *menor = std::min_element(pacientes.begin(),pacientes.end(),[](Pessoa a, Pessoa b){return a.CalcularIMC() < b.CalcularIMC();});
    return menor->CalcularIMC();
}

void Pacientes::ordenarPorNome()
{
    std::sort(pacientes.begin(), pacientes.end(), [](Pessoa a, Pessoa b){return a.getNome()<b.getNome();});
}

void Pacientes::ordenarPorIMC()
{
    ordenarPorNome();
    std::stable_sort(pacientes.begin(),pacientes.end(),[](Pessoa a, Pessoa b){return a.CalcularIMC()<b.CalcularIMC();});
}

