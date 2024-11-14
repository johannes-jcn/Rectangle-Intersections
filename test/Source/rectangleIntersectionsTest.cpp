/* rectangleIntersections test file.
*  Tests both the capabilities of correctly parsing a json file and finding the
*  intersections between the rectangles as well as the capability of handling various
*  erroneous inputs.
*  The json file names help understand the meaningfulness of each test scenario.
*  The standard output messages of the tested methods are disabled during testing,
*  in order to facilitate the visualization of the result.
*/

#include "../include/acutest.h"
#include "../../include/RectanglesParser.hpp"
#include "../../include/IntersectionsCalculator.hpp"

#include <exception>
#include <stdexcept>
#include <string>

#include <sstream>
#include <iostream>

void test_rectParserRobustness(void)
{
    // overriding standard output in order to avoid cluttering the terminal
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    NitroTest::RectanglesParser rectParser1("jsonfiles/test_rectParserRobustness/incomplete.json");
    list<shared_ptr<NitroTest::Rectangle>> parsedRectList = rectParser1.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 0);

    NitroTest::RectanglesParser rectParser2("jsonfiles/test_rectParserRobustness/wrongFormat.json");
    parsedRectList = rectParser2.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 0);

    NitroTest::RectanglesParser rectParser3("jsonfiles/test_rectParserRobustness/wrongAttribute.json");
    parsedRectList = rectParser3.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 0);

    NitroTest::RectanglesParser rectParser4("jsonfiles/test_rectParserRobustness/empty.json");
    parsedRectList = rectParser4.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 0);

    NitroTest::RectanglesParser rectParser5("jsonfiles/test_rectParserRobustness/garbage.json");
    parsedRectList = rectParser5.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 0);

    std::cout.rdbuf(p_cout_streambuf); // restore cout buffer.
}

void test_parserAndCalculatorSize(void)
{
    // overriding standard output in order to avoid cluttering the terminal
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    NitroTest::IntersectionsCalculator calculator;
    list<shared_ptr<NitroTest::Rectangle>> parsedRectList;
    std::vector<NitroTest::Intersection> intersections;

    NitroTest::RectanglesParser rectParser1("jsonFiles/test_parserAndCalculatorSize/givenExample.json");
    parsedRectList = rectParser1.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 4);
    
    intersections = calculator.calculateIntersections(parsedRectList);
    TEST_ASSERT(intersections.size() == 7);
    
    NitroTest::RectanglesParser rectParser2("jsonFiles/test_parserAndCalculatorSize/singleRectangle.json");
    parsedRectList = rectParser2.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 1);
    
    intersections = calculator.calculateIntersections(parsedRectList);
    TEST_ASSERT(intersections.size() == 0);
    
    NitroTest::RectanglesParser rectParser3("jsonFiles/test_parserAndCalculatorSize/noRectangles.json");
    parsedRectList = rectParser3.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 0);
    
    intersections = calculator.calculateIntersections(parsedRectList);
    TEST_ASSERT(intersections.size() == 0);
    
    NitroTest::RectanglesParser rectParser4("jsonFiles/test_parserAndCalculatorSize/tenRectangles.json");
    parsedRectList = rectParser4.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 10);
    
    intersections = calculator.calculateIntersections(parsedRectList);
    TEST_ASSERT(intersections.size() == 2);
    
    NitroTest::RectanglesParser rectParser5("jsonFiles/test_parserAndCalculatorSize/fifteenRectangles.json");
    parsedRectList = rectParser5.getListOfRectangles();
    TEST_ASSERT(parsedRectList.size() == 10);
    
    intersections = calculator.calculateIntersections(parsedRectList);
    TEST_ASSERT(intersections.size() == 2);    
    
    std::cout.rdbuf(p_cout_streambuf); // restore cout buffer.
}

