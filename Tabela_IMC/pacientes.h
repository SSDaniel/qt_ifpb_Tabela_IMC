#ifndef PACIENTES_H
#define PACIENTES_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "pessoa.h"

class Pacientes : public QObject
{
    Q_OBJECT
private:
    QVector<Pessoa> pacientes;

public:
    explicit Pacientes(QObject *parent = nullptr);
    void inserirPessoa(const Pessoa a);
    float mediaDosPacientes();
    float maiorIMC();
    float menorIMC();
    void ordenarPorNome();
    void ordenarPorIMC();
    int size();
    void clear();

    Pessoa operator[](int i);


signals:

public slots:
};

#endif // PACIENTES_H
