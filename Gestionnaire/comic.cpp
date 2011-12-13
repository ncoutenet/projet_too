#include "comic.h"

Comic::Comic()
{
}

Comic::~Comic()
{
}

void Comic::initialisation()
{
    std::cout<<"Veuillez entrer le titre du comic : ";
    std::cin>>_title;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'auteur du comic : ";
    std::cin>>_author;
    std::cout<<std::endl;

    std::cout<<"Veuillez entrer l'éditeur du comic : ";
    std::cin>>_editor;
    std::cout<<std::endl;
}
