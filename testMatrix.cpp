#include <iostream>
#include <string>
#include "Matrix.hpp"

using namespace std;

int main(){
    Matrix m = Matrix();
    Matrix m1 = Matrix(5,3);
    Matrix m2 = Matrix(4,4, "Fours");
    m2.zeros();
    m1.ones();
    cout << m2;
    cout << m1;
    m1.T();
    m1.dot(m2);
    cout << m1;
}