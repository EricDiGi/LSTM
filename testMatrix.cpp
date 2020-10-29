#include <iostream>
#include <string>
#include "Matrix.hpp"

using namespace std;

void loadM1(Matrix &m1){
    m1.at(0,0, 1);
    m1.at(0,1,2);
    m1.at(1,0,7);
    m1.at(1,1,4);
}
void loadM2(Matrix &m1){
    m1.at(0,0, 3);
    m1.at(0,1,5);
    m1.at(1,0,3);
    m1.at(1,1,2);
}

int main(){
    Matrix m = Matrix();
    Matrix m1 = Matrix(2,2);
    Matrix m2 = Matrix(2,2, "Fours");
    m2.ones();
    loadM1(m1);
    loadM2(m2);
    //m2.T();
    cout << m2;
    cout << m1;
    
    Matrix D = m2.dot(m1);
    D.randn();
    cout << D;
    cout << (m1+m2);
}