#include <iostream>
#include <string>
#include "Matrix.hpp"

using namespace std;

Matrix::Matrix(){
    this->name = "UNNAMED";
    this->h = 3; this->w = 3;
    this->mat = new double*[3];
    for(int i = 0; i < 3; i++){
        this->mat[i] = new double[3];
    }
}

//Iterate by H then W
Matrix::Matrix(int x, int y){
    this->name = "UNNAMED";
    this->h = y; this->w = x;
    this->mat = new double*[h];
    for(int i = 0; i < h; i++){
        this->mat[i] = new double[w];
    }
}

Matrix::Matrix(int x, int y, string n){
    this->name = n;
    this->h = y; this->w = x;
    this->mat = new double*[h];
    for(int i = 0; i < h; i++){
        this->mat[i] = new double[w];
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < h; i++){
        delete this->mat[i];
    }
    delete this->mat;
}

void Matrix::setName(string n){
    this->name = n;
}

void Matrix::zeros(){
    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            this->mat[i][j] = 0.0;
        }
    }
}

void Matrix::ones(){
    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            this->mat[i][j] = 1.0;
        }
    }
}

void Matrix::transpose(){
    double** newMat = new double*[this->w];
    for(int i = 0; i < this->w; i++){
        newMat[i] = new double[this->h];
    }

    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            newMat[j][i] = this->mat[i][j];
        }
    }
    int buf = this->w;
    this->w = this->h;
    this->h = buf;

    this->mat = newMat;

}

void Matrix::T(){transpose();}

void Matrix::dot(Matrix &m){
    int *shape = m.shape();
    bool compatible = (this->w <= shape[0]);
    cout << "COMPAT: " << compatible << endl;
    return;
    //check if the matrices are compatible
    //take the dot product of two matrices
}

int* Matrix::shape(){
    int out[2] = {this->w, this->h};
    int *p = out;
    return p;
}