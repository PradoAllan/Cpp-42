#include <iostream>

class   Employee{
    private:
        std::string name;
        std::string position;
        float       salary;
        int         age;
    public:
        Employee();
        ~Employee();

        void        set_name(std::string name);
        void        set_position(std::string position);
        void        set_salary(float salary);
        void        set_age(int age);

        std::string get_name();
        std::string get_position();
        float       get_salary();
        int         get_age();
};