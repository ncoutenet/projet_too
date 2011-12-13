#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <limits>

class Document
{
public:
    Document();
    virtual ~Document();
    std::string getTitle();
protected:
    std::string _title;
};

#endif // DOCUMENT_H
