#ifndef OPENGEDK_COMPILER_H_INCLUDED
#define OPENGEDK_COMPILER_H_INCLUDED

/* File: gedkCompiler.h
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
 * Purpose: compiler detection stuff.
 *
*/


#include "gedkCompilerGCCDetection.h"
#include "gedkCompilerMSVCDetection.h"

#ifdef __GNUC__
// Check gcc supported version used
#   if !GEDK_GCC_VERSION_OR_HIGHER(8,1,0)
#       error "Open GEDK requires GCC 8.1.0 or higher."
#   endif
#   define GEDK_GCC // This means that GCC compiler used.
#   include "compilerGCC/gedkCompilerGCC.h"
#elif defined(_MSC_VER)
// Check msvc supported version used
#   if !GEDK_MSVC_VERSION_OR_HIGHER(GEDK_VISUAL_STUDIO_2019_16_x_10_16_x_11)
#       error "Open GEDK requires Visual Studio 2019 (16.10-16.11) or higher."
#   endif
#   define GEDK_MSVC // This means that MSVC compiler used.
#else
#   error "unsupported compiler used. Now {gcc8.1.0, Visual Studio 2019 (16.10-16.11)} only is supported."
#endif // __GNUC__

#endif // OPENGEDK_COMPILER_H_INCLUDED


