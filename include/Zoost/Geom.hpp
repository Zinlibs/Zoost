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

#ifndef ZOOST_GEOM_HPP
#define ZOOST_GEOM_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <array>
#include <initializer_list>
#include <set>
#include <Zoost/Math.hpp>
#include <Zoost/Vector2.hpp>
#include <Zoost/Transformable.hpp>
#include <Zoost/Rect.hpp>
#include <Zoost/Segment.hpp>
#include <Zoost/Triangle.hpp>
#include <Zoost/Vertex.hpp>
#include <Zoost/Liaison.hpp>
#include <Zoost/Face.hpp>
#include <Zoost/Config.hpp>

namespace zin
{

class ZOOST_API Geom : public Transformable
{
public:

    ////////////////////////////////////////////////////////////
    // Intersection struct
    ////////////////////////////////////////////////////////////
    struct Intersection { Point result; const Liaison* l1; const Liaison* l2; };

    ////////////////////////////////////////////////////////////
    // Geom observer class
    ////////////////////////////////////////////////////////////
    class Observer
    {
        virtual void onTransformUpdated() {}
        virtual void onVertexAdded() {}
        virtual void onLiaisonAdded() {}
        virtual void onFaceAdded() {}
        virtual void onVertexRemoved(size_t id) {}
        virtual void onLiaisonRemoved(size_t id) {}
        virtual void onFaceRemoved(size_t id) {}
        virtual void onVertexMoved() {}
        virtual void onErasing() {}
        friend class Geom;
    };
    
public:
    
    ////////////////////////////////////////////////////////////
    // Constructor
    ////////////////////////////////////////////////////////////
    Geom();

    ////////////////////////////////////////////////////////////
    // Copy constructor
    ////////////////////////////////////////////////////////////
    Geom(const Geom& geom);

    ////////////////////////////////////////////////////////////
    // Destructor
    ////////////////////////////////////////////////////////////
    ~Geom();

    ////////////////////////////////////////////////////////////
    // Add an observer
    ////////////////////////////////////////////////////////////
    void addObserver(Observer& observer);

    ////////////////////////////////////////////////////////////
    // Remove an observer
    ////////////////////////////////////////////////////////////
    void removeObserver(Observer& observer);

    ////////////////////////////////////////////////////////////
    // Clear all the points, liaisons & faces
    ////////////////////////////////////////////////////////////
    virtual void clear();

    ////////////////////////////////////////////////////////////
    // Return the result of the given geom plus the current one
    ////////////////////////////////////////////////////////////
    virtual Geom& add(const Geom& geom);

    ////////////////////////////////////////////////////////////
    // Add geometry from another geom
    ////////////////////////////////////////////////////////////
    Geom operator+(const Geom& geom);
    
    ////////////////////////////////////////////////////////////
    // Add geometry from another geom
    ////////////////////////////////////////////////////////////
    Geom& operator+=(const Geom& geom);
    
    ////////////////////////////////////////////////////////////
    // Replace the current geometry by the given one
    ////////////////////////////////////////////////////////////
    virtual Geom& operator=(const Geom& geom);

    ////////////////////////////////////////////////////////////
    // Add a point to the geom and return its identifier
    ////////////////////////////////////////////////////////////
    virtual Vertex& addVertex(const Coords& coords);
    
    ////////////////////////////////////////////////////////////
    // Add a liaison to the geom and return its identifier
    ////////////////////////////////////////////////////////////
    virtual Liaison& addLiaison(const Vertex& vertex1, const Vertex& vertex2);

    ////////////////////////////////////////////////////////////
    // Add a face to the geom and return its identifier
    ////////////////////////////////////////////////////////////
    virtual Face& addFace(const Vertex& vertex1, const Vertex& vertex2, const Vertex& vertex3);

    ////////////////////////////////////////////////////////////
    // Remove a vertex from the geom
    ////////////////////////////////////////////////////////////
    virtual void removeVertex(const Vertex& vertex);
    
    ////////////////////////////////////////////////////////////
    // Remove a liaison from the geom
    ////////////////////////////////////////////////////////////
    virtual void removeLiaison(const Liaison& liaison);

    ////////////////////////////////////////////////////////////
    // Remove a face from the geom
    ////////////////////////////////////////////////////////////
    virtual void removeFace(const Face& face);

    ////////////////////////////////////////////////////////////
    // Get the vertex matching to the indice
    ////////////////////////////////////////////////////////////
    Vertex& getVertex(size_t indice) const;

    ////////////////////////////////////////////////////////////
    // Get the liaison matching to the indice
    ////////////////////////////////////////////////////////////
    Liaison& getLiaison(size_t indice) const;

