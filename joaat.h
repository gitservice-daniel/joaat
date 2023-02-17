/*
	joaat.h
	Copyright (c) Daniel H. All rights reserved

	This source code is provided 'as-is', without any express or implied
	warranty.In no event will the author be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter itand redistribute it
	freely, subject to the following restrictions:

	1. The origin of this source code must not be misrepresented; you must not
	   claim that you wrote the original source code.If you use this source code
	   a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original source code.

	3. This notice may not be removed or altered from any source distribution.

	Daniel H. (daaniel08@protonmail.com)
*/
#ifndef __JOAAT_H__
#define __JOAAT_H__

#include <string>

#ifdef _MSC_VER

typedef unsigned __int8  uint8_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;

#else // GCC, Clang, ...

#include <stdint.h>

#endif

/*
* Hashing with JOAAT
*
* @Usage:
* > JOAAT joaat;
* >
* > uint32_t myData = joaat.hash("HelloWorld");
* > std::cout << myData << std::endl;
* >
*
* Or use it with an streaming option:
*
* @Usage
* > JOAAT joaat;
* > while (dataflow) {
* >     joaat.add("DATA");
* > }
* >
* > uint32_t data = joaat.hash();
* > std::cout << data << std::endl;
* >
*
*/
class JOAAT {

	public:

		// Hash a c++ string
		uint32_t hash(const std::string& text);

		// Hash the current stream
		uint32_t hash();

		// Add data to the current stream
		void add(std::string data);

		// Reset current stream
		void reset();

	private:

		std::string stream = "";

};

#endif
