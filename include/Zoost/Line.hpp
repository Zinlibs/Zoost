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

#ifndef ZOOST_LINE_HPP
#define ZOOST_LINE_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Zoost/Vector2.hpp>
#include <Zoost/Math.hpp>
#include <Zoost/Config.hpp>

namespace zin
{

struct ZOOST_API Line
{
    ////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////
    Line(const Point& point1, const Point& point2);
    
    ////////////////////////////////////////////////////////////
    // Check if the line intersects another one
    ////////////////////////////////////////////////////////////
    bool intersects(const Line& line);

    ////////////////////////////////////////////////////////////
    // Check if the line intersects another one
    ////////////////////////////////////////////////////////////
    bool intersects(const Line& line, Point& result);

    ////////////////////////////////////////////////////////////
    // Check if the line intersects another one
    ////////////////////////////////////////////////////////////
    static bool intersects(const Point& point1, const Point& point2, const Point& point3, const Point& point4);

    ////////////////////////////////////////////////////////////
    // Check if the line intersects another one
    ////////////////////////////////////////////////////////////
    static bool intersects(const Point& point1, const Point& point2, const Point& point3, const Point& point4, Point& result);
        
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////       
    Point p1, p2;
};

}

#endif // ZOOST_LINE_HPP
