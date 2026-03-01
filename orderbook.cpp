// A real system is not just a data structure — it’s an architecture (memory + latency + concurrency + matching rules + logging + safety).

// Let’s build a complete design roadmap for a professional system.

// 🧠 Production Order Book Design (C++ — Full Architecture)

// We’ll structure the system like real exchanges:

// Core Components
// ├── Order
// ├── Order Entry Gateway
// ├── Order Book (bids + asks)
// ├── Price Levels
// ├── Matching Engine
// ├── Trade Engine
// ├── Order Types (GTC, FAK, etc.)
// ├── Order Modify / Cancel
// ├── Market Data / Trade Info
// ├── Memory & Performance Layer

// Client sends order
//         ↓
// Order enters book
//         ↓
// Waits for matching
//         ↓
// Gets partially / fully filled
//         ↓
// Eventually removed

// inside system

// 🧠 Exchange Rule: Price Priority → Time Priority

// All real exchanges follow:

// 1️⃣ Best price first
// 2️⃣ If same price → earliest order first

// This second rule is FIFO.
// I’ll explain each like a systems design interview + production engineering.
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>
//So OrderType only matters while the order is still in the book, before the trade happens.
enum class OrderType{//one of these value will be passed
	GoodTillCancel,//order valid till its canceled //limit
	FillAndKill//order should be fastly filled or canceled //market
};

enum class Side{
	Buy,	//bids -> buy orders(customer)  //descending order price jyada | unit km mein kharede
	Sell 	//asks -> sell orders(seller)  //ascending order   price km    | unit jyada mein bech 
};


using Price = std::int32_t
using Quantity = std::uint32_t
using OrderId = std::uint64_t

struct LevelInfo{
	Price price_;
	Quantity quantity_;	
};
//----------------------making packet of level-----------

using LevelInfos = std::std::vector<LevelInfo> ;

class OrderBookLevelInfos{
public:
	OrderBookLevelInfos(const LevelInfos& bids,const LevelInfos& asks)
	:bids_{bids}
	,asks_{asks}
	{}
const LevelInfos& GetBids() const{ return bids_;}
const LevelInfos& GetAsks() const{ return bids_;}
private:
	LevelInfos bids_;//intializing our private member api
	LevelInfos asks_;
	
};


//------------------order 
//here all the order given by the user is kept (bids,asks-> item asked ,item reamaning is kept here to check after which check  trade is perfect and which is not-> tradeinfo
// Order = single request
// OrderBook = system managing all requests
// It lives in the order book until it is:
// fully filled
// partially filled
// cancelled
// expired (e.g., FAK)

class Order
{
		Order(OrderType orderType ,OrderId orderId, Side side, Price price, Quantity quantity)
		:orderType_{orderType}		//order is gtc or fak
		,orderId_{orderId}			//unique identifier for buyer and seller
		,side_{side}				// is it buyer(bids) or seller(asks)
		,price_{price}				//price  
		,intialQuantity_{quantity}	//how many unit it want to buy or sells 
		,remainingQuantity_{quantity}//how mant unit is still  unfilled 
		{ }
	OrderType GetOrderType() const			{ return orderType_;}
	OrderId GetOrderId() const				{ return orderId_;}
	Side GetSide() const 					{ return side_;}
	Price GetPrice()const 					{ return price_; }
	Quantity GetIntialQuantity ()const		{ return intialQuantity_;}
	Quantity GetRemainingQuantity()const 	{ return remainingQuantity_;}
	Quantity GetFilledQuantity() const		{ return	GetIntialQuantity() - GetRemainingQuantity() ;}//how many quatity is filled
	bool IsFilled() const 					{ return GetRemainingQuantity() == 0;}
//if someone asked quantity which is greater than the remaning quantity (unmatched demeand) throw an error
void Fill(Quantity quantity){
	if ( quantity > GetRemainingQuantity())
		throw std::logic_error(std::format("Order ({}) cannot be filled more than the remaining quantity ", GetOrderId));
	remainingQuantity_ -= quantity; 
} 


private :
OrderType orderType_;
OrderId orderId_;
Side side_;
Price price_;
Quantity intialQuantity_;
Quantity remainingQuantity_;

};

//--------------------making packet of order



using OrderPointer = std::shared_pointer<Order>;		//fast management (memory)of order//effecientlly updates without copying the whole data //access or share the order across any conatiner
using OrderPointers = std::list<OrderPointer>;			//fast insertion and deletion of any orderpointer  




// -------------------- Modify Request --------------------
//===========now we need to modify the order we need basic things from the order ,


