#pragma once

# include <stack>
# include <string>
# include <exception>

class RPN
{
    private:
        const std::string   _input; 
        std::stack<int>     _stack;
        int                 _result;

        RPN(const RPN &src);
        void    execOperation(int n1, int n2, char operation);
    public:
        RPN(void);
        RPN(const std::string input);
        ~RPN(void);
        RPN &operator=(const RPN &src);
        
        int     getResult(void) const;

        int     sum(int n1, int n2) const;
        int     minus(int n1, int n2) const;
        int     multiply(int n1, int n2) const;
        int     divide(int n1, int n2) const;

        void    execute(void);


        class WrongRPNInput : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class WrongRPNInputChar : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};