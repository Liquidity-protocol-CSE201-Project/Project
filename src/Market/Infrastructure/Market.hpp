#ifndef Market_hpp
#define Market_hpp

#include "CommunityActor.hpp"

class Market {
public:
    Market();
    ~Market();

    // the add functions is not used in market simulating process
    // instead is used to create Rug Pull Strategy of Arbitrager
    void addInitialScenario(const std::unordered_map<std::string, double> &price_tags, PROTOCOL pool_type);
    void addToken(const std::string &name, double price);
    void addToken(Token *token);
    void addPool(PoolInterface *pool);

    void runEpoch();

    std::unordered_set<Token *> GetMarketTokens() const;
    std::unordered_set<PoolInterface *> GetMarketPools() const;
private:
    static int MarketCount;
    int MarketIndex;
    int epoch;

    void randTokenPrice();

    std::unordered_set<Token *> tokens_;
    std::unordered_set<PoolInterface *> pools_;

    CommunityActor *A;
};

#endif