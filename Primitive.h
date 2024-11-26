#ifndef PRIMITIVE_H 
#define PRIMITIVE_H 

#include <string> 
#include <sstream> 

class Primitive { // Определение абстрактного базового класса Primitive
public: // Объявление публичной секции класса

    Primitive(const std::string& name, const std::string& type) : name(name), type(type) {} // Конструктор класса, инициализирующий имя и тип примитива 

    std::string getName() const { // Метод для получения имени примитива
        return name; // Возврат имени примитива
    }

    std::string getType() const { // Метод для получения типа примитива
        return type; // Возврат типа примитива
    }

    virtual ~Primitive() = default; // Виртуальный деструктор для полиморфизма, позволяет корректно освобождать ресурсы производных классов

    virtual void draw() = 0; // Чисто виртуальный метод для отрисовки примитива (должен быть реализован в производных классах)
    virtual std::string get() const = 0; // Чисто виртуальный метод для получения информации о примитиве (должен быть реализован в производных классах)

private: // Объявление приватной секции класса
    std::string name; // Имя примитива (строка)
    std::string type; // Тип примитива (строка)
};

class Rectangle : public Primitive { // Определение класса Rectangle, наследующего от Primitive
public: // Объявление публичной секции класса
    Rectangle(const std::string& name, double width, double height) : // Конструктор класса, инициализирующий имя, ширину и высоту
        Primitive(name, "rectangle"), width(width), height(height) {} // Инициализация базового класса с типом "rectangle"

    void draw() override { // Переопределение метода draw для отрисовки прямоугольника
        std::cout << "Отрисовка прямоугольника " << getName() << " (стороны: " << width << ", " << height << ")" << std::endl; 
    }
    
    double getWidth() const { return width; } // Метод для получения ширины прямоугольника

    std::string get() const override { // Переопределение метода get для получения информации о прямоугольнике
        return "прямоугольника " + getName() + " (стороны: " + std::to_string(width) + ", " + std::to_string(height) + ")"; 
    }

private: // Объявление приватной секции класса
    double width; // Ширина прямоугольника
    double height; // Высота прямоугольника
};

class Square : public Primitive { 
public: // Объявление публичной секции класса
    Square(const std::string& name, double side) : Primitive(name, "square"), side(side) {}

    void draw() override { // Переопределение метода draw для отрисовки квадрата
        std::cout << "Отрисовка квадрата " << getName() << " (длина: " << side << ")" << std::endl; 
    }

    std::string get() const override { // Переопределение метода get для получения информации о квадрате
        return "квадрата " + getName() + " (длина: " + std::to_string(side) + ")"; // Формирование строки с информацией о квадрате
    } 
private: // Объявление приватной секции класса
    double side; 
};

class Circle : public Primitive { // Определение класса Circle, наследующего от Primitive
public: // Объявление публичной секции класса
    Circle(const std::string& name, double radius) : Primitive(name, "circle"), radius(radius) {} // Конструктор класса инициализирует имя и радиус круга

    void draw() override { // Переопределение метода draw для отрисовки круга
        std::cout << "Отрисовка круга " << getName() << " (радиус: " << radius << ")" << std::endl; 
    }

    std::string get() const override { // Переопределение метода get для получения информации о круге
        return "круга " + getName() + " (радиус: " + std::to_string(radius) + ")"; // Формирование строки с информацией о круге
    }

private: // Объявление приватной секции класса
    double radius; // Радиус круга
};

class Triangle : public Primitive { // Определение класса Triangle, наследующего от Primitive
public: // Объявление публичной секции класса
    Triangle(const std::string& name, double a, double b, double c) : Primitive(name, "triangle"), a(a), b(b), c(c) {} // Конструктор класса инициализирует имя и длины сторон треугольника

    void draw() override { // Переопределение метода draw для отрисовки треугольника
        std::cout << "Отрисовка треугольника " << getName() << " (стороны: " << a << ", " << b << ", " << c << ")" << std::endl; 
    }

    std::string get() const override { // Переопределение метода get для получения информации о треугольнике
        return "треугольника " + getName() + " (стороны: " + std::to_string(a) + ", " + std::to_string(b)  + ", " + std::to_string(c)+ ")";  // Формирование строки с информацией о треугольнике 
    }
private:  // Объявление приватной секции класса 
    double a, b, c;  // Длины сторон треугольника 
};

#endif  // Завершение условия компиляции для заголовка PRIMITIVE_H 