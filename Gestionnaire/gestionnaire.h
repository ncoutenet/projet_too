#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "document.h"

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
private:
    std::vector<Document> _listeDoc;
};

#endif // GESTIONNAIRE_H
