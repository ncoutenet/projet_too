#include "document.h"

Document::Document()
{
    std::cout<<"Veuillez entrer le titre du document: ";
    std::cin>> _title;
    std::cout<<std::endl;
}
Document::~Document()
{

}

std::string Document::getTitle()
{
 return _title;
}
