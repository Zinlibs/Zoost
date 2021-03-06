////////////////////////////////////////////////////////////
//
// Zoost C++ library
// Copyright (C) 2011-2012 Pierre-Emmanuel BRIAN (zinlibs@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef ZOOST_VECTOR2_HPP
#define ZOOST_VECTOR2_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cmath>
#include <Zoost/Config.hpp>

namespace zin
{

template <typename T>
class ZOOST_API Vector2
{
public:

    ////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////
	Vector2(T x = 0, T y = 0);
	
    ////////////////////////////////////////////////////////////
    // Copy constructor
    ////////////////////////////////////////////////////////////
	Vector2(const Vector2<T>& vector);

    ////////////////////////////////////////////////////////////
    // Set the vector coordinates
    ////////////////////////////////////////////////////////////	
    void set(T x, T y);

    ////////////////////////////////////////////////////////////
    // Get the length of the vector
    ////////////////////////////////////////////////////////////
    T length() const;
    
    ////////////////////////////////////////////////////////////
    // Get the length of the vector
    ////////////////////////////////////////////////////////////
    static T length(const Vector2<T>& vector);
    
    ////////////////////////////////////////////////////////////
    // Get the scalar product between two vectors
    ////////////////////////////////////////////////////////////
    static T scalarProduct(const Vector2<T>& vector1, const Vector2<T>& vector2);

    ////////////////////////////////////////////////////////////
    // Get the angle between two vectors
    ////////////////////////////////////////////////////////////
    static T angle(const Vector2<T>& vector1, const Vector2<T>& vector2);
    
    ////////////////////////////////////////////////////////////
    // Get the normalized vector
    ////////////////////////////////////////////////////////////>
    Vector2<T> getNormal();

    ////////////////////////////////////////////////////////////
    // Normalize the vector
    ////////////////////////////////////////////////////////////
    void normalize();
    
    ////////////////////////////////////////////////////////////
    // Get the addition of the two vectors
    ////////////////////////////////////////////////////////////
    Vector2<T> operator+(const Vector2<T>& vector) const;
    
    ////////////////////////////////////////////////////////////
    // Get the substraction of the two vectors
    ////////////////////////////////////////////////////////////
    Vector2<T> operator-(const Vector2<T>& vector) const;

    ////////////////////////////////////////////////////////////
    // Get the multiplication of the two vectors
    ////////////////////////////////////////////////////////////    
    Vector2<T>& operator*(const Vector2<T>& vector);
    
    ////////////////////////////////////////////////////////////
    // Add the two vectors
    ////////////////////////////////////////////////////////////
    Vector2<T>& operator+=(const Vector2<T>& vector);

    ////////////////////////////////////////////////////////////
    // Substract the twho vector
    ////////////////////////////////////////////////////////////
    Vector2<T>& operator-=(const Vector2<T>& vector);
    
    ////////////////////////////////////////////////////////////
    // Return true if the two vectors are equal
    ////////////////////////////////////////////////////////////
    bool operator==(const Vector2<T>& vector) const;
                
    ////////////////////////////////////////////////////////////
    // Return true if the two vectors are inequal
    ////////////////////////////////////////////////////////////
    bool operator!=(const Vector2<T>& vector) const;

    ////////////////////////////////////////////////////////////
    // Get the result of the current vector with coords + value
    ////////////////////////////////////////////////////////////
    Vector2<T> operator+(T value) const;
    
    ////////////////////////////////////////////////////////////
    // Get the result of the current vector with coords - value
    ////////////////////////////////////////////////////////////
    Vector2<T> operator-(T value) const;
    
    ////////////////////////////////////////////////////////////
    // Get the result of the current vector with coords * value
    ////////////////////////////////////////////////////////////
    Vector2<T> operator*(T value) const;
    
    ////////////////////////////////////////////////////////////
    // Get the result of the current vector with coords / value
    ////////////////////////////////////////////////////////////
    Vector2<T> operator/(T value) const;
    
    ////////////////////////////////////////////////////////////
    // Add a value to the vector's coords
    ////////////////////////////////////////////////////////////
    Vector2<T>& operator+=(T value);
    
    ////////////////////////////////////////////////////////////
    // Substract a value to the vector's coords
    ////////////////////////////////////////////////////////////
    Vector2<T>& operator-=(T value);
    
    ////////////////////////////////////////////////////////////
    // Multiply the vector's coords by the value
    ////////////////////////////////////////////////////////////
    Vector2<T>& operator*=(T value);
    
    ////////////////////////////////////////////////////////////
    // Divide the vector's coords by the value
    ////////////////////////////////////////////////////////////
    Vector2<T>& operator/=(T value);
    
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
	T x, y;
};

typedef Vector2<int>    Vector2i;
typedef Vector2<double> Vector2d;
typedef Vector2<double> Coords;
typedef Vector2d        Point;
typedef Vector2d        Size;
typedef Vector2d        Scale;

}

#include <Zoost/Vector2.inl>

#endif // ZOOST_VECTOR2_HPP
