#include "domino.h"

int Domino::isUnique() {//если уникально возвращает 1

    for (int i = 0; i < this->csize - 1; i++) {
        for (int j = i + 1; j < this->csize; j++) {

            if (((this->arr[i].get_bottom() == this->arr[j].get_bottom() &&
                  this->arr[i].get_top() == this->arr[j].get_top()) or

                 (this->arr[i].get_bottom() == this->arr[j].get_top() &&
                  this->arr[i].get_top() == this->arr[j].get_bottom())) and (this->arr[j].get_top() != -1)) {

                return -1;
            }
        }
    }
    return 1;
}

void Domino::print() {
    for (int i = 0; i < this->csize; i++) {
        std::cout << "Number->" << i + 1 << std::endl;
        std::cout << "Bottom->" << this->arr[i].get_bottom() << std::endl;
        std::cout << "Top->" << this->arr[i].get_top() << std::endl << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl << std::endl;
}

Bone &Domino::pop_bone(Bone &val) {
    for (int i = 0; i < this->csize; i++) {
        if (arr[i] == val) { //this->arr[i].isequal(val)
            Bone *b = new Bone(val);
            Bone &tmp = this->arr[this->csize - 1];
            this->arr[this->csize - 1] = this->arr[i];
            this->arr[i] = tmp;
            this->arr[this->csize - 1].set_bottom(-1);
            this->arr[this->csize - 1].set_top(-1);
            this->csize--;
            return *b;
        }
    }
    throw std::runtime_error("Nothing found");
}

void Domino::bouble() { //упорядочить кости по возрастанию суммы очков;
    for (int i = 0; i < csize - 1; i++) {
        for (int j = i + 1; j < csize; j++) {
            if (arr[i].get_bottom() + arr[i].get_top() > arr[j].get_top() + arr[j].get_bottom()) {
                arr[i].swap(arr[j]);
            }
        }
    }
}

void Bone::set_bottom(int t) {
    this->bottom = t;
}

Bone::Bone() {
    top = -1;
    bottom = -1;
}

Bone::Bone(Bone &bone) {
    this->bottom = bone.get_bottom();
    this->top = bone.get_top();
}

void Bone::set_top(int t) {
    this->top = t;
}

int Bone::get_top() const {
    return top;
}

int Bone::get_bottom() const {
    return bottom;
}

bool Bone::isequal(Bone &bone) const {
    if ((this->top == bone.get_top() and this->bottom == bone.get_bottom()) or
        (this->bottom == bone.get_top() and this->top == bone.get_bottom()))
        return true;
    return false;
}

bool Bone::operator==(const Bone &bone) const { //сравнение
    if ((top == bone.top and bottom == bone.bottom) or
        (bottom == bone.top and top == bone.bottom))
        return true;
    return false;
}

void Bone::swap(Bone &tmp) {
    int a = tmp.get_bottom();
    int b = tmp.get_top();
    tmp.set_top(this->get_top());
    tmp.set_bottom(this->get_bottom());
    this->set_bottom(a);
    this->set_top(b);
}


Domino &
Domino::find(int val) { //выделить из группы костей подгруппу костей, содержащих конкретное значение хотя бы один раз.
    Domino *d = new Domino();
    int x = 0;
    for (int i = 0; i < csize; i++) {
        if (arr[i].get_bottom() == val || arr[i].get_top() == val) {
            Bone *b = new Bone(arr[i]);
            d->set_arr(x, *b);
            x++;
        }
    }
    return *d;
}


void Domino::set_csize(int i) {
    this->csize = i;
}

[[nodiscard]] int Domino::get_csize() const {
    return this->csize;
}

const Bone Domino::get_elem(int i) { // “открыть” кость по её номеру в группе, создав экземпляр класса с одной костью;
    return this->arr[i]; //проверка на i<28
}


Domino::Domino(Domino const &domino) {
    this->csize = domino.csize;
    this->arr = new Bone[this->csize];
    for (int i = 0; i < csize; ++i) {
        arr[i] = domino.arr[i];
    }
}


Bone &Domino::operator[](int index) { //индексация 1/2, возвращение копии (r-value)
    return arr[index];
}


Domino &Domino::operator--(){
    arr[csize-1].set_bottom(-1);
    arr[csize-1].set_top(-1);
    --csize;
    return *this;
}

Domino Domino::operator--(int){
    Domino prev(*this);
    arr[csize-1].set_bottom(-1);
    arr[csize-1].set_top(-1);
    --csize;
    return prev;
}


void Domino::set_arr(int i, Bone val) {
    this->arr[i] = val;
    this->csize++;
}

Domino Domino::operator+(const Domino &domino) const{ //бинарный
    int new_size = domino.csize + csize;
    if (new_size > 28) throw std::overflow_error("no space");
    Domino new_domino(domino);

    for (int i = 0; i < csize; ++i) {
        new_domino[csize + i + 1] = arr[i];
    }
    return new_domino;
}

Domino &Domino::operator-(){ //меняет местами top and bottom
    for(int i =0; i<csize; i++){
        int swap = arr[i].get_bottom();
        arr[i].set_bottom(arr[i].get_top());
        arr[i].set_top(swap);
    }
    return *this;
}

Domino &Domino::operator+=(Domino domino){
    for(int i = 0; i< domino.csize; i++){
        for(int j = 0; j< csize;j++ ){
            if( !(arr[i] == domino.arr[j]))
                set_arr(csize,domino.get_elem(j));
        }
        if(csize == 28)
            break;
    }
    return *this;
}

Domino::Domino(int size) {
    csize = size;
    arr = new Bone[28];
    srand(time(NULL));

    for (int i = 0; i < this->csize; ++i) {

        do {
            this->arr[i].set_bottom(rand() % 7);
            this->arr[i].set_top(rand() % 7);

        } while (isUnique() == -1);
    }
}

Domino::Domino(int t, int b) {
    this->csize = 1;
    arr = new Bone[28];
    this->arr[0].set_bottom(b);
    this->arr[0].set_top(t);
}


std::istream &operator>>(std::istream &a, Domino &domino) {

    int flag = 0;

    Bone *special_bone = new Bone();

    do {
        int c, b;
        std::cout << "Введите значение первой грани" << std::endl;
        a >> c;
        std::cout << "Введите значение второй грани" << std::endl;
        a >> b;

        Bone *bone = new Bone();
        bone->set_bottom(b);
        bone->set_top(c);

        domino.set_arr(domino.get_csize(), *bone);


        if (domino.isUnique() == -1) {
            std::cout << "Элемент не уникален, повторите попытку" << std::endl << std::endl;
            domino.set_csize(domino.get_csize() - 1);
            domino.set_arr(domino.get_csize(), *special_bone);
            domino.set_csize(domino.get_csize() - 1);
        } else {
            flag = 1;
            std::cout << "Вставлен элемент на " << domino.get_csize() << "-ую позицию" << std::endl << std::endl;
        }

    } while (flag == 0);
    return a;
}


std::ostream &operator<<(std::ostream &a, const Domino &domino) {
    for (int i = 0; i < domino.csize; i++) {
        a << "Number->" << i + 1 << std::endl;
        a << "Bottom->" << domino.arr[i].get_bottom() << std::endl;
        a << "Top->" << domino.arr[i].get_top() << std::endl << std::endl;
    }
    return a;
}



bool correct_get_int(int &a) {
    std::cin >> a;
    if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore();
        return false;
    }
    return true;
}

int get_int() {
    int num;
    while (true) {
        if (correct_get_int(num) and num <= 28 and num >= 0)
            break;
        std::cout << "Wrong number" << std::endl;
    }
    return num;
}