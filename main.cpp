#include <iostream>
#include <string>
#include <vector>
// csv parser
#include <chrono> 
// to measure the efficiency of our code with timing
#include "DataVisualizer.h"
#include "CsvReader.h"
#include "Backtester.h"
#include "MovingAverageCrossover.h"
using namespace std;
int main(){
 /*   CsvReader reader("../large_data.csv");
    vector<vector<string>> data;
    auto start = chrono::high_resolution_clock::now();

    if(reader.readAll(data)){
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "baseline performance" << endl;
        cout << "read" << data.size() << " rows" << endl;
        cout << "time taken: " << diff.count() << " seconds" << endl;
        cout << "successfully parsed csv file" << endl;
        
        DataVisualizer visualizer;
        visualizer.plotPriceHistory(data);

        Backtester backtester(data);
        backtester.run();
    }
    else{
        cerr << "failed to parse csv file" << endl;
        return 1;
    }

   
    return 0;
    */  // Old main, to benchmark our csvParser and test the backtester loop
    CsvReader reader("../large_data.csv");
    vector<vector<string>> csvData;
    if(reader.readAll(csvData)){
        cout << " parsed " << csvData.size() << "rows" << endl;
        double initial_cash = 100000.0;
        // creating strategy
        unique_ptr<Strategy> strategy = 
            make_unique<MovingAverageCrossover>(20, 50);
        Backtester backtester(csvData, strategy.get(), initial_cash);
        backtester.run();
    }
        else{
            cerr << "failed to read csv" << endl;
            return 1;
        }
        return 0;
     
}

