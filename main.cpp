#include <iostream>
#include <string>
#include <vector>
// csv parser
#include <chrono> 
// to measure the efficiency of our code with timing

#include "CsvReader.h"

using namespace std;
int main(){
    CsvReader reader("../large_data.csv");
    vector<vector<string>> data;
    auto start = chrono::high_resolution_clock::now();

    if(reader.readAll(data)){
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "baseline performance" << endl;
        cout << "read" << data.size() << " rows" << endl;
        cout << "time taken: " << diff.count() << " seconds" << endl;
        cout << "successfully parsed csv file" << endl;
        // will already be printed inside function
    }
    else{
        cerr << "failed to parse csv file" << endl;
        return 1;
    }

    return 0;
}

