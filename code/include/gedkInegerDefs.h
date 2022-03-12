#ifndef OPENGEDK_INTEGERDEFS_H_INCLUDED
#define OPENGEDK_INTEGERDEFS_H_INCLUDED

/* File: gedkIntegerDefs.h
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
 * Purpose: integer types definitions.
 *
*/

#include "gedkPlatform.h"



namespace gedk
{

// compiler-defined typedefs
//---------------------------
#ifdef GEDK_GCC

// signed integers
typedef int8_t  int8_t;
typedef int16_t int16_t;
typedef int32_t int32_t;

#   ifdef GEDK_PLATFORM64
	typedef int64_t int64_t;
#   endif // GEDK_OS_WINDOWS64

// unsigned integers
typedef uint8_t  uint8_t;
typedef uint16_t uint16_t;
typedef uint32_t uint32_t;

#   ifdef GEDK_PLATFORM64
	typedef uint64_t uint64_t;
#   endif // GEDK_OS_WINDOWS64

#elif defined(GEDK_MSVC)

// signed integers
typedef __int8  int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;

#   ifdef GEDK_PLATFORM64
	typedef __int64 int64_t;
#   endif // GEDK_OS_WINDOWS64

// unsigned integers
typedef unsigned __int8  uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;

#   ifdef GEDK_PLATFORM64
	typedef unsigned __int64 uint64_t;
#   endif // GEDK_OS_WINDOWS64

#else
#   error "Unsupported compiler used."
#endif // GEDK_GCC

// user-friendly typedefs
//------------------------

// types for count storage
typedef int8_t  Count8;
typedef int16_t Count16;
typedef int32_t Count32;

typedef uint8_t  UCount8;
typedef uint16_t UCount16;
typedef uint32_t UCount32;

// types for size storage
typedef Count8 Size8;
typedef Count16 Size16;
typedef Count32 Size32;

typedef UCount8 USize8;
typedef UCount16 USize16;
typedef UCount32 USize32;

// types for inex storage
typedef int8_t  Index8;
typedef int16_t Index16;
typedef int32_t Index32;

typedef uint8_t  UIndex8;
typedef uint16_t UIndex16;
typedef uint32_t UIndex32;

// types for flags (bits massive) data storage
typedef uint8_t  Flags8;
typedef uint16_t Flags16;
typedef uint32_t Flags32;

/// Data byte - unsigned 8-bit integer.
typedef uint8_t  DataByte;

/// Boolean of type 8-bit unsigned integer.
typedef uint8_t UBool8;
const UBool8 kFalse8 = 0;
const UBool8 kTrue8 = 1;

/// Boolean of type 32-bit unsigned integer.
typedef uint8_t UBool32;
const UBool32 kFalse32 = 0;
const UBool32 kTrue32 = 1;
} // end of gedk


#endif // OPENGEDK_INTEGERDEFS_H_INCLUDED
