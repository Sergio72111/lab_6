#include <iostream>
#include "DocumentController.h"

int main() {
    DocumentController controller;
    int choice;

    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Создать документ\n";
        std::cout << "2. Открыть документ\n";
        std::cout << "3. Сохранить документ\n";
        std::cout << "4. Добавить примитив\n";
        std::cout << "5. Удалить примитив\n";
        std::cout << "6. Удалить документ\n";
        std::cout << "7. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                controller.createDocument();
                break;
            }
            case 2: {
                std::cout << "Введите имя документа для открытия: ";
                std::string filename;
                std::cin >> filename;
                controller.openDocument(filename);
                break;
            }
            case 3: {
                std::cout << "Введите имя документа для сохранения: ";
                std::string filename; 
                std::cin >> filename;
                controller.saveDocument(filename);
                break;
            }
            case 4: {
                std::cout << "Введите имя документа для добавления примитива: ";
                std::string filename;
                std::cin >> filename;

                std::cout << "Введите тип примитива (rectangle/square/circle/triangle): ";
                std::string type;
                std::cin >> type;

                controller.addPrimitive(filename, type);
                break;
            }
            case 5: {
                std::cout << "Введите имя документа для удаления примитива: ";
                std::string filename;
                std::cin >> filename;

                std::cout << "Введите имя примитива для удаления: ";
                std::string primitiveName;
                std::cin >> primitiveName;

                std::cout << "Введите тип примитива (rectangle/square/circle/triangle): ";
                std::string primitiveType;
                std::cin >> primitiveType;

                controller.removePrimitive(filename, primitiveName, primitiveType);
                break;
            }
            case 6: {
                std::cout << "Введите имя документа для удаления: ";
                std::string filename;
                std::cin >> filename;
                controller.removeDocument(filename);
                break;
            }
            case 7:
                return 0; // Exit the program
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }

    return 0; // This line is technically unreachable but is good practice
}