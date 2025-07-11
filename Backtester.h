#ifndef BACKTESTER_H
#define BACKTESTER_H
#include "Portfolio.h"
#include <vector>
#include <string>
#include "MarketData.h"
using namespace std;
class Strategy;

class Backtester{
    public:
        Backtester(const vector<vector<string>>& csvData, Strategy* strategy, double initial_cash);

        void run();
    private:
        vector<MarketData> m_marketData;
        Strategy* m_strategy;
        Portfolio m_portfolio;
};

#endif
