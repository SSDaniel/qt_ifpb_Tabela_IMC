#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalvar,SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));

}

MainWindow::~MainWindow(){delete ui;}

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_avg->setText(QString::number(lista.mediaDosPacientes(),'f',2));
    ui->lbl_highest->setText(QString::number(lista.maiorIMC(),'f',2));
    ui->lbl_lowest->setText(QString::number(lista.menorIMC(),'f',2));
    if(lista.mediaDosPacientes()<18.5 || lista.mediaDosPacientes()>30){QString color = "green";ui->lbl_avg->setStyleSheet("color: "+color);};
}

void MainWindow::inserirPessoaNaTabela(Pessoa pessoa, int row)
{
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(pessoa.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(pessoa.CalcularIMC())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(pessoa.getStatus()));
}

void MainWindow::salvar()
{

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Pessoas","","DadosIMC(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( GerenciadorDeArquivos::salvarPacientes(nomeArquivo,lista) ){
        QMessageBox::information(this, "Salvar pacientes","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar pacientes","Não foi possível salvar os dados");
    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Pessoas","","DadosIMC(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    lista.clear();

    if(GerenciadorDeArquivos::carregarPacientes(nomeArquivo,lista)){

        ui->tbl_data->clearContents();
        for(int i=0;i<lista.size();i++){

            if(i >= ui->tbl_data->rowCount())
                ui->tbl_data->insertRow(i);

            inserirPessoaNaTabela(lista[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar pacientes","Não foi possível carregar os dados");
    }

}

void MainWindow::on_btn_insert_clicked()
{

    if(ui->le_nameInput->text().size() != 0 && ui->le_avgInput->text().size() != 0 && ui->lineEdit_peso->text().size() != 0){
        Pessoa pessoa;
        pessoa.setNome(ui->le_nameInput->text().toUpper());
        pessoa.setaltura(ui->le_avgInput->text().toFloat());
        pessoa.setpeso(ui->lineEdit_peso ->text().toFloat());

        int qnt_row = ui->tbl_data->rowCount();

        ui->tbl_data->insertRow(qnt_row);
        inserirPessoaNaTabela(pessoa, qnt_row);

        ui->le_nameInput->clear();
        ui->le_avgInput->clear();
        ui->lineEdit_peso->clear();

        lista.inserirPessoa(pessoa);
        atualizarEstatisticas();
    }
}

void MainWindow::on_btn_NameSort_clicked()
{
    ui->tbl_data->clearContents();

    lista.ordenarPorNome();
    for(int i = 0; i<lista.size(); i++){
        inserirPessoaNaTabela(lista[i], i);
    }
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_data->clearContents();
    lista.ordenarPorIMC();
    for(int i = 0; i<lista.size();i++){
        inserirPessoaNaTabela(lista[i],i);
    }
}


