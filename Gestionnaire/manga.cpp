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

std::string Manga::modifier()
{
    int i=0;
    char choix;
    std::string name, file, suppr,  buffer;

    std::cout<<"Modification du manga:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du manga a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    std::ifstream lecture(file.c_str());
    if (lecture)
    {
        lecture >> buffer;        lecture >> _title;
        lecture >> buffer;        lecture >> _author;
        lecture >> buffer;        lecture >> _editor;
        lecture >> buffer;        lecture >> _type;
        lecture.seekg(0, std::ios::beg);

        while (i<4)
        {
            getline(lecture, buffer);
            do
            {
                std::cout<< buffer <<std::endl;
                std::cout<< "Voulez-vous modifier cette ligne? [y/n]" <<std::endl;
                std::cin>>choix;
            } while( (choix != 'y') && (choix != 'Y') && (choix != 'n') && (choix != 'N') );
            if ( (choix == 'y') || (choix == 'Y') )
            {
                std::cout<< "Veuillez entrer la nouvelle donnée:" <<std::endl;
                std::cin>>buffer;
                suppr = "rm ";
                suppr += file;
                system(suppr.c_str());
                if (i == 0)
                    _title = buffer;
                if (i == 1)
                    _author = buffer;
                if (i == 2)
                    _editor = buffer;
                if (i == 3)
                    _type = buffer;
            }
            i++;
        }
        ajouter();
    }
    else
    {
        std::cout<<"ERREUR: Impossible de modifier le fichier."<<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');

    return name;
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
