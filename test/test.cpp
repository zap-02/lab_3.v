#include <gtest/gtest.h>
#define private public
#include <UI.h>


TEST(test1,Positiv){
    Domino *domino = new Domino(2,4);
    Bone *bone = new Bone();
    bone->set_top(2);
    bone->set_bottom(4);
    ASSERT_EQ(domino->get_elem(0).top,bone->top);
}

TEST(test1_5,Positiv){
    Domino *domino = new Domino(2,4);
    Bone *bone = new Bone();
    bone->set_top(2);
    bone->set_bottom(4);
    ASSERT_EQ(domino->get_elem(0).bottom,bone->bottom);
}

TEST(test2,Positiv){
    Domino *domino = new Domino(2,4);
    Bone *bone = new Bone();
    bone->set_top(2);
    bone->set_bottom(4);
    ASSERT_EQ( domino->get_elem(0) == *bone, 1);
}


TEST(test3,Positiv){
    Domino *domino = new Domino();
    Bone *bone1 = new Bone();
    bone1->set_top(4);
    bone1->set_bottom(2);

    domino->set_arr(2,*bone1);

    Bone *bone = new Bone();
    bone->set_top(2);
    bone->set_bottom(4);
    ASSERT_EQ( domino->get_elem(2) == *bone,1 );
}

TEST(test4,Positiv){
    Domino *domino = new Domino(2,4);
    domino->set_csize(7);

    ASSERT_EQ( domino->get_csize(), 7);
}


TEST(test5,Positiv){
    Domino *domino = new Domino(2,4);
    Bone *bone = new Bone();
    bone->set_top(3);
    bone->set_bottom(4);
    domino->set_arr(1,*bone);

    bone->set_top(5);
    bone->set_bottom(4);
    domino->set_arr(2,*bone);

    Domino *new_domino = new Domino();
    *new_domino = domino->find(2);
    ASSERT_EQ( domino->get_elem(0).get_top(), 2);
}

TEST(test6,Positiv){
    Domino domino(2,4);
    Bone *bone = new Bone();
    bone->set_top(3);
    bone->set_bottom(4);
    domino.set_arr(1,*bone);

    bone->set_top(5);
    bone->set_bottom(4);
    domino.set_arr(2,*bone);

    --domino;

    ASSERT_EQ( domino.get_elem(2).get_top(), -1);
}

TEST(test7,Positiv){
    Domino domino(2,4);
    Bone *bone = new Bone();
    bone->set_top(3);
    bone->set_bottom(4);
    domino.set_arr(1,*bone);

    bone->set_top(5);
    bone->set_bottom(4);
    domino.set_arr(2,*bone);

    domino--;

    ASSERT_EQ( domino.get_elem(2).get_top(), -1);
}

TEST(test8,Positiv) {
    Domino domino(2, 4);
    Bone *bone = new Bone();
    bone->set_top(3);
    bone->set_bottom(4);
    domino.set_arr(1, *bone);

    bone->set_top(5);
    bone->set_bottom(4);
    domino.set_arr(2, *bone);

    Domino new_domino(5, 6);

    Domino sum =  new_domino + domino ;

    ASSERT_EQ(sum.get_elem(1).get_top(), 3);
}


TEST(test9,Positiv) {
    Domino domino(2, 4);
    Bone *bone = new Bone();
    bone->set_top(3);
    bone->set_bottom(4);
    domino.set_arr(1, *bone);

    bone->set_top(5);
    bone->set_bottom(4);
    domino.set_arr(2, *bone);

    -domino;

    ASSERT_EQ(domino.get_elem(1).get_top(), 4);
}


TEST(test10,Positiv) {
    Domino domino(2, 4);
    Bone *bone = new Bone();
    bone->set_top(3);
    bone->set_bottom(4);
    domino.set_arr(1, *bone);

    bone->set_top(5);
    bone->set_bottom(4);
    domino.set_arr(2, *bone);

    Domino new_domino(5, 6);

    new_domino+=domino;

    ASSERT_EQ(new_domino.get_elem(3).get_top(), 5);
}





