#ifndef Matrix_HPP
#define Matrix_HPP

#include <iostream>
#include <string>
class Matrix{
    private:
        double** mat;
        int h;
        int w; 
        std::string name;
    public:
        //Construct & destruct
        Matrix();
        Matrix(int x, int y);
        Matrix(int x, int y, std::string n);
        ~Matrix();
        void setName(std::string n);

        //Initial population
        void zeros(); //populate matrix with zeros
        void ones();

        //Arithmatic
        void dot(Matrix &m);

        //reshape
        void transpose();
        void T();

        //Metrix
        int* shape();

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