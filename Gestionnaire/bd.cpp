#include "bd.h"

BD::BD()
{
    std::cout<<"Veuillez entrer l'éditeur de la BD : ";
    std::cin>>_editor;
    std::cout<<std::endl;
}

BD::~BD()
{
}

std::string BD::getEditor()
{
    return _editor;
}
