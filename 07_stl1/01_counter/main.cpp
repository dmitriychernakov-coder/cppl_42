#include <iostream>
#include <queue>
#include <string>
#include<set>

int main()
{
    // std::string text = "hello world!";
    std::string text;
    std::cout << "[IN]: ";
    std::getline(std::cin, text);

    std::multiset<char> char_multiset{text.begin(), text.end()};
    std::set<char> char_set(char_multiset.begin(), char_multiset.end());


    auto compar = [](const std::pair<int, char>& a, const std::pair<int, char>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    };
    
    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, decltype(compar)> prior_que(compar);


    for (const auto& c : char_set) {
        int freq = char_multiset.count(c);
        prior_que.push({freq, c});
    }

    std::cout << "[OUT]: " << std::endl;
    while (!prior_que.empty())
    {
        const auto& pair = prior_que.top();
        std::cout <<  pair.second << ": " << pair.first << std::endl;
        prior_que.pop();
    }
    

    return 0;
}