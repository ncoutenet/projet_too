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
          do{
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
          }while ( (choix < 0) && (choix > 7) );

        switch(choix)
        {
        case Quitter:
            break;
        case AfficherDoc:
            afficher();
            break;
        case AjouterDoc:
            ajouter();
            break;
        case ModifierDoc:
            modifier();
            break;
        case SupprimerDoc:
            supprimer();
            break;
        case TrierDoc:
            break;
        case Rechercher:
            break;
        case ExportDoc:
            exporter();
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
            break;
        }
        system("clear");
    }
}

void Gestionnaire::ajouter()
{
    std::string name, file;

    std::cout<<"Ajout d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ofstream Ajout(file.c_str());
    if (Ajout)
    {
        Ajout << name  <<std::endl;
    }
}

void Gestionnaire::supprimer()
{
    std::string name, file;

    std::cout<<"Suppression d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    system(file.c_str());
}

void Gestionnaire::modifier()
{
    std::string name, file, file2;

    std::cout<<"Modification d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    std::cout<<"Veuillez entrer le nom du nouveau element:";
    std::cin>>name;
    std::cout<<std::endl;

    file2 = "../Elements/";
    file2 += name;
    file2 += ".txt";

    system(file.c_str());
    std::ofstream Ajout(file2.c_str());
    if (Ajout)
    {
        Ajout << name  <<std::endl;
    }
}

void Gestionnaire::afficher()
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
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier en lecture."<<std::endl;
    }

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
            Ajout << "<title>Objet</title>" <<std::endl;
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
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier en lecture."<<std::endl;
    }
}

