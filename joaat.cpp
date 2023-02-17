/*
    joaat.cpp
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
#include "joaat.h"

std::string to_lowercase(std::string input) {
    for (auto& c : input) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }
    }
    return input;
}

uint32_t joaat(const std::string& _key) {
    std::string key = to_lowercase(_key);

    uint32_t hash = 0;
    size_t length = key.length();

    if (length >= 4) {
        const uint32_t* key_ptr = reinterpret_cast<const uint32_t*>(key.data());
        const uint32_t* key_end = key_ptr + (length / 4);

        while (key_ptr < key_end) {
            uint32_t chunk = *key_ptr++;

            hash += (chunk & 0xFF);
            hash += (hash << 10);
            hash ^= (hash >> 6);

            chunk >>= 8;
            hash += (chunk & 0xFF);
            hash += (hash << 10);
            hash ^= (hash >> 6);

            chunk >>= 8;
            hash += (chunk & 0xFF);
            hash += (hash << 10);
            hash ^= (hash >> 6);

            chunk >>= 8;
            hash += (chunk & 0xFF);
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }

        length &= 3;
    }

    if (length > 0) {
        const char* key_ptr = key.data() + (key.length() - length);

        if (length >= 2) {
            uint16_t chunk = *reinterpret_cast<const uint16_t*>(key_ptr);

            hash += (chunk & 0xFF);
            hash += (hash << 10);
            hash ^= (hash >> 6);

            chunk >>= 8;
            hash += (chunk & 0xFF);
            hash += (hash << 10);
            hash ^= (hash >> 6);

            key_ptr += 2;
            length -= 2;
        }

        if (length > 0) {
            uint8_t chunk = *key_ptr;

            hash += chunk;
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

uint32_t JOAAT::hash(const std::string& text) {
    return joaat(text);
}

uint32_t JOAAT::hash() {
    return joaat(JOAAT::stream);
}
void JOAAT::add(std::string data) {
    JOAAT::stream.append(data);
}

void JOAAT::reset() {
    JOAAT::stream = "";
}
