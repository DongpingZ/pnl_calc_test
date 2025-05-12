#ifndef TRADE_H
#define TRADE_H

#include <string>
#include <cstdint>

enum class TradeSide {
    BUY,
    SELL
};

class Trade {
public:
    Trade() = delete;
    Trade(uint64_t timestamp, std::string symbol, TradeSide side, double price, uint32_t quantity);
    explicit Trade(const std::string& line);
    
    uint64_t getTimestamp() const;
    std::string getSymbol() const;
    TradeSide getSide() const;
    double getPrice() const;
    uint32_t getQty() const;
    
    void print() const;
    
private:
    uint64_t timestamp_ = 0;
    std::string symbol_ = "EMPTY_SYMBOL";
    TradeSide side_ = TradeSide::BUY;
    double price_ = 0.0;
    uint32_t qty_ = 0;
};

#endif // TRADE_H
