#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<double> components;

public:
    Vector(const std::vector<double>& components) : components(components) {}

    Vector add(const Vector& other) const {
        if (components.size() != other.components.size()) {
            throw std::invalid_argument("Vectors must have the same dimension");
        }

        std::vector<double> result(components.size());
        for (size_t i = 0; i < components.size(); ++i) {
            result[i] = components[i] + other.components[i];
        }

        return Vector(result);
    }

    Vector subtract(const Vector& other) const {
        if (components.size() != other.components.size()) {
            throw std::invalid_argument("Vectors must have the same dimension");
        }

        std::vector<double> result(components.size());
        for (size_t i = 0; i < components.size(); ++i) {
            result[i] = components[i] - other.components[i];
        }

        return Vector(result);
    }

    double dotProduct(const Vector& other) const {
        if (components.size() != other.components.size()) {
            throw std::invalid_argument("Vectors must have the same dimension");
        }

        double result = 0.0;
        for (size_t i = 0; i < components.size(); ++i) {
            result += components[i] * other.components[i];
        }

        return result;
    }

    void print() const {
        for (double component : components) {
            std::cout << component << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    Vector v1({ 1.0, 2.0, 3.0 });
    Vector v2({ 4.0, 5.0, 6.0 });

    Vector sum = v1.add(v2);
    Vector difference = v1.subtract(v2);
    double dotProduct = v1.dotProduct(v2);

    std::cout << "Сумма: ";
    sum.print();

    std::cout << "Разность: ";
    difference.print();

    std::cout << "Скалярное произведение: " << dotProduct << std::endl;

    return 0;
}
