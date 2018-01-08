#include "DPDA.h"
#include <iostream>

DPDA::DPDA() : _currentState(0), _stack(),  _dpdaTable(
{
    {
        { { { { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toState1_2Z } } } },
        { { { { &DPDA::toState1_00 , &DPDA::toEndState, &DPDA::toState1_0Z } },{ { &DPDA::toState2_10 , &DPDA::toEndState, &DPDA::toState2_1Z } },{ { &DPDA::toState5_20 , &DPDA::toEndState, &DPDA::toState5_2Z } } } },
        { { { { &DPDA::toState3_00 , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toState2_10 , &DPDA::toState2_11, &DPDA::toState2_1Z } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toState8_2Z } } } },
        { { { { &DPDA::toState4_00 , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } } } },
        { { { { &DPDA::toState3_00 , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toState8_2Z } } } },
        { { { { &DPDA::toState6 , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState , &DPDA::toEndState, } } } },
        { { { { &DPDA::toState7 , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState , &DPDA::toEndState, } } } },
        { { { { &DPDA::toState5 , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState , &DPDA::toEndState, } } } },
        { { { { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState, &DPDA::toEndState } },{ { &DPDA::toEndState , &DPDA::toEndState , &DPDA::toEndState, } } } }
    }
}
)
{}

int DPDA::interpreterInput(const char in) const
{
    switch(in)
    {
    case '0': return 0;
    case '1': return 1;
    case '-': return 2;
    default: return -1;
    }
}

int DPDA::getFromStack()
{
    int tmp = _stack.top();
    _stack.pop();
    return tmp;
}

void DPDA::toEndState()
{
    _currentState = -1;
}

void DPDA::toState1_2Z()
{
    _currentState = 1;
    _stack.push(2);
}

void DPDA::toState1_00()
{
    _currentState = 1;
    _stack.push(0);
    _stack.push(0);
}

void DPDA::toState1_0Z()
{
    _currentState = 1;
    _stack.push(2);
    _stack.push(0);
}

void DPDA::toState2_1Z()
{
    _currentState = 2;
    _stack.push(2);
    _stack.push(1);
}

void DPDA::toState2_10()
{
    _currentState = 2;
    _stack.push(0);
    _stack.push(1);
}

void DPDA::toState2_11()
{
    _currentState = 2;
}

void DPDA::toState3_00()
{
    _currentState = 3;
    _stack.push(0);
}

void DPDA::toState4_00()
{
    _currentState = 4;
}

void DPDA::toState5_2Z()
{
    _currentState = 5;
    _stack.push(2);
}

void DPDA::toState5_20()
{
    _currentState = 5;
    _stack.push(0);
}

void DPDA::toState5()
{
    _currentState = 5;
}

void DPDA::toState6()
{
    _currentState = 6;
}

void DPDA::toState7()
{
    _currentState = 7;
}

void DPDA::toState8_2Z()
{
    _currentState = 8;
    _stack.push(2);
}

bool DPDA::check(std::string input)
{
    _currentState = 0;

    if (!_stack.empty())
    {
        std::stack<int>().swap(_stack);
    }
    
    _stack.push(2);

    std::cout << input << ' ';
    for (auto c : input)
    {
       
        int num = interpreterInput(c);
        if (num == -1)
        {
            std::cout << '\'' << c << '\'' << " is unknown symbol\n";
            std::stack<int>().swap(_stack);
            return false;
        }
        int numStack = getFromStack();
        (this->*_dpdaTable[_currentState][num][numStack])();
        if (_currentState == -1)
        {
            std::cout << '\''<< c << '\'' << " is first wrong symbol\n";
            std::stack<int>().swap(_stack);
            return false;
        }
    }
    if (_currentState == 8 && _stack.top() == 2)
    {
        std::cout << " is correct. Congratulations\n";
        _stack.pop();
        return true;
    }
    if (_currentState == 5)
    {
        while (_stack.top() != 2 && _stack.top() == 0)
        {
            int numStack = getFromStack();
            (this->*_dpdaTable[_currentState][0][numStack])();
            
        }
        if (_currentState != 5)
        {
            std::cout << " is wrong, number of '0' is not multiple 3\n";
            std::stack<int>().swap(_stack);
            return false;
        }
        std::cout << " is correct. Congratulations\n";
        _stack.pop();
        return true;
    }
    std::stack<int>().swap(_stack);
    std::cout << " is wrong, second \'-\' is missed\n";
    return false;
}
       
