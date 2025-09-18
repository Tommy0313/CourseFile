//
// Created by User on 2024/12/27.
//

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <vector>
#include "Money.hpp"

class Checker{
public:
    int check(std::vector<Money> money){
        int ans = 0;
        for(auto i:money){
            ans += i.GetAmount();
        }
        return ans;
    }
    Checker(){

    }
};

#endif