#include <iostream>

class Printer
{
    private:
        std::string _name;
        int         _avaliablePaper;
    public:
        Printer(std::string name, int paper): _name(name), _avaliablePaper(paper) {}
        void Print(std::string text)
        {
            int requiredPaper = text.length() / 10;

            // if (requiredPaper > _avaliablePaper)
            //     throw "No paper...";
            if (requiredPaper > _avaliablePaper)
                throw 'A';
            std::cout << text << std::endl;
            _avaliablePaper -= requiredPaper;
        }
};

int     main(void)
{
    Printer my("teste", 10);

    try
    {
        my.Print("Hi, my name is Allan and I'm a Software Engineer!");
        my.Print("Hi, my name is Allan and I'm a Software Engineer!");
        my.Print("Hi, my name is Allan and I'm a Software Engineer!");
        my.Print("Hi, my name is Allan and I'm a Software Engineer!");
    }
    catch (const char *error)
    {
        std::cerr << "Execption: " << error << std::endl;
    }
    catch (int error)
    {
        std::cerr << "Execption: " << error << std::endl;
    }
    catch (...)
    {
        std::cerr << "Generic exception..." << std::endl;
    }

    return (0);
}