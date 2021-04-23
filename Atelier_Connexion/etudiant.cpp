#include "etudiant.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>
Etudiant::Etudiant()
{
id=0;
nom="";
prenom="";
}
Etudiant::Etudiant(int id,QString nom,QString prenom)
{
    this->id=id; this->nom=nom;
    this->prenom=prenom;
}
int Etudiant::getid()
{
    return id;
}
QString Etudiant:: getnom()
{
    return nom;
}
QString Etudiant::getprenom()
{
    return prenom;
}
void Etudiant::setid(int id)
{
    this->id=id;
}
void Etudiant::setnom(QString nom)
{
    this->nom=nom;
}
void Etudiant::setprenom(QString prenom)
{
    this->prenom=prenom;

}
 bool Etudiant::Ajouter()
 {

     QSqlQuery query;
     QString id_string=QString::number(id);
          query.prepare("INSERT INTO etudiant (id,nom, prenom) "
                        "VALUES (:id,:forename,:surname)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename",nom);
          query.bindValue(":surname", prenom);
       return query.exec();

 }
 bool Etudiant::modifier(int id)
 {
     QSqlQuery query;
          query.prepare("INSERT INTO etudiant (nom, prenom where id=:id) "
                        "VALUES (:forename,:surname)");
          //query.bindValue(":forename",nom);
          //query.bindValue(":surname", prenom);
       return query.exec();
 }
 QSqlQueryModel *Etudiant::afficher()
 {
   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM etudiant");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifain"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         return model;
 }
bool Etudiant::Supprime(int id)
{
    QSqlQuery query;
         query.prepare("delete from etudiant where id=:id");
         query.bindValue(0, id);
      return query.exec();
}
