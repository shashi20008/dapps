#include "DappsContext.h"
#include "../exceptions/DappsException.h"

dapps::DappsContext::DappsContext(void* dappsObject)
{
	if(dappsObject == NULL)
	{
		throw new DappsException("Invalid Dapps Object to initialize Context.");
	}
	m_this = dappsObject;
	m_objects = new std::map<std::string, void*>();
}

void* dapps::DappsContext::getThis() // Returns logical this pointer.
{
	return m_this;
}

dapps::ContextMap* dapps::DappsContext::getContextMap()
{
	return m_objects;
}

void* dapps::DappsContext::get(std::string key)
{
	ContextMap::iterator it = m_objects->find(key);
	if(it != m_objects->end())
	{
		return it->second;
	}
	return NULL;
}

bool dapps::DappsContext::has(std::string key)
{
	return m_objects->count(key);
}

void dapps::DappsContext::put(std::string key, void* object)
{
	m_objects->insert(ContextPair(key, object));
}
