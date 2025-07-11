#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Strategy.h"
#include "MarketData.h"

class Portfolio {
public:
    // Constructor takes the starting cash balance.
    Portfolio(double initial_cash);

    // Processes a signal from the strategy to execute a trade.
    void onSignal(Signal signal, const MarketData& data);

    // Prints a final summary of the portfolio's performance.
    void printSummary(const MarketData& last_data_point);

private:
    double m_initial_cash;
    double m_cash;
    int m_position; // How many shares we currently own
};

#endif //PORTFOLIO_H

