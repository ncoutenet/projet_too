#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "comic.h"
#include "manga.h"
#include "article.hh"
#include "roman.hh"
#include <fstream>

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
    void _affMangas();
    void _affComics();
    void _affRomans();
    void _affArticles();
    std::vector<std::string> _listeMangas;
    std::vector<std::string> _listeComics;
    std::vector<std::string> _listeRomans;
    std::vector<std::string> _listeArticles;
};

#endif // GESTIONNAIRE_H
