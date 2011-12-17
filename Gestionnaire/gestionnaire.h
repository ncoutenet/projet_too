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
    void menuModif();
    void supprimer();
    void afficher();
    void exporter();
    void rechercher();
private:
    void _initialisation();
    void _sauvegarde();
    void _affMangas();
    void _affComics();
    void _affRomans();
    void _affArticles();
    void _majListe(std::string&);
    std::vector<std::string> _listeMangas;
    std::vector<std::string> _listeComics;
    std::vector<std::string> _listeRomans;
    std::vector<std::string> _listeArticles;
};

#endif // GESTIONNAIRE_H
