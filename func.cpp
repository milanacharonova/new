#include "head.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using namespace PACK;
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
