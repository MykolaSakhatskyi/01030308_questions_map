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
        {"Був зерном він у землі, Став із сіллю на столі. З ним їсти ми сідаємо, І гостей стрічаємо.","хліб"},
        {"Виріс в полі колоском,На столі лежу шматком","хліб"},
        {"В кожнім місті і селі головний він на столі.","хліб"},
        {"Тарілка супу між ліктями,А він в руках у всіх скибками.Без нього, як видно,Не смачно і не ситно!","хліб"},
        {"Є такі слова: “Він усьому голова” В хрустку скоринку одягнений М’який чорний, білий …","хліб"}
    };
    std::cout << "Гра - відгадай 5 загадок" << endl;
    std::cout << "За кожну правильну відповідь ви отримаєте певну кількість балів" << endl;
    std::cout << "Будьте уважні, ви не побачите те що ви вводите" << endl;
    std::cout << "Помилки також виправити не вдасться" << endl;
    std::cout << "Для відповіді введіть слово і чекайте поки з'явиться наступне питання" << endl;
    std::cout << "Для того щоб ввести відповідь, дається 30 секунд" << endl;
    std::cout << "ПОЇХАЛИ!!!" << endl;
    std::cout << "---------------------------------------------------------------------" << endl;
    for (auto& element : zagadky) {
        std::cout << element.first << endl;
        std::cout << "Ваша відповідь:"<< endl;
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
    std::cout << "Ви набрали " << sumOfPoints<< " балів" << endl;
    return 0;
}