class OrderModify{
	OrderModify(OrderId orderId, Side side, Price price, Quantity quantity)
:orderId_{orderId}			//unique identifier for buyer and seller
,side_{side}				// is it buyer(bids) or seller(asks)
,price_{price}				//price  
,quantity_{quantity}//how many unit it want to buy or sells 
{}
	OrderId GetOrderId() const				{ return orderId_;}
	Side GetSide() const 					{ return side_;}
	Price GetPrice()const 					{ return price_; }
	Quantity GetQuantity ()const			{ return quantity_;}

OrderPointer ToOrderPointer(OrderType type){
	return std::make_shared<Order>(type,GetOrderId(),GetSide(),GetPrice(),GetQuantity());
}

private :
OrderId orderId_;
Side side_;
Price price_;
Quantity quantity_;

};

//----------------------Trade Info of order-----------------------------
// When a new order comes in, we check the opposite side for matches.
// We pass both sides (bid and ask) to the Trade class so it knows:
// Who bought					/.If match occurs:
// Who should					Remove quantity from bid and ask levels
// How much						Create a Trade object to record what was executed
// At what price				Log trade for reporting / settlement
//since in trade we dont need the ordertype because the trade is already happened 

struct TradeInfo{
OrderId orderId_;
Side side_;
Price price_; 
Quantity quantity_;
};

class Trade{
public:
	Trade(TradeInfo& bidtrade, TradeInfo& asktrade)
	:bidtrade_{ bidtrade}
	,asktrade_{ asktrade}
	{}
	const TradeInfo& GetBitTrade() const	{ return bittrade_; }
	const TradeInfo& GetAskTrade() const	{ return asktrade_; }
private:
 TradeInfo bittrade_;
 TradeInfo asktrade_;
 
};


//-----making packet of tradeInfo
using Trades = std::vector<trade>; 

//============ORDER BOOK===========

class OrderBook{
private:
	struct OrderEntry{	//fast cancel or modification//list can give me location of order using iterator 
// Order = Book
// OrderEntry = Catalog entry
// The catalog entry tells:
// Shelf,Position,Identifier
//
		 OrderPointer order_ { nullptr};//pointer → actual order
		 OrderPointer::iterator location;//iterator → exact position in price level queue
	};
	std::map<Price, OrderPointer, std::greater<Price>> bids_;
	std::map<Price, OrderPointer, std::less<Price>> asks_;
	std::unordered_map<OrderId, OrderPointer> orders_;

	bool CanMatch(Side side, Price price ){
		if (side == Side::Buy){//check if side is buy
			if (asks_.empty())//if asks (sells) is empty there is nothing 
				return false;//nothing to match with the buyer 

			const auto& [bestAsk, _]= *asks_.begin();//first one be at low price of seller since we use map with less sort
			return price >= bestAsk; //if price is bigger than or equal to the best ask return true else it will false
				
								}
				
				else{//if seller side //if someone is willing to buy is em
					if(bids_.empty())//is buyer is empty
				return false;

				const auto& [bestBid,_] = *bids_.begin();//give the greatest price   buyer
					}			
			
										}			
		Trades MatchOrders(){
			Trades trades;
			trades.reserve(orders_.size());//avoid memory allocation faster
			while(true){
				if(bids_.empty()||asks_.empty())
					break;
				 // choose best PRICE
				auto& [bidPrice, bids]= *bids_.begin();//putting the value orderpointer in bids
				auto& [asksPrice, asks] = *asks_.begin();

				if(bidPrice < askPrice)
					break;

				while(bids.size() && asks.size()){
// choose ORDER inside that price
					auto& bid = bids.front();//having the orderpointer of the first orderpointer having the greatest val of bids 
					auto& ask = asks.front();//having the orderpointer of the first orderpointer having the lowest val of asks

					Quantity qunatity = std::min(bid->GetRemainingQuantity(), ask->GetRemainingQuantity());//getting the min of bids and
					bid->Fill(quantity);
					ask->Fill(quantity);
//after filleing the quantity we have to check the that the remaining item is empty or not if it is empty remove the bids/ask orderId and pop its value
					if(bid->IsFilled()){
						bids.pop_front();
						order_.erase(bid->GetOrderId()); 
					}
					if(asks-> IsFilled()){
						asks.pop_front();
						order_.erase(ask->GetOrderId());
					}
//if the whole bids is empty why we are deleting the price of bid 
					if(bids.empty())
						bids.erase(bidPrice);

					if(ask.empty())
						asks_erase(askPrice);
				
					trades.push_back(Trade{
						TradeInfo{ bid->GetOrderId(), bid->GetPrice(), qunatity};
						TradeInfo{ ask->GetOrderId(), ask->GetPrice(), qunatity};
						
					});

				}

			}
//to remove the bids order id from fastandkill 

			if(!bids.empty()){
				auto& [_, bids] = *bids_.begin();
				auto& order = bids.front();
				if ( order->GetOrderType()== OrderType::FillAndKill)
					CancelOrder(order->GetOrderId());
			}
			if(!asks.empty()){
				auto& [_, asks] = *asks_.begin();
				auto& order = asks.front();
				if ( order->GetOrderType()== OrderType::FillAndKill)
					CancelOrder(order->GetOrderId());
				
			}
		}
			 
return trades;

public :


