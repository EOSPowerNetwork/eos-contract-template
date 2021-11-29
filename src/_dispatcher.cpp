#include "_dispatcher.hpp"
#include "class1.hpp"
#include "class2.hpp"

// Final part of the dispatcher
EOSIO_ACTION_DISPATCHER(contract_name::actions)

// Things to populate the ABI with
EOSIO_ABIGEN(actions(contract_name::actions),
             table("schema1"_n, contract_name::Schema1),
             ricardian_clause("Class 1 clause", contract_name::ricardian_clause),
             ricardian_clause("Class 2 clause", contract_name::ricardian_clause2))
