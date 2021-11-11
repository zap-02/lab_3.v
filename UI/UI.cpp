//
// Created by zap on 14.10.2021.
//

#include "UI.h"

Domino UI::domino_init() {
    int choice;
    do {
        std::cout << "1.Инициализировать пустой конструктор;" << std::endl;
        std::cout
                << "2.Cоздание экземпляров класса с инициализацией количеством костей, значения которых определяются с помощью генератора случайных чисел;"
                << std::endl;
        std::cout
                << "3.Cоздание экземпляров класса с инициализацией начальным состоянием одной кости с разными частями;"
                << std::endl;

        choice = get_int();

        int num, a, b;

        switch (choice) {
            case 1:
                this->domino = *new Domino();
                choice = 0;
                break;

            case 2:
                std::cout << "Введите количество костей для генерации" << std::endl;
                num = get_int();
                this->domino = *new Domino(num);
                choice = 0;
                break;

            case 3:
                std::cout << "Введите первую грань" << std::endl;
                a = get_int();
                std::cout << "Введите первую грань" << std::endl;
                b = get_int();
                this->domino = *new Domino(a, b);
                choice = 0;
                break;

            case 0:
                break;


            default:
                std::cout << "Неверно выбран пункт меню\n";
                break;

        }
    } while (choice != 0);

    return this->domino;

}

void UI::set_domino(Domino &dominos) {
    this->domino = dominos;
}

void UI::input_value() { //ввод экземпляров класса из входного потока и вывод в выходной поток


    int flag = 0;

    Bone *special_bone = new Bone();
    special_bone->set_bottom(-1);
    special_bone->set_top(-1);

    do {
        int a, b;
        std::cout << "Введите значение первой грани" << std::endl;
        a = get_int();
        std::cout << "Введите значение второй грани" << std::endl;
        b = get_int();

        Bone *bone = new Bone();
        bone->set_bottom(b);
        bone->set_top(a);

        this->domino.set_arr(this->domino.get_csize(), *bone);


        if (this->domino.isUnique() == -1) {
            std::cout << "Элемент не уникален, повторите попытку" << std::endl << std::endl;
            domino.set_csize(this->domino.get_csize() - 1);
            domino.set_arr(this->domino.get_csize(), *special_bone);
            domino.set_csize(this->domino.get_csize() - 1);
        } else {
            flag = 1;
            std::cout << "Вставлен элемент на " << this->domino.get_csize() << "-ую позицию" << std::endl << std::endl;
        }

    } while (flag == 0);

}

void UI::input_rand_value() {

    srand(time(NULL));
    int flag = 0;

    Bone *special_bone = new Bone();
    special_bone->set_bottom(-1);
    special_bone->set_top(-1);

    do {
        int a, b;
        a = rand() % 7;
        b = rand() % 7;

        Bone *bone = new Bone();
        bone->set_bottom(b);
        bone->set_top(a);

        this->domino.set_arr(this->domino.get_csize(), *bone);


        if (this->domino.isUnique() == -1) {
            domino.set_csize(this->domino.get_csize() - 1);
            domino.set_arr(this->domino.get_csize(), *special_bone);
            domino.set_csize(this->domino.get_csize() - 1);
        } else {
            flag = 1;
            std::cout << "Элемент с гранями " << a << " и " << b << std::endl;
            std::cout << "Вставлен на " << this->domino.get_csize() << "-ую позицию" << std::endl << std::endl;

        }

    } while (flag == 0);

}

Bone UI::pop_bone() {

    int a, b;
    std::cout << "Введите значение первой грани" << std::endl;
    a = get_int();
    std::cout << "Введите значение второй грани" << std::endl;
    b = get_int();

    Bone *bone = new Bone();
    bone->set_bottom(b);
    bone->set_top(a);
    Bone new_bone;

    try {
        new_bone = domino.pop_bone(*bone);
        std::cout << "Вы попнули кость с гранями " << a << " и " << b << std::endl << std::endl;
    } catch (std::runtime_error &ba) {
        std::cout << ba.what();
    }


    return new_bone;
}

void UI::open_bone() {

    std::cout << "Введите номер кости которую нужно открыть" << std::endl;
    int num = get_int();
    num = num - 1;
    if (num > 28 or num < 1 or num > domino.get_csize()) {
        std::cout << "Неверное значение" << std::endl;
        return;
    }

    Bone bone = this->domino.get_elem(num);


    std::cout << "Кость с гранями " << bone.get_top() << " и " << bone.get_bottom() << std::endl << std::endl;

}

void UI::order_domino() {
    this->domino.bouble();
    std::cout << "Кости упорядочены" << std::endl;
}

void UI::print_domino() {
//    this->domino.print();
    std::cout << domino << std::endl;
}

void UI::subgroup_bones() {
    std::cout << "Введите контрольное значение - " << std::endl;
    int val = get_int();

    if (val > 7 or val < 1) {
        std::cout << "Неверное значение" << std::endl;
        return;
    }

    Domino dominos = this->domino.find(val);

    dominos.print();

}




