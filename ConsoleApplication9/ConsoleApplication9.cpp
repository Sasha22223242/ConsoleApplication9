#include <iostream>
#include <Windows.h>
#include <CoreWindow.h>
#include <chrono>
#include <algorithm>

using namespace std;



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(nullptr));
    cout << "\t\tШВИДКІСТЬ ДРУКУ\n\n Cуть гри: потрібно швидко надрукувати випадкове слово на ПК\n\tДля початку гри натисніть Enter";
    cin.ignore();
    string rnd_words[]{ "will","slow","row","fork","time","leviathan" };
    int size = sizeof(rnd_words) / sizeof(rnd_words[0]);
    string word = rnd_words[rand() % size];
    cout << "Введіть слово: \033[44m " << word << "\033[0m\n";
    auto startPlayer = chrono::steady_clock::now();
    string user = "";
    while (user != word) {
        cout << "→";
        cin >> user;
        string res = (user != word) ? "Не правильно. Час плине  " : " ";
        cout << res << endl;
    }
    auto endPlayer = chrono::steady_clock::now();
    chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
    double timePlayer = elapsedPlayer.count();
    cout << "\n\t\tВаш результат: ";


    for (short i = 1; i < 4; i++) {
        cout << i << ' ';
        Sleep(1000);
    }

    cout << "\n\t\tTime: " << round(timePlayer) << "seconds\n";
    cout << "\n\t\tХід компютера\n";
    auto startPC = chrono::steady_clock::now();
    auto endPC = chrono::steady_clock::now();
    chrono::duration<double> elapsedPC = endPC - startPC;
    double timePC = elapsedPC.count() * 10000000;
    int rnd = rand() % 5;


    for (short i = 0; i < 3; i++) {
        cout << ". ";
        Sleep(1000);
    }
    cout << "\n\t\tTime: " << timePC * rnd << "seconds\n";
    int ballUser = 0, ballPC = 0, rand = 1;
    cout << "Round #" << rand << "Winer: ";
    Sleep(1000);
    if (timePlayer < timePC) {
        cout << "\033[32mГравець\033[0m\n";
        ballUser++;
    }
    else if (timePlayer > timePC) {
        cout << "\033[33mPC\033[0m\n";
        ballPC++;
    }
    else {

    }
    cout << "\n\t\tБали гравця: " << ballUser << "\n\t\tБали PC:" << ballPC << endl;


    return 0;
}