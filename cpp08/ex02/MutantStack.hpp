#pragma once

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack(void): std::stack<T>() {}
        MutantStack(const MutantStack &src): std::stack<T>(src) {}
        MutantStack &operator=(const MutantStack &src)
        {
            if (this != &src)
                this->c = src.c;
            return (*this);
        }

        ~MutantStack(void) {}

        typedef typename std::stack<T>::container_type::iterator reverse_iterator;
		MutantStack<T>::reverse_iterator rbegin (void) {
			return (this->c.begin());
		}
		MutantStack<T>::reverse_iterator rend (void){
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::const_iterator	const_reverse_iterator;
		MutantStack<T>::const_reverse_iterator rbegin (void) const {
			return (this->c.begin());
		}
		MutantStack<T>::const_reverse_iterator rend (void) const {
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::reverse_iterator iterator;
		MutantStack<T>::iterator begin (void) {
			return (this->c.rbegin());
		}
		MutantStack<T>::iterator end (void) {
			return (this->c.rend());
		}

		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_iterator;
		MutantStack<T>::const_iterator begin (void) const {
			return (this->c.rbegin());
		}
		MutantStack<T>::const_iterator end (void) const {
			return (this->c.rend());
		}
};