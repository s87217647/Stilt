//
// Created by Administrator on 10/11/2020.
//

#ifndef STILT_SPARSE_MATRIX_H
#define STILT_SPARSE_MATRIX_H

#include <vector>
#include <list>
#include "Matrix.h"

using namespace std;



template <typename T>
class Sparse_Matrix{
private:
    struct Node {
        size_t _col;
        T _val;

        Node(size_t c = 0, T v = T()) : _col(c), _val(v){}

        size_t get_col() const{return  _col;}
        const T get_value() const{return _val;}
        void set_value(const T &val){_val = val;}
        virtual const T& operator=(const T& val){ return _val = val;}

        friend ostream& operator<<(ostream& os, const Node &node ){
//            return os << "{C: " << node.get_col() << ", V: " << node.get_value() << " }"; // something is wrong with this line
        }

    };

    vector<list<Node>> _rows;
    size_t _num_rows, _num_cols;
    T _default_val;

public:
//    Sparse_Matrix()(size_t nr = 0, size_t nc = 0, const T &default_val = T()):
//    _num_rows(nr), _num_cols(nc), _default_val(default_val){}

    size_t get_num_rows() const{return _num_rows;}
    size_t get_num_cols() const{return _num_cols;}

    bool is_valid(size_t r, size_t c) const;
    void clear();
    const T get(size_t r, size_t c) const;
    bool set(size_t row, size_t col, const T& val);
    Matrix<T> get_slice(size_t r1, size_t c1, size_t r2, size_t c2) const;
    string toString() const;
    friend class  Tests;


};


#endif //STILT_SPARSE_MATRIX_H
