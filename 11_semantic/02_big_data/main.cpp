#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

class biging_integer {

    std::vector<int> digits;

    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:

    explicit biging_integer(const std::string& str = "0") {

        size_t start_num = 0;

        if (str.empty()) {
            digits.push_back(0);
            return;
        }


        for (size_t i = str.size(); i > start_num; --i) {
            char chr = str[i-1];
            if (chr < '0' || chr > '9') {
                throw std::invalid_argument("Wrong  number");
            }
            digits.push_back(chr - '0');
        }

    }

    ~biging_integer() = default;

    biging_integer(const biging_integer& other) = default;

    biging_integer(biging_integer&& other) noexcept
        : digits(std::move(other.digits)) {
    }

    biging_integer& operator =(biging_integer&& other) noexcept {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }

    biging_integer operator +(const biging_integer& other) {
        biging_integer result;
        result.digits.resize(std::max(this->digits.size(), other.digits.size()) + 1);

        int calc = 0;
        for (size_t i = 0; i < result.digits.size(); ++i) {
            
            int sum = calc;

            if (i < this->digits.size()) {
                sum += this->digits[i];
            };

            if (i < other.digits.size()) {
                sum += other.digits[i];
            };

            result.digits[i] = sum % 10;
            calc = sum / 10;
        }

        return result;
    }

    biging_integer operator*(const biging_integer& other) const {

        biging_integer result;

        for (size_t i = 0; i < other.digits.size(); ++i) {
            int calc = 0;
            biging_integer temp;

            for (size_t j = 0; j < this->digits.size() || calc > 0; ++j) {
                int prod = calc;
                
                if (j < this->digits.size()) {
                    prod += this->digits[j] * other.digits[i];
                }

                temp.digits.push_back(prod % 10);
                calc = prod / 10;
            }

            for (size_t k = 0; k < i; ++k) {
                temp.digits.push_back(0);
            }

            result = result + temp;
        }

        return result;
    }

    biging_integer operator*(int multi) const {
        return (*this) * biging_integer(std::to_string(multi));
                
        if (multi == 0) {
            return biging_integer("0");
        };

        biging_integer result;
        int calc = 0;

        for (size_t i = 0; i < this->digits.size() || calc > 0; ++i) {
            int prod = calc;
            if (i < this->digits.size()) {
                prod += this->digits[i] * multi;
            }

            result.digits.push_back(prod % 10);
            calc = prod / 10;
        }
        return result;
    }

    friend std::ostream& operator <<(std::ostream& ost, const biging_integer& bigin);
};

std::ostream& operator <<(std::ostream& ost, const biging_integer& bigin) {

    biging_integer temp(bigin); 
    temp.trim();

    for (auto i = temp.digits.rbegin(); i != temp.digits.rend(); ++i) {
        ost << *i;
    }

        return ost;
    }


int main() {
    try {
        auto number1 = biging_integer("114575");
        auto number2 = biging_integer("78524");

        //auto number2 = biging_integer("78524O");

        std::cout << "Число 1: " << number1 << std::endl;
        std::cout << "Число 2: " << number2 << std::endl;

  
        auto result_add = number1 + number2;
        std::cout << "Сложение: " << result_add << std::endl;

        auto result_mult = number1 * 2;
        std::cout << "Умножение: " << result_mult << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}