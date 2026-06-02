#include<iostream>
#include<vector>
#include<algorithm>
#include <sstream>


int main() {


    std::cout << "[IN]: ";

    std::string text;
    // std::cout << "[IN]: ";
    std::getline(std::cin, text);
    // int num = std::stoi(text);
    std::istringstream text_num(text);
    std::vector<int> num_vec;
    int num;
    while (text_num >> num) {
        num_vec.push_back(num);
    }


    std::sort(num_vec.begin(), num_vec.end());
    auto unic_vec = std::unique(num_vec.begin(), num_vec.end());
    num_vec.erase(unic_vec, num_vec.end());

    std::cout << "[OUT]: ";
    for (const int& num : num_vec) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;



}