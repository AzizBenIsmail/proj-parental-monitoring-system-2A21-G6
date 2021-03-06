#ifndef ANIMAL_H
#define ANIMAL_H
#include "anim.h"
#include "fiche_animal.h"
#include <QDialog>

namespace Ui {
class Animal;
}

class Animal : public QDialog
{
    Q_OBJECT

public:
    explicit Animal(QWidget *parent = nullptr);
    ~Animal();

private slots:
    void on_pushButton_R_clicked();

    void on_pushButton_Q_clicked();

    void on_Ajouter_FICHE_clicked();

    void on_Supprimer_fiche_clicked();

    void on_PDF_clicked();

    void on_Supprimer_clicked();

    void on_Afficher_clicked();

    void on_Tr_Animal_clicked();

    void on_Ajouter_clicked();

    void on_txt_recherche_animal_textChanged(const QString &arg1);

    void on_Afficher_Fiche_clicked();

    void on_pushButton_im_clicked();

    void on_pushButton_clicked();
    //history




    void addToHistory(QString action,QString type,QString id);

    void on_pushButton_2_clicked();

    QSqlQueryModel * afficherHistorique();
    bool historyDelete();





    void on_comboBox_activated(const QString &arg1);


    //void on_comboBox_activated(const QString &arg1);




    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_comboBox_2_activated(const QString &arg1);

private:
    Ui::Animal *ui;
    Anim a;
    Fiche_animal b;
};

#endif // ANIMAL_H
