#include "filewriter.h"

FileWriter::FileWriter(const std::string& fileout){
    SHOW_WHERE;
    _fileout = fileout;
    this->open(fileout);
}

FileWriter::~FileWriter(){
    _writer.close();
}

bool FileWriter::is_open(){
    return _writer.is_open();
}

void FileWriter::close(){
    _writer.close();
}

void FileWriter::open(const std::string& fileout){
    if(_writer.is_open()){
        _writer.close();
    }
    _writer.open(fileout);
    if(!_writer){
        SHOW_WHERE
        std::cerr << "Error opening output file: " << fileout <<std::endl;
    }
}
