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

    file = "../Elements/";

    std::cout<<"Ajout d'un element:"<<std::endl;
    std::cout<<"Veuillez entrer le nom de l'element:";
    std::cin>>name;
    std::cout<<std::endl;

    file += name;
    file += ".txt";

    std::cout<<file<<std::endl;
    std::ofstream Ajout(file.c_str());
}

void Objet::supprimer()
{

}

void Objet::modifier()
{

}

void Objet::exporter()
{

}
