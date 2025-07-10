#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
using namespace std;


class CsvReader { 
    public:
        CsvReader(const string& filename); // passing filename by constant reference
        bool readAll(vector<vector<string>>& data); // function will fill the vector data

    private:
        string m_filename; 
};

#endif
