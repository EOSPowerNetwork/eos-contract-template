#pragma once

#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>
#include <eosio/name.hpp>
#include <string>

#include "Schema1.hpp"

namespace contract_name
{
    using std::string;
    using namespace eosio;
    using contract_name::Schema1;

    extern const char* action1_ricardian;
    extern const char* action2_ricardian;
    extern const char* ricardian_clause2;

    class class2_contract : public contract
    {
       public:
        using contract::contract;

        class2_contract(name receiver, name code, datastream<const char*> ds);

        void action1();

        void action2(const name& someone);

        using Schema1Table = eosio::multi_index<"schema1"_n, Schema1>;
    };
}  // namespace contract_name
