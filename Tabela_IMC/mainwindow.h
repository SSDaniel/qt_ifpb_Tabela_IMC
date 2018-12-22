#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include "gerenciadordearquivos.h"
#include "pessoa.h"
#include "pacientes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Pacientes lista;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();
    void on_btn_NameSort_clicked();
    void on_btn_GradeSort_clicked();
    void salvar();
    void carregar();

private:
    Ui::MainWindow *ui;
    void inserirPessoaNaTabela(Pessoa pessoa, int row);
};

#endif // MAINWINDOW_H
