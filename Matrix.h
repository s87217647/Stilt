//
// Created by Administrator on 10/11/2020.
//

#ifndef STILT_MATRIX_H
#define STILT_MATRIX_H
#include <vector>
#include <xstring>

using namespace std;

template <typename T>
class Matrix{
protected:
 vector<vector<T>> _rows;
public:
    Matrix(size_t nr = 0, size_t nc = 0);

    size_t get_num_rows() const{return  _rows.size();}
    size_t get_num_cols() const{return _rows.size()>0? _rows.size():0;};
    void clear(){ _rows.clear();}

    void resize(size_t nr, size_t nc);
    T &at(size_t r, size_t c); //throws OOB
    string to_string() const; // Reread that const aye?

    class OBB_exception : public exception{
    public:string what(){return  "Out of bounds access";}
    //Friends---------------------------------

    friend ostream &operator<< (ostream& os, const  Matrix<T> &mat){
        return  os << mat.to_string();
    }

    friend bool operator== (const Matrix<T> &m1, const Matrix<T> &m2){
        if(m1.get_num_cols() != m2.get_num_cols()) return false;
        if(m1.get_num_rows() != m2.get_num_rows()) return false;

        // Fill it
        // Fill it

        return true;
    }

    friend bool operator!= (const Matrix<T> &m1,const Matrix<T> &m2){
        return  !(m1 == m2);
    }
    friend class Tests;


    };

};
#endif //STILT_MATRIX_H
