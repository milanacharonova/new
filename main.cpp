#include <iostream>
#include "head.h"

using namespace std;
using namespace PACK;
int main()
{
    int a;
    do {
           cout << "\n--- Меню ---\n"
                << "1. Отправить посылку\n"
                << "2. Добавить отделение\n"
                << "3. Удалить отделение\n"
                << "4. Показать информацию об отделениях\n"
                << "5. test\n"
                << "6. Выдать посылку\n"
                << "7. Пропустить день\n"
                << "0. Выйти\n"
                << "Выберите действие: ";
           cin >> a;

           switch (a) {
               case 1: add(); break;
               //case 2: post.addpost(); break;
               //case 3: post.delpost(arr, count); break;
               case 4: display(); break;
               case 5: test(); break;
               //case 6: give(arr, &count); break;
               case 7: time(); break;
               case 0:
                   cout << "Выход." << endl;
                   break;
               default:
                   cout << "Неверный выбор. Повторите." << endl;
           }
       } while (a != 0);

       return 0;
   }
