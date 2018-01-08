#ifndef _PUSHDOWNAUTOMATA
#define _PUSHDOWNAUTOMATA

#include <string>
#include <stack>
#include <array>
class DPDA
{
    int _currentState;
    std::stack<int> _stack;
    using DpdaMbFn = void(DPDA::*)();
    std::array<std::array<std::array<DpdaMbFn, 3>, 3>, 9> _dpdaTable;
    int interpreterInput(const char in) const;
    int getFromStack();
    void toState1_2Z();
    void toState1_00();
    void toState1_0Z();
    void toState2_1Z();
    void toState2_10();
    void toState2_11(); 
    void toState3_00();
    void toState4_00();  
    void toState5_2Z();
    void toState5_20();
    void toState5();
    void toState6();
    void toState7();
    void toState8_2Z();
    void toEndState();
public:
    DPDA();
    bool check(std::string input);
};

#endif
