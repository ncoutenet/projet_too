#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

class Document
{
public:
    Document();
    ~Document();
    std::string getTitle();
    void ajouter();
    void modifier();
    protected:
    std::string _title;
};

#endif // DOCUMENT_H
