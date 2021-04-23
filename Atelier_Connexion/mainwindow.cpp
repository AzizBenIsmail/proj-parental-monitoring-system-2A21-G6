#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0,9999999,this));
    ui->tableView_aff->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{ int id=ui->id->text().toInt();
    QString nom=ui->Nom->text();
    QString prenom=ui->prenom->text();
    Etudiant E(id,nom,prenom);
    bool test=E.Ajouter();
  if(test)
   {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                 QObject::tr("ajout successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tableView_aff->setModel(E.afficher());

             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                 QObject::tr("ajout failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_S_clicked()
{
    Etudiant e1;
    e1.setid(ui->lineEdit_idS->text().toInt());
    bool test;
    test=e1.Supprime(e1.getid());
    if(test)
     {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                   QObject::tr("sup successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
ui->tableView_aff->setModel(e1.afficher());
               }
                   else
                       QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                   QObject::tr("sup failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_Modifier_clicked()
{
    Etudiant e1;
    e1.setid(ui->id_modifier->text().toInt());
    int id=ui->id->text().toInt();
    QString nom=ui->Nom->text();
    QString prenom=ui->prenom->text();
    Etudiant e(id,nom,prenom);
    bool test=e1.modifier(e1.getid());
      if(test)
       {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                     QObject::tr("ajout successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView_aff->setModel(e.afficher());

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                     QObject::tr("ajout failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
