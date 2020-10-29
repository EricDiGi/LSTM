#include <iostream>
#include "Matrix.hpp"
#include "Vanilla.hpp"

using namespace std;

Vanilla::Vanilla(){
    this->hidden = Matrix(3,3,"hidden");
    //this->hidden.zeros();
/*
    this->W_hh = Matrix(3,3,"W_hh");
    this->W_hh.randn();

    cout << "here 1" << endl;
    //this->W_xh = Matrix(3,3,"W_xh");
    cout << "here 2" << endl;
    //this->W_xh.randn();

    this->W_hy = Matrix(3,3,"W_hy");//.randn();
    this->W_hy.randn();
    this->Bh = (Matrix(3,1,"Bh"));//.randn();
    this->Bh.randn();
    this->By = (Matrix(3,1,"By"));//.randd();
    this->By.randd();*/
    cout << "BOOOOOOOOO" << endl;
}

Vanilla::~Vanilla(){
    this->hidden = Matrix();
}