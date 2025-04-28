/*
Задача: Реализация обобщённого контейнера и функции для работы с элементами

Описание задачи:
Вам нужно реализовать шаблонный класс, который будет представлять собой контейнер (аналог массива) с возможностью:
1. Добавления элементов в контейнер.
2. Получения элементов по индексу с проверкой диапазона.
3. Реализация функции для обмена значениями двух элементов.
Также нужно будет реализовать несколько шаблонных функций для работы с этим классом и другими типами данных.

Требования:
1. Реализовать класс SimpleVector с шаблонами:
  •  Шаблонный класс должен поддерживать тип элементов и размер.
  •  Реализовать методы для добавления и получения элемента по индексу.
  •  Метод для обмена значениями двух элементов.
2. Создать шаблонную функцию swap, которая будет обменивать значения двух переменных любых типов.

Входные данные:

•  Массив или список элементов (для класса SimpleVector).
•  Для функции swap — два значения любых типов.

Выходные данные:

•  Для класса SimpleVector: вывод содержимого контейнера после выполнения операций добавления и обмена значениями.
•  Для функции swap: вывод значений после обмена.

Структура:

1. Создайте класс SimpleVector с шаблонным типом данных и фиксированным размером.
2. Реализуйте методы:
  •  add: добавление элемента в контейнер.
  •  get: получение элемента по индексу с проверкой диапазона.
3. Напишите функцию swap, которая меняет местами два элемента.
4. В функции main создайте несколько объектов SimpleVector с различными типами данных (например, int, double, string), добавляйте элементы в контейнер и выполните обмен значениями.
*/

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class T, size_t SIZE>
class SimpleVector {
private:
    T data[SIZE];
    size_t currentSize = 0;

public:

    void add(const T& element) {
        if (currentSize < SIZE) {
            data[currentSize] = element;
            currentSize++;
        }
        else {
            cout << "Контейнер полон!" << endl;
        }
    }

    bool get(size_t index, T& value) const {
        if (index < 0 || index >= currentSize) {
            cout << "Индекс за пределами нашего диапазона!" << endl;
            return false;
        }
        value = data[index];
        return true;
    }

    void swap(size_t index1, size_t index2) {
        if (index1 < currentSize && index2 < currentSize) {
            T temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }
        else {
            cout << "Один или оба индекса за пределами нашего диапозона!" << endl;
            return;
        }
    }

    void print() const {
        cout << "Содержимое контейнера: ";
        for (size_t i = 0; i < currentSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    size_t size() const { // Метод для получения текущего размера
        return currentSize;
    }
};

template <class T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    setlocale(LC_ALL, "RU");

    // Пример с int
    SimpleVector<int, 5> intVector;
    intVector.add(1);
    intVector.add(2);
    intVector.add(3);
    cout << "Содержимое контейнера: ";
    intVector.print(); // Вывод: Содержимое контейнера: 1 2 3

    if (intVector.size() > 1) {
        intVector.swap(0, 1);
        intVector.print(); // Вывод: Содержимое контейнера: 2 1 3

        int value;
        if (intVector.get(2, value)) { 
            cout << "Элемент по индексу 2: " << value << endl; // Вывод: Элемент по индексу 2: 3
        }
        else {
            cout << "Ошибка: Индекс 2 вне диапазона." << endl;
        }
    }
    else {
        cout << "Ошибка: Недостаточно элементов для обмена." << endl;
    }

    // Пример с double
    SimpleVector<double, 3> doubleVector;
    doubleVector.add(1.1);
    doubleVector.add(2.2);
    doubleVector.add(3.3);
    doubleVector.print(); // Вывод: Содержимое контейнера: 1.1 2.2 3.3

    // Пример со string
    SimpleVector<string, 4> stringVector;
    stringVector.add("Hello");
    stringVector.add("World");
    stringVector.print(); // Вывод: Содержимое контейнера: Hello World

    // Пример использования шаблонной функции swap
    int x = 5, y = 10;
    cout << "До обмена: x = " << x << ", y = " << y << endl; // Вывод: До обмена: x = 5, y = 10
    ::swap(x, y);
    cout << "После обмена: x = " << x << ", y = " << y << endl; // Вывод: После обмена: x = 10, y = 5

    string str1 = "First", str2 = "Second";
    cout << "До обмена: str1 = " << str1 << ", str2 = " << str2 << endl; // Вывод: До обмена: str1 = First, str2 = Second
    swap(str1, str2);
    cout << "После обмена: str1 = " << str1 << ", str2 = " << str2 << endl; // Вывод: После обмена: str1 = Second, str2 = First

    return 0;
}
