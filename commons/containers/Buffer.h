#ifndef __dapps_BUFFER__
#define __dapps_BUFFER__

#define DAPPS_BUFFER_INITIAL_SIZE 1024

#incldue <string>
#include <cstddef>

namespace dapps
{
	class Buffer
	{
		private:
			char* m_value;
			std::size_t m_size;
			std::size_t m_loc; // Location of last byte in buffer
			
			void resize(std::size_t newSize);
			char* copyTo(char*);
		
		public:
			Buffer(std::size_t = DAPPS_BUFFER_INITIAL_SIZE);
			~Buffer();
			Buffer* append(std::string);
			Buffer* append(char*);
			Buffer* append(char);
			std::string str();
			const char* c_str();
			char* c_strCopy();
	};
}

#endif //__dapps_BUFFER__
