#include "dapps.h"

using namespace dapps;

int main(int argc, char** argv)
{
	Dapps* app = new Dapps();
	app->args = new ArgsProcessor(argc, argv);
	return 0;
}
