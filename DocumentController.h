#ifndef DOCUMENTCONTROLLER_H // Проверка, определен ли уже заголовок DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H // Определение заголовка DOCUMENTCONTROLLER_H

#include <memory> // Подключение библиотеки для работы с умными указателями
#include "Document.h" // Подключение заголовка Document.h, который содержит определение класса Document

class DocumentController { 
public: 

    void createDocument() { // Метод для создания нового документа
        std::cout << "Введите имя нового документа: "; 
        std::string name; // Переменная для хранения имени документа
        std::cin >> name; // Считывание имени документа с ввода
        document = std::make_shared<Document>(name); // Создание нового объекта Document и присвоение его умному указателю
        std::cout << "Создан документ " << document->getName() << std::endl; 
    }

    void openDocument(const std::string& filename) { // Метод для открытия существующего документа по имени файла
        if (document->getName() == filename) { // Проверка, совпадает ли имя документа с именем файла
            std::cout << "Открыт документ " << filename << std::endl; 
            std::cout << "Примитивы в документе:" << std::endl; 
            document->drawAllPrimitives(); // Вызов метода для отрисовки всех примитивов в документе
        } else { // Если имя документа не совпадает с именем файла
            std::cout << "Документ не создан."<<std::endl; 
        }
    }

    void saveDocument(const std::string& filename) { // Метод для сохранения документа в файл
        if (document->getName() == filename) { // Проверка, совпадает ли имя документа с именем файла
            document->saveToFile(filename); // Вызов метода для сохранения документа в файл
            std::cout << "Примитивы в документе:" << std::endl; // Сообщение о выводе примитивов в документе
            document->drawAllPrimitives(); // Вызов метода для отрисовки всех примитивов в документе после сохранения
        } else { // Если имя документа не совпадает с именем файла
            std::cout << "Документ не создан."<<std::endl; // Вывод сообщения о том, что документ не создан
        }
    }

    void addPrimitive(const std::string& type) { // Метод для добавления примитива в документ по типу примитива
        if (document) { // Проверка, существует ли документ
            std::cout << "Введите имя примитива: "; // Запрос имени примитива у пользователя
            std::string name; // Переменная для хранения имени примитива
            std::cin >> name; // Считывание имени примитива с ввода

            if (type == "rectangle") { // Если тип примитива - прямоугольник
                std::cout << "Введите ширину: "; // Запрос ширины у пользователя
                double width; // Переменная для хранения ширины
                std::cin >> width; // Считывание ширины с ввода
                std::cout << "Введите высоту: "; // Запрос высоты у пользователя
                double height; // Переменная для хранения высоты
                std::cin >> height; // Считывание высоты с ввода
                document->addPrimitive(std::make_shared<Rectangle>(name, width, height)); // Создание и добавление нового прямоугольника в документ

            } else if (type == "square") { // Если тип примитива - квадрат
                std::cout << "Введите длину стороны: "; // Запрос длины стороны у пользователя
                double side; // Переменная для хранения длины стороны
                std::cin >> side; // Считывание длины стороны с ввода
                document->addPrimitive(std::make_shared<Square>(name, side)); // Создание и добавление нового квадрата в документ

            } else if (type == "circle") { // Если тип примитива - круг
                std::cout << "Введите радиус: "; // Запрос радиуса у пользователя
                double radius; // Переменная для хранения радиуса
                std::cin >> radius; // Считывание радиуса с ввода
                document->addPrimitive(std::make_shared<Circle>(name, radius)); // Создание и добавление нового круга в документ

            } else if (type == "triangle") { // Если тип примитива - треугольник
                std::cout << "Введите длину стороны a: "; // Запрос длины стороны a у пользователя
                double a; // Переменная для хранения длины стороны a
                std::cin >> a; // Считывание длины стороны a с ввода
                std::cout << "Введите длину стороны b: "; // Запрос длины стороны b у пользователя
                double b; // Переменная для хранения длины стороны b
                std::cin >> b; // Считывание длины стороны b с ввода
                std::cout << "Введите длину стороны c: "; // Запрос длины стороны c у пользователя
                double c; // Переменная для хранения длины стороны c 
                std::cin >> c;  // Считывание длины стороны c с ввода 
                document->addPrimitive(std::make_shared<Triangle>(name, a, b, c));  // Создание и добавление нового треугольника в документ

            } else {  // Если тип примитива неподдерживаемый 
                std::cout << "Неподдерживаемый тип примитива.\n";  // Вывод сообщения об ошибке 
            }
        } else {  // Если документ не существует 
            std::cout << "Документ не создан.\n";  // Вывод сообщения о том, что документ не создан 
        }
    }
    
    void removePrimitive(const std::string& primitiveName, const std::string& primitiveType) {  // Метод для удаления примитива по имени и типу 
        if (document) {  // Проверка, существует ли документ 
            document->removePrimitive(primitiveName, primitiveType);  // Вызов метода удаления примитива из документа 
        } else {  // Если документ не существует 
            std::cout << "Документ не создан." << std::endl;  // Вывод сообщения о том, что документ не создан 
        }
    }

    void removeDocument(const std::string& filename) {  // Метод для удаления документа по имени файла 
        if (document->getName() == filename) {  // Проверка, совпадает ли имя документа с именем файла 
            std::cout << "Удаление документа '" << filename << "' и всех содержащихся примитивов:" << std::endl;  // Вывод сообщения об удалении документа 
            document->deleteAllPrimitives();  // Вызов метода удаления всех примитивов из документа 
            document.reset();  // Удаляет указатель на документ; примитивы удаляются автоматически, если нет других ссылок 
        } else {  // Если имя документа не совпадает с именем файла 
            std::cout << "Документ не создан." << std::endl;  // Вывод сообщения о том, что документ не создан 
        }
    }
private:  // Объявление приватной секции класса 
    std::shared_ptr<Document> document;  // Умный указатель на объект Document, представляющий текущий открытый документ 
};

#endif  // Завершение условия компиляции для заголовка DOCUMENTCONTROLLER_H 