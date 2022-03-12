/* File: test_pool01.cpp
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
 * Purpose: test and sample showing how to use pool.
 *
*/
#include <iostream>
#include <string>
#include <string.h>

#include "test_dummy.h"
#include "gedkPool.h"

void Test()
{
    std::cout << "-- Test begin --\n" << std::endl;
    using gedk::TestDummy;

    gedk::Pool<TestDummy> dummyPool;

    { // case 1
        std::cout << "-- case 1 --\n" << std::endl;
        gedk::Pool<TestDummy>::SP dummySP{dummyPool.CreateSP()};
        dummySP->setName("case 1");
        gedk::Pool<TestDummy>::SP dummySP2{dummyPool.CreateSP()};
    }

    { // case 2
        std::cout << "-- case 2 --\n" << std::endl;
        gedk::Pool<TestDummy>::UP dummyUP{dummyPool.CreateUP()};
        dummyUP->setName("case 2");
        TestDummy* p = dummyUP.release();
        dummyPool.Destroy(p);
    }
    std::cout << "-- Test end --\n" << std::endl;
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




