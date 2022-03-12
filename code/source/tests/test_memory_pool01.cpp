/* File: test_memory_pool01.cpp
 *
 * --------
 * License
 * --------
 * Copyright (c) 2022 Marat Sungatullin (aka MrSung, aka mrsung82, aka graveman).
 * This code is covered under dual licenses.
 * You can use either GPL3 license or zlib license at your discretion.
 *
 * GNU General Public License version 3:
 * --------------------------------------
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * The zlib/libpng License (Zlib):
 * --------------------------------
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it freely,
 * subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim
 * that you wrote the original software. If you use this software in a product,
 * an acknowledgment in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be misrepresented
 * as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * Contacts:
 * ----------
 * Email: mrsung82@gmail.com
 *  Theme in message: OpenGEDK - <your question or issue>.
 *  (don't spam, please!)
 *
 * ------
 * Info
 * ------
 *
 * Purpose: test and sample showing how to use memory pool.
 *
*/
#include <iostream>
#include <string>
#include <string.h>

#include "gedkMemoryPool.h"
#include <new>

struct Dummy
{
    Dummy(const char* name = "abcd0123efgh456", int value = 0) : value(value)
    {
        setName(name);
    }


    void setName(const char* name)
    {
        strcpy(this->name, name);
    }

    char name[16];
    int value;
};

void Test()
{
    gedk::MemoryPool<sizeof(Dummy)> pool;
    Dummy* p = new(pool.Allocate()) Dummy("Fredy", 1984);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;return;
    p = new(pool.Allocate()) Dummy("Fredy", 1985);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;
    p = new(pool.Allocate()) Dummy("Fredy", 1986);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;
    p = new(pool.Allocate()) Dummy("Fredy", 1987);
std::cout << "Pool capacity: " << pool.Capacity() << std::endl;

    p = new(pool.Allocate()) Dummy("Fredy", 1988);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;
    p = new(pool.Allocate()) Dummy("Fredy", 1989);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;
    p = new(pool.Allocate()) Dummy("Fredy", 1990);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;
    p = new(pool.Allocate()) Dummy("Fredy", 1991);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;

    p = new(pool.Allocate()) Dummy("Fredy", 1992);
    std::cout << "Pool capacity: " << pool.Capacity() << std::endl;

}

void WaitKeyAndQuit()
{
	std::string q;
	std::cout << "Press any key followed Enter to quit..." << std::endl;
	std::cin >> q;
}

int main()
{
    Test();
    WaitKeyAndQuit();
    return 0;
}


