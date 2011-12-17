#include "manga.h"

Manga::Manga()
{
}

Manga::~Manga()
{
}

std::string Manga::getType()
{
    return _type;
}

std::string Manga::ajouter()
{
    std::string file;
    std::cout<<"Ajout du manga:"<<std::endl;

    file = "../Elements/";
    file += _title;
    file += ".txt";

    std::ofstream Ajout(file.c_str());
    if (Ajout)
    {
        Ajout << "Titre: ";
        Ajout << _title <<std::endl;
        Ajout << "Auteur: ";
        Ajout << _author <<std::endl;
        Ajout << "Editeur: ";
        Ajout << _editor<<std::endl;
        Ajout << "Type: ";
        Ajout << _type <<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible de créer le fichier."<<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');

    return _title;
}

void Manga::modifier()
{
    std::string name, author, editor, type,  file, file2;

    std::cout<<"Modification du manga:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du manga a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer le nom du manga:";
    std::cin>>name;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'auteur:";
    std::cin>>author;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'editeur:";
    std::cin>>editor;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le type du manga:";
    std::cin>>type;
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
        Ajout << "Editeur: ";
        Ajout << editor <<std::endl;
        Ajout << "Type: ";
        Ajout << type <<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible de modifier le fichier."<<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Manga::initialisation()
{
    std::cout<<"Veuillez entrer le titre du manga (Espaces Non Admis) : ";
    std::cin>>_title;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'auteur du manga : ";
    std::cin>>_author;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'éditeur du manga : ";
    std::cin>>_editor;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer le type du manga : ";
    std::cin>>_type;
    std::cout<<std::endl;
}
