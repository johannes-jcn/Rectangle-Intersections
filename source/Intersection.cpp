#include "../include/Intersection.hpp"

namespace NitroTest
{
    Intersection::Intersection()
    : Rectangle()
    {
        // Empty;
    }

    Intersection::Intersection(int x, int y, unsigned int w, unsigned int h)
    : Rectangle(x, y, w, h)
    {
        // Empty.
    }

    bool Intersection::operator<(const Intersection& obj) const
    {
        return mRects.size() < obj.getRects().size();
    }

    void Intersection::setRects(std::vector<unsigned int> rects)
    {
        mRects = rects;
    }
    
    std::vector<unsigned int> Intersection::getRects() const
    {
        return mRects;
    }
}