#ifndef MARKETDATA_H
#define MARKETDATA_H


#include <string>
using namespace std;
// simple structure to hold one row of market data.
struct MarketData{
    string timestamp;
    double price;
    int volume;
};

#endif
