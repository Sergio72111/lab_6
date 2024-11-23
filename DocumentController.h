#ifndef DOCUMENTCONTROLLER_H // Проверка, определен ли уже заголовок DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H // Определение заголовка DOCUMENTCONTROLLER_H

#include <memory> // Подключение библиотеки для работы с умными указателями
#include <vector> // Подключение библиотеки для работы с векторами
#include <iostream> // Подключение библиотеки для ввода-вывода
#include "Document.h" // Подключение заголовка Document.h, который содержит определение класса Document

class DocumentController { 
public: 

    void createDocument() { // Метод для создания нового документа
        std::cout << "Введите имя нового документа: "; 
        std::string name; // Переменная для хранения имени документа
        std::cin >> name; // Считывание имени документа с ввода
        auto newDocument = std::make_shared<Document>(name); // Создание нового объекта Document
        documents.push_back(newDocument); // Добавление документа в вектор
        std::cout << "Создан документ " << newDocument->getName() << std::endl; 
    }

    void openDocument(const std::string& filename) { // Метод для открытия существующего документа по имени файла
        for (const auto& doc : documents) { // Перебор всех документов в векторе
            if (doc->getName() == filename) { // Проверка, совпадает ли имя документа с именем файла
                std::cout << "Открыт документ " << filename << std::endl; 
                std::cout << "Примитивы в документе:" << std::endl; 
                doc->drawAllPrimitives(); // Вызов метода для отрисовки всех примитивов в документе
                return; // Выход из метода после успешного открытия документа
            }
        }
        std::cout << "Документ '" << filename << "' не найден."<< std::endl; // Если документ не найден
    }

    void saveDocument(const std::string& filename) { // Метод для сохранения документа в файл
        for (const auto& doc : documents) { // Перебор всех документов в векторе
            if (doc->getName() == filename) { // Проверка, совпадает ли имя документа с именем файла
                doc->saveToFile(filename); // Вызов метода для сохранения документа в файл
                std::cout << "Примитивы в документе:" << std::endl; 
                doc->drawAllPrimitives(); // Вызов метода для отрисовки всех примитивов в документе после сохранения
                return; // Выход из метода после успешного сохранения документа
            }
        }
        std::cout << "Документ '" << filename << "' не найден."<< std::endl; // Если документ не найден
    }

    void addPrimitive(const std::string& type) { // Метод для добавления примитива в документ по типу примитива
        if (!documents.empty()) { // Проверка, существует ли хотя бы один документ
            std::cout << "Введите имя примитива: "; 
            std::string name; // Переменная для хранения имени примитива
            std::cin >> name; // Считывание имени примитива с ввода
            
            auto currentDocument = documents.back(); // Используем последний созданный документ

            if (type == "rectangle") {
                std::cout << "Введите ширину: "; 
                double width; 
                std::cin >> width; 
                std::cout << "Введите высоту: "; 
                double height; 
                std::cin >> height; 
                currentDocument->addPrimitive(std::make_shared<Rectangle>(name, width, height)); 

            } else if (type == "square") {
                std::cout << "Введите длину стороны: "; 
                double side; 
                std::cin >> side; 
                currentDocument->addPrimitive(std::make_shared<Square>(name, side)); 

            } else if (type == "circle") {
                std::cout << "Введите радиус: "; 
                double radius; 
                std::cin >> radius; 
                currentDocument->addPrimitive(std::make_shared<Circle>(name, radius)); 

            } else if (type == "triangle") {
                std::cout << "Введите длину стороны a: "; 
                double a; 
                std::cin >> a; 
                std::cout << "Введите длину стороны b: "; 
                double b; 
                std::cin >> b; 
                std::cout << "Введите длину стороны c: "; 
                double c;  
                std::cin >> c;
                currentDocument->addPrimitive(std::make_shared<Triangle>(name, a, b, c)); 

            } else {
                std::cout << "Неподдерживаемый тип примитива.\n";  
            }
        } else {
            std::cout << "Документ не создан.\n";  
        }
    }
    
    void removePrimitive(const std::string& primitiveName, const std::string& primitiveType) {  // Метод для удаления примитива по имени и типу 
        if (!documents.empty()) {  // Проверка, существует ли хотя бы один документ 
            documents.back()->removePrimitive(primitiveName, primitiveType);  // Вызов метода удаления примитива из последнего созданного документа 
        } else {  // Если документов нет 
            std::cout << "Документ не создан." << std::endl;  
        }
    }

    void removeDocument(const std::string& filename) {  // Метод для удаления документа по имени файла 
        for (auto it = documents.begin(); it != documents.end(); ++it) {  // Перебор всех документов в векторе
            if ((*it)->getName() == filename) {  // Проверка, совпадает ли имя документа с именем файла 
                std::cout << "Удаление документа '" << filename << "' и всех содержащихся примитивов:" << std::endl;
                (*it)->deleteAllPrimitives();  // Вызов метода удаления всех примитивов из документа 
                documents.erase(it);  // Удаление указателя на документ из вектора
                return;
            }
        }
        std::cout << "Документ '" << filename << "' не найден." << std::endl;  // Если документ не найден
    }

private:  // Объявление приватной секции класса 
    std::vector<std::shared_ptr<Document>> documents;  // Вектор умных указателей на объекты Document, представляющие все открытые документы 
};

#endif  // Завершение условия компиляции для заголовка DOCUMENTCONTROLLER_H  