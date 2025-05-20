#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace PACK{
class post {
public:
    int name;
    int x; // Координата X
    int y; // Координата Y
    vector<int> _packs; // Посылки в отделении
};
class pack{
public:
    int _id;               // трек-номер
    string _sendname; // имя отправителя
    string _getname;  // имя получателя
    int _to;               // приемное отделение
    int _weight;           // вес посылки
    int _remainingTime;    // оставшееся время доставки в днях
    int _currentX;         // x сейчас
    int _currentY;         // y сейчас
    friend ostream& operator<<(ostream& os, const pack& Pack);
    friend istream& operator>>(istream& is, const pack& Pack);
};
    void display();
    void addpost();
    void delpost();
    double distance();
    void add();
}
