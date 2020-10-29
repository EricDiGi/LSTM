#ifndef Matrix_HPP
#define Matrix_HPP

#include <iostream>
#include <string>
class Matrix{
    private:
        double** mat = NULL;
        int h = 0;
        int w = 0; 
        std::string name = "";
    public:
        //Construct & destruct
        Matrix();
        Matrix(int x, int y);
        Matrix(int x, int y, std::string n);
        Matrix(int x, int y, double** mat, std::string n);
        ~Matrix();
        void setName(std::string n);
        void at(int x, int y, int data);

        //Initial population
        void zeros(); //populate matrix with zeros
        void ones();
        void randn(); //random doubles from the standard normal distribution
        void randd();

        //Arithmatic
        Matrix dot(Matrix &m);
        Matrix tanH();


        //reshape
        void transpose();
        void T();

        //Metrix
        int width();
        int height();
        double** getMat();
        std::string getName();
        double stdDev(double m,int n);
        double normalDist(int x, double stdev, double m);


        Matrix operator+(const Matrix &a){
            bool cont = ((a.h == this->h)&&(a.w==this->w));
            cont = (cont && (a.mat != NULL) && (this->mat!=NULL));
            double** nMat = NULL;

            if(cont){
                nMat = new double*[a.h];
                for(int i = 0; i < a.h; i++){
                    nMat[i] = new double[a.w];
                    for(int j = 0; j < a.w; j++){
                        nMat[i][j] = a.mat[i][j] + this->mat[i][j];
                    }
                }
                return Matrix(a.w, a.h, nMat, a.name+"+"+this->name);
            }
            return Matrix();
        }

        friend Matrix operator*(int a, const Matrix &m){
            bool cont = m.mat != NULL;
            double** nMat = NULL;
            
            if(cont){
                nMat = new double*[m.h];
                for(int i = 0; i < m.h; i++){
                    nMat[i] = new double[m.w];
                    for(int j = 0; j < m.w; j++){
                        nMat[i][j] = (double)a * m.mat[i][j];
                    }
                }
                return Matrix(m.w, m.h, nMat, m.name);
            }
            return Matrix();
        }

        Matrix operator*(int a){
            bool cont = this->mat != NULL;
            double** nMat = NULL;
            
            if(cont){
                nMat = new double*[this->h];
                for(int i = 0; i < this->h; i++){
                    nMat[i] = new double[this->w];
                    for(int j = 0; j < this->w; j++){
                        nMat[i][j] = (double)a * this->mat[i][j];
                    }
                }
                return Matrix(this->w, this->h, nMat, this->name);
            }
            return Matrix();
        }

        friend std::ostream &operator<< (std::ostream &out, const Matrix &m){
            std::string comma;
            std::string tab;
            out << m.name << " = [ ";
            for(int i = 0; i < m.h; i++){
                tab = (i>0) ? "\t" : "";
                out <<tab << "[ ";
                for(int j = 0; j < m.w; j++){
                    comma = (j == m.w-1) ? " " : ", ";
                    out << m.mat[i][j] << comma;
                }
                out << "],\n";
            }
            out << "]\n";
            return out;
        }
};


#endif