#include <iostream>
#include "../UI/UI.h"

int main() {
    UI domino;

    domino.domino_init();

    int choice;
    do {

        std::cout << "1.Ввод экземпляров класса из входного потока " << std::endl;
        std::cout << "2.Добавить кость к группе, значение которой получается с помощью генератора случайных чисел" << std::endl;
        std::cout << "3.Изъять кость из группы" << std::endl;
        std::cout << "4.Вывод в выходной поток"<< std::endl;
        std::cout << "5.“Открыть” кость по её номеру в группе, создав экземпляр класса с одной костью" << std::endl;
        std::cout << "6.Упорядочить кости по возрастанию суммы очков" << std::endl;
        std::cout << "7.Выделить из группы костей подгруппу костей, содержащих конкретное значение хотя бы один раз." << std::endl;
        std::cout << "0.Выход" << std::endl;

        choice = get_int();
        switch (choice) {

            case 1:
//                domino.input_value();
                std::cin >> domino.get_domino();
                break;

            case 2:
                domino.input_rand_value();
                break;

            case 3:
                domino.pop_bone();
                break;


            case 4:
                domino.print_domino();
                break;


            case 5:

                domino.open_bone();
                break;


            case 6:
                domino.order_domino();
                break;

            case 7:
                domino.subgroup_bones();
                break;


            case 0:
                break;


            default:
                std::cout << "Неверно выбран пункт меню\n";
                break;

        }

    } while (choice != 0);

    return 0;
}