    ////////////////////////////////////////////////////////////
    // Get the face matching to the indice
    ////////////////////////////////////////////////////////////
    Face& getFace(size_t indice) const;

    ////////////////////////////////////////////////////////////
    // Get the vertices count
    ////////////////////////////////////////////////////////////
    size_t getVerticesCount() const;

    ////////////////////////////////////////////////////////////
    // Get the liaisons count
    ////////////////////////////////////////////////////////////
    size_t getLiaisonsCount() const;

    ////////////////////////////////////////////////////////////
    // Get the faces count
    ////////////////////////////////////////////////////////////
    size_t getFacesCount() const;

    ////////////////////////////////////////////////////////////
    // Compute the local bounds of the geom
    ////////////////////////////////////////////////////////////
    void computeLocalBounds() const;

    ////////////////////////////////////////////////////////////
    // Compute the global bounds of the geom
    ////////////////////////////////////////////////////////////
    void computeGlobalBounds() const;

    ////////////////////////////////////////////////////////////
    // Get the bounds of the geom
    ////////////////////////////////////////////////////////////
    Rect getLocalBounds() const;

    ////////////////////////////////////////////////////////////
    // Get the bounds of the geom
    ////////////////////////////////////////////////////////////
    Rect getGlobalBounds() const;
    
    ////////////////////////////////////////////////////////////
    // Check if the given geom is intersecting the current one
    ////////////////////////////////////////////////////////////
    bool intersects(const Geom& geom) const;
    
    ////////////////////////////////////////////////////////////
    // Check if the geom is intersecting the given one
    ////////////////////////////////////////////////////////////
    bool intersects(const Geom& geom, std::vector<Intersection>& intersections);
    
    ////////////////////////////////////////////////////////////
    // Check if the given point is contained by the geom
    ////////////////////////////////////////////////////////////
    virtual bool contains(Point point);
    
    ////////////////////////////////////////////////////////////
    // Check if the given point is contained by the geom
    ////////////////////////////////////////////////////////////
    bool contains(Point point, std::vector<Face*>& faces);

    ////////////////////////////////////////////////////////////
    // Get a segment geom
    ////////////////////////////////////////////////////////////
    static Geom segment(const Point& point1, const Point& point2);

    ////////////////////////////////////////////////////////////
    // Get a triangle geom
    ////////////////////////////////////////////////////////////
    static Geom triangle(const Point& point1, const Point& point2, const Point& point3);
    
    ////////////////////////////////////////////////////////////
    // Get a quad geom
    ////////////////////////////////////////////////////////////
    static Geom quad(const Point& point1, const Point& point2, const Point& point3, const Point& point4);

    ////////////////////////////////////////////////////////////
    // Get a rectangle geom
    ////////////////////////////////////////////////////////////
    static Geom rectangle(const Point& size);

    ////////////////////////////////////////////////////////////
    // Get a rectangle geom
    ////////////////////////////////////////////////////////////
    static Geom rectangle(const Rect& rect);

    ////////////////////////////////////////////////////////////
    // Get a scare geom
    ////////////////////////////////////////////////////////////
    static Geom scare(double length);
    
    ////////////////////////////////////////////////////////////
    // Get a circle geom
    ////////////////////////////////////////////////////////////
    static Geom circle(double radius = 20);
    
    ////////////////////////////////////////////////////////////
    // Get a star geom
    ////////////////////////////////////////////////////////////
    static Geom star(double width1 = 30, double width2 = 60, unsigned int complexity = 5);
    
    ////////////////////////////////////////////////////////////
    // Get a polygon geom
    ////////////////////////////////////////////////////////////
    static Geom polygon(double radius = 20, unsigned int complexity = 5);

    ////////////////////////////////////////////////////////////
    // Get a polygon geom
    ////////////////////////////////////////////////////////////
    static Geom polygon(const std::initializer_list<Point>& points);
    
protected:

    friend class Vertex;

    ////////////////////////////////////////////////////////////
    // Method called when the tranform is updated
    ////////////////////////////////////////////////////////////
    void onTransformUpdated() const;

    ////////////////////////////////////////////////////////////
    // Method called when a vertex is moved
    ////////////////////////////////////////////////////////////
    void onVertexMoved() const;

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    mutable bool                  m_localBoundsUpdated;
    mutable bool                  m_globalBoundsUpdated;
    mutable Rect                  m_localBounds;
    mutable Rect                  m_globalBounds;                            
    mutable std::vector<Vertex*>  m_vertices;
    mutable std::vector<Face*>    m_faces;
    mutable std::vector<Liaison*> m_liaisons;
    std::set<Observer*>           m_observers;
};

}

#endif // ZOOST_GEOM_HPP