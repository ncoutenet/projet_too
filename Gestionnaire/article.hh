#ifndef ARTICLE_HH
#define ARTICLE_HH
#include "livre.h"

class Article : public Livre
{
public:
    Article();
    ~Article();
    std::string getTheme();
    std::string getDateParution();
    void ajouter();
    void modifier();
protected:
    std::string _theme;
    std::string _dateParution;
};

#endif // ARTICLE_HH
