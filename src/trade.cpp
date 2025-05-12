#include "trade.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

Trade::Trade(uint64_t timestamp, std::string symbol, TradeSide side, double price, uint32_t qty)
    : timestamp_(timestamp), symbol_(symbol), side_(side), price_(price), qty_(qty) {}

uint64_t Trade::getTimestamp() const { return timestamp_; }
std::string Trade::getSymbol() const { return symbol_; }
TradeSide Trade::getSide() const { return side_; }
double Trade::getPrice() const { return price_; }
uint32_t Trade::getQty() const { return qty_; }

void Trade::print() const {
    std::cout << "Trade: " << timestamp_ << ", " << symbol_ << ", ";
    if (side_ == TradeSide::BUY) 
        std::cout << "B";
    else
        std::cout << "S";
    std::cout << ", " << price_ << ", " << qty_ << std::endl;
}

Trade::Trade(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    
    // Parse timestamp
    std::getline(ss, token, ',');
    timestamp_ = std::stoull(token);
    
    // Parse symbol
    std::getline(ss, token, ',');
    symbol_ = token;
    
    // Parse side
    std::getline(ss, token, ',');
    side_ = (token == "B") ? TradeSide::BUY : TradeSide::SELL;
    
    // Parse price
    std::getline(ss, token, ',');
    price_ = std::stod(token);
    
    // Parse quantity
    std::getline(ss, token, ',');
    qty_ = std::stoul(token);
}