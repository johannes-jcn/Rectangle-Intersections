
#include <exception>
#include "../include/json.hpp"
#include "../include/Rectangle.hpp"
#include "../include/Intersection.hpp"
#include "../include/RectanglesParser.hpp"
#include "../include/IntersectionsCalculator.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    NitroTest::RectanglesParser rectParser(argv[1]);
    list<shared_ptr<NitroTest::Rectangle>> parsedRectList = rectParser.getListOfRectangles();
    if(parsedRectList.size() == 0) return 1;

    NitroTest::IntersectionsCalculator calculator;
    std::vector<NitroTest::Intersection> intersections = calculator.calculateIntersections(parsedRectList);

    cout << "Input:" << endl;
    for (auto const& i : parsedRectList)
    {
        std::cout << "      " << i->ID() << ": ";
        std::cout << "Rectangle at (" << i->X() << "," << i->Y() << "), ";
        std::cout << "w=" << i->W() << ", " << "h=" << i->H() << "." << endl;
    }

    cout << endl;

    std::vector<unsigned int> rectIntersect;

    sort(intersections.begin(), intersections.end());
    cout << "Intersections" << endl;
    for(auto i : intersections)
    {
        rectIntersect = i.getRects();

        cout << "      "  << "Between rectangle " << rectIntersect[0];
        for(int j = 1; j < rectIntersect.size() - 1; j++)
        {
            cout << ", " << rectIntersect[j];
        }
        cout << " and " <<  rectIntersect[rectIntersect.size() - 1];
        cout << " at (" << i.X() << "," << i.Y() << "),";
        cout << " w=" << i.W() << ", ";
        cout << "h=" << i.H() << "." << endl;

    }
    return 0;
}