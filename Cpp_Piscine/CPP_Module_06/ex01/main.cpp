#include <iostream>
#include <string>

typedef struct s_data {
    int someVal;
    std::string someStr;
}   Data;

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data my_data;
    my_data.someVal = 12;
    my_data.someStr = "this is a string";
    uintptr_t ptr = serialize(&my_data);
    Data *new_data = deserialize(ptr);
    std::cout << "my_data ptr: " << &my_data << "\nnew_data ptr:" << new_data << std::endl;
    std::cout << "\nmy_data.someVal = " << my_data.someVal << "\nnew_data.someVal = " << new_data->someVal << std::endl;
    std::cout << "\nmy_data.someStr = " << my_data.someStr << "\nnew_data.someStr = " << new_data->someStr << std::endl;
    return 0;
}