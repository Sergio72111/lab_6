#ifndef DOCUMENTCONTROLLER_H
#define DOCUMENTCONTROLLER_H

#include <memory>
#include <iostream>
#include <unordered_map>
#include "Document.h"

class DocumentController {
public:
    void createDocument() {
        std::cout << "Введите имя нового документа: ";
        std::string name;
        std::cin >> name;

        // Check if document already exists
        if (documents.find(name) != documents.end()) {
            std::cout << "Документ с таким именем уже существует." << std::endl;
            return;
        }

        documents[name] = std::make_shared<Document>(name);
        std::cout << "Создан документ " << name << std::endl;
    }

    void openDocument(const std::string& filename) {
        auto it = documents.find(filename);
        if (it != documents.end()) {
            auto& document = it->second;
            std::cout << "Открыт документ " << filename << std::endl;
            std::cout << "Примитивы в документе:" << std::endl;
            document->drawAllPrimitives();
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

    void saveDocument(const std::string& filename) {
        auto it = documents.find(filename);
        if (it != documents.end()) {
            auto& document = it->second;
            document->saveToFile(filename);
            std::cout << "Документ '" << filename << "' сохранен." << std::endl;
            std::cout << "Примитивы в документе:" << std::endl;
            document->drawAllPrimitives();
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

    void addPrimitive(const std::string& filename, const std::string& type) {
        auto it = documents.find(filename);
        if (it != documents.end()) {
            auto& document = it->second;

            std::cout << "Введите имя примитива: ";
            std::string name;
            std::cin >> name;

            if (type == "rectangle") {
                double width, height;
                std::cout << "Введите ширину: ";
                std::cin >> width;
                std::cout << "Введите высоту: ";
                std::cin >> height;
                document->addPrimitive(std::make_shared<Rectangle>(name, width, height));

            } else if (type == "square") {
                double side;
                std::cout << "Введите длину стороны: ";
                std::cin >> side;
                document->addPrimitive(std::make_shared<Square>(name, side));

            } else if (type == "circle") {
                double radius;
                std::cout << "Введите радиус: ";
                std::cin >> radius;
                document->addPrimitive(std::make_shared<Circle>(name, radius));

            } else if (type == "triangle") {
                double a, b, c;
                std::cout << "Введите длину стороны a: ";
                std::cin >> a;
                std::cout << "Введите длину стороны b: ";
                std::cin >> b;
                std::cout << "Введите длину стороны c: ";
                std::cin >> c;
                document->addPrimitive(std::make_shared<Triangle>(name, a, b, c));

            } else {
                std::cout << "Неподдерживаемый тип примитива.\n";
            }
        } else {
            std::cout << "Документ не найден.\n";
        }
    }

    void removePrimitive(const std::string& filename, const std::string& primitiveName, const std::string& primitiveType) {
        auto it = documents.find(filename);
        if (it != documents.end()) {
            auto& document = it->second;
            document->removePrimitive(primitiveName, primitiveType);
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

    void removeDocument(const std::string& filename) {
        auto it = documents.find(filename);
        if (it != documents.end()) {
            auto& document = it->second;
            std::cout << "Удаление документа '" << filename << "' и всех содержащихся примитивов:" << std::endl;
            document->deleteAllPrimitives();
            documents.erase(it); // Remove the document from the map
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

private:
    // Use a map to store documents by their names
    std::unordered_map<std::string, std::shared_ptr<Document>> documents;
};

#endif