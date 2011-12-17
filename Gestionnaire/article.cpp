#include "article.hh"

Article::Article()
{
}

Article::~ Article()
{
}

std::string Article::getTheme()
{
    return _theme;
}

std::string Article::getDateParution()
{
    return _dateParution;
}

std::string Article::ajouter()
{
    std::string file;

    std::cout<<"Ajout d'un Article:"<<std::endl;

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
        Ajout << "Theme: ";
        Ajout << _theme <<std::endl;
        Ajout << "Date de parution: ";
        Ajout << _dateParution <<std::endl;
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

void Article::modifier()
{
    std::string name, author, theme, dateParution, file, file2;

    std::cout<<"Modification de l'article:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'article' a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer le nom de l'article:";
    std::cin>>name;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'auteur:";
    std::cin>>author;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer le theme:";
    std::cin>>theme;
    std::cout<<std::endl;
    std::cout<<"Veuillez entrer la date de parution:";
    std::cin>>dateParution;
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
        Ajout << "Theme: ";
        Ajout << theme <<std::endl;
        Ajout << "Date de parution: ";
        Ajout << dateParution <<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible de modifier le fichier."<<std::endl;
    }

    std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
    getchar();
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

void Article::initialisation()
{
    std::cout<<"Veuillez entrer le titre de l'article (Espaces Non Admis) : ";
    std::cin>>_title;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'auteur de l'article : ";
    std::cin>>_author;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer le theme de l'article : ";
    std::cin>>_theme;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer la date de parution : ";
    std::cin>>_dateParution;
    std::cout<<std::endl;
}