void test_parserAndCalculatorIntersections(void)
{
    // overriding standard output in order to avoid cluttering the terminal
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    NitroTest::IntersectionsCalculator calculator;
    list<shared_ptr<NitroTest::Rectangle>> parsedRectList;
    std::vector<NitroTest::Intersection> intersections;

    NitroTest::RectanglesParser rectParser1("jsonFiles/test_parserAndCalculatorIntersections/givenExample.json");
    parsedRectList = rectParser1.getListOfRectangles();
    
    intersections = calculator.calculateIntersections(parsedRectList);
    sort(intersections.begin(), intersections.end());

    TEST_ASSERT(intersections[0].X() == 140);
    TEST_ASSERT(intersections[0].Y() == 160);
    TEST_ASSERT(intersections[0].W() == 210);
    TEST_ASSERT(intersections[0].H() == 20);
    std::vector<unsigned int> rectangles = intersections[0].getRects();
    
    TEST_ASSERT(rectangles[0] == 1);
    TEST_ASSERT(rectangles[1] == 3);
    
    TEST_ASSERT(intersections[2].X() == 140);
    TEST_ASSERT(intersections[2].Y() == 200);
    TEST_ASSERT(intersections[2].W() == 230);
    TEST_ASSERT(intersections[2].H() == 60);
    rectangles = intersections[2].getRects();
    
    TEST_ASSERT(rectangles[0] == 2);
    TEST_ASSERT(rectangles[1] == 3);
    
    TEST_ASSERT(intersections[5].X() == 160);
    TEST_ASSERT(intersections[5].Y() == 160);
    TEST_ASSERT(intersections[5].W() == 190);
    TEST_ASSERT(intersections[5].H() == 20);
    rectangles = intersections[5].getRects();
    
    TEST_ASSERT(rectangles[0] == 1);
    TEST_ASSERT(rectangles[1] == 3);
    TEST_ASSERT(rectangles[2] == 4);
    
    TEST_ASSERT(intersections[6].X() == 160);
    TEST_ASSERT(intersections[6].Y() == 200);
    TEST_ASSERT(intersections[6].W() == 210);
    TEST_ASSERT(intersections[6].H() == 60);
    rectangles = intersections[6].getRects();
    
    TEST_ASSERT(rectangles[0] == 2);
    TEST_ASSERT(rectangles[1] == 3);
    TEST_ASSERT(rectangles[2] == 4);

    NitroTest::RectanglesParser rectParser2("jsonFiles/test_parserAndCalculatorIntersections/tenRectangles.json");
    parsedRectList = rectParser2.getListOfRectangles();
    
    intersections = calculator.calculateIntersections(parsedRectList);
    sort(intersections.begin(), intersections.end());

    
    TEST_ASSERT(intersections[ intersections.size() - 11 ].X() == 10);
    TEST_ASSERT(intersections[ intersections.size() - 11 ].Y() == 10);
    TEST_ASSERT(intersections[ intersections.size() - 11 ].W() == 11);
    TEST_ASSERT(intersections[ intersections.size() - 11 ].H() == 11);
    rectangles = intersections[ intersections.size() - 11 ].getRects();
    
    TEST_ASSERT(rectangles[0] == 1);
    TEST_ASSERT(rectangles[1] == 2);
    TEST_ASSERT(rectangles[2] == 3);
    TEST_ASSERT(rectangles[3] == 4);
    TEST_ASSERT(rectangles[4] == 5);
    TEST_ASSERT(rectangles[5] == 6);
    TEST_ASSERT(rectangles[6] == 8);
    TEST_ASSERT(rectangles[7] == 9);
    TEST_ASSERT(rectangles[8] == 10);
    
    TEST_ASSERT(intersections[ intersections.size() - 1 ].X() == 10);
    TEST_ASSERT(intersections[ intersections.size() - 1 ].Y() == 10);
    TEST_ASSERT(intersections[ intersections.size() - 1 ].W() == 11);
    TEST_ASSERT(intersections[ intersections.size() - 1 ].H() == 11);
    rectangles = intersections[ intersections.size() - 1 ].getRects();
    
    TEST_ASSERT(rectangles[0] == 1);
    TEST_ASSERT(rectangles[1] == 2);
    TEST_ASSERT(rectangles[2] == 3);
    TEST_ASSERT(rectangles[3] == 4);
    TEST_ASSERT(rectangles[4] == 5);
    TEST_ASSERT(rectangles[5] == 6);
    TEST_ASSERT(rectangles[6] == 7);
    TEST_ASSERT(rectangles[7] == 8);
    TEST_ASSERT(rectangles[8] == 9);
    TEST_ASSERT(rectangles[9] == 10);
    
    std::cout.rdbuf(p_cout_streambuf); // restore cout buffer.
}

TEST_LIST = 
{
    { "test_rectParserRobustness", test_rectParserRobustness },
    { "test_parserAndCalculatorSize", test_parserAndCalculatorSize },
    { "test_parserAndCalculatorIntersections", test_parserAndCalculatorIntersections },
    { NULL, NULL } // Zeroed record marking the end of the list. Required by test platform.
};
