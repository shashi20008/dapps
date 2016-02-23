#include "dapps.h"
#include "commons/JSON.h"

using namespace dapps;

int main(int argc, char** argv)
{
	Dapps* app = new Dapps();
	app->args = new ArgsProcessor(argc, argv);

	if(app->args->has("registry")){
		app->registry = new RegistryServer(app);
	}
	
	if(app->args->has("testJSON"))
	{
		std::cout << "testing json" << std::endl;
		JSON_t* _json = JSON::parse("{\"abcd\":\"efgh\", \"num\": 123456789, \"negnum\": -123, \"zero\":0,  \"key\": {\"inner\": \"innerval\", \"emptyObject\":{}}, \"float\":-123.0}");
		std::cout << "json parsed size::" << std::endl;
		//std::cout << _json->m_val.m_object->size() << std::endl;
		std::cout << "JSON:: " << JSON::stringify(_json).c_str() <<std::endl;
	}
	return 0;
}
