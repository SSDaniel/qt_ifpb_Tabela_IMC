#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>
#include "pacientes.h"
#include "pessoa.h"

class GerenciadorDeArquivos
{
public:
    GerenciadorDeArquivos();
    static bool salvarPacientes(QString &arquivo, Pacientes &pacientes);
    static bool carregarPacientes(QString &arquivo, Pacientes &pacientes);
};

#endif // GERENCIADORDEARQUIVOS_H
