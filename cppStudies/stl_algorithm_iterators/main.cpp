#include <iostream>
#include <algorithm>
#include <vector>

void print(const std::vector<int>& v, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void triple_it(int &n)
{
    n = n * 3;
}

int main(void)
{
    std::vector<int> vector;

    vector.push_back(8);
    vector.push_back(5);
    vector.push_back(3);
    vector.push_back(10);
    vector.push_back(4);
    print(vector, 5);
    std::for_each(vector.begin(), vector.end(), triple_it);
    print(vector, 5);

    std::vector<int>::iterator it_front = vector.begin();   // Basicamente é um ponteiro para o prmeiro indice do array
    std::vector<int>::iterator it_back = vector.end();      // Basicamente é um ponteiro para o ultimo indice do array

    it_front += 1;  // Andamos um indice para direita no array
    it_back -= 1;   // Andamos um indice para esquerda no array

    std::for_each(it_front, it_back, triple_it);
    print(vector, 5);

    std::for_each(&vector[0], &vector[4], triple_it);
    print(vector, 5);

    return (0);
}