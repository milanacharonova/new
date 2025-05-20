#include "head.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using namespace PACK;

ostream& operator<<(ostream& os, const PACK::pack& Pack){
    os << Pack._id << " "<< Pack._sendname << " " << Pack._getname << " " << Pack._to<< " "<<Pack._weight<< " " <<Pack._remainingTime <<" " << Pack._currentX<< " "<< Pack._currentY;
    return os;
}

istream& operator>>(istream& is, PACK::pack& Pack){
    is >> Pack._id >> Pack._sendname >> Pack._getname >> Pack._to>>Pack._weight>>Pack._remainingTime>> Pack._currentX>> Pack._currentY;
    return is;
}

int count_strings(string a){ //Пересчёт строк. Для использования:    int a = count_strings("название файла");
    ifstream f;
    f.open(a);
    string line;
    int i = 0;
    while(getline(f, line)){
        i++;
    };
    f.close();
    return i;
}

void pack::add(){
    cout << "Введите имя отправителя: ";
    cin >> _sendname;
    cout << "Введите имя получателя: ";
    cin >> _getname;
    cout << "Введите отправочное отделение: ";
    cin >> _from;
    cout << "Введите приемное отделение: ";
    cin >> _to;
    cout << "Введите вес: ";
    cin >> _weight;

}

