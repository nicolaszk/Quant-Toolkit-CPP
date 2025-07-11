#include "DataVisualizer.h" 
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for system()
using namespace std;

bool DataVisualizer::plotPriceHistory(const vector<vector<string>>& data) {
    ofstream dataFile("plot_data.dat");
    if(!dataFile.is_open()){
        cerr << "could not create plot_data.dat" << endl;
        return false;
    }
    // the price is in the secnd solumn (index 1) of the row, for every row, add the price
    for(const auto& row : data){
        if(row.size() > 1) {
            dataFile << row[1] << "\n";
        }
    }
    dataFile.close();

    // write script file for gnuplot
    ofstream scriptFile("plot_script.gp");
    if(!scriptFile.is_open()){
        cerr << "coult not create plot_script.gp" << endl;
        return false;
    }

    scriptFile << "set terminal pngcairo enhanced font 'Verdana,10'\n";
    scriptFile << "set output 'price_chart.png'\n";
    scriptFile << "set title 'Price History'\n";
    scriptFile << "set xlabel 'Time (Index)'\n";
    scriptFile << "set ylabel 'Price'\n";
    scriptFile << "plot 'plot_data.dat' with lines title 'Price'\n";
    scriptFile.close();

    cout << "generating plot" << endl;
    int ret = system("gnuplot plot_script.gp");
    if(ret != 0){
        cerr << "gnuplot failed to execute" << endl;
        return false;
    }
    cout << "plot generated successfully as 'price_chart.png'" << endl;
    return true;
}


