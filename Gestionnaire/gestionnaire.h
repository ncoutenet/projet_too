#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "comic.h"
#include "manga.h"
#include "article.hh"
#include "roman.hh"

class Gestionnaire
{
public:
    Gestionnaire();
    ~Gestionnaire();
    void afficheMenu();
    void menuAjouter();
    void supprimer();
    void afficher();
    void exporter();
    void rechercher();
private:
    std::vector<Document> _listeDoc;
};

#endif // GESTIONNAIRE_H
