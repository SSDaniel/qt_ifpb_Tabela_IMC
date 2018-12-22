#include "pessoa.h"

QString Pessoa::getNome() const{return nome;}

float Pessoa::getpeso() const{return peso;}

void Pessoa::setpeso(float value){peso = value;}

void Pessoa::setNome(const QString &value){nome = value;}

float Pessoa::getaltura() const{return altura;}

void Pessoa::setaltura(float value){altura = value;}

float Pessoa::CalcularIMC() const
{
    return peso/(altura*altura);
}

QString Pessoa::getStatus() const
{
    if(CalcularIMC()<18.5){return "Baixo Peso";}
    if(18.5<CalcularIMC()&& CalcularIMC()<25){return "Peso Adequado";}
    if(25<CalcularIMC() && CalcularIMC()<30){return "Sobrepeso";}
    if(CalcularIMC()>30){return "Obesidade";}
}

Pessoa::Pessoa(){}

Pessoa::Pessoa(QString n, float m)
{
    nome = n;
    imc = CalcularIMC();

}
