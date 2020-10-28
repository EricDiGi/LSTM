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

Matrix::Matrix(int x, int y, double** mat, string n){
    this->name = n;
    this->h = y; this->w = x;
    this->mat = mat;
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

void Matrix::at(int x, int y, int data){
    this->mat[y][x] = data;
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

Matrix Matrix::dot(Matrix &m){
    bool compatible = (this->w == m.height());
    if(!compatible){return Matrix(0,0);}

    double** MAT = m.getMat();
    double** temp = new double*[this->h];
    for(int i = 0; i < this->h; i++){
        temp[i] = new double[m.width()];
        for(int j = 0; j < m.width(); j++){
            temp[i][j] = 0;
        }
    }
    //dot product
    for(int y = 0; y < this->h; y++){
        for(int x = 0; x < m.width(); x++){
            for(int k = 0; k < this->w; k++){
                temp[y][x] += (this->mat[y][k] * MAT[k][x]);
            }
        }
    }
    
    return Matrix(m.width(), this->h,temp, this->name+"."+m.getName());
}

int Matrix::width(){
    return this->w;
}

int Matrix::height(){
    return this->h;
}

double** Matrix::getMat(){
    return this->mat;
}

string Matrix::getName(){
    return this->name;
}