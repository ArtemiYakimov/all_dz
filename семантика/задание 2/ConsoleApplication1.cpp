#include <string>
#include <algorithm>
#include <iostream>

class big_integer {
private:
    std::string value;

public:
    big_integer() : value("") {} // default constructor

    big_integer(const std::string& str) : value(str) {
        while (!value.empty() && value[0] == '0') {
            value.erase(0, 1);
        }
    }

    big_integer(big_integer&& other) noexcept : value(std::move(other.value)) {}

    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            value = std::move(other.value);
        }
        return *this;
    }

    big_integer operator+(const big_integer& other) const {
        big_integer result;
        result.value = add(value, other.value);
        return result;
    }

    big_integer operator*(int multiplier) const {
        big_integer result;
        result.value = multiply(value, multiplier);
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        os << num.value;
        return os;
    }

private:
    static std::string add(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0;

        size_t i = a.size();
        size_t j = b.size();

        while (i > 0 || j > 0 || carry) {
            int sum = carry;
            if (i > 0) {
                sum += a[--i] - '0';
            }
            if (j > 0) {
                sum += b[--j] - '0';
            }
            carry = sum / 10;
            result.push_back('0' + sum % 10);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }

    static std::string multiply(const std::string& num, int multiplier) {
        std::string result;
        int carry = 0;

        for (size_t i = num.size() - 1; i >= 0; --i) { // changed to size_t
            int product = (num[i] - '0') * multiplier + carry;
            carry = product / 10;
            result.push_back('0' + product % 10);
        }

        if (carry) {
            result.push_back('0' + carry);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    big_integer number1("114575");
    big_integer number2("78524");
    big_integer result = number1 + number2;
    std::cout << result << std::endl; // 193099

    return 0;
}
