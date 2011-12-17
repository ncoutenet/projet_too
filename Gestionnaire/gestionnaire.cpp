#include "gestionnaire.h"
#include <cstdlib>

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
}

void Gestionnaire::afficheMenu()
{
    int choix;
    enum LibraryAction{
        Quitter,
        AfficherDoc,
        AjouterDoc,
        ModifierDoc,
        SupprimerDoc,
        TrierDoc,
        Rechercher,
        ExportDoc
    };

    _initialisation();
    while (choix != 0)
    {
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"-                  MENU                    -"<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"-1)Afficher les documents                  -"<<std::endl;
        std::cout<<"-2)Ajouter un document                     -"<<std::endl;
        std::cout<<"-3)Modifier un document                    -"<<std::endl;
        std::cout<<"-4)Supprimer un document                   -"<<std::endl;
        std::cout<<"-5)Trier la liste des documents            -"<<std::endl;
        std::cout<<"-6)Rechercher un document                  -"<<std::endl;
        std::cout<<"-7)exporter la liste en version html       -"<<std::endl;
        std::cout<<"-0)Quitter                                 -"<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"Votre choix : ";
        std::cin>>choix;
        std::cout<<std::endl;

        switch(choix)
        {
        case Quitter:
            _sauvegarde();
            break;
        case AfficherDoc:
            system("clear");
            afficher();
            break;
        case AjouterDoc:
            system("clear");
            menuAjouter();
            break;
        case ModifierDoc:
            system("clear");
            menuModif();
            break;
        case SupprimerDoc:
            system("clear");
            supprimer();
            break;
        case TrierDoc:
            system("clear");
            break;
        case Rechercher:
            system("clear");
            rechercher();
            break;
        case ExportDoc:
            system("clear");
            exporter();
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        }
        system("clear");
    }
}

void Gestionnaire::menuAjouter()
{
    Manga myManga;
    Comic myComic;
    Article myArticle;
    Roman myRoman;

    int choix=-4;
    enum addAction{
        retour,
        manga,
        comic,
        roman,
        article
    };
    while (choix != 0)
    {
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"-                  AJOUT                   -"<<std::endl;
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"-1)Ajouter un manga                        -"<<std::endl;
            std::cout<<"-2)Ajouter un comic                        -"<<std::endl;
            std::cout<<"-3)Ajouter un roman                        -"<<std::endl;
            std::cout<<"-4)Ajouter un article                      -"<<std::endl;
            std::cout<<"-0)Retour                                  -"<<std::endl;
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"Votre choix : ";
            std::cin>>choix;
            std::cout<<std::endl;

        switch(choix)
        {
        case retour:
            break;
        case manga:
            myManga.initialisation();
            _listeMangas.push_back(myManga.ajouter());
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        case comic:
            myComic.initialisation();
            _listeComics.push_back(myComic.ajouter());
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        case roman:
            myRoman.initialisation();
            _listeRomans.push_back(myRoman.ajouter());
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        case article:
            myArticle.initialisation();
            _listeArticles.push_back(myArticle.ajouter());
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        }
    }
}

void Gestionnaire::afficher()
{
    int choix;
    enum displayChoice
    {
        retour,
        manga,
        comic,
        article,
        roman
    };

    while (choix != 0)
    {
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"-                 AFFICHER                 -"<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"-1)Manga                                   -"<<std::endl;
        std::cout<<"-2)Comic                                   -"<<std::endl;
        std::cout<<"-3)Article                                 -"<<std::endl;
        std::cout<<"-4)Roman                                   -"<<std::endl;
        std::cout<<"-0)Retour                                  -"<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"Votre choix : ";
        std::cin>>choix;
        std::cout<<std::endl;

        switch (choix)
        {
        case retour:
            system("clear");
            break;
        case manga:
            _affMangas();
            system("clear");
            break;
        case comic:
            _affComics();
            system("clear");
            break;
        case article:
            _affArticles();
            system("clear");
            break;
        case roman:
            _affRomans();
            system("clear");
            break;
        }
    }
}

