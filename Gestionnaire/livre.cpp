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
