#include "Rectangle.hpp"
#include "Intersection.hpp"
#include <memory>
#include <vector>
#include <list>

using namespace std;

namespace NitroTest
{    
class IntersectionsCalculator
{
    public:    
        //! \brief Constructor.
        //! \return None.
        IntersectionsCalculator();

        //! \brief Calculates all intersections between rectangles in given list.
        //! \param[in] rects - A list of rectangles.
        //! \return A list of all intersections.
        std::vector<Intersection> calculateIntersections(list<shared_ptr<Rectangle>> rects);

    private:

        //! \brief Calculates all intersections between rectangles in given list and r1.
        //! \param[in] r1 - A rectangle.
        //! \param[in] rects - A list of rectangles.
        //! \param[in] indexRects - If r1 is an intersection, the rectangles that comprised it.
        //! \return None.
        void calculateIntersectionRec(Rectangle r1, list<shared_ptr<Rectangle>> rects, vector<unsigned int> indexRects);

        //! \brief Checks if two given rectangles have an intersection.
        //! \param[in] r1, r2 - Rectangles.
        //! \return Whether the two rectangles intersect.
        bool haveIntersection(Rectangle r1, Rectangle r2) const;

        //! \brief Calculates the intersection between two rectangles.
        //! \pre The two rectangles intersect.
        //! \param[in] r1, r2 - Rectangles.
        //! \return Status of the operation.
        Intersection intersectionCalc(Rectangle r1, Rectangle r2) const;

        std::vector<Intersection> mIntersections; // The latest list of intersections calculated.

};
} // namespace NitroTest.
