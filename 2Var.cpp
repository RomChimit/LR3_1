
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Структура для хранения данных о книге
struct Student {
    int id;
    char name; //имя
    char faculty; //факультет
    char speciality; //направление
    int age; //возраст
    float average; //ссредний балл
    int course; //какой курс
};

// 1. Чтение из файла
Student* readFromFile(int& size) {
    ifstream fin("studs.txt");
    if (!fin) {
        cout « "Ошибка открытия файла!" « endl;
        return nullptr;
    }

    fin » size; // Читаем количество книг
    Book* stud = new Book[size]; // Выделяем динамическую память

    for (int i = 0; i < size; i++) {
        fin » studs[i].name;
        fin » studs[i].faculty;
        fin » studs[i].speciality;
        fin » studs[i].age;
        fin » studs[i].average;
        fin » studs[i].course;
    }
    fin.close();
    return studs;
}

// 2. Просмотр данных
void displayData(Student* stud, int size) {
    cout « "\nСписок студентов:\n";
    for (int i = 0; i < size; i++) {
        cout « "\nСтудент " « i + 1 « ":" « endl;
        cout « "Имя: " « studs[i].name « endl;
        cout « "Факультет: " « studs[i].faculty « endl;
        cout « "Направление: " « studs[i].speciality « endl;
        cout « "Возраст: " « studs[i].age « endl;
        cout « "Средний балл: " « studs[i].average « endl;
        cout « "Номер курса: " « studs[i].course « endl;
    }
}

// 3. Корректировка данных
void editStud(Student* studs, int size) {
    int index;
    cout « "Введите id студента для распознавания (1-" « size « "): ";
    cin » index;
    index--; // Преобразуем в индекс массива

    if (index >= 0 && index < size) {
        cout « "Введите новые данные:\n";
        cout « "Имя: ";
        cin » studs[index].name;
        cout « "Факультет: ";
        cin » studs[index].faculty;
        cout « "Направление: ";
        cin » studs[index].speciality;
        cout « "Возраст: ";
        cin » studs[index].age;
        cout « "Средний балл: ";
        cin » studs[index].average;
        cout « "Номер курса: ";
        cin » studs[index].course;
    }
    else {
        cout « "Неверный id студента!" « endl;
    }
}

// 4. Вычисления
void calculations(Student* studs, int size) {
    float totalAge = 0;
    int totalAverage = 0;

    for (int i = 0; i < size; i++) {
        totalAge += studs[i].age;
        totalAverage += studs[i].average;
    }

    cout « "\nСредний возраст студентов: " « totalAge / size « endl;
    cout « "Общее количество баллов: " « totalAverage « endl;
}

// 5. Сохранение в файл
void saveToFile(Student* studs, int size) {
    ofstream fout("new_studs.txt");
    if (!fout) {
        cout « "Ошибка создания файла!" « endl;
        return;
    }

    fout « size « endl;
    for (int i = 0; i < size; i++) {
        fout « studs[i].name « " "
             « studs[i].faculty « " "
             « studs[i].speciality « " "
             « studs[i].age « " "
             « studs[i].average « " "
             « studs[i].course« endl;
    }
    fout.close();
    cout « "Данные сохранены в файл 'new_studs.txt'" « endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size = 0;
    Student* studs = nullptr;
    int choice;

    do {
        cout « "\nМеню:\n";
        cout « "1. Чтение из файла\n";
        cout « "2. Просмотр данных\n";
        cout « "3. Редактировать информацию\n";
        cout « "4. Вычисления\n";
        cout « "5. Сохранить в файл\n";
        cout « "0. Выход\n";
        cout « "Выберите действие: ";
        cin » choice;

        switch (choice) {
        case 1:
            if (studs != nullptr) delete[] studs;
            studs = readFromFile(size);
            break;
        case 2:
            if (studs != nullptr) displayData(studs, size);
            else cout « "Сначала загрузите данные!" « endl;
            break;
        case 3:
            if (studs != nullptr) editStud(studs, size);
            else cout « "Сначала загрузите данные!" « endl;
            break;
        case 4:
            if (studs != nullptr) calculations(studs, size);
            else cout « "Сначала загрузите данные!" « endl;
            break;
        case 5:
            if (studs != nullptr) saveToFile(studs, size);
            else cout « "Сначала загрузите данные!" « endl;
            break;
        }
    } while (choice != 0);

    if (studs != nullptr) delete[]
    studs;
    return 0;
}