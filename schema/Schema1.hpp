#pragma once

#include <eosio/eosio.hpp>
#include <eosio/name.hpp>

#include <string>
#include <vector>

namespace contract_name
{
    using eosio::name;
    using std::string;
    using std::vector;

    struct Schema1
    {
        name to;
        uint32_t lastPayout;
        string memoSuffix;

        uint64_t primary_key() const { return to.value; }
    };
    EOSIO_REFLECT(Schema1, to, lastPayout, memoSuffix);
}  // namespace contract_name