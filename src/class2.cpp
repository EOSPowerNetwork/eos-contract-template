#include <eosio/eosio.hpp>
#include <eosio/name.hpp>
#include <string>

#include "class2.hpp"

using namespace eosio;
using std::string;
using namespace contract_name;

class2_contract::class2_contract(name receiver, name code, datastream<const char*> ds) : contract(receiver, code, ds)
{
    /* NOP */
}

void class2_contract::action1()
{
    print("action1");
}
void class2_contract::action2(const name& someone)
{
    require_auth(someone);
    print("action2");
}
