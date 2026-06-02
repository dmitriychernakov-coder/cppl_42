#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>

template <typename T>
void print_container(const T& container) {
    bool start = true;

    for(const auto& el:container) {
    
        if(!start) {
            std::cout << ", ";
        } 

        std::cout << el;
        start = false;
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = { "один", "два", "три", "четыре"}; 
    print_container(test_set);

    std::list<std::string> test_list = { "один", "два", "три", "четыре"}; 
    print_container(test_list);  

    std::vector<std::string> test_vector = { "один", "два", "три", "четыре"}; 
    print_container(test_vector);

    return 0;
}


