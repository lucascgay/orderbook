#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>

enum class OrderType 
{
    GoodTillCancel, 
    FillAndKill

};

enum class BuyOrSell
{
    Buy, 
    Sell
};

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;

struct LevelInfo
{
    Price price_;
    Quantity quantity_;
};

using LevelInfos = std::vector<LevelInfo>;

class OrderbookLevelInfos
{
public:
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks) : 
        bids_(bids), 
        asks_(asks) 
    { }

    const LevelInfos& GetBids() const { return bids_; }
    const LevelInfos& GetAsks() const { return asks_; }

private:
    LevelInfos bids_;
    LevelInfos asks_;
};

class Order
{
public:
    Order(OrderType orderType, OrderId orderId, BuyOrSell side, Price price, Quantity quantity) :
        orderType(orderType), 
        orderId(orderId),
        side(side),
        price(price),
        quantity(quantity)
    {}

private:
    OrderType orderType;
    OrderId orderId;
    BuyOrSell side;
    Price price;
    Quantity quantity;
};

int main()
{
    return 0;
}