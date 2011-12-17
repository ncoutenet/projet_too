#ifndef MANGA_H
#define MANGA_H
#include "bd.h"

class Manga : public BD
{
public:
    Manga();
    ~Manga();
    std::string getType();    
    std::string ajouter();
    std::string modifier();
    void initialisation();
private:
    std::string _type;
};

#endif // MANGA_H
