#include "head.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
namespace PACK{
ostream& operator<<(ostream& os, const PACK::pack& Pack){
    os << Pack.id << " " << Pack.sendname << " " << Pack.getname << " " << Pack.to<< " " <<Pack.weight<< " " << Pack.remainingTime << " " << Pack.currentX<< " " << Pack.currentY << "\n";
    return os;
}

istream& operator>>(istream& is, PACK::pack& Pack){
    is >> Pack.id >> Pack.sendname >> Pack.getname >> Pack.to>>Pack.weight>>Pack.remainingTime>> Pack.currentX>> Pack.currentY;
    return is;
}

ostream& operator<<(ostream& os, const PACK::post& Post){
    os << Post.name << " " << Post.x << " " << Post.y;
          for (int track : Post.packs) {
              os << " " << track;
          };
          os << '\n';
    return os;
}

istream& operator>>(istream& is, PACK::post& Post){
    string line;
    getline(is, line);
    istringstream iss(line);
    Post.packs.clear();
    iss >> Post.name >> Post.x >> Post.y;
    int track;
    while(iss >> track){
        Post.packs.push_back(track);
    }
    return is;
}
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

void PACK::add(){
    pack editable;
    cout << "Введите имя отправителя: ";
    cin >> editable.sendname;
    cout << "Введите имя получателя: ";
    cin >> editable.getname;
    cout << "Введите отправочное отделение: ";
    string from;
    cin >> from;
    editable.currentX = 0;
    editable.currentY = 0;
    ifstream file3("post.txt");
    post editable3;
    int check = 0;
    if (!file3.is_open())
        cout << "Не удалось открыть файл5." << endl;
    while(file3 >> editable3){
        if (from == editable3.name){
            editable.currentX = editable3.x;
            editable.currentY = editable3.y;
            cout << editable.currentX << editable.currentY << endl;
            check = 1;
            break;
        }
    }
    file3.close();
    if (check == 0){
        cout << "Такого отправочного отделения не существует." << endl;
        return;
    }

    cout << "Введите приемное отделение: ";
    cin >> editable.to;

    ifstream file4("post.txt");
    post editable4;
    check = 0;
    if (!file4.is_open())
        cout << "Не удалось открыть файл4." << endl;
    while(file4 >> editable4){
        if (editable.to == editable4.name){
            check = 1;
            break;
        }
    }
    file4.close();
    if (check == 0){
        cout << "Такого приемного  отделения не существует." << endl;
        return;
    }

    cout << "Введите вес: ";
    cin >> editable.weight;
    int flag = 1;
    int potencialId = 0;
    while(flag == 1){
        flag = 0;
        potencialId = rand() % 9000 + 1000;
        ifstream file("pack.txt");
        pack editable2;
        if (!file.is_open())
            cout << "Не удалось открыть файл3." << endl;
        while(file >> editable2){
            if (potencialId == editable2.id){
                flag = 1;
                break;
            }
        }
        file.close();
    }
    editable.id = potencialId;
    int x2;
    int y2;
    ifstream file7("post.txt");
    if (!file7.is_open())
        cout << "Не удалось открыть файл7." << endl;
    post editable7;
    while(file7 >> editable7){
        if(editable.to == editable7.name){
            x2 = editable7.x;
            y2 = editable7.y;
        }
    }
    int dist = sqrt(pow(x2 - editable.currentX , 2) + pow(y2 - editable.currentY , 2));
    int speed = 60;
    editable.remainingTime = dist/speed;
    cout << x2 << " " << y2 << " " << editable.currentX << editable.currentY << endl;
    file7.close();
    ofstream file1("pack.txt", ios::app);
    if (!file1.is_open())
        cout << "Не удалось открыть файл1." << endl;
    file1 << editable;
    file1.close();
}

void PACK::display() {
    string line;
    ifstream file("post.txt");
    if (file.is_open()) {
        int n = 1;
        while (getline(file, line)) {
            istringstream iss(line);
            string name;
            int  x, y;
            vector<int> packs;
            iss >> name >> x >> y;
            int trak;
            while (iss >> trak) {
                packs.push_back(trak);
            }
            cout << n << ". Название: " << name << ", Координаты: (" << x << ", " << y << "), Трек-номера: ";
            for (size_t i = 0; i < packs.size(); ++i) {
                cout << packs[i];
                if (i < packs.size() - 1) cout << ", ";
            }
            cout << endl;
            n++;
        }
        cout << "---------------" << endl;
        file.close();
    } else {
        cout << "Не удалось открыть файл." << endl;
    }
}

void PACK::time(){
    PACK::post editable;
    int a = count_strings("pack.txt");
    PACK::pack arr[a];
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
            fstream file("post.txt");
            PACK::post edit;
            while(file >> edit){
                if(edit.name == arr[i].to){
                    edit.packs.push_back(arr[i].id);
                    file << edit;
                }

            }
        }
    }
    fpack.close();
    fpost.close();
    ofstream f;
    f.open("pack.txt");
    for(int i = 0; i < a; i++){
        f << arr[i].id << " " << arr[i].sendname<< " " << arr[i].getname << " " << arr[i].to << " " << arr[i].weight <<" " << arr[i].remainingTime << " " << arr[i].currentX << " " << arr[i].currentY << endl;
    }
    f.close();
}
void PACK::test(){
    post test;
    ifstream file("post.txt");
    while(file >> test){
        cout << test;
    }
}
