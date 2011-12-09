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
            std::cout<<"-3)Supprimer un document                   -"<<std::endl;
            std::cout<<"-4)Trier la liste des documents            -"<<std::endl;
            std::cout<<"-5)Rechercher un document                  -"<<std::endl;
            std::cout<<"-6)exporter la liste en version html       -"<<std::endl;
            std::cout<<"-0)Quitter                                 -"<<std::endl;
            std::cout<<"--------------------------------------------"<<std::endl;
            std::cout<<"Votre choix : ";
            std::cin>>choix;
          }while ( (choix < 0) && (choix > 6) );

        switch(choix)
        {
        case Quitter:
            break;
        case AfficherDoc:
            break;
        case AjouterDoc:
            break;
        case SupprimerDoc:
            break;
        case TrierDoc:
            break;
        case Rechercher:
            break;
        case ExportDoc:
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
            break;
        }//end switch
        system("clear");
    }//end while
}//end function
