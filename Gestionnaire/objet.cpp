#include "objet.hh"

Objet::Objet()
{

}

Objet::~Objet()
{

}

void Objet::ajouter()
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

void Objet::supprimer()
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

void Objet::modifier()
{
    std::string name, file, file2;

    std::cout<<"Modifier d'un element:"<<std::endl;
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

void Objet::exporter()
{

}
