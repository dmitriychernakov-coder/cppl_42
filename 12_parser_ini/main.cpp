#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <regex> 


class IniParser {
    std::map<std::string, std::map<std::string, std::string>> map_var;

public:
    explicit IniParser(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Error no file " + filename);
        }

        std::string current_section;
        std::string line;

        while (std::getline(file, line)) {
            line = std::regex_replace(line, std::regex("^\\s+|\\s+$"), "");

            if (line.empty()) {
                continue;
            }

            size_t comment_str = line.find(';');
            if (comment_str != std::string::npos) {
                line = line.substr(0, comment_str);
                line = std::regex_replace(line, std::regex("^\\s+|\\s+$"), "");
                if (line.empty()) {
                    continue;
                }
            }

            if (line.front() == '[' && line.back() == ']') {
                current_section = std::regex_replace(line.substr(1, line.size() - 2), std::regex("^\\s+|\\s+$"), "");
                if (!current_section.empty()) {
                    map_var[current_section];
                }
                continue;
            }

            if (!current_section.empty()) {
                size_t pos = line.find('=');
                if (pos != std::string::npos) {
                    std::string key = std::regex_replace(line.substr(0, pos), std::regex("^\\s+|\\s+$"), "");
                    std::string value = std::regex_replace(line.substr(pos + 1), std::regex("^\\s+|\\s+$"), "");

                    if (!key.empty()) {
                        map_var[current_section][key] = value;
                    }
                }
            }
        }
    }



public:
    template<typename T>
    T getvalue(const std::string& section, const std::string& var) {
        T result{};
        //todo: получаем строку из имени переменной и секции в stringvalue
            std::string stringvalue = getvaluestring(section, var);
            
        //дальше может варьироваться в зависимости от фантазии typeid(int) == typeid(T)
        if constexpr (std::is_same<int, T>::value) {
            result = std::stoi(stringvalue);
        }
        else if constexpr (std::is_same<double, T>::value) {
            result = std::stod(stringvalue);
        }
        else if constexpr (std::is_same<std::string, T>::value) {
            result = stringvalue;
        }
        else
        {
        static_assert(sizeof(T) == -1, "no implementation for this type!");
        }
        //возвращаем результат
        return result;
    }
private:
    std::string getvaluestring(const std::string& section, const std::string& var) {
    //return "1.3";
    auto sec_var = map_var.find(section);
        if (sec_var == map_var.end()) {
            throw std::runtime_error(section + " not found");
        }
        auto var_val = sec_var->second.find(var);
        if (var_val == sec_var->second.end()) {
            throw std::runtime_error(var + " not found in " + section);
        }
        return var_val->second;
    } 
};

int main() {
    try {
        IniParser parser("file.ini");
        auto value = parser.getvalue<int>("Section1","var1");
        //auto value = parser.getvalue<std::string>("Section2","var2");
        //auto value = parser.getvalue<double>("Section1","var1");
        std::cout << "Value: " << value << "   in Section1.var1" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Undefinded error" << std::endl;
    }
    return 0;
}