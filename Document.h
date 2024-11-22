#ifndef DOCUMENT_H // Проверка, определен ли уже заголовок DOCUMENT_H
#define DOCUMENT_H // Определение заголовка DOCUMENT_H

#include <string> 
#include <vector> 
#include <memory> 
#include "Primitive.h" 
#include <algorithm> 

class Document { 
public: 

    Document(const std::string& name) : name(name) {} // Конструктор класса, инициализирующий имя документа

    void addPrimitive(std::shared_ptr<Primitive> primitive) { // Метод для добавления примитива в документ
        primitives.push_back(primitive); // Добавление примитива в вектор примитивов
        std::cout << "В документ " << name << " добавлен примитив " << primitive->getType() << ": "<< primitive->getName() << std::endl; // Вывод сообщения о добавлении примитива
    } 

    void removePrimitive(const std::string& primitiveName, const std::string& primitiveType) { // Метод для удаления примитива по имени и типу
        auto it = std::find_if(primitives.begin(), primitives.end(),[&](const std::shared_ptr<Primitive>& p) {return p->getName() == primitiveName && p->getType() == primitiveType;}); // Поиск примитива в векторе по имени и типу
        if (it != primitives.end()) { // Если примитив найден
            std::cout << "Из документа " << name << " удален примитив " << (*it)->getName() << " типа " << (*it)->getType() << std::endl;  
            primitives.erase(it); // Удаление найденного примитива из вектора
        } else { // Если примитив не найден
            std::cout << "Примитив с именем '" << primitiveName << "' типа '" << primitiveType << "' не найден." << std::endl; 
        }
    }

    void saveToFile(const std::string& filename) { // Метод для сохранения документа в файл
        std::cout << "Документ " << name << " сохранен в файл " << filename << std::endl; 
    }

    void loadFromFile(const std::string& filename) { // Метод для загрузки документа из файла
        std::cout << "Документ " << name << " загружен из файла " << filename << std::endl; 
    }

    std::string getName() const { // Метод для получения имени документа
        return name; // Возврат имени документа
    }

    void drawAllPrimitives() const { // Метод для отрисовки всех примитивов в документе
        for (const auto& primitive : primitives) { // Цикл по всем примитивам в векторе
            std::cout << "Отрисовка " << primitive->get() << std::endl;; 
        }
    }

    void deleteAllPrimitives() const { // Метод для удаления всех примитивов в документе
        for (const auto& primitive : primitives) { // Цикл по всем примитивам в векторе
            std::cout << "Удаление " << primitive->get() << std::endl;; 
        }
    }

private: // Объявление приватной секции класса
    std::string name; // Имя документа (строка)
    std::vector<std::shared_ptr<Primitive>> primitives; // Вектор умных указателей на объекты Primitive, содержащий все примитивы документа
};

#endif // Завершение условия компиляции для заголовка DOCUMENT_H