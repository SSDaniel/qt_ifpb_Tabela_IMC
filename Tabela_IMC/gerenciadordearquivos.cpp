#include "gerenciadordearquivos.h"

GerenciadorDeArquivos::GerenciadorDeArquivos(){}
bool GerenciadorDeArquivos::salvarPacientes(QString &arquivo, Pacientes &pacientes)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }
    QTextStream out(&file);
    for(int i=0;i<pacientes.size();i++){
        out << pacientes[i].getNome()<<","<<pacientes[i].CalcularIMC()<<"\n";
    }
    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarPacientes(QString &arquivo, Pacientes &pacientes)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();
        QStringList dados = linha.split(",");
        Pessoa a(dados[0],dados[1].toFloat());
        pacientes.inserirPessoa(a);

    }
    return true;
}
