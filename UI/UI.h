#ifndef LAB_3_1__UI_H
#define LAB_3_1__UI_H

#include "domino.h"
#include <iostream>

class UI {
private:
    Domino domino;
public:
    Domino &get_domino() {
        return domino;
    }

    void set_domino(Domino &dominos);

    Domino domino_init();

    void input_value();

    void input_rand_value();

    Bone pop_bone();

    void open_bone();

    void order_domino();

    void subgroup_bones();

    void print_domino();


};

#endif //LAB_3_1__UI_H
