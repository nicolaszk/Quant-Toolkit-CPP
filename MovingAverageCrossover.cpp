#include "MovingAverageCrossover.h"
#include <iostream>
#include <stdexcept>

MovingAverageCrossover::MovingAverageCrossover(size_t short_period, size_t long_period) : m_short_period(short_period), m_long_period(long_period){
    if(short_period >= long_period){
        throw std::invalid_argument("short period must be less than long period");
    }
}

double MovingAverageCrossover::calculate_sma(size_t period){
    if(m_prices.size() < period){
        return 0.0;
    }
    double sum_period = accumulate(m_prices.end() - period, m_prices.end(), 0.0);
    return sum_period/period;
}

Signal MovingAverageCrossover::onMarketData(const MarketData& data) {
    m_prices.push_back(data.price);
    if(m_prices.size() <= m_long_period){
        return Signal::HOLD;
    }
    double short_sma = calculate_sma(m_short_period);
    double long_sma = calculate_sma(m_long_period);
    m_prices.pop_back();
    double prev_short_sma = calculate_sma(m_short_period);
    double prev_long_sma = calculate_sma(m_long_period);
    m_prices.push_back(data.price);

    if(short_sma > long_sma && prev_short_sma <= prev_long_sma){
        return Signal::BUY;
    }
    else if(short_sma < long_sma && prev_short_sma >= prev_long_sma){
        return Signal::SELL;
    }
    return Signal::HOLD;
}


