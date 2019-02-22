
//  our templetaed vector class
//  template
//  Created by Jinqi Song on 2019/02/21.
// Libary file for a templated vector class



#ifndef pic10b_vector_h
#define pic10b_vector_h

#include <iostream>
#include <vector>
#include<string>
// std::ostream, std::cout
namespace Pic10b{
    template<typename T>
    class vector{
    private:
        T* the_data;
        size_t the_size;
        size_t the_capacity;
        static const int INIT_CAP = 10;
        
        //Other members [private]
        void reserve( size_t new_capacity );
        
    public:
        // The big 4
        vector();
        vector( const vector& );
        vector& operator=( const vector& );
        ~vector();
        
        // Other members [public]
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T& operator[]( size_t index );
        T operator[]( size_t index ) const;
        void push_back( T new_value );
        vector& operator+=( const vector& );
        vector<T> operator*(T a );
        vector<T> operator+(const vector& );
    }; // end of class