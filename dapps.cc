#include "dapps.h"
#include "commons/json/JSON.h"
#include <uv.h>

using namespace dapps;

int main(int argc, char** argv)
{
	Dapps* app = new Dapps();
	app->args = new ArgsProcessor(argc, argv);
	app->loggingUtil = new LoggingUtil();
	if(app->args->has("config"))
	{
		ArgsValList* configFiles = app->args->get("config");
		if(configFiles != NULL && configFiles->size() > 0)
		{
			app->config = new ConfigProcessor(configFiles->at(0));
		}
	}

	if(app->args->has("registry")){
		app->registry = new RegistryServer(app);
	}
	
	if(app->args->has("appServer"))
	{
		app->appServer = new DappsServer(app);
	}
	
	if(app->args->has("testJSON"))
	{
		std::cout << "testing json" << std::endl;
		JSON_t* _json = JSON::parse("{\"abcd\":\"efgh\", \"num\": 123456789, \"negnum\": -123, \"zero\":0,  \"key\": {\"inner\": \"innerval\", \"emptyObject\":{}}, \"float\":-123.07, \"bool\":true}");
		std::cout << "json parsed size::" << _json->m_val.m_object->size() << std::endl;
		std::cout << "JSON:: " << JSON::stringify(_json).c_str() <<std::endl;
	}
	uv_run(uv_default_loop(), UV_RUN_DEFAULT);
	return 0;
}
