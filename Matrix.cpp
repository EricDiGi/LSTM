#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <bits/stdc++.h>
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
    cout << "very top";
    this->name = n;
    this->h = y; this->w = x;
    this->mat = new double*[h];
    cout << "top";
    for(int i = 0; i < h; i++){
        this->mat[i] = new double[w];
    }
    cout << "work" << endl;
}

Matrix::Matrix(int x, int y, double** mat, string n){
    this->name = n;
    this->h = y; this->w = x;
    this->mat = mat;
}

Matrix::~Matrix(){
    for(int i = 0; i < h; i++){
        delete[] this->mat[i];
    }
    delete[] this->mat;
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

void Matrix::randn(){
    double max = 4.0; double r; double base;
    double sum = 0; double mean; double N = 0;
    srand(time(NULL));
    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            base = rand() % (int)max;
            r = base + ((double)(rand()%(int)max) / max);
            //this->mat[i][j] = r;
            N++;
            sum += r;
        }
    }
    mean = sum / N;
    double stdev = stdDev(mean, N);
    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            this->mat[i][j] = normalDist(rand()%(int)max, stdev,mean);
        }
    }
    cout << "randn"<< endl;
}

void Matrix::randd(){
    srand(time(NULL));
    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            this->mat[i][j] = (double)rand();
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

Matrix Matrix::tanH(){
    double** nMat = NULL;
    if(this->mat == NULL){return Matrix();}
    nMat = new double*[this->h];
    //double v;
    for(int i = 0; i < this->h; i++){
        nMat[i] = new double[this->w];
        for(int j = 0; j < this->w; j++){
            nMat[i][j] = tanh(this->mat[i][j]);
        }
    }
    return Matrix(this->w, this->h, nMat, this->name);
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

double Matrix::stdDev(double m, int n){
    double sum = 0;
    for(int i = 0; i < this->h; i++){
        for(int j = 0; j < this->w; j++){
            sum += pow((this->mat[i][j] - m),2);
        }
    }
    return sqrt(sum/(double)n);
}

double Matrix::normalDist(int x, double stdev, double m){
    //cout << "mean: " << m << "\tstdev: " << stdev << endl;
    double exponent = -0.5 * pow(((double)x - m)/stdev, 2);
    double base = (1/(stdev * sqrt(2*M_PI))) * pow(M_E,exponent);
    return base; 
}

string Matrix::getName(){
    return this->name;
}