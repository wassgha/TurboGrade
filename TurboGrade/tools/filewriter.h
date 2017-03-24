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

    /**
     * @brief FileWriter constructor
     * @param fileout the output file
     */
    FileWriter(const std::string& fileout);

    ~FileWriter(); // destructor


    /**
     * @brief operator<< writes a generic object to the file
     * @param t the generic object
     */
    template<typename T>
    FileWriter& operator<<(T t){
        if(_writer.is_open()){
            _writer << t;
            _writer.flush();
        }
        return *this;
    }

    /**
     * @brief open opens the output file
     * @param fileout the output file
     */
    void open(const std::string& fileout);

    /**
     * @brief is_open retrieves the state of the writer
     * @return true if the writer is open
     */
    bool is_open();

    /**
     * @brief close closes the writer
     */
    void close();

private:
    //file handle
    std::ofstream _writer;

    //output file
    std::string _fileout;
};

#endif // FILEWRITER_H
