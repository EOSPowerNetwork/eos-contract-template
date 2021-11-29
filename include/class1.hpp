#pragma once

#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>
#include <eosio/name.hpp>
#include <eosio/singleton.hpp>
#include <string>
#include <vector>
namespace contract_name
{
    using eosio::check;
    using eosio::contract;
    using eosio::datastream;
    using eosio::name;
    using eosio::print;
    using std::string;

    // Ricardian contracts live in ricardian/class1-ricardian.cpp
    extern const char* sayhi_ricardian;
    extern const char* sayhialice_ricardian;
    extern const char* ricardian_clause;

    class class1_contract : public contract
    {
       public:
        using eosio::contract::contract;

        class1_contract(name receiver, name code, datastream<const char*> ds);

        void sayhi();

        void sayhialice(const name& someone);
    };
}  // namespace contract_name