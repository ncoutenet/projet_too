#ifndef LIVRE_H
#define LIVRE_H
#include "document.h"

///class Livre, inheriting of class Document.

class Livre : public Document
{
public:
    Livre();
    virtual ~Livre();
    std::string getAuthor();
protected:
    std::string _author;
};

#endif // LIVRE_H
