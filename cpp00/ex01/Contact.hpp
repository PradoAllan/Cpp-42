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
        ContactParams(std::string name, std::string lastName);
        ~Contact(); // Destructor
        // Setters
        void    set_name(std::string name);
        void    set_lastName(std::string lastName);
        void    set_nickname(std::string nickname);
        void    set_darkestSecret(std::string darkestSecret);
        void    set_phoneNumber(std::string phoneNumber);
        // Getters
        std::string set_name(std::string name);
        std::string set_lastName(std::string lastName);
        std::string set_nickname(std::string nickname);
        std::string set_darkestSecret(std::string darkestSecret);
        std::string set_phoneNumber(std::string phoneNumber);
        // Other methods
}

#endif