#include <iostream>

#include <osg/Version>

int main( int argc, char** argv) {
	std::cout << "OSG version: " << osgGetVersion() << std::endl;

    return 0;
}
