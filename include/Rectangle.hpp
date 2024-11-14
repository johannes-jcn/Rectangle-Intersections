#pragma once

namespace NitroTest
{
class Rectangle
{
    public:
        //! \brief Constructor.
        //! \param[in] x - Top left corner x coordinate of the rectangle.
        //! \param[in] y - Top left corner y coordinate of the rectangle.
        //! \param[in] w - Width of the rectangle.
        //! \param[in] h - Height of the rectangle.
        //! \return None.
        Rectangle(int x, int y, unsigned int w, unsigned int h);

        //! \brief Constructor.
        //! \param[in] x - Top left corner x coordinate of the rectangle.
        //! \param[in] y - Top left corner y coordinate of the rectangle.
        //! \param[in] w - Width of the rectangle.
        //! \param[in] h - Height of the rectangle.
        //! \param[in] id - A unique id for the rectangle.
        //! \return None.
        Rectangle(int x, int y, unsigned int w, unsigned int h, unsigned int id);

        //! \brief Constructor.
        //! \return None.
        Rectangle();

        //! \brief Returns the top left corner x coordinate of the rectangle.
        //! \return Top left corner x coordinate of the rectangle.
        int X();

        //! \brief Returns the top left corner y coordinate of the rectangle.
        //! \return Top left corner y coordinate of the rectangle.
        int Y();

        //! \brief Returns the width of the rectangle.
        //! \return Width of the rectangle.
        unsigned int W();

        //! \brief Returns the height of the rectangle.
        //! \return Height of the rectangle.
        unsigned int H();

        //! \brief Returns the rectangles unique id. Zero if uninitialized.
        //! \return The rectangles unique id.
        unsigned int ID();

    private:
        unsigned int mID; //! Unique ID.
        int mX; //! Top left corner x coordinate.
        int mY; //! Top left corner y coordinate.
        unsigned int mW; //! Width.
        unsigned int mH; //! Height.

};
} // namespace NitroTest.