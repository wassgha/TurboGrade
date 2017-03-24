#include "filewriter.h"

/**
 * @brief FileWriter::FileWriter
 * @param fileout the output file
 */
FileWriter::FileWriter(const std::string& fileout){
    SHOW_WHERE;
    _fileout = fileout;
    this->open(fileout);
}

/**
 * @brief FileWriter::~FileWriter destructor closes ofstream
 */
FileWriter::~FileWriter(){
    _writer.close();
}

/**
 * @brief FileWriter::is_open gets the state of the ofstream
 * @return true if the writer is open
 */
bool FileWriter::is_open(){
    return _writer.is_open();
}

/**
 * @brief FileWriter::close closes the writer
 */
void FileWriter::close(){
    _writer.close();
}

/**
 * @brief FileWriter::open closes a currently open file (if exists), and opens
 * the specified fileout
 * @param fileout output file
 */
void FileWriter::open(const std::string& fileout){
    if(_writer.is_open()){
        _writer.close();
    }
    _writer.open(fileout);
    if(!_writer){
        SHOW_WHERE
        std::cerr << "Error opening output file: " << fileout <<std::endl;
    }
    _fileout=fileout;
}
