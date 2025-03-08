#include <iostream>
#include <stdexcept>

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

class custom_exception : public std::exception
{
    virtual const char* what() const _NOEXCEPT
    {
        return ("Custom exception");
    }
};

void function()
{
    throw 42;
}
void function2()
{
    function();
}


int     main(void)
{
    // Printer my("teste", 10);

    // try
    // {
    //     my.Print("Hi, my name is Allan and I'm a Software Engineer!");
    //     my.Print("Hi, my name is Allan and I'm a Software Engineer!");
    //     my.Print("Hi, my name is Allan and I'm a Software Engineer!");
    //     my.Print("Hi, my name is Allan and I'm a Software Engineer!");
    // }
    // catch (const char *error)
    // {
    //     std::cerr << "Execption: " << error << std::endl;
    // }
    // catch (int error)
    // {
    //     std::cerr << "Execption: " << error << std::endl;
    // }
    // catch (...)
    // {
    //     std::cerr << "Generic exception..." << std::endl;
    // }

    // std::string word = "allan";

    // try
    // {
    //     std::cout << word.at(0) << std::endl;
    //     //std::cout << word.at(5) << std::endl;
    //     int *arr = new int[999999999999999];
    //     arr[0] = 0;
    // }
    // // catch (std::out_of_range& e)
    // // {
    // //     std::cerr << "Exception: " << e.what() << std::endl;
    // // }
    // // catch (std::bad_alloc& e)
    // // {
    // //     std::cerr << "Exception: " << e.what() << std::endl;
    // // }
    // catch (std::exception &e)
    // {
    //     std::cerr << "Base class: " << e.what() << std::endl;
    // }
    // catch (...)
    // {
    //     std::cerr << "Exception caught." << std::endl;
    // }

    try
    {
        //throw std::exception();
        //throw std::runtime_error("test");
        // throw custom_exception();
        // throw 20;
        function2();
    }
    catch(std::exception& e)
    {
        std::cerr << "Test: " << e.what() << std::endl;
    }
    catch (int error)
    {
        std::cerr << "int error code: " << error << std::endl;
    }
    

    return (0);
}