#include "Rectangle.hpp"
#include "../include/json.hpp"
#include <memory>
#include <list>

using json = nlohmann::json;
using namespace std;

namespace NitroTest 
{    
class RectanglesParser
{
    public:
        //! \brief Constructor.
        //! \param[in] fileName - The path to a json file with the rectangles definition.
        //! \return None.
        RectanglesParser(const string fileName);
        
        //! \brief Returns a list of rectangles. Empty if parsing failed.
        //! \return a list of rectangles.
        list<shared_ptr<Rectangle>> getListOfRectangles();

    private:

        //! \brief Writes fileName parameter into internal file name member.
        //! \param[in] fileName - Path to a file.
        //! \return None.
        void setFileName(const string fileName);
        
        //! \brief Reads json file from internal file name and sets internal readiness member.
        //! \return Whether the parsing was successful.
        bool parseJson();

        //! \brief Builds a list of maximum ten rectangles from parsed json object.
        //! \param[in] parsed - json object previously parsed.
        //! \return Readiness of built list.
        bool buildList(json parsed);

        string mCurrentFileName; //! File name to read the json from.
        list<shared_ptr<Rectangle>> mRectangleList; //! A list of parsed rectangles.
};
} // namespace NitroTest.
