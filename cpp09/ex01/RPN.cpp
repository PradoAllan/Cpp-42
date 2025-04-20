#include "RPN.hpp"
#include <iostream>

// RPN(void);
RPN::RPN(void): _input(NULL) {}

// RPN(const char *input);
RPN::RPN(const std::string input): _input(input) {}

// RPN(const RPN &src);
RPN::RPN(const RPN &src)
{
    *this = src;
}

// ~RPN(void);
RPN::~RPN(void) {}

// RPN &operator=(const RPN &src);
RPN &RPN::operator=(const RPN &src)
{
    if (this != &src)
        this->_stack = src._stack;
    return (*this);
}

// int     getResult(void) const;
int RPN::getResult(void) const
{
    return (this->_result);
}

// int     sum(int n1, int n2);
int RPN::sum(int n1, int n2) const
{
    return (n1 + n2);
}

// int     minus(int n1, int n2);
int RPN::minus(int n1, int n2) const
{
    return (n1 - n2);
}

// int     multiply(int n1, int n2);
int RPN::multiply(int n1, int n2) const
{
    return (n1 * n2);
}

// int     divide(int n1, int n2);
int RPN::divide(int n1, int n2) const
{
    return (n1 / n2);
}

// void    execOperation(int n1, int n2, char operation);
void RPN::execOperation(int n1, int n2, char operation)
{
    if (operation == '+')
        this->_stack.push(this->sum(n1, n2));
    else if (operation == '-')
        this->_stack.push(this->minus(n1, n2));
    else if (operation == '*')
        this->_stack.push(this->multiply(n1, n2));
    else
        this->_stack.push(this->divide(n1, n2));
}

static bool isValidChar(char c, std::string values)
{
    bool counter = false;

    if (isdigit(c))
        return (true);
    for (size_t i = 0; i < values.size(); i++)
    {
        if (c == values[i])
            counter = true;
    }
    return (counter);
}

// void    execute(void);
void RPN::execute(void)
{
    int n1 = 0;
    int n2 = 0;

    if (this->_input.empty())
        throw(WrongRPNInput());
    for (size_t i = 0; i < this->_input.size(); i++)
    {
        //std::cout << std::endl;
        //std::cout << "'" << this->_input[i] << "'" << std::endl;
        if (!isValidChar(this->_input[i], " +-*/"))
            throw(WrongRPNInputChar());
        else if (this->_input[i] != ' ')
        {
            if (isdigit(this->_input[i]))
                this->_stack.push(this->_input[i] - '0');
            else if (this->_stack.size() < 2)
                throw(WrongRPNInput());
            else
            {
                n2 = this->_stack.top();
                this->_stack.pop();
                n1 = this->_stack.top();
                this->_stack.pop();
                //std::cout << "value1: " << n1 << std::endl;
                //std::cout << "value2: " << n2 << std::endl;
                this->execOperation(n1, n2, this->_input[i]);
                //std::cout << "result: " << this->_stack.top() << std::endl;
            }
        }
    }
    if (this->_stack.size() != 1)
        throw(WrongRPNInput());
    this->_result = this->_stack.top();
}

const char *RPN::WrongRPNInput::what() const throw()
{
    return ("The input is not in a Reverse Polish Notation rule...");
}

const char *RPN::WrongRPNInputChar::what() const throw()
{
    return ("Not valid Character in the Input...");
}