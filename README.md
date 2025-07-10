#Quant-Toolkit-CPP

This is a collection of high-performance basic tools in c++ for quant finance including a CSV parser, a data visualizer and a trading strategy backtester.
This project is a personal exploration into building efficient financial infrastructure from scratch, in C++.

---

## Modules

This repository is structured as a series of interconnected mini-projects.

## 1. CSV Parser

A from-scratch CSV parser for handling large market data files. The goal was to minimize memory allocations and disk I/0 to achieve the lowest possible latency.

**The optimization journey:**
* **Baseline:** The first implementation used `std::ifstream` and `std::stringstream` that took 3.3 seconds to process a 1 million row file.
* **Optimization 1 (Manual Parsing):**  By removing `stringstream` and parsing lines manually with `string::find`, the time was reduced to 1.8 seconds. This demonstrated the high overhead of creating millions of `stringstream` objects, one for every row.
* **Optimization 2 (Memory Buffering):** The final version reads the entire file into an in-memory buffer in a single operation. All subsequent parsing happens on thsi buffer, minimizing disk I/0 operations. This approach achieved a time of 1.5 seconds. This shows the inneficiency of disk I/0 operations when compared to RAM operations.

## 2. Data Visualizer (Planned)

This module will take the parsed data and use Gnuplot to generate charts and visualizations of price action and other metrics

## 3. Trading Backtester (Planned)

An event-driven backtesting engine that will use the CSV parser to feed market data to user-defined trading strategies and evaluate their performance.

