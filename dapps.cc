#include "dapps.h"
#include "commons/json/JSON.h"
#include <uv.h>

using namespace dapps;

dapps::Dapps* dapps::Dapps::m_self = NULL;
dapps::Dapps* dapps::Dapps::get()
{
	if(m_self == NULL)
	{
		m_self = new Dapps();
	}
	return m_self;
}

dapps::Dapps::Dapps() {

}

int main(int argc, char** argv)
{
	Dapps* app = Dapps::get();
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
	
	if(app->config == NULL)
	{
		std::cout << "Usage: ./dapps --config \"path/to/config\" [--registry] [--appServer]" << std::endl << std::endl;
		std::cout << "No configuration found. Exiting.." << std::endl;
		return 0;
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
