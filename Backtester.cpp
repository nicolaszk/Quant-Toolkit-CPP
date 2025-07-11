#include "Backtester.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include "Strategy.h"

using namespace std;
Backtester::Backtester(const vector<vector<string>>& csvData, Strategy* strategy, double initial_cash) : m_strategy(strategy), m_portfolio(initial_cash){
    m_marketData.reserve(csvData.size());
    for(const auto& row: csvData){
        if(row.size() == 3) {
            try {          
                MarketData md;
                md.timestamp = row[0];
                md.price = stod(row[1]);
                md.volume = stoi(row[2]);
                m_marketData.push_back(md);
            }
            catch (const invalid_argument& e){
                cerr << "could not parse row " << e.what() << endl;
            }
            catch (const out_of_range& e){
                cerr << "value out of range " << e.what() << endl;
            }
        }
    }
}

void Backtester::run() {
    std::cout << "Starting backtest..." << std::endl;

    for (const auto& dataPoint : m_marketData) {
        Signal signal = m_strategy->onMarketData(dataPoint);
        // On each tick, pass the signal and data to the portfolio to handle.
        m_portfolio.onSignal(signal, dataPoint);
    }

    // After the loop, print the final performance summary.
    if (!m_marketData.empty()) {
        m_portfolio.printSummary(m_marketData.back());
    }

    std::cout << "Backtest finished." << std::endl;
}
