#include "../include/Rectangle.hpp"
#include <iostream>

namespace NitroTest
{

    Rectangle::Rectangle(int x, int y, unsigned int w, unsigned int h)
    {
        mX = x;
        mY = y;
        mW = w;
        mH = h;
        mID = 0;
    }
    Rectangle::Rectangle(int x, int y, unsigned int w, unsigned int h, unsigned int id)
    {
        mX = x;
        mY = y;
        mW = w;
        mH = h;
        mID = id;
    }

    Rectangle::Rectangle()
    {
        mX = 0;
        mY = 0;
        mW = 0;
        mH = 0;
    }

    int Rectangle::X()
    {
        return mX;
    }

    int Rectangle::Y()
    {
        return mY;
    }

    unsigned int Rectangle::W()
    {
        return mW;
    }

    unsigned int Rectangle::H()
    {
        return mH;
    }

    unsigned int Rectangle::ID()
    {
        return mID;
    }

} // namespace NitroTest.