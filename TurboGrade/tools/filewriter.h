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

    //FileWriter& operator<<(std::string str);

    template<typename T>
    FileWriter& operator<<(T t){
        if(_writer.is_open()){
            _writer << t;
            _writer.flush();
        }
        return *this;
    }

    void open(const std::string& fileout);

    bool is_open();

    void close();

private:
    std::ofstream _writer;
    std::string _fileout;
};

#endif // FILEWRITER_H
