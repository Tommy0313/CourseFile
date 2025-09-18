#ifndef MONEY_HPP
#define MONEY_HPP

#include <utility>
enum class MoneyType{
    OOP,
    TWP,
    OOTD,
    PUA,
    FS
};
class Money{
private:
    int amount;
    MoneyType type;
public:
    Money(MoneyType type, int amount);
    int GetAmount() { return amount; }
    MoneyType GetType() { return type; }
};
#endif