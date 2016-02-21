#include "dapps.h"

using namespace dapps;

int main(int argc, char** argv)
{
	Dapps* app = new Dapps();
	app->args = new ArgsProcessor(argc, argv);

	if(app->args->has("registry")){
		app->registry = new RegistryServer();
	}
	
	return 0;
}
