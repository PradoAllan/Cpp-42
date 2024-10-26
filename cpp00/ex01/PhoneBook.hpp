#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[3];
		int		counter;
		int		index;
	public:
		PhoneBook(); // Constructor
		~PhoneBook(); // Destructor
		// Setters
		void	set_counter(int counter);
		void	set_index(int index);
		// Getters
		int		get_counter();
		int		get_index();
		// Other methods
		void	showAllContacts();
		void	addNewContact(std::string name,
								std::string lastName,
								std::string nickname,
								std::string darkestSecret,
								std::string phoneNumber);
		void	addFunction();
		void	searchFunction(std::string option);
		void	incrementIndex();
};

#endif