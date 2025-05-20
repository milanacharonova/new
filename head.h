#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace PACK{
class post {
public:
    sting name;
    int x; // Координата X
    int y; // Координата Y
    vector<int> packs; // Посылки в отделении
    friend ostream& operator<<(ostream& os, const post& Post);
    friend istream& operator>>(istream& is, const post& Post);
};
class pack{
public:
    int id;               // трек-номер
    string sendname; // имя отправителя
    string getname;  // имя получателя
    string to;               // приемное отделение
    int weight;           // вес посылки
    int remainingTime;    // оставшееся время доставки в днях
    int currentX;         // x сейчас
    int currentY;         // y сейчас
    friend ostream& operator<<(ostream& os, const pack& Pack);
    friend istream& operator>>(istream& is, const pack& Pack);
};
    void display();
    void addpost();
    void delpost();
    double distance();
    void add();
}

