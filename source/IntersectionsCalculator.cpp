#include "../include/IntersectionsCalculator.hpp"
#include "../include/Intersection.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

namespace NitroTest
{
    IntersectionsCalculator::IntersectionsCalculator()
    {
        //empty.
    }

    std::vector<Intersection> IntersectionsCalculator::calculateIntersections(list<shared_ptr<Rectangle>> rects)
    {
        mIntersections.clear();
        vector<unsigned int> indexes;
        auto it = rects.begin();
        
        Rectangle rect;
        while(rects.size() > 0)
        {
            rect = *(*it);
            indexes.push_back(rect.ID());
            it = rects.erase(it);
            calculateIntersectionRec(rect, rects, indexes);
            indexes.clear();
        }

        return mIntersections;
    }
    
    void IntersectionsCalculator::calculateIntersectionRec(Rectangle r1, list<shared_ptr<Rectangle>> rects, vector<unsigned int> indexRects) 
    {
        auto it = rects.begin();
        Intersection intersection;
        while(rects.size() > 0)
        {
            if(haveIntersection(r1, *(*it)))
            {
                intersection = intersectionCalc(r1,*(*it));
                indexRects.push_back((*it)->ID());
                intersection.setRects(indexRects);
                mIntersections.push_back(intersection);
                it = rects.erase(it);
                calculateIntersectionRec(intersection, rects, indexRects);
                indexRects.pop_back();
            } else
            {                
                it++;
                rects.pop_front();
            }
        }
    }

    bool IntersectionsCalculator::haveIntersection(Rectangle r1, Rectangle r2) const
    {
        if(r1.X() > r2.X()) // C1: if r2 start is to the left of r1 start.
        {
            if(r1.X() > r2.X() + r2.W()) return false; // C2: if r2 ends to the left of r1 start, no intersection.
        } else if(r2.X() > r1.X() + r1.W()) return false; // C3: if not C1 and r1 ends to the left of r2 start, no intersection.

        if(r1.Y() > r2.Y()) // C4: if r2 start is above r1 start.
        {
            if(r1.Y() > r2.Y() + r2.H()) return false; // C5: if r2 ends above r1 start, no intersection.
        } else if(r2.Y() > r1.Y() + r1.H()) return false; // C6: if not C4 and r1 ends above r2 start, no intersection.
        
        return true; // C7: if none of the above conditions are true, the rectangles intersect.
    }

    Intersection IntersectionsCalculator::intersectionCalc(Rectangle r1, Rectangle r2) const
    {
        int x, y;
        unsigned int w, h;

        x = max(r1.X(), r2.X());
        y = max(r1.Y(), r2.Y());
        w = ( min( r1.X() + r1.W(), r2.X() + r2.W()) - x);
        h = ( min( r1.Y() + r1.H(), r2.Y() + r2.H()) - y);

        return Intersection(x,y,w,h);
    }

} // namespace NitroTest.
