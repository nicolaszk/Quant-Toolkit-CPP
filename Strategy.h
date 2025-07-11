#ifndef STRATEGY_H
#define STRATEGY_H

#include "MarketData.h"

using namespace std;
// possible signals our strategies can generate
enum class Signal {
    HOLD, BUY, SELL
};
//base class for all strategies, is like an interface in java
//any class that inherits from strategy must provide an onMarketData function
class Strategy{
    public:
        virtual ~Strategy() = default;
        virtual Signal onMarketData(const MarketData& data) = 0; // pure virtual function.
};

#endif
