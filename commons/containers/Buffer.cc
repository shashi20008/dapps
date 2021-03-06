#include "Buffer.h"
#include <iostream>

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

dapps::Buffer* dapps::Buffer::append(const char* str)
{
	std::size_t length = 0;
	while(str[length])
	{
		length++;
	}
	return append(str, length);
}

dapps::Buffer* dapps::Buffer::append(const char* str, std::size_t length, std::size_t loc)
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
	return this;
}

dapps::Buffer* dapps::Buffer::append(char ch)
{
	return append(&ch, 1);
}

bool dapps::Buffer::endsWith(std::string str)
{
	if(m_loc < str.length())
	{
		return false;
	}
	
	std::size_t len = str.length();
	std::size_t whence = m_loc - len;
	for(std::size_t i = 0; i < len; i++)
	{
		if(m_value[whence + i] != str[i])
		{
			return false;
		}
	}
	return true;
}

bool dapps::Buffer::startsWith(std::string str)
{
	if(m_loc < str.length())
	{
		return false;
	}
	
	std::size_t len = str.length();
	for(std::size_t i = 0; i < len; i++)
	{
		if(m_value[i] != str[i])
		{
			return false;
		}
	}
	return true;
}

bool dapps::Buffer::isEmpty()
{
	return (m_loc == 0);
}

void dapps::Buffer::clear()
{
	m_loc = 0;
	m_value[m_loc] = '\0';
}

void dapps::Buffer::setLength(std::size_t newSize)
{
	if(m_loc < newSize)
	{
		return; // Can't go beyond boundaries.
	}
	m_loc = newSize;
	m_value[m_loc] = '\0';
}

std::string dapps::Buffer::str()
{
	std::string str = m_value;
	return str;
}

char* dapps::Buffer::c_str()
{
	return m_value;
}

char* dapps::Buffer::c_strCopy()
{
	char* retCStr = new char[m_loc + 1];
	return copyTo(retCStr);
}

dapps::Buffer::Buffer(const Buffer& source)
{
	m_size = source.m_size;
	m_loc = source.m_loc;
	m_value = new char[m_size];
	for(std::size_t i = 0; i <= m_loc; i++)
	{
		m_value[i] = source.m_value[i];
	}
}

dapps::Buffer& dapps::Buffer::operator=(const Buffer& source)
{
	if(this == &source)
	{
		return *this;
	}
	m_size = source.m_size;
	m_loc = source.m_loc;
	
	if(m_value)
	{
		delete[] m_value;
	}
	m_value = new char[m_size];
	for(std::size_t i = 0; i <= m_loc; i++)
	{
		m_value[i] = source.m_value[i];
	}
	return *this;
}

char& dapps::Buffer::operator[](std::size_t index)
{
	if(index >= m_loc)
	{
		throw OutOfBoundsException("Invalid index access in Buffer");
	}
	return m_value[index];
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
	copyTo(newVal);
	delete m_value;
	m_value = newVal;
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
	return newVal;
}

std::size_t dapps::Buffer::size()
{
	return m_loc;
}
