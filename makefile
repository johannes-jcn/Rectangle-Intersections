rectangleIntersections : source/exec.cpp build/Rectangle.o build/Intersection.o build/RectanglesParser.o build/IntersectionsCalculator.o
	g++  -o build/exec build/Rectangle.o build/Intersection.o build/RectanglesParser.o build/IntersectionsCalculator.o source/exec.cpp

build: 
		mkdir build -p

test: test/Source/rectangleIntersectionsTest.cpp build/Rectangle.o build/Intersection.o build/RectanglesParser.o build/IntersectionsCalculator.o
	g++  -o build/test build/Rectangle.o build/Intersection.o build/RectanglesParser.o build/IntersectionsCalculator.o test/source/rectangleIntersectionsTest.cpp


build/Rectangle.o: source/Rectangle.cpp include/Rectangle.hpp | build
		g++ -c source/Rectangle.cpp -o build/Rectangle.o
		
build/Intersection.o: source/Intersection.cpp include/Intersection.hpp| build
		g++ -c source/Intersection.cpp -o build/Intersection.o
		
build/RectanglesParser.o: source/RectanglesParser.cpp include/RectanglesParser.hpp| build
		g++ -c source/RectanglesParser.cpp -o build/RectanglesParser.o

build/IntersectionsCalculator.o: source/IntersectionsCalculator.cpp include/IntersectionsCalculator.hpp | build
		g++ -c source/IntersectionsCalculator.cpp -o build/IntersectionsCalculator.o
		
clean: 
		rm -rf build