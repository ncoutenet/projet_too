#include "article.hh"

Article::Article()
{
}

Article::~ Article()
{
}

///function getTheme() for having theme who is protected
std::string Article::getTheme()
{
    return _theme;
}

///function getDateParution() for having theme who is protected
std::string Article::getDateParution()
{
    return _dateParution;
}

///function ajouter() for adding a new Article
std::string Article::ajouter()
{
    std::string file;

    std::cout<<"Ajout d'un Article:"<<std::endl;

    file = "../Elements/";
    file += _title;
    file += ".txt";

    ///open the file, and purge it if he is not empty
    std::ofstream Ajout(file.c_str(), std::ios::out | std::ios::trunc);
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

///function modifier() for modifying an Article
std::string Article::modifier()
{
    int i=0;
    char choix;
    std::string name, file, suppr,  buffer;

    std::cout<<"Modification de l'article:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'article a modifier:";
    std::cin>>name;
    std::cout<<std::endl;

    file = "../Elements/";
    file += name;
    file += ".txt";

    ///for reading the last values
    std::ifstream lecture(file.c_str());
    if (lecture)
    {
        lecture >> buffer;        lecture >> _title;
        lecture >> buffer;        lecture >> _author;
        lecture >> buffer;        lecture >> _theme;
        lecture >> buffer;        lecture >> buffer;
        lecture >> buffer;        lecture >> _dateParution;

        ///for puting the cursor at the beginning of the file
        lecture.seekg(0, std::ios::beg);
        while (i<4)
        {
            ///for asking if we modify a value
            getline(lecture, buffer);
            do
            {
                std::cout<< buffer <<std::endl;
                std::cout<< "Voulez-vous modifier cette ligne? [y/n]" <<std::endl;
                std::cin>>choix;
            } while( (choix != 'y') && (choix != 'Y') && (choix != 'n') && (choix != 'N') );
            ///if modify, ask the new value
            if ( (choix == 'y') || (choix == 'Y') )
            {
                std::cout<< "Veuillez entrer la nouvelle donnée:" <<std::endl;
                std::cin>>buffer;
                if (i == 0)
                {
                    _title = buffer;
                    suppr = "rm ";
                    suppr += file;
                    system(suppr.c_str());
                }
                if (i == 1)
                    _author = buffer;
                if (i == 2)
                    _theme = buffer;
                if (i == 3)
                    _dateParution = buffer;
            }
            i++;
        }
        ///call of ajouter(); for reducing the code
        ajouter();
    }
    else
    {
        std::cout<<"ERREUR: Impossible de modifier le fichier."<<std::endl;
        std::cout<<"Veuillez appuyer sur enter pour continuer."<<std::endl;
        getchar();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
    return name;
}

///function initialisation() for initialising an Article
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
