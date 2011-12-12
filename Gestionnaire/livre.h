#ifndef LIVRE_H
#define LIVRE_H
#include "document.h"

class Livre : public Document
{
public:
    Livre();
    ~Livre();
    std::string getAuthor();
    void ajouter();
    void modifier();
protected:
    std::string _author;
};

#endif // LIVRE_H
