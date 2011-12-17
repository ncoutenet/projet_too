#include "livre.h"

Livre::Livre()
{
}

Livre::~ Livre()
{
}

///for having the Author who is protected
std::string Livre::getAuthor()
{
    return _author;
}
