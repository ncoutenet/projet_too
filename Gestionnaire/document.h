#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <iostream>

class Document
{
public:
    Document();
    ~Document();
    std::string getTitle();
    protected:
    std::string _title;
};

#endif // DOCUMENT_H
