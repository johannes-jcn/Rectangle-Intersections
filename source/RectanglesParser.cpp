#include "../include/RectanglesParser.hpp"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;
using namespace std;

namespace NitroTest
{

    RectanglesParser::RectanglesParser(const string fileName)
    {
        setFileName(fileName);
    }

    list<shared_ptr<Rectangle>> RectanglesParser::getListOfRectangles()
    {
        list<shared_ptr<Rectangle>> returnList;
    
        if(parseJson())
        {
            returnList = mRectangleList;
        }
        return returnList;
    }

    void RectanglesParser::setFileName(const string fileName)
    {
        mCurrentFileName = fileName;
    }

    bool RectanglesParser::parseJson()
    {
        json j;
        try
        {
            ifstream f(mCurrentFileName);
            j = json::parse(f);
        }
        catch(exception e)
        {
            cout << endl << "There has been a parse error." << endl;
            cout << "Please review file \"" << mCurrentFileName << "\"." << endl;
            return false;
        }

        if(buildList(j) == true)
        {
            return true;
        }
        return false;
    }
    
    bool RectanglesParser::buildList(json parsed)
    {        
        unsigned int id (0);
        string rectangles;
        try
            {
                rectangles = "/" + parsed.begin().key() + '/';
            }
            catch(const exception& e)
            {
                cout << endl << "The json file is not following the expected standard." << endl;
                cout << "Please review file \"" << mCurrentFileName << "\"." << endl;
                return false;
            }


        string fullPath(rectangles + to_string(id));

        bool inRange (true);
        int x (0);
        int y (0);
        unsigned int w (0);
        unsigned int h (0);

        while(inRange)
        {
            try
            {
                x = parsed[json::json_pointer{fullPath + "/x"}];
                y = parsed[json::json_pointer{fullPath + "/y"}];
                w = parsed[json::json_pointer{fullPath + "/w"}];
                h = parsed[json::json_pointer{fullPath + "/h"}];
                id++;
                mRectangleList.push_back(make_shared<Rectangle>(x, y, w, h, id));
                fullPath = rectangles + to_string(id);
            }
            catch(const exception& e) // E1: The current json object did not have all the expected attributes.
            {
                cout << endl << "The json object at position " << id + 1 << " is not following the expected standard." << endl;
                cout << "Please review file \"" << mCurrentFileName << "\"." << endl;
                return false;
            }
            try
            {
                parsed.at(json::json_pointer{fullPath});
                if(id == 10) throw exception();
            }
            catch(const std::exception& e) // E2: The next json object either does not exist or is the eleventh.
            {
                cout << endl << "Successfully parsed json file \"" << mCurrentFileName << "\"." << endl << endl; 
                inRange = false;
            }
        }
        return true;
    }

} // namespace NitroTest.
