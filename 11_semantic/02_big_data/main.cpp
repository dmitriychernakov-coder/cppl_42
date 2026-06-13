
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class big_integer {
    std::vector<char> digits;
public:

    big_integer() {
        digits.push_back(0);
    }

    explicit big_integer(const std::string& str_num) {
        input(str_num);
    }

    big_integer(const big_integer& other) : digits(other.digits) {}

    big_integer(big_integer&& other) noexcept : digits(std::move(other.digits)) {}

    big_integer& operator=(const big_integer& other) {
        if (this != &other) {
            digits = other.digits;
        }
        return *this;
    }

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        big_integer result;
        result.digits.clear();
        int shift = 0;
        auto it1 = this->digits.begin();
        auto it2 = other.digits.begin();

        while (it1 != this->digits.end() || it2 != other.digits.end()) {
            int digit1 = (it1 != this->digits.end()) ? *it1 : 0;
            int digit2 = (it2 != other.digits.end()) ? *it2 : 0;

            int sum = digit1 + digit2 + shift;
            shift = sum / 10;
            result.digits.push_back(sum % 10);

            if (it1 != this->digits.end()) ++it1;
            if (it2 != other.digits.end()) ++it2;
        }

        if (shift > 0) {
            result.digits.push_back(shift);
        }

        return result;
    }

    big_integer operator*(const big_integer& other) const {
        big_integer result;
        for (size_t i = 0; i < other.digits.size(); ++i) {
            int shift = 0;
            big_integer part_num;
            part_num.digits.clear();

            for (char d : this->digits) {
                int mult = d * other.digits[i] + shift;
                part_num.digits.push_back(mult % 10);
                shift = mult / 10;
            }
            if (shift > 0) {
                part_num.digits.push_back(shift);
            }

            for (size_t j = 0; j < i; ++j) {
                part_num.digits.insert(part_num.digits.begin(), 0);
            }

            result = result + part_num;
        }
        return result;
    }

    void input(const std::string& text) {
        bool is_digit = false;
        for (char c : text) {
            if (c >= '0' && c <= '9') {
                digits.push_back(c - '0');
                is_digit = true;
            } else {
                std::cerr << "Wrong digit: '" << c << "'" << std::endl;
                digits.clear();
                return;
            }
        }
        if (!is_digit) { digits.push_back(0); }
        std::reverse(digits.begin(), digits.end());
    }

    void print() const {
        if (digits.empty()) {
            std::cout << "No data";
            return;
        }
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            std::cout << static_cast<int>(*it);
        }
    }
};

    std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        num.print();
        return os;
    }

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");

    std::cout << "number 1: " << number1 << std::endl;
    std::cout << "number 2: " << number2 << std::endl;

    auto result = number1 + number2;

    std::cout << "result_sum: " << result << std::endl;

    auto result_mult = number1 * number2;
    std::cout << "result_mult: " << result_mult<< std::endl;

    return 0;
}