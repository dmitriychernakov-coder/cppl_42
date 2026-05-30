#include <iostream>
#include <string>
#include<set>
#include<stack>

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


    std::multiset<char> char_multiset{text.begin(), text.end()};
    std::set<char> char_set(char_multiset.begin(), char_multiset.end());
    std::stack<char> char_stack;

    for (const auto& s : char_set) {
        char_stack.push(s);
    }
    

    std::cout << "[OUT]: " << std::endl;
    while (!char_stack.empty())  {
        std::cout << char_stack.top() << std::endl;
        char_stack.pop();
    }


    return 0;
}