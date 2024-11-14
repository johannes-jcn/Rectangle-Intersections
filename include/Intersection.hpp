#include "Rectangle.hpp"
#include <vector>

#pragma once

namespace NitroTest
{

class Intersection : public Rectangle
{
    public:
        //! \brief Constructor.
        //! \return None.
        Intersection();

        //! \brief Constructor.
        //! \return None.
        Intersection(int x, int y, unsigned int w, unsigned int h);

        //! \brief Operator< overload.
        //! \param[in] obj - The intersection to compare to.
        //! \return Whether the amount of rectangles in this intersection is smaller than in obj.
        bool operator<(const Intersection& obj) const;

        //! \brief Returns a list with all IDs of rectangles that made up this intersection.
        //! \return A lsit of IDs.
        std::vector<unsigned int> getRects() const;
        
        //! \brief sets the internal list of IDs to rects.
        //! \return None.
        void setRects(std::vector<unsigned int> rects);

    private:
        std::vector<unsigned int> mRects; //! List with the IDs of all rectangles comprising this intersection.
};
} // namespace NitroTest.