 Trades AddOrder(OrderPointer order)
 {

     if (orders_.contains(order->GetOrderId()))
         return { };

     if (order->GetOrderType() == OrderType::FillAndKill && !CanMatch(order->GetSide(), order->GetPrice()))
         return { };

     OrderPointers::iterator iterator;

     if (order->GetSide() == Side::Buy)
     {
         auto& orders = bids_[order->GetPrice()];
         orders.push_back(order);
         iterator = std::next(orders.begin(), orders.size() - 1);
     }
     else
     {
         auto& orders = asks_[order->GetPrice()];
         orders.push_back(order);
         iterator = std::next(orders.begin(), orders.size() - 1);
     }

     orders_.insert({ order->GetOrderId(), OrderEntry{ order, iterator } });

     return MatchOrders();
 }

Trades MatchOrder(OrderModify order)
{
    if (!orders_.contains(order.GetOrderId()))
        return { };

    const auto& [existingOrder, _] = orders_.at(order.GetOrderId());
    CancelOrder(order.GetOrderId());
    return AddOrder(order.ToOrderPointer(existingOrder->GetOrderType()));
}

std::size_t Size() const
{
    return orders_.size();
}

OrderbookLevelInfos GetOrderInfos() const
{
    LevelInfos bidInfos, askInfos;
    bidInfos.reserve(orders_.size());
    askInfos.reserve(orders_.size());

    auto CreateLevelInfos = [](Price price, const OrderPointers& orders)
    {
        return LevelInfo{
            price,
            std::accumulate(
                orders.begin(),
                orders.end(),
                (Quantity)0,
                [](Quantity runningSum, const OrderPointer& order)
                {
                    return runningSum + order->GetRemainingQuantity();
                })
        };
    };

    for (const auto& [price, orders] : bids_)
        bidInfos.push_back(CreateLevelInfos(price, orders));

    for (const auto& [price, orders] : asks_)
        askInfos.push_back(CreateLevelInfos(price, orders));

    return OrderbookLevelInfos{ bidInfos, askInfos };
}
				};
int main()
{
    OrderBook book;

    auto printTrades = [](const Trades& trades)
    {
        for (const auto& trade : trades)
        {
            std::cout << "TRADE | "
                      << "BidID: " << trade.GetBitTrade().orderId_
                      << " AskID: " << trade.GetAskTrade().orderId_
                      << " Qty: " << trade.GetBitTrade().quantity_
                      << " Price: " << trade.GetBitTrade().price_
                      << "\n";
        }
    };

    std::cout << "=== ADD BUY 100 @ 10 ===\n";
    printTrades(book.AddOrder(
        std::make_shared<Order>(
            OrderType::GoodTillCancel, 1, Side::Buy, 100, 10)));

    std::cout << "=== ADD BUY 100 @ 5 ===\n";
    printTrades(book.AddOrder(
        std::make_shared<Order>(
            OrderType::GoodTillCancel, 2, Side::Buy, 100, 5)));

    std::cout << "=== ADD SELL 100 @ 8 ===\n";
    printTrades(book.AddOrder(
        std::make_shared<Order>(
            OrderType::GoodTillCancel, 3, Side::Sell, 100, 8)));

    std::cout << "=== ADD SELL 100 @ 10 ===\n";
    printTrades(book.AddOrder(
        std::make_shared<Order>(
            OrderType::GoodTillCancel, 4, Side::Sell, 100, 10)));

    std::cout << "=== ADD FAK BUY 100 @ 20 ===\n";
    printTrades(book.AddOrder(
        std::make_shared<Order>(
            OrderType::FillAndKill, 5, Side::Buy, 100, 20)));

    std::cout << "=== MODIFY ORDER 2 → 100 @ 15 ===\n";
    printTrades(book.MatchOrder(
        OrderModify(2, Side::Buy, 100, 15)));

    std::cout << "\n=== FINAL BOOK STATE ===\n";

    auto snapshot = book.GetOrderInfos();

    std::cout << "\nBIDS:\n";
    for (const auto& level : snapshot.GetBids())
        std::cout << "Price: " << level.price_
                  << " Qty: " << level.quantity_ << "\n";

    std::cout << "\nASKS:\n";
    for (const auto& level : snapshot.GetAsks())
        std::cout << "Price: " << level.price_
                  << " Qty: " << level.quantity_ << "\n";

    return 0;
}