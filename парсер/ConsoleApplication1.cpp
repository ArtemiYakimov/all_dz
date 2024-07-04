#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

class IniParser {
public:
    IniParser(const std::string& filename) {
        loadIniFile(filename);
    }

    template <typename T>
    T getValue(const std::string& sectionName, const std::string& valueName) {
        if (data.find(sectionName) == data.end() || data[sectionName].find(valueName) == data[sectionName].end()) {
            throw std::runtime_error("Value not found");
        }

        try {
            return convertToType<T>(data[sectionName][valueName]);
        }
        catch (const std::exception& e) {
            throw std::runtime_error("Error converting value: " + std::string(e.what()));
        }
    }

private:
    void loadIniFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }

        std::string currentSection;
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == ';') {
                continue;
            }
            else if (line[0] == '[' && line[line.length() - 1] == ']') {
                currentSection = line.substr(1, line.length() - 2);
            }
            else {
                size_t equalPos = line.find('=');
                if (equalPos != std::string::npos) {
                    std::string name = line.substr(0, equalPos);
                    std::string value = line.substr(equalPos + 1);
                    data[currentSection][name] = value;
                }
            }
        }
    }

    template <typename T>
    T convertToType(const std::string& value) {
        std::istringstream iss(value);
        T result;
        iss >> result;
        return result;
    }

    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> data;
};

int main() {
    try {
        IniParser parser("example.ini");
        int intValue = parser.getValue<int>("Section1", "var1");
        std::string stringValue = parser.getValue<std::string>("Section2", "var2");
        std::cout << "int value: " << intValue << std::endl;
        std::cout << "string value: " << stringValue << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}