#ifndef __dapps_BUFFER__
#define __dapps_BUFFER__

#define DAPPS_BUFFER_INITIAL_SIZE 1024 

#include <string>
#include <cstddef>
#include "../exceptions/OutOfBoundsException.h"

namespace dapps
{
	class Buffer
	{
		private:
			char* m_value;
			std::size_t m_size;
			std::size_t m_loc; // Location of last byte in buffer
			
			Buffer* ensureCapacity(std::size_t capacity);
			Buffer* resize(std::size_t newSize);
			char* copyTo(char*);
		
		public:
			Buffer(std::size_t = DAPPS_BUFFER_INITIAL_SIZE);
			~Buffer();
			Buffer* append(std::string);
			Buffer* append(char*);
			Buffer* append(const char*, std::size_t, std::size_t start = 0);
			Buffer* append(char);
			std::string str();
			const char* c_str();
			char* c_strCopy();
			
			// operators
			Buffer(const Buffer&);
			Buffer& operator=(const Buffer&);
			char& operator[](std::size_t);
	};
}

#endif //__dapps_BUFFER__
