#include "livre.h"

Livre::Livre()
{
}

Livre::~ Livre()
{
}

///function getAuthor() for having the Author who is protected
std::string Livre::getAuthor()
{
    return _author;
}
