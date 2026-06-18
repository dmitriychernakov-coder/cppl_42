#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <regex> 


class ini_parser {
    std::map<std::string, std::map<std::string, std::string>> map_var;

public:
    explicit ini_parser(const std::string& filename) {
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

    template <typename T>
    T get_value(const std::string& key_path) const {
        size_t dot_pos = key_path.find('.');
        if (dot_pos == std::string::npos) {
            throw std::runtime_error("Expect section.key");
        }

        std::string section = key_path.substr(0, dot_pos);
        std::string key = key_path.substr(dot_pos + 1);

        auto sec_var = map_var.find(section);
        if (sec_var == map_var.end()) {
            throw std::runtime_error("Swction " + section + " not finded");
        }

        auto var_dat = sec_var->second.find(key);
        if (var_dat == sec_var->second.end()) {
            throw std::runtime_error("Key  " + key + " not finded in '" + section);
        }

        try {
            return static_cast<T>(std::stoi(var_dat->second));
        } catch (const std::invalid_argument&) {
            throw std::runtime_error("Data  " + var_dat->second + " not converted to int");
        } 
    }

};

int main() {
    try {
        ini_parser parser("file.ini");
        int value = parser.get_value<int>("Section1.var1");
        std::cout << "Value: " << value << "   in Section1.var1" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Undefinded error" << std::endl;
    }
    return 0;
}