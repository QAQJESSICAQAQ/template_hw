
//  our templetaed vector class
//  template
//  Created by Jinqi Song on 2019/02/21.
// Libary file for a templated vector class

//this class is based on an old non-templetated 
//vector class we talked about in pic10b class


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
	
    /** *********************** OTHER MEMBERS *********************** **/
   
    template<typename T>
    bool vector<T>::empty() const {
        return the_size == 0;
    }
    
    template<typename T>
    size_t vector<T>::size() const {
        return the_size;
    }
    
    template<typename T>
    size_t vector<T>::capacity() const {
        return the_capacity;
    }
    
    template<typename T>
    T& vector<T>::operator[]( size_t index ){
        return the_data[index];
    }
    
    template<typename T>
    T vector<T>::operator[]( size_t index ) const {
        return the_data[index];
    }
    
    template<typename T>
    void vector<T>::push_back( T new_value ){
        if ( the_size == the_capacity )
            reserve( the_capacity + 1 );     // `the_data` is reassigned
        
        the_data[the_size++] = new_value;
    }
    
    template<typename T>
    void vector<T>::reserve( size_t new_capacity ){
        if ( new_capacity > the_capacity ) {
            if ( new_capacity <= 2 * the_capacity )
                new_capacity = 2 * the_capacity;
            
            T* old_location = the_data;
            
            the_data = new T[new_capacity];
            the_capacity = new_capacity;
            
            for ( size_t i = 0 ; i < the_size ; ++i )
                the_data[i] = old_location[i];
            
            delete old_location;
        }
        
    }
	
	
	
    /** ************************ OPERATORS (member) ************************ **/
    template<typename T>
    vector<T> vector<T>::operator*(T a ){
        vector vec(*this);
        for ( int i = 0 ; i < the_size ; ++i )
            vec[i] =a* vec[i];
        return vec;
    }
    
 
        
    template<typename T>
    vector<T> vector<T>::operator+(const vector<T>& rhs ){
        vector vec(*this);
        for ( int i = 0 ; i < the_size ; ++i )
            vec[i] =vec[i]+ rhs[i];
        return vec;
    }
    
    template<typename T>
    vector<T>& vector<T>::operator+=( const vector<T>& rhs ){
    for ( int i = 0 ; i < the_size ; ++i )
        the_data[i] += rhs.the_data[i];
        return *this;
    }
	
	
/** ************************ OPERATORS (nonmember) ************************ **/
template<typename T>
Pic10b::vector<T> operator*(T a, const Pic10b::vector<T>& rhs ){
    Pic10b::vector<T> copy(rhs);
    for (size_t i = 0 ; i < rhs.size() ; ++i)
        copy[i]=a*copy[i];
    return copy;
}

template<>
Pic10b::vector<std::string> operator*(std::string str, const Pic10b::vector<std::string>& rhs ){
    Pic10b::vector<std::string> copy(rhs);
    for (size_t i = 0 ; i < rhs.size(); ++i)
        copy[i]=str+" "+copy[i];
    return copy;
}

template<typename T>
T operator*(const Pic10b::vector<T>& lhs, const Pic10b::vector<T>& rhs ){
    T dot_product=0;
    for (size_t i = 0 ; i < rhs.size() ; ++i)
        dot_product+=lhs[i]*rhs[i];
    return dot_product;
}

template<typename T>
Pic10b::vector<T> operator+(Pic10b::vector<T>& lhs, Pic10b::vector<T>& rhs ){
    Pic10b::vector<T> copy(rhs);
    for (size_t i = 0 ; i < rhs.size() ; ++i)
        copy[i]=lhs[i]+rhs[i];
    return copy;
}
	
	
template<typename T>
T compare(const Pic10b::vector<T>& lhs, const Pic10b::vector<T>& rhs ) {
    T dot_product_diff=0;
    dot_product_diff=lhs * lhs - rhs * rhs;
    return dot_product_diff;
    
}
	

template<typename T>
bool operator<(const Pic10b::vector<T>& f , const Pic10b::vector<T>& g ){
    return compare(f,g) < 0 ;
}
template<typename T>
bool operator>(const Pic10b::vector<T>& f , const Pic10b::vector<T>& g ){
    return compare(f,g) > 0 ;
}
template<typename T>
bool operator<=(const Pic10b::vector<T>& f , const Pic10b::vector<T>& g ){
    return compare(f,g) <= 0 ;
}
template<typename T>
bool operator>=(const Pic10b::vector<T>& f , const Pic10b::vector<T>& g ){
    return compare(f,g) >= 0 ;
}
template<typename T>
bool operator==(const Pic10b::vector<T>& f , const Pic10b::vector<T>& g ){
    return compare(f,g) == 0 ;
}
template<typename T>
bool operator!=(const Pic10b::vector<T>& f , const Pic10b::vector<T>& g ){
    return compare(f,g) != 0 ;
}
	

//overloading <<
template<>
bool operator==(const Pic10b::vector<std::string>& f , const Pic10b::vector<std::string>& g ){
    bool a=true;
    for (size_t i = 0 ; i < g.size() ; ++i)
        if (f[i]!=g[i])
            a=false;
    return a;
}


template<>
bool operator!=(const Pic10b::vector<std::string>& f , const Pic10b::vector<std::string>& g ){
    bool a=true;
    for (size_t i = 0 ; i < g.size() ; ++i)
        if (f[i]==g[i])
            a=false;
    return a;
}
	
template<>
std::ostream& operator<<( std::ostream& out, const Pic10b::vector<std::string>& v ){
    std::cout<< "[";
    for ( size_t i = 0 ; i < v.size()-1 ; ++i )
        out <<" "<<v[i] << "," <<" ";
    out<< v[v.size()-1]<< " ]";
    return out;
}	



#endif
	