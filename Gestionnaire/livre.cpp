#include "livre.h"

Livre::Livre()
{
    std::cout<<"Veuillez entrer l'auteur : ";
    std::cin>>_author;
    std::cout<<std::endl;
}

Livre::~ Livre()
{
}

std::string Livre::getAuthor()
{
    return _author;
}

void Livre::ajouter()
{
    std::string name, author, file;

    std::cout<<"Ajout d'un livre:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du document:";
    std::cin>>name;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'auteur:";
    std::cin>>author;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ofstream Ajout(file.c_str());
    if (Ajout)
    {
        Ajout << "Titre: ";
        Ajout << name <<std::endl;
        Ajout << "Auteur: ";
        Ajout << author <<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible de créer le fichier."<<std::endl;
    }
}

void Livre::modifier()
{
    std::string name, author, file, file2;

    std::cout<<"Modification du livre:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du livre a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer le nom du livre document:";
    std::cin>>name;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'auteur:";
    std::cin>>author;
    std::cout<<std::endl;

    file = " rm ../Elements/";
    file += name;
    file += ".txt";

    file2 = "../Elements/";
    file2 += name;
    file2 += ".txt";

    system(file.c_str());
    std::ofstream Ajout(file2.c_str());
    if (Ajout)
    {
        Ajout << "Titre: ";
        Ajout << name  <<std::endl;
        Ajout << "Auteur: ";
        Ajout << author <<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible de modifier le fichier."<<std::endl;
    }
}
