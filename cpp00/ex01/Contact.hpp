#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
//first name, last name, nickname, phone number, and darkest secret.

class   Contact
{
    private:
        std::string name;
        std::string lastName;
        std::string nickname;
        std::string darkestSecret;
        std::string phoneNumber;
    public:
        Contact(); // Constructor
        //void    ContactParams(std::string name, std::string lastName);
        ~Contact(); // Destructor
        // Setters
        void    set_name(std::string name);
        void    set_lastName(std::string lastName);
        void    set_nickname(std::string nickname);
        void    set_darkestSecret(std::string darkestSecret);
        void    set_phoneNumber(std::string phoneNumber);
        // Getters
        std::string get_name();
        std::string get_lastName();
        std::string get_nickname();
        std::string get_darkestSecret();
        std::string get_phoneNumber();
        // Other methods
        void    showAttributes();
};

#endif