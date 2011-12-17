#ifndef COMIC_H
#define COMIC_H
#include "bd.h"

///class Comic, inheriting of class BD.

class Comic : public BD
{
public:
    Comic();
    ~Comic();
    std::string ajouter();
    std::string modifier();
    void initialisation();
private:
};

#endif // COMIC_H
