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
    std::string name, file;
    int choix;
    enum addAction{
        retour,
        manga,
        bd
    };
    while (choix != 0)
    {
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"-                  AJOUT                   -"<<std::endl;
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"-1)Ajouter un manga                        -"<<std::endl;
            std::cout<<"-2)Ajouter un comic                        -"<<std::endl;
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
            break;
        case bd:
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
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
            system("clear");
            break;
        case comic:
            system("clear");
            break;
        case article:
            system("clear");
            break;
        case roman:
            system("clear");
            break;
        }
    }
}

void Gestionnaire::rechercher()
{
    std::string name, file, ligne;

    std::cout<<"Affichage d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ifstream Affiche(file.c_str());
    if(Affiche)
    {
        while(getline(Affiche, ligne))    //Tant qu'on n'est pas a la fin, on lit
        {
            std::cout<<ligne<<std::endl;
        }

    }
    else
    {
        std::cout<<"ERREUR: Impossible d'afficher le fichier."<<std::endl;
    }
    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::exporter()
{
    std::string name, file, ligne, page;

    std::cout<<"Export d'un element en html:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    page = "../Pages/";
    page += name;
    page += ".html";

    std::ifstream Expor(file.c_str());
    if(Expor)
    {
        std::ofstream Ajout(page.c_str());
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
            Ajout << "<title>";
            Ajout << name <<std::endl;
            Ajout << "</title>" <<std::endl;
            Ajout << "</head>" <<std::endl;
            Ajout << "<body>" <<std::endl;
            while(getline(Expor, ligne))
            {
                Ajout << ligne <<std::endl;
            }
            Ajout << "</body>" <<std::endl;
            Ajout << "</html>" <<std::endl;
        }
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'exporter le fichier en html."<<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Gestionnaire::supprimer()
{
    std::string name, file;

    std::cout<<"Suppression du document:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du document a supprimer:";
    std::cin>>name;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    system(file.c_str());
   std::cout<<"Fichier supprimé!"<<std::endl;

   std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
   getchar();
   std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}
