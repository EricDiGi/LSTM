#ifndef Vanilla_HPP
#define Vanilla_HPP

#include "Matrix.hpp"
#include <iostream>

class Vanilla{
    private:
        Matrix hidden;
        Matrix W_hh;
        Matrix W_xh;
        Matrix W_hy;
        Matrix Bh;
        Matrix By;
    public:
        Vanilla();
        ~Vanilla();

};

#endif