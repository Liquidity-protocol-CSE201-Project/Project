#include <cassert>
#include "Token.hpp"
#include "UniswapV2Pool.hpp"

int main() {
    Token *token1 = Token::GetToken("token1");
    Token *token2 = Token::GetToken("token2");

    UniswapV2Pool pool({{token1, 10}, {token2, 20}});

    assert(pool.Swap(token1, token2, 10) == 10);
    assert(pool.GetQuantity(token1) == 20);
    assert(pool.GetQuantity(token2) == 10);

    return 0;
}