#ifndef OPERATORSTACK_H
#define OPERATORSTACK_H

#include <stack>

class Operator;

class OperatorStack : public std::stack<Operator*>
{
};

#endif // OPERATORSTACK_H
