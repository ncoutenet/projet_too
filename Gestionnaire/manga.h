#ifndef MANGA_H
#define MANGA_H
#include "bd.h"

class Manga : public BD
{
public:
    Manga();
    ~Manga();
    std::string getType();    
    void ajouter();
    void modifier();
private:
    std::string _type;
};

#endif // MANGA_H
