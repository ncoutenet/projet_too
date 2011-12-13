#ifndef ROMAN_HH
#define ROMAN_HH
#include"livre.h"

class Roman : public Livre
{
public:
    Roman();
    ~Roman();
    std::string getEditor();
    void ajouter();
    void modifier();
protected:
    std::string _editor;
};

#endif // ROMAN_HH
