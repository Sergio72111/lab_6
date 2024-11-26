#ifndef DOCUMENTCONTROLLER_H 
#define DOCUMENTCONTROLLER_H

#include <memory> 
#include <iostream> 
#include <unordered_map> 
#include "Document.h"

class DocumentController { // Определение класса DocumentController
public:
    void createDocument() { // Метод для создания нового документа
        std::cout << "Введите имя нового документа: "; 
        std::string name; // Переменная для хранения имени документа
        std::cin >> name; // Считывание имени документа с ввода

        // Проверка, существует ли документ с таким именем
        if (documents.find(name) != documents.end()) { 
            std::cout << "Документ с таким именем уже существует." << std::endl; 
            return; // Выход из метода
        }

        documents[name] = std::make_shared<Document>(name); // Создание нового документа и добавление его в хэш-таблицу
        std::cout << "Создан документ " << name << std::endl; 
    }

    void openDocument(const std::string& filename) { // Метод для открытия существующего документа по имени файла
        auto it = documents.find(filename); // Поиск документа в хэш-таблице
        if (it != documents.end()) { // Если документ найден
            auto& document = it->second; // Получение указателя на документ
            std::cout << "Открыт документ " << filename << std::endl; 
            std::cout << "Примитивы в документе:" << std::endl;
            document->drawAllPrimitives(); // Вызов метода для отображения всех примитивов в документе
        } else {
            std::cout << "Документ не найден." << std::endl; 
        }
    }

    void saveDocument(const std::string& filename) { // Метод для сохранения существующего документа по имени файла
        auto it = documents.find(filename); // Поиск документа в хэш-таблице
        if (it != documents.end()) { // Если документ найден
            auto& document = it->second; // Получение указателя на документ
            document->saveToFile(filename); // Вызов метода для сохранения документа в файл
            std::cout << "Документ '" << filename << "' сохранен." << std::endl; 
            std::cout << "Примитивы в документе:" << std::endl;
            document->drawAllPrimitives(); // Вызов метода для отображения всех примитивов в документе после сохранения
        } else {
            std::cout << "Документ не найден." << std::endl; 
        }
    }

    void addPrimitive(const std::string& filename, const std::string& type) { // Метод для добавления примитива в документ по имени файла и типу примитива
        auto it = documents.find(filename); // Поиск документа в хэш-таблице
        if (it != documents.end()) { // Если документ найден
            auto& document = it->second; // Получение указателя на документ

            std::cout << "Введите имя примитива: "; 
            std::string name; // Переменная для хранения имени примитива
            std::cin >> name; // Считывание имени примитива с ввода

            if (type == "rectangle") { // Если тип примитива - прямоугольник
                double width, height; // Переменные для хранения ширины и высоты прямоугольника
                std::cout << "Введите ширину: "; 
                std::cin >> width; // Считывание ширины с ввода
                std::cout << "Введите высоту: "; 
                std::cin >> height; // Считывание высоты с ввода
                document->addPrimitive(std::make_shared<Rectangle>(name, width, height)); // Создание прямоугольника и добавление его в документ

            } else if (type == "square") { // Если тип примитива - квадрат
                double side; 
                std::cout << "Введите длину стороны: "; 
                std::cin >> side; 
                document->addPrimitive(std::make_shared<Square>(name, side)); // Создание квадрата и добавление его в документ

            } else if (type == "circle") { // Если тип примитива - круг
                double radius;
                std::cout << "Введите радиус: "; 
                std::cin >> radius; 
                document->addPrimitive(std::make_shared<Circle>(name, radius));  // Создание круга и добавление его в документ

            } else if (type == "triangle") {  // Если тип примитива - треугольник 
                double a, b, c; 
                std::cout << "Введите длину стороны a: "; 
                std::cin >> a; 
                std::cout << "Введите длину стороны b: "; 
                std::cin >> b; 
                std::cout << "Введите длину стороны c: "; 
                std::cin >> c; 
                document->addPrimitive(std::make_shared<Triangle>(name, a, b, c));  // Создание треугольника и добавление его в документ

            } else {
                std::cout << "Неподдерживаемый тип примитива.\n"; 
            }
        } else {
            std::cout << "Документ не найден.\n";  
        }
    }

    void removePrimitive(const std::string& filename, const std::string& primitiveName, const std::string& primitiveType) {  // Метод для удаления примитива из документа по имени файла, имени и типу примитива 
        auto it = documents.find(filename);  // Поиск документа в хэш-таблице 
        if (it != documents.end()) {  // Если документ найден 
            auto& document = it->second;  // Получение указателя на документ 
            document->removePrimitive(primitiveName, primitiveType);  // Вызов метода для удаления примитива из документа  
        } else {
            std::cout << "Документ не найден." << std::endl;   
        }
    }

    void removeDocument(const std::string& filename) {  // Метод для удаления документа по имени файла  
        auto it = documents.find(filename);  // Поиск документа в хэш-таблице  
        if (it != documents.end()) {  // Если документ найден  
            auto& document = it->second;  // Получение указателя на документ  
            std::cout << "Удаление документа '" << filename << "' и всех содержащихся примитивов:" << std::endl;  
            document->deleteAllPrimitives();  // Вызов метода для удаления всех примитивов из документа  
            documents.erase(it);  // Удаление документа из хэш-таблицы  
        } else {
            std::cout << "Документ не найден." << std::endl;   
        }
    }

private:
    // Использование карты для хранения документов по их именам  
    std::unordered_map<std::string, std::shared_ptr<Document>> documents;  // Хэш-таблица для хранения указателей на документы  
};

#endif  // Завершение условной компиляции  