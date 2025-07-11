#include "Portfolio.h"
#include <iostream>
#include <cmath> // For floor

Portfolio::Portfolio(double initial_cash)
    : m_initial_cash(initial_cash), m_cash(initial_cash), m_position(0) {}

void Portfolio::onSignal(Signal signal, const MarketData& data) {
    // --- Execute Buy Signal ---
    // We can only buy if we are "flat" (don't currently own any shares).
    // This is a simple strategy to avoid complexity for now.
    if (signal == Signal::BUY && m_position == 0) {
        // Simple sizing: use all available cash to buy shares.
        int quantity_to_buy = floor(m_cash / data.price);
        
        if (quantity_to_buy > 0) {
            m_position += quantity_to_buy;
            m_cash -= quantity_to_buy * data.price;
            std::cout << data.timestamp << " - EXECUTED BUY:  " << quantity_to_buy << " shares @ " << data.price << std::endl;
        }
    }
    // --- Execute Sell Signal ---
    // We can only sell if we currently have a position.
    else if (signal == Signal::SELL && m_position > 0) {
        double sale_value = m_position * data.price;
        m_cash += sale_value;
        std::cout << data.timestamp << " - EXECUTED SELL: " << m_position << " shares @ " << data.price << " | New Cash: " << m_cash << std::endl;
        m_position = 0; // We sold all our shares
    }
}

void Portfolio::printSummary(const MarketData& last_data_point) {
    // Calculate the final value of the portfolio if we still have a position.
    double final_equity = m_cash + (m_position * last_data_point.price);
    double profit_loss = final_equity - m_initial_cash;
    double return_pct = (profit_loss / m_initial_cash) * 100.0;

    std::cout << "\n--- BACKTEST PERFORMANCE SUMMARY ---" << std::endl;
    std::cout << "Initial Portfolio Value: " << m_initial_cash << std::endl;
    std::cout << "Final Portfolio Value:   " << final_equity << std::endl;
    std::cout << "Profit/Loss:             " << profit_loss << std::endl;
    std::cout << "Total Return:            " << return_pct << "%" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

