#include "roman.hh"

Roman::Roman()
{
}

Roman::~ Roman()
{
}

///function getEditor() for having theme who is protected
std::string Roman::getEditor()
{
    return _editor;
}

///function ajouter() for adding a new Roman
std::string Roman::ajouter()
{
    std::string file;

    std::cout<<"Ajout d'un roman:"<<std::endl;

    file = "../Elements/";
    file += _title;
    file += ".txt";

    ///open the file, and purge it if he is not empty
    std::ofstream Ajout(file.c_str());
    if (Ajout)
    {
        Ajout << "Titre: ";
        Ajout << _title <<std::endl;
        Ajout << "Auteur: ";
        Ajout << _author <<std::endl;
        Ajout << "Editeur: ";
        Ajout << _editor <<std::endl;
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

///function modifier() for modifying a Roman
std::string Roman::modifier()
{
    int i=0;
    char choix;
    std::string name, file, suppr,  buffer;

    std::cout<<"Modification du roman:"<<std::endl;
    std::cout<<"Veuillez entrer le nom du roman a modifier:";
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
        lecture >> buffer;        lecture >> _editor;

        ///for puting the cursor at the beginning of the file
        lecture.seekg(0, std::ios::beg);
        while (i<3)
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
                    _editor = buffer;
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

///function initialisation() for initialising a Roman
void Roman::initialisation()
{
    std::cout<<"Veuillez entrer le titre du roman (Espaces Non Admis) : ";
    std::cin>>_title;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'auteur du roman : ";
    std::cin>>_author;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'éditeur' : ";
    std::cin>>_editor;
    std::cout<<std::endl;
}
