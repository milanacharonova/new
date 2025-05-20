#include <iostream>
#include <string>
#include <vector>
namespace PACK{
class post {
    std::string _name;
    int index;
    int _x; // Координата X
    int _y; // Координата Y
    std::vector<int> _packs; // Посылки в отделении
public:
    post() = default;
    post(int index, int x, int y, std::vector<int> packs);

    void display();
    void addpost();
    void delpost();
    double distance();
};
class pack{
    std::string _sendname; // имя отправителя
    std::string _getname;  // имя получателя
    int _from;             // отправочное отделение
    int _to;               // приемное отделение
    int _weight;           // вес посылки
    int _id;               // трек-номер
public:
    int _remainingTime;    // оставшееся время доставки в днях
    int _currentX;         // x сейчас
    int _currentY;         // y сейчас
    void add();
    
};
}
