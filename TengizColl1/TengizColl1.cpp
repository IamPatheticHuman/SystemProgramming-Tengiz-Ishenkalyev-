#include <iostream>
#include <string>
#include <algorithm>

struct MARSH {
    std::string start_point;
    std::string end_point;
    int route_number;
};


void inputRoutes(MARSH routes[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Введите данные для маршрута " << i + 1 << ":\n";
        std::cout << "Начальный пункт: ";
        std::cin >> routes[i].start_point;
        std::cout << "Конечный пункт: ";
        std::cin >> routes[i].end_point;
        std::cout << "Номер маршрута: ";
        std::cin >> routes[i].route_number;
    }

    std::sort(routes, routes + size, [](const MARSH& a, const MARSH& b) {
        return a.route_number < b.route_number;
        });
}

void displayRoutes(const MARSH routes[], int size) {
    std::cout << "\nСписок всех маршрутов:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Маршрут номер: " << routes[i].route_number << "\n";
        std::cout << "Начальный пункт: " << routes[i].start_point << "\n";
        std::cout << "Конечный пункт: " << routes[i].end_point << "\n\n";
    }
}

void findRoutesByPoint(const MARSH routes[], int size, const std::string& point) {
    bool found = false;

    std::cout << "\nМаршруты, связанные с пунктом \"" << point << "\":\n";
    for (int i = 0; i < size; i++) {
        if (routes[i].start_point == point || routes[i].end_point == point) {
            std::cout << "Маршрут номер: " << routes[i].route_number << "\n";
            std::cout << "Начальный пункт: " << routes[i].start_point << "\n";
            std::cout << "Конечный пункт: " << routes[i].end_point << "\n\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Маршруты с пунктом \"" << point << "\" не найдены.\n";
    }
}

void editRoute(MARSH routes[], int size, int route_number) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (routes[i].route_number == route_number) {
            std::cout << "Редактирование маршрута номер " << route_number << ":\n";
            std::cout << "Введите новый начальный пункт: ";
            std::cin >> routes[i].start_point;
            std::cout << "Введите новый конечный пункт: ";
            std::cin >> routes[i].end_point;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Маршрут с номером " << route_number << " не найден.\n";
    }
}

int main() {
    const int SIZE = 8;
    MARSH routes[SIZE];
    system("chcp 1251");
    inputRoutes(routes, SIZE);

    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Вывести все маршруты\n";
        std::cout << "2. Найти маршруты по пункту\n";
        std::cout << "3. Редактировать маршрут по номеру\n";
        std::cout << "4. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayRoutes(routes, SIZE);
            break;

        case 2: {
            std::string point;
            std::cout << "Введите название пункта: ";
            std::cin >> point;
            findRoutesByPoint(routes, SIZE, point);
            break;
        }

        case 3: {
            int route_number;
            std::cout << "Введите номер маршрута для редактирования: ";
            std::cin >> route_number;
            editRoute(routes, SIZE, route_number);
            break;
        }

        case 4:
            std::cout << "Выход из программы.\n";
            break;

        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}