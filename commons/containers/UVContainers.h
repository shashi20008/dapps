#ifndef __dapps_UV_CONTAINERS__
#define __dapps_UV_CONTAINERS__
#include <map>
#include <string>

namespace dapps
{
	typedef std::map<std::string, void*> ContextMap;
	typedef std::pair<std::string, void*> ContextPair;
	class DappsContext
	{
		void* m_this; //Dapps (Logical) Parent object reference
		ContextMap* m_objects;
		
		public:
			DappsContext(void*);
			void* getThis(); //Returns logical this pointer.
			ContextMap* getContextMap();
			void* get(std::string);
			bool has(std::string);
			void put(std::string, void*);
	};
}

#endif //__dapps_UV_CONTAINERS__
