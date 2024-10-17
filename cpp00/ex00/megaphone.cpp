#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
			std::cout << "Testing: " << av[i];
	}
	return (1);
}

/*
int	main(int ac, char **av)
{
	char	s[30];

	std::cout << "Hello world!" << std::endl;
	std::cout << "Input your name" << std::endl;
	std::cin >> s;
	std::cout << "Hello, [" << s << "]" << std::endl;


	return (1);
}
*/
