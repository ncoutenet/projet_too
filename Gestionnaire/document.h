#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream> ///in and out stream
#include <string> ///for using string variables and string functions
#include <fstream> ///for using in and out flow
#include <cstdlib> ///for using files
#include <vector> ///for using vectors
#include <cstdio> ///for using system commands
#include <limits> ///for having numeric_limits for the keyboard waiting

///class Document, mother of all Document-type class.

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
