#ifndef OPENGEDK_COMPILERMSVCDETECTION_H_INCLUDED
#define OPENGEDK_COMPILERMSVCDETECTION_H_INCLUDED

/* File: gedk
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
 * Purpose: msvc compiler detection macros.
 *
*/

#define GEDK_VISUAL_STUDIO_6_x_0		        1200
#define GEDK_VISUAL_STUDIO_NET_2002_7_x_0		1300
#define GEDK_VISUAL_STUDIO_NET_2003_7_x_1		1310
#define GEDK_VISUAL_STUDIO_2005_8_x_0			1400
#define GEDK_VISUAL_STUDIO_2008_9_x_0			1500
#define GEDK_VISUAL_STUDIO_2010_10_x_0			1600
#define GEDK_VISUAL_STUDIO_2012_11_x_0			1700
#define GEDK_VISUAL_STUDIO_2013_12_x_0			1800
#define GEDK_VISUAL_STUDIO_2015_14_x_0			1900
#define GEDK_VISUAL_STUDIO_2017 RTW_15_x_0		1910
#define GEDK_VISUAL_STUDIO_2017_15_x_3			1911
#define GEDK_VISUAL_STUDIO_2017_15_x_5			1912
#define GEDK_VISUAL_STUDIO_2017_15_x_6			1913
#define GEDK_VISUAL_STUDIO_2017_15_x_7			1914
#define GEDK_VISUAL_STUDIO_2017_15_x_8			1915
#define GEDK_VISUAL_STUDIO_2017_15_x_9			1916
#define GEDK_VISUAL_STUDIO_2019 RTW_16_x_0		1920
#define GEDK_VISUAL_STUDIO_2019_16_x_1			1921
#define GEDK_VISUAL_STUDIO_2019_16_x_2			1922
#define GEDK_VISUAL_STUDIO_2019_16_x_3			1923
#define GEDK_VISUAL_STUDIO_2019_16_x_4			1924
#define GEDK_VISUAL_STUDIO_2019_16_x_5			1925
#define GEDK_VISUAL_STUDIO_2019_16_x_6			1926
#define GEDK_VISUAL_STUDIO_2019_16_x_7			1927
#define GEDK_VISUAL_STUDIO_2019_16_x_8_16_x_9	1928
#define GEDK_VISUAL_STUDIO_2019_16_x_10_16_x_11	1929
#define GEDK_VISUAL_STUDIO_2022 RTW_17_x_0		1930

/** Macro to get MSVC version.
*/
#define GEDK_MSVC_VERSION _MSC_VER

#define GEDK_MSVC_VERSION_OR_HIGHER(ver) (GEDK_MSVC_VERSION >= ver)

#endif // OPENGEDK_COMPILERMSVCDETECTION_H_INCLUDED
