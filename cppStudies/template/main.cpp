#include <iostream>

template <typename T, typename U>
class Pair
{
    private:
        T const &_lhs;
        U const &_rhs;

        Pair<T, U>(void);

    public:
        Pair<T, U>(T const &lhs, U const &rhs): _lhs(lhs), _rhs(rhs)
        {
            std::cout << "Generic template class." << std::endl;
            return ;
        }

        ~Pair<T, U>(void) {}

        T const & fst(void) const {return this->_lhs;}
        T const & snd(void) const {return this->_rhs;}
};