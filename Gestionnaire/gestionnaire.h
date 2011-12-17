#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "comic.h" ///for including comic's class
#include "manga.h" ///for including manga's class
#include "article.hh" ///for including article's class
#include "roman.hh" ///for including novel's class

///class Gestionnaire is used for managing all the documents

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
    void menuTrier();
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
    void _sortTitle();
    void _sortAuthors();
    std::vector<std::string> _initAuthors(char);
    std::vector<std::string> _listeMangas;
    std::vector<std::string> _listeComics;
    std::vector<std::string> _listeRomans;
    std::vector<std::string> _listeArticles;
};

#endif // GESTIONNAIRE_H
