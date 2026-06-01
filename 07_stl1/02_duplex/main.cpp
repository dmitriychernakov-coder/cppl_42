#include <iostream>
#include <string>
#include<set>
#include<stack>
#include<algorithm>
#include<vector>

int main()
{
    std::cout << "[IN]: " << std::endl;
    // std::string text = "12336324444";
    int len{5};
    std::cin >> len;
    std::cin.ignore();
    std::string text;
    char c;

    for(int i = 0; i < len; ++i) {
        if (std::cin.get(c)) {
            text += c;
            std::cin.ignore();
        }
    }

    std::set<char> char_set{text.begin(), text.end()};

    std::vector<char> char_vec(char_set.begin(), char_set.end());

    std::sort (char_vec.begin(), char_vec.end(), std::greater<>());

    std::cout << "[OUT]: " << std::endl;
    for(const auto& i:char_vec) {
         std::cout << i << std::endl;
    }        

    return 0;
}