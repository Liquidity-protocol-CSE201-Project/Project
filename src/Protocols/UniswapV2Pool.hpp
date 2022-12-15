#ifndef UNISWAP_V2_POOL_HPP
#define UNISWAP_V2_POOL_HPP

#include "../Utilities/Utilities.hpp"
#include <fstream>
using namespace std;

class UniswapV2Pool : public PoolInterface {
public:
    using PoolInterface::PoolInterface;

    double ComputeInvariant(const std::unordered_map<Token *, double> &quantities) const {
        double ans = 1;
        for (auto [token, quantity] : quantities) {
            ans *= quantity;
        }
        return ans;
    }

    double ComputeSpotExchangeRate(Token *input_token, Token *output_token) const {
        return GetQuantity(input_token) / GetQuantity(output_token);
    }

    double ComputeSwappedQuantity(Token *input_token, Token *output_token, double input_quantity) const {
        return GetQuantity(output_token) - GetQuantity(input_token) * GetQuantity(output_token) / (GetQuantity(input_token) + input_quantity);
    }

    double ComputeInputRequirement(Token *input_token, Token *output_token, double output_quantity) const {
        return ( GetQuantity(output_token) * GetQuantity(input_token) ) / ( GetQuantity(output_token) - output_quantity ) - GetQuantity(input_token);
    }

    double ComputeSlippage(Token *input_token, Token *output_token, double input_quantity) const {
        output_token= Token::GetToken("token1");
        return input_quantity / GetQuantity(input_token);
    }
};

#endif
