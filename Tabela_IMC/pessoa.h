#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

class Pessoa
{

private:
    QString nome;
    float imc,altura,peso;
    bool status;

public:
    explicit Pessoa();
    Pessoa(QString n, float m);
    QString getNome() const;
    float getpeso() const;
    void setpeso(float value);
    float CalcularIMC() const;
    QString getStatus() const;
    void setNome(const QString &value);
    float getaltura() const;
    void setaltura(float value);
signals:

public slots:
};

#endif // ALUNO_H
