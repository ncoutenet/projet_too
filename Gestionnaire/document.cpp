#include "document.h"

Document::Document()
{
    std::cout<<"Veuillez entrer le titre du document: ";
    std::cin>> _title;
    std::cout<<std::endl;
}

Document::~Document()
{
}

std::string Document::getTitle()
{
 return _title;
}

void Document::ajouter()
{
    std::string name, file;

    std::cout<<"Ajout d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du document:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ofstream Ajout(file.c_str());
    if (Ajout)
    {
        Ajout << "Titre: ";
        Ajout << name  <<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible de créer le fichier."<<std::endl;
    }
}

void Document::modifier()
{
    std::string name, file, file2;

    std::cout<<"Modification du document:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du document a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer le nom du nouveau document:";
    std::cin>>name;
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
    }
    else
    {
        std::cout<<"ERREUR: Impossible de modifier le fichier."<<std::endl;
    }
}