void Gestionnaire::_initialisation()
{
    std::string ligne;
    std::ifstream manga("../Sources/listMangas.txt");
    if (manga)
    {
        while(getline(manga, ligne))
        {
            _listeMangas.push_back(ligne);
        }
    }
    else
    {
        std::cout<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    manga.close();

    std::ifstream comic("../Sources/listComics.txt");
    if (comic)
    {
        while(getline(comic, ligne))
        {
            _listeComics.push_back(ligne);
        }
    }
    else
    {
        std::cout<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    comic.close();

    std::ifstream roman("../Sources/listRomans.txt");
    if (roman)
    {
        while(getline(roman, ligne))
        {
            _listeRomans.push_back(ligne);
        }
    }
    else
    {
        std::cout<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    roman.close();

    std::ifstream article("../Sources/listComics.txt");
    if (article)
    {
        while(getline(article, ligne))
        {
            _listeArticles.push_back(ligne);
        }
    }
    else
    {
        std::cout<<"Erreur: impossible d'ouvrir le fichier source!"<<std::endl;
    }
    article.close();
}

void Gestionnaire::_affMangas()
{
    std::string affiche, ligne;
    unsigned int i;
    for (i = 0; i < _listeMangas.size(); i++)
    {
        affiche = "../Elements/";
        affiche += _listeMangas.at(i);
        affiche += ".txt";
        std::ifstream lecture(affiche.c_str());

        if(lecture)
        {
            while(getline(lecture, ligne))
            {
                std::cout<<ligne<<std::endl;
            }
        }
        else
        {
            std::cout<<"Erreur: impossible d'ouvrir le fichier!"<<std::endl;
        }
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::_affComics()
{
    std::string affiche, ligne;
    unsigned int i;
    for (i = 0; i < _listeComics.size(); i++)
    {
        affiche = "../Elements/";
        affiche += _listeComics.at(i);
        affiche += ".txt";
        std::ifstream lecture(affiche.c_str());

        if (lecture)
        {
            while (getline(lecture, ligne))
            {
                std::cout<<ligne<<std::endl;
            }
        }
        else
        {
            std::cout<<"Erreur: impossible d'ouvrir le fichier!"<<std::endl;
        }
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::_affRomans()
{
    std::string affiche, ligne;
    unsigned int i;
    for (i = 0; i < _listeRomans.size(); i++)
    {
        affiche = "../Elements/";
        affiche += _listeRomans.at(i);
        affiche += ".txt";
        std::ifstream lecture(affiche.c_str());

        if (lecture)
        {
            while (getline(lecture, ligne))
            {
                std::cout<<ligne<<std::endl;
            }
        }
        else
        {
            std::cout<<"Erreur: impossible d'ouvrir le fichier!"<<std::endl;
        }
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::_affArticles()
{
    std::string affiche, ligne;
    unsigned int i;
    for (i = 0; i < _listeArticles.size(); i++)
    {
        affiche = "../Elements/";
        affiche += _listeArticles.at(i);
        affiche += ".txt";
        std::ifstream lecture(affiche.c_str());

        if (lecture)
        {
            while (getline(lecture, ligne))
            {
                std::cout<<ligne<<std::endl;
            }
        }
        else
        {
            std::cout<<"Erreur: impossible d'ouvrir le fichier!"<<std::endl;
        }
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::rechercher()
{
    std::string name, categ;
    bool trouve = false;
    unsigned int i = 0;

    std::cout<<"Recherche d'un document:"<<std::endl;
    std::cout<<"Veuilleez entrer le titre du document à rechercher : ";
    std::cin>>name;
    std::cout<<std::endl;

    while ( (i < _listeMangas.size()) && (!trouve) )
    {
        if (_listeMangas.at(i) == name)
        {
            trouve = true;
            categ = "Manga";
        }
        else
        {
            i++;
        }
    }

    if (!trouve)
    {
        i = 0;
    }

    while ( (i < _listeComics.size()) && (!trouve) )
    {
        if (_listeComics.at(i) == name)
        {
            trouve = true;
            categ = "Comic";
        }
        else
        {
            i++;
        }
    }

    if (!trouve)
    {
        i = 0;
    }

    while ( (i < _listeRomans.size()) && (!trouve) )
    {
        if (_listeRomans.at(i) == name)
        {
            trouve = true;
            categ = "Roman";
        }
        else
        {
            i++;
        }
    }

    if (!trouve)
    {
        i = 0;
    }

    while ( (i < _listeArticles.size()) && (!trouve) )
    {
        if (_listeArticles.at(i) == name)
        {
            trouve = true;
            categ = "Article";
        }
        else
        {
            i++;
        }
    }

    if (trouve)
    {
        std::cout<<"Le document intitulé "<<name<<" a été trouvé!"<<std::endl;
        std::cout<<"C'est un "<<categ<<"."<<std::endl;
    }
    else
    {
        std::cout<<"Le document intitulé "<<name<<" est introuvable!"<<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::exporter()
{
    std::string ligne;
    std::cout<<"Export en html:"<<std::endl;
    std::ofstream Ajout("../Pages/Liste_des_documents.html");
    if (Ajout)
    {
        Ajout << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" <<std::endl;
        Ajout << "    \"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" <<std::endl;
        Ajout << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"fr\">" <<std::endl;
        Ajout << "<head>" <<std::endl;
        Ajout << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />" <<std::endl;
        Ajout << "<meta name=\"description\" content=\"Objet\" />" <<std::endl;
        Ajout << "<meta name=\"keywords\" content=\"xhtml,internet,too\" />" <<std::endl;
        Ajout << "<meta name=\"author\" content=\"none\" />" <<std::endl;
        Ajout << "<title>Liste des éléments:</title>" <<std::endl;
        Ajout << "</head>" <<std::endl;
        Ajout << "<body>" <<std::endl;
        Ajout << "<h1> Mangas: <br/>" <<std::endl;
        std::ifstream manga("../Sources/listMangas.txt");
        while(getline(manga, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "<h1> Comics: <br/>" <<std::endl;
        std::ifstream comic("../Sources/listComics.txt");
        while(getline(comic, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "<h1> Romans: <br/>" <<std::endl;
        std::ifstream roman("../Sources/listRomans.txt");
        while(getline(roman, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "<h1> Articles: <br/>" <<std::endl;
        std::ifstream article("../Sources/listArticles.txt");
        while(getline(article, ligne))
        {
            Ajout << ligne <<std::endl;
            Ajout << "<br/>" <<std::endl;
        }
        Ajout << "</body>" <<std::endl;
        Ajout << "</html>" <<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::supprimer()
{
    std::string name, file;

    std::cout<<"Suppression d'un document:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du document à supprimer:";
    std::cin>>name;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    _majListe(name);

    system(file.c_str());
   std::cout<<"Fichier supprimé!"<<std::endl;

   std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
   getchar();
   std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::_majListe(std::string& n)
{
    unsigned int i = 0;
    bool trouve = false;
    while ( (i < _listeMangas.size()) && (!trouve) )
    {
        if (n == _listeMangas.at(i))
        {
            trouve = true;
            _listeMangas.erase(_listeMangas.begin()+i);
        }
        else
        {
            i++;
        }
    }

    i = 0;
    while ( (i < _listeComics.size()) && (!trouve) )
    {
        if (n == _listeComics.at(i))
        {
            trouve = true;
            _listeComics.erase(_listeComics.begin()+i);
        }
        else
        {
            i++;
        }
    }

    i = 0;
    while ( (i < _listeRomans.size()) && (!trouve) )
    {
        if (n == _listeRomans.at(i))
        {
            trouve = true;
            _listeRomans.erase(_listeRomans.begin()+i);
        }
        else
        {
            i++;
        }
    }

    i = 0;
    while ( (i < _listeArticles.size()) && (!trouve) )
    {
        if (n == _listeArticles.at(i))
        {
            trouve = true;
            _listeArticles.erase(_listeArticles.begin()+i);
        }
        else
        {
            i++;
        }
    }
}

void Gestionnaire::_sauvegarde()
{
    unsigned int i;
    std::string ligne;
    std::ofstream fichier("../Sources/listArticles.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listeArticles.size(); i++)
        {
            ligne = _listeArticles.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cout<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }

    fichier.open("../Sources/listRomans.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listeRomans.size(); i++)
        {
            ligne = _listeRomans.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cout<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }

    fichier.open("../Sources/listComics.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listeComics.size(); i++)
        {
            ligne = _listeComics.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cout<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }

    fichier.open("../Sources/listMangas.txt", std::ios::out | std::ios::trunc);
    if (fichier)
    {
        for (i = 0; i < _listeMangas.size(); i++)
        {
            ligne = _listeMangas.at(i);
            fichier << ligne << std::endl;
        }
        fichier.close();
    }
    else
    {
        std::cout<<"Erreur! Impossible d'ouvrir le fichier!"<<std::endl;
    }
}

void Gestionnaire::menuModif()
{
    Manga myManga;
    Comic myComic;
    Roman myRoman;
    Article myArticle;
    int choix = -1;
    std::string old;

    enum modifAction{
        retour,
        manga,
        comic,
        roman,
        article
    };

    while (choix != 0)
    {
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"-                  MODIFIER                -"<<std::endl;
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"-1)Modifier un manga                       -"<<std::endl;
            std::cout<<"-2)Modifier un comic                       -"<<std::endl;
            std::cout<<"-3)Modifier un roman                       -"<<std::endl;
            std::cout<<"-4)Modifier un article                     -"<<std::endl;
            std::cout<<"-0)Retour                                  -"<<std::endl;
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"Votre choix : ";
            std::cin>>choix;
            std::cout<<std::endl;

        switch(choix)
        {
        case retour:
            break;
        case manga:
            old = myManga.modifier();
            _listeMangas.push_back(myManga.getTitle());
            _majListe(old);
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        case comic:
            old = myComic.modifier();
            _listeComics.push_back(myComic.getTitle());
            _majListe(old);
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        case roman:
            old = myRoman.modifier();
            _listeRomans.push_back(myRoman.getTitle());
            _majListe(old);
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        case article:
            old = myArticle.modifier();
            _listeArticles.push_back(myArticle.getTitle());
            _majListe(old);
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
            std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
            getchar();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        }
    }
}

void Gestionnaire::menuTrier()
{
    int choix = -1;

    enum sortAction{
        Retour,
        Title,
        Author
    };

    while (choix != 0)
    {
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"-                   TRI                    -"<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"-1)Tri par titre                           -"<<std::endl;
        std::cout<<"-2)Tri par auteur                          -"<<std::endl;
        std::cout<<"-0)Retour                                  -"<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"Veuillez entrer votre choix : ";
        std::cin>>choix;
        std::cout<<std::endl;

        switch(choix)
        {
            case Retour:
                system("clear");
                break;
            case Title:
                system("clear");
                _sortTitle();
                break;
            case Author:
                system("clear");
                _sortAuthors();
                break;
            default:
                std::cout<<"Erreur de saisie!!!"<<std::endl;
                std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
                getchar();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                break;
        }
    }
}

void Gestionnaire::_sortTitle()
{

}

void Gestionnaire::_sortAuthors()
{

}
