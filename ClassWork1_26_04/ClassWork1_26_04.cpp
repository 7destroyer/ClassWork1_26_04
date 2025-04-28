/*
������: ���������� ����������� ���������� � ������� ��� ������ � ����������

�������� ������:
��� ����� ����������� ��������� �����, ������� ����� ������������ ����� ��������� (������ �������) � ������������:
1. ���������� ��������� � ���������.
2. ��������� ��������� �� ������� � ��������� ���������.
3. ���������� ������� ��� ������ ���������� ���� ���������.
����� ����� ����� ����������� ��������� ��������� ������� ��� ������ � ���� ������� � ������� ������ ������.

����������:
1. ����������� ����� SimpleVector � ���������:
  �  ��������� ����� ������ ������������ ��� ��������� � ������.
  �  ����������� ������ ��� ���������� � ��������� �������� �� �������.
  �  ����� ��� ������ ���������� ���� ���������.
2. ������� ��������� ������� swap, ������� ����� ���������� �������� ���� ���������� ����� �����.

������� ������:

�  ������ ��� ������ ��������� (��� ������ SimpleVector).
�  ��� ������� swap � ��� �������� ����� �����.

�������� ������:

�  ��� ������ SimpleVector: ����� ����������� ���������� ����� ���������� �������� ���������� � ������ ����������.
�  ��� ������� swap: ����� �������� ����� ������.

���������:

1. �������� ����� SimpleVector � ��������� ����� ������ � ������������� ��������.
2. ���������� ������:
  �  add: ���������� �������� � ���������.
  �  get: ��������� �������� �� ������� � ��������� ���������.
3. �������� ������� swap, ������� ������ ������� ��� ��������.
4. � ������� main �������� ��������� �������� SimpleVector � ���������� ������ ������ (��������, int, double, string), ���������� �������� � ��������� � ��������� ����� ����������.
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
            cout << "��������� �����!" << endl;
        }
    }

    bool get(size_t index, T& value) const {
        if (index < 0 || index >= currentSize) {
            cout << "������ �� ��������� ������ ���������!" << endl;
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
            cout << "���� ��� ��� ������� �� ��������� ������ ���������!" << endl;
            return;
        }
    }

    void print() const {
        cout << "���������� ����������: ";
        for (size_t i = 0; i < currentSize; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    size_t size() const { // ����� ��� ��������� �������� �������
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

    // ������ � int
    SimpleVector<int, 5> intVector;
    intVector.add(1);
    intVector.add(2);
    intVector.add(3);
    cout << "���������� ����������: ";
    intVector.print(); // �����: ���������� ����������: 1 2 3

    if (intVector.size() > 1) {
        intVector.swap(0, 1);
        intVector.print(); // �����: ���������� ����������: 2 1 3

        int value;
        if (intVector.get(2, value)) { 
            cout << "������� �� ������� 2: " << value << endl; // �����: ������� �� ������� 2: 3
        }
        else {
            cout << "������: ������ 2 ��� ���������." << endl;
        }
    }
    else {
        cout << "������: ������������ ��������� ��� ������." << endl;
    }

    // ������ � double
    SimpleVector<double, 3> doubleVector;
    doubleVector.add(1.1);
    doubleVector.add(2.2);
    doubleVector.add(3.3);
    doubleVector.print(); // �����: ���������� ����������: 1.1 2.2 3.3

    // ������ �� string
    SimpleVector<string, 4> stringVector;
    stringVector.add("Hello");
    stringVector.add("World");
    stringVector.print(); // �����: ���������� ����������: Hello World

    // ������ ������������� ��������� ������� swap
    int x = 5, y = 10;
    cout << "�� ������: x = " << x << ", y = " << y << endl; // �����: �� ������: x = 5, y = 10
    ::swap(x, y);
    cout << "����� ������: x = " << x << ", y = " << y << endl; // �����: ����� ������: x = 10, y = 5

    string str1 = "First", str2 = "Second";
    cout << "�� ������: str1 = " << str1 << ", str2 = " << str2 << endl; // �����: �� ������: str1 = First, str2 = Second
    swap(str1, str2);
    cout << "����� ������: str1 = " << str1 << ", str2 = " << str2 << endl; // �����: ����� ������: str1 = Second, str2 = First

    return 0;
}
