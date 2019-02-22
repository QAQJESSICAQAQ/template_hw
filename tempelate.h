
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
	
	
	
    /** ************************* THE BIG 4 ************************* **/
    
    //default constructor
    template<typename T>
    vector<T>::vector()
    : the_data(nullptr), the_size(0), the_capacity(INIT_CAP) {
        std::cout<<"xxxxxxx Default Constructor Called xxxxxxx"<<std::endl;
        the_data = new T[the_capacity];
    }
    
    
    //copy constructor
    template<typename T>
    vector<T>::vector( const vector<T>& source )
    : the_data(nullptr), the_size(source.the_size),
    the_capacity(source.the_capacity) {
        std::cout<<"xxxxxxx Copy Constructor Called xxxxxxx"<<std::endl;
        
        the_data = new T[the_capacity];
        
        // Deep copy of internal array
        for ( int i = 0 ; i < the_size ; ++i ){
            the_data[i] = source.the_data[i];
        }
        
    }
    
    //assginment operator
    template<typename T>
    vector<T>& vector<T>::operator=( const vector<T>& rhs ) {
         std::cout<<"xxxxxxx Assignment Operator xxxxxxx"<<std::endl;
        if ( this != &rhs ) {     // x=x
            // Release old memory and request more
            delete[] the_data;
            the_data = new T[rhs.the_capacity];
            
            // Shallow copy non-pointers
            the_size = rhs.the_size;
            the_capacity = rhs.the_capacity;
            
            // Deep copy internal array
            for ( int i = 0 ; i < the_size ; ++i )
                the_data[i] = rhs.the_data[i];
        }
       
        return *this;
    }
    
    //destructor
    template<typename T>
    vector<T>::~vector<T>(){
         std::cout<<"xxxxxxx Dustructor Called xxxxxxx"<<std::endl;
        delete[] the_data;
       
    }
	
	
	
	
	
	
	
	
	
	
	
	
	