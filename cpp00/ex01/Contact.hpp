#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string darkestSecret;
        std::string phoneNumber;
    
    public:
        Contact();
        ~Contact();

        void    set_firstName();
        void    set_lastName();
        void    set_nickname();
        void    set_darkestSecret();
        void    set_phoneNumber();

        std::string get_firstName();
        std::string get_lastName();
        std::string get_nickname();
        std::string get_darkestSecret();
        std::string get_phoneNumber();

        void    show_contact();
};

#endif