#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;

    data.value = 42;
	std::cout << "data address: " << &data << std::endl;
    std::cout << "data.value: " << data.value << std::endl;
    std::cout << "-----Calling Serializer()-----" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized Data: " << raw << std::endl;
    std::cout << "raw address: " << &raw << std::endl;
    std::cout << "-----Calling Deserializer()-----" << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "ptr address: " << ptr << std::endl;
    std::cout << "ptr.value: " << ptr->value << std::endl;
    return (0);
}