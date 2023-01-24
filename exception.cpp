#include <iostream>

class Fuzzy {
public:
    Fuzzy(double value, double minus, double plus) : value(value), minus(minus), plus(plus) {}

    double getValue() const {
        return value;
    }

    double getMinus() const {
        return minus;
    }

    double getPlus() const {
        return plus;
    }

private:
    double value;
    double minus;
    double plus;
};

std::ostream& operator<<(std::ostream& out, const Fuzzy& f) {
    return out << "{" << f.getValue() << " - " << f.getMinus() << ", " << f.getValue() << ", "
        << f.getValue() << " + " << f.getPlus() << "}";
}

Fuzzy operator+(const Fuzzy& a, const Fuzzy& b) {
    return { a.getValue() + b.getValue(), a.getMinus() + b.getMinus(), a.getPlus() + b.getPlus() };
}

Fuzzy operator*(const Fuzzy& a, const Fuzzy& b) {
    double value = a.getValue() * b.getValue();
    double minus = b.getValue() * a.getMinus() + a.getValue() * b.getMinus() + a.getMinus() * b.getMinus();
    double plus = b.getValue() * a.getPlus() + a.getValue() * b.getPlus() + a.getPlus() * b.getPlus();
    return { value, minus, plus };
}

int main() {

    Fuzzy a{ 5, 3, 2 }, b{ 3, 2, 1 };

    std::cout << "a = " << a << std::endl
        << "b = " << b << std::endl
        << "a + b = " << (a + b) << std::endl
        << "a * b = " << (a * b) << std::endl;
    
    return 0;
}
