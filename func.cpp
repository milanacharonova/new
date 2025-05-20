#include "head.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using namespace PACK;

ostream& operator<<(ostream& os, const PACK::pack& Pack){
    os << Pack.id << " "<< Pack.sendname << " " << Pack.getname << " " << Pack.to<< " "<<Pack.weight<< " " <<Pack.remainingTime <<" " << Pack.currentX<< " "<< Pack.currentY;
    return os;
}

istream& operator>>(istream& is, PACK::pack& Pack){
    is >> Pack.id >> Pack.sendname >> Pack.getname >> Pack.to>>Pack.weight>>Pack.remainingTime>> Pack.currentX>> Pack.currentY;
    return is;
}

ostream& operator<<(ostream& os, const PACK::post& Post){
    os << Post.name << " " << Post.x << Post.y << " ";
    return os;
}

istream& operator>>(istream& is, PACK::post& Post){
    is >> Post.name >> Post.x >> Post.y;
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

void time(){
    post editable;
    int a = count_strings("packages.txt");
    pack arr[a];
    ifstream fpack;
    ifstream fpost;
    fpack.open("pack.txt");
    fpost.open("post.txt");
    for(int i = 0; i < a; i++){
        fpack >> arr[i];
        if(arr[i].remainingTime != 0){
            arr[i].remainingTime -= 1;
            while(fpost >> editable){
                if(editable.name == arr[i].to){
                    int x = editable.x-arr[i].currentX;
                    int y = editable.y-arr[i].currentY;
                    int c=sqrt(pow(x,2)+pow(y,2));
                    int speed=60;
                    arr[i].currentX=x*speed/c;
                    arr[i].currentY=y*speed/c;
                    break;
                }
            }
        }else{
         cout << "Посылка " << arr[i].id << " прибыла" << endl;
        }
    }
}
