#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <conio.h>
using namespace std;

bool Checker(string key, const vector<char>& userInput) {
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] != userInput[i]) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    system("chcp 1251>nul");
    char someChar = 'v';
    int sumOfPoints = 0;
    int maxPoint = 5;
    map<string, string> zagadky = { 
        {"��� ������ �� � ����, ���� �� ���� �� ����. � ��� ���� �� �����, � ������ �������.","���"},
        {"���� � ��� ��������,�� ���� ���� �������","���"},
        {"� ����� ��� � ��� �������� �� �� ����.","���"},
        {"������ ���� �� ������,� �� � ����� � ��� ��������.��� �����, �� �����,�� ������ � �� �����!","���"},
        {"� ��� �����: �³� ������ ������� � ������� �������� ��������� ̒���� ������, ���� �","���"}
    };
    std::cout << "��� - ������� 5 �������" << endl;
    std::cout << "�� ����� ��������� ������� �� �������� ����� ������� ����" << endl;
    std::cout << "������ �����, �� �� �������� �� �� �� �������" << endl;
    std::cout << "������� ����� ��������� �� ��������" << endl;
    std::cout << "��� ������ ������ ����� � ������� ���� �'������� �������� �������" << endl;
    std::cout << "��� ���� ��� ������ �������, ������ 30 ������" << endl;
    std::cout << "�ί����!!!" << endl;
    std::cout << "---------------------------------------------------------------------" << endl;
    for (auto& element : zagadky) {
        std::cout << element.first << endl;
        std::cout << "���� �������:"<< endl;
        vector<char> world;
        auto start_time = std::chrono::steady_clock::now();
        while (true) {
            auto end_time = std::chrono::steady_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
            if (duration.count() == 30)
                break;
            if (_kbhit()) {
                char c = _getch();
                world.push_back(c);
            }
        }
        if (world.size() == 0) {
            world.push_back(someChar);
            world.push_back(someChar);
            world.push_back(someChar);
            world.push_back(someChar);
        }
        if (Checker(element.second, world))
            sumOfPoints += maxPoint;
        maxPoint--;  
    }
    std::cout << "�� ������� " << sumOfPoints<< " ����" << endl;
    return 0;
}