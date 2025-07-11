#ifndef MOVINGAVERAGECROSSOVER_H
#define MOVINGAVERAGECROSSOVER_H

#include "Strategy.h"
#include <vector>
#include <numeric>

using namespace std;

class MovingAverageCrossover : public Strategy{
    public:
        //constructors takes period for short and long moving averages
        MovingAverageCrossover(size_t short_period, size_t long_period);
        //the override keyword is just a safety check
        Signal onMarketData(const MarketData& data) override;
    private:
        size_t m_short_period;
        size_t m_long_period;
        vector<double> m_prices; // stores recent prices
        double calculate_sma(size_t period);                        
};
#endif 
