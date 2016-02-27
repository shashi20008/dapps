#include "Buffer.h"

dapps::Buffer::Buffer(std::size_t capacity)
{
	m_size = capacity + 1;
	m_value = new char[m_size];
	m_loc = 0;
}

dapps::Buffer::~Buffer()
{
	delete[] m_value;
}

dapps::Buffer* dapps::Buffer::append(std::string str)
{
	return append(str.c_str(), str.length());
}

dapps::Buffer* dapps::Buffer::append(char* str)
{
	std::size_t length = 0;
	while(*str)
	{
		length++;
	}
	return append(str, length);
}

Buffer* append(char* str, std::size_t length, std::size_t loc)
{
	ensureCapacity(m_loc + length);
	std::size_t endLoc = loc + length;
	while(loc < endLoc)
	{
		m_value[m_loc] = str[loc];
		m_loc++;
		loc++;
	}
	m_value[m_loc] = '\0';
}

dapps::Buffer* dapps::Buffer::append(char ch)
{
}

std::string dapps::Buffer::str()
{
	std::string str = m_value;
	return str;
}

const char* dapps::Buffer::c_str()
{
	return m_value;
}

char* dapps::Buffer::c_strCopy()
{
	char* retCStr = new char[m_length + 1];
	return copyTo(retCStr);
}

// Privates

dapps::Buffer* dapps::Buffer::ensureCapacity(std::size_t capacity)
{
	if(m_size > capacity)
	{
		return this;
	}
	std::size_t newSize = (m_size * 2) - 1;
	resize(newSize);
	return this;
}

dapps::Buffer* dapps::Buffer::resize(std::size_t newSize)
{
	char* newVal = new char[newSize];
	m_value = copyTo(newVal);
	return this;
}

char* dapps::Buffer::copyTo(char* newVal)
{
	std::size_t itr;
	for(itr = 0; itr < m_loc; itr++)
	{
		newVal[itr] = m_value[itr];
	}
	newVal[itr] = '\0';
}
