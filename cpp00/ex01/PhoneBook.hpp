#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     index;
        int     limit;
    public:
        PhoneBook();
        ~PhoneBook();

        void    set_index(int index);
        void    set_limit(int limit);

        int     get_index();
        int     get_limit();

        void    add_function();
        void    search_function();
        void    show_contacts();
};

#endif