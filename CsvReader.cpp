#include "CsvReader.h" 
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
// constructor
CsvReader::CsvReader(const string& filename) : m_filename(filename) { // most efficient way to initialize member variables in c++ 
} 
// implementation of parser
bool CsvReader::readAll(vector<vector<string>>& data){
    ifstream file(m_filename, ios::binary);
    if(!file.is_open()){
        cerr << "could not open file" << endl;
        return false;
    }
    file.seekg(0, ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, ios::beg);
    // goes to end of file, saves the size, goes back to the start
    //
    // creates a string buffer and reserves memory to hold the file
    string buffer;
    buffer.reserve(file_size);

    buffer.assign((istreambuf_iterator<char>(file)),
                    istreambuf_iterator<char>());
    file.close();

    size_t line_count = std::count(buffer.begin(), buffer.end(), '\n');

    data.clear();
    data.reserve(line_count);
   
    size_t line_start = 0;
    size_t line_end = 0;

    line_start = buffer.find('\n',0) + 1;
    std::cout << "read file:" << endl;
    while(line_start < buffer.size()){
        line_end = buffer.find('\n', line_start);
        if(line_end == string::npos){ //edge case if the file doesnt end with a newline
            line_end = buffer.size();
        }
        vector<string> row;
        row.reserve(3);
        size_t cell_start = line_start;
        size_t cell_end = 0;

        while(cell_start < line_end){
            cell_end = buffer.find(',', cell_start);
            if(cell_end == string::npos || cell_end > line_end){
                cell_end = line_end;
            }
            row.push_back(buffer.substr(cell_start, cell_end - cell_start));
            cell_start = cell_end+1;
        }
        data.push_back(move(row));
        line_start = line_end+1;
    }

    return true;
}

