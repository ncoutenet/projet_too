#ifndef MANGA_H
#define MANGA_H
#include "bd.h"

class Manga : public BD
{
public:
    Manga();
    ~Manga();
    std::string getType();

private:
    std::string _type;
};

#endif // MANGA_H
