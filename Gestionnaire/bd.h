#ifndef BD_H
#define BD_H
#include "livre.h"

class BD : public Livre
{
public:
    BD();
    ~BD();
    std::string getEditor();

protected:
    std::string _editor;
};

#endif // BD_H
