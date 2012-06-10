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

#ifndef ZOOST_TRANSFORMABLE_HPP
#define ZOOST_TRANSFORMABLE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <set>
#include <Zoost/Vector2.hpp>
#include <Zoost/Transform.hpp>
#include <Zoost/Rect.hpp>
#include <Zoost/Segment.hpp>
#include <Zoost/Config.hpp>

namespace zin
{

class ZOOST_API Transformable
{
public:

    ////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////
    Transformable(const Vector2d& position = Vector2d(0, 0), double rotation = 0, const Vector2d& scale = Vector2d(1, 1));

    ////////////////////////////////////////////////////////////
    // Assignement operator
    ////////////////////////////////////////////////////////////
    Transformable& operator=(const Transformable& transformable);

    ////////////////////////////////////////////////////////////
    // Reset the transform
    ////////////////////////////////////////////////////////////
    void init();

    ////////////////////////////////////////////////////////////
    // Set position x
    ////////////////////////////////////////////////////////////
    void setPositionX(double posX);
    
    ////////////////////////////////////////////////////////////
    // Set position y
    ////////////////////////////////////////////////////////////
    void setPositionY(double posY);
    
    ////////////////////////////////////////////////////////////
    // Set position
    ////////////////////////////////////////////////////////////
    void setPosition(double posX, double posY);
    
    ////////////////////////////////////////////////////////////
    // Set position
    ////////////////////////////////////////////////////////////
    void setPosition(const Vector2d& pos);
    
    ////////////////////////////////////////////////////////////
    // Move horizontally
    ////////////////////////////////////////////////////////////
    void moveX(double shiftX);
    
    ////////////////////////////////////////////////////////////
    // Move vertically
    ////////////////////////////////////////////////////////////
    void moveY(double shiftY);
    
    ////////////////////////////////////////////////////////////
    // Move the transformable
    ////////////////////////////////////////////////////////////
    void move(double shiftX, double shiftY);
    
    ////////////////////////////////////////////////////////////
    // Move the transformable
    ////////////////////////////////////////////////////////////
    void move(const Vector2d& shift);
    
    ////////////////////////////////////////////////////////////
    // Get the X coordinate
    ////////////////////////////////////////////////////////////
    double getPositionX();

    ////////////////////////////////////////////////////////////
    // Get the Y coordinate
    ////////////////////////////////////////////////////////////
    double getPositionY();

    ////////////////////////////////////////////////////////////
    // Get the position of the transformable
    ////////////////////////////////////////////////////////////
    Point getPosition();
    
    ////////////////////////////////////////////////////////////
    // Set the rotation of the transformable
    ////////////////////////////////////////////////////////////
    void setRotation(double angle);
    
    ////////////////////////////////////////////////////////////
    // Rotate the transformable
    ////////////////////////////////////////////////////////////
    void rotate(double angle);
    
    ////////////////////////////////////////////////////////////
    // Get the rotation
    ////////////////////////////////////////////////////////////
    double getRotation();
    
    ////////////////////////////////////////////////////////////
    // Set the horizontal scale of the transformable
    ////////////////////////////////////////////////////////////
    void setScaleX(double coeffX);
    
    ////////////////////////////////////////////////////////////
    // Set the vertical scale of the transformable
    ////////////////////////////////////////////////////////////
    void setScaleY(double coeffY);
    
    ////////////////////////////////////////////////////////////
    // Set the scale of the transformable
    ////////////////////////////////////////////////////////////
    void setScale(double coeffX, double coeffY);
    
    ////////////////////////////////////////////////////////////
    // Set the scale of the transformable
    ////////////////////////////////////////////////////////////
    void setScale(const Vector2d& coeff);
    
    ////////////////////////////////////////////////////////////
    // Scale the transformable horizontally
    ////////////////////////////////////////////////////////////
    void scaleX(double coeffX);
    
    ////////////////////////////////////////////////////////////
    // Scale the transformable vertically
    ////////////////////////////////////////////////////////////
    void scaleY(double coeffY);
    
    ////////////////////////////////////////////////////////////
    // Scale the transformable
    ////////////////////////////////////////////////////////////
    void scale(double coeffX, double coeffY);
    
    ////////////////////////////////////////////////////////////
    // Scale the transformable
    ////////////////////////////////////////////////////////////
    void scale(const Vector2d& coeff);
    
    ////////////////////////////////////////////////////////////
    // Get the scale
    ////////////////////////////////////////////////////////////
    Vector2d getScale();
    
    ////////////////////////////////////////////////////////////
    // Set the origin
    ////////////////////////////////////////////////////////////
    void setOrigin(double x, double y);

    ////////////////////////////////////////////////////////////
    // Set the origin
    ////////////////////////////////////////////////////////////
    void setOrigin(const Vector2d& origin);
    
    ////////////////////////////////////////////////////////////
    // Get the origin
    ////////////////////////////////////////////////////////////
    const Vector2d& getOrigin() const;

    ////////////////////////////////////////////////////////////
    // get the transformation
    ////////////////////////////////////////////////////////////    
    Transform& getTransform() const;

    ////////////////////////////////////////////////////////////
    // Get the inverse tranformation
    ////////////////////////////////////////////////////////////
    Transform& getInvTransform() const;
    
    ////////////////////////////////////////////////////////////
    // Convert a point to local coordinates
    ////////////////////////////////////////////////////////////
    Point convertToLocal(const Point& point) const;
    
    ////////////////////////////////////////////////////////////
    // Convert a point to local coordinates
    ////////////////////////////////////////////////////////////
    Point convertToLocal(const double pointX, const double pointY) const;

    ////////////////////////////////////////////////////////////
    // Convert a segment to local coordinates
    ////////////////////////////////////////////////////////////
    Segment convertToLocal(const Segment& segment) const;

    ////////////////////////////////////////////////////////////
    // Convert a rect to local coordinates
    ////////////////////////////////////////////////////////////
    Rect convertToLocal(const Rect& rect) const;
    
    ////////////////////////////////////////////////////////////
    // Convert a point to global coordinates
    ////////////////////////////////////////////////////////////
    Point convertToGlobal(const Point& point) const;

    ////////////////////////////////////////////////////////////
    // Convert a point to global coordinates
    ////////////////////////////////////////////////////////////
    Point convertToGlobal(const double pointX, const double pointY) const;

    ////////////////////////////////////////////////////////////
    // Convert a segment to global coordinates
    ////////////////////////////////////////////////////////////
    Segment convertToGlobal(const Segment& segment) const;

    ////////////////////////////////////////////////////////////
    // Convert a rect to local coordinates
    ////////////////////////////////////////////////////////////
    Rect convertToGlobal(const Rect& rect) const;

protected:

    ////////////////////////////////////////////////////////////
    // Method called when a the transform is updated
    ////////////////////////////////////////////////////////////
    virtual void onTransformUpdated() const {}

    ////////////////////////////////////////////////////////////
    // Data members
    ////////////////////////////////////////////////////////////    
    mutable bool      m_transformUpdated,
                      m_invTransformUpdated;
    mutable Transform m_transform,
                      m_invTransform;
    Point             m_origin;
    Point             m_position;
    Vector2d          m_scale;
    double            m_rotation;
};

}

#endif // ZOOST_TRANSFORMABLE_HPP