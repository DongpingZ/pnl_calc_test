#include "trade.h"
#include <sstream>
#include <stdexcept>

Trade::Trade(uint64_t timestamp, std::string symbol, TradeSide side, double price, uint32_t qty)
    : timestamp_(timestamp), symbol_(symbol), side_(side), price_(price), qty_(qty) {}

uint64_t Trade::getTimestamp() const { return timestamp_; }
std::string Trade::getSymbol() const { return symbol_; }
TradeSide Trade::getSide() const { return side_; }
double Trade::getPrice() const { return price_; }
uint32_t Trade::getQty() const { return qty_; }

Trade Trade::fromCsvLine(const std::string& line) {
    return Trade();
}