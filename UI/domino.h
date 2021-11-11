#ifndef INC_LAB_3_1_DOMINO_H
#define INC_LAB_3_1_DOMINO_H

#include <iostream>
#include <string>

struct Bone {
private:
    int top;
    int bottom;
public:
    Bone();

    Bone(Bone &bone);

    ~Bone() = default;

    void set_top(int t);

    void set_bottom(int t);

    int get_top() const;

    int get_bottom() const;

    bool isequal(Bone &bone) const;

    bool operator==(const Bone &bone) const ;

    void swap(Bone &tmp);
};

class Domino {
private:
    Bone *arr;
    int csize;
public:
    void set_arr(int i, Bone val);

    void set_csize(int i);

    [[nodiscard]] int get_csize() const;

    const Bone get_elem(int i);

    int isUnique();

    Domino() {
        arr = new Bone[28];
        this->csize = 0;
    }



    Domino(Domino const &domino);

    ~Domino(){
        delete[] arr;
    }


    Bone &operator[](int index);

    Domino &operator--();

    Domino operator--(int);

    Domino operator+(const Domino &domino) const;


    Domino &operator-();

    Domino &operator+=(Domino domino);

    explicit Domino(int size);

    Domino(int t, int b);

    void print();

    Bone &pop_bone(Bone &val);

    void bouble();

    Domino &find(int val);

    friend std::ostream &operator<<(std::ostream &a, const Domino &domino);

    friend  std::istream &operator>>(std::istream &a, Domino &domino);
};

int get_int();

//inline std::ostream &operator<<(std::ostream &a, const Domino &domino) {
//    for (int i = 0; i < domino.csize; i++) {
//        a << "Number->" << i + 1 << std::endl;
//        a << "Bottom->" << domino.arr[i].get_bottom() << std::endl;
//        a << "Top->" << domino.arr[i].get_top() << std::endl << std::endl;
//    }
//    return a;
//}
//
//inline std::istream &operator>>(std::istream &a, Domino &domino) {
//
//    int flag = 0;
//
//    Bone *special_bone = new Bone();
//    special_bone->set_bottom(-1);
//    special_bone->set_top(-1);
//
//    do {
//        int c, b;
//        std::cout << "Введите значение первой грани" << std::endl;
//        a >> c;
//        std::cout << "Введите значение второй грани" << std::endl;
//        a >> b;
//
//        Bone *bone = new Bone();
//        bone->set_bottom(b);
//        bone->set_top(c);
//
//        domino.set_arr(domino.get_csize(), *bone);
//
//
//        if (domino.isUnique() == -1) {
//            std::cout << "Элемент не уникален, повторите попытку" << std::endl << std::endl;
//            domino.set_csize(domino.get_csize() - 1);
//            domino.set_arr(domino.get_csize(), *special_bone);
//            domino.set_csize(domino.get_csize() - 1);
//        } else {
//            flag = 1;
//            std::cout << "Вставлен элемент на " << domino.get_csize() << "-ую позицию" << std::endl << std::endl;
//        }
//
//    } while (flag == 0);
//    return a;
//}





#endif
