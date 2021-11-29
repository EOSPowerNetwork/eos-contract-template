#pragma once
#include <tuple>
#include "class1.hpp"
#include "class2.hpp"

namespace contract_name
{
    static constexpr auto contract_account = "contractacc"_n;

    namespace actions
    {
        using contract_c1 = class1_contract;
        using contract_c2 = class2_contract;

        using sayhi = eosio::action_wrapper<"sayhi"_h, &contract_c1::sayhi, contract_account>;
        using sayhialice = eosio::action_wrapper<"sayhialice"_h, &contract_c1::sayhialice, contract_account>;

        using action1 = eosio::action_wrapper<"action1"_h, &contract_c2::action1, contract_account>;
        using action2 = eosio::action_wrapper<"action2"_h, &contract_c2::action2, contract_account>;

        template <typename F>
        void for_each_action(F&& f)
        {
            f("sayhi"_h, eosio::action_type_wrapper<&contract_c1::sayhi>{}, sayhi_ricardian);
            f("sayhialice"_h, eosio::action_type_wrapper<&contract_c1::sayhialice>{}, sayhialice_ricardian, "someone");

            f("action1"_h, eosio::action_type_wrapper<&contract_c2::action1>{}, action1_ricardian);
            f("action2"_h, eosio::action_type_wrapper<&contract_c2::action2>{}, action2_ricardian, "someone");
        }

        inline bool eosio_apply(uint64_t receiver, uint64_t code, uint64_t action)
        {
            bool executed = false;
            if (code == receiver)
            {
                switch (action)
                {
                    case eosio::hash_name("sayhi"):
                        executed = eosio::execute_action(eosio::name(receiver), eosio::name(code), &class1_contract::sayhi);
                        break;
                    case eosio::hash_name("sayhialice"):
                        executed = eosio::execute_action(eosio::name(receiver), eosio::name(code), &class1_contract::sayhialice);
                        break;
                    case eosio::hash_name("action1"):
                        executed = eosio::execute_action(eosio::name(receiver), eosio::name(code), &class2_contract::action1);
                        break;
                    case eosio::hash_name("action2"):
                        executed = eosio::execute_action(eosio::name(receiver), eosio::name(code), &class2_contract::action2);
                        break;
                }
                eosio::check(executed == true, "unknown action");
            }
            return executed;
        }

        /*  Would be nice if there was a simple clsdk dispatcher helper 
         *  macro for multi-class contracts, for example:

            EOSIO_ACTIONS("contractname"_n, (
                class1_contract,
                action(sayhi, name, ricardian_contract(sayhi_ricardian))
            ),(
                class2_contract,
                action(saybye, name, ricardian_contract(saybye_ricardian))
            ))
        */

    }  // namespace actions

}  // namespace contract_name
