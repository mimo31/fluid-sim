#include <cstdlib>

#include "application.hpp"

// #define TESTING

#ifdef TESTING
#include "tests.hpp"
#endif // TESTING

namespace brandy0
{

void run(const int argc, const char *const *const argv)
{
	#ifdef TESTING
	
	Tests tests;
	tests.run();
	
	#else
	
	Application app;
	app.run(argc, argv);
	
	#endif // TESTING

	return;
}

}

int main(const int argc, const char *const *const argv)
{
	brandy0::run(argc, argv);
	return EXIT_SUCCESS;
}
