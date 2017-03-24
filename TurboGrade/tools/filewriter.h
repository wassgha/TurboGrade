#ifndef FILEWRITER_H
#define FILEWRITER_H
#include "objectidentifier.h"
#include <fstream>
#include <string>
#include <iostream>

class FileWriter : public ObjectIdentifier
{
public:
    FileWriter() = delete; //don't allow base constructor

    FileWriter(const std::string& fileout);
    ~FileWriter();

    template<typename T>
    FileWriter& operator<<(T t);

private:
    std::ofstream _writer;
    std::string _fileout;
};

#endif // FILEWRITER_H
