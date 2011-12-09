#include "gestionnaire.h"
#include <cstdlib>
#include "objet.hh"

Gestionnaire::Gestionnaire()
{
}

Gestionnaire::~Gestionnaire()
{
}

void Gestionnaire::afficheMenu()
{
    Objet objet;
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
            objet.afficher();
            break;
        case AjouterDoc:
            objet.ajouter();
            break;
        case ModifierDoc:
            objet.modifier();
            break;
        case SupprimerDoc:
            objet.supprimer();
            break;
        case TrierDoc:
            break;
        case Rechercher:
            break;
        case ExportDoc:
            objet.exporter();
            break;
        default:
            std::cout<<"Erreur de saisie, veuillez taper la position de l'action à réaliser."<<std::endl;
            break;
        }//end switch
        system("clear");
    }//end while
}//end function
