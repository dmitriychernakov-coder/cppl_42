
#include<iostream>
#include<vector>
#include<utility>


template <typename T>
void move_vectors(std::vector<T>& two_move, std::vector<T>& one_move) {
    two_move = std::move(one_move); 
}
template<typename T>
void print_data(T data) {
    if (data.empty()) {
        std::cout << "No data!____________" <<std::endl;
        std::cout << std::endl;
        return;
    }

    for(const auto& it:data) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;

}

int main() {

    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << "one.size()  " << one.size() << std::endl;
    std::cout << "two.size()  " << two.size() << std::endl;
    std::cout << std::endl;
    
    std::cout << "one.data():  " << std::endl;
    print_data(one);
    std::cout << "two.data():  " << std::endl;
    print_data(two);

    move_vectors(two,one);
    std::cout << "one.size()  " << one.size() << std::endl;
    std::cout << "two.size()  " << two.size() << std::endl;
    std::cout << std::endl;
    
    std::cout << "one.data():  " << std::endl;
    print_data(one);
    std::cout << "two.data():  " << std::endl;
    print_data(two);
    return 0;

}



