#pragma once

# include <iostream>

class Whatever
{
    private:

    public:
        Whatever(void);
        Whatever(const Whatever &src);
        ~Whatever(void);

        Whatever &operator=(const Whatever &src);

        template <typename T>
        static void swap(T &a, T &b)
        {
            T c;

            c = a;
            a = b;
            b = c;
        };

        template <typename T>
        static T min(T a, T b)
        {
            return ((b <= a) ? b : a);
        };

        template <typename T>
        static T max(T a, T b)
        {
            return ((b >= a) ? b : a);
        };
};