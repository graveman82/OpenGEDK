#ifndef OPENGEDK_SINGLETON_H_INCLUDED
#define OPENGEDK_SINGLETON_H_INCLUDED

/* File: gedkSingleton.h
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
 * Purpose: singleton pattern definition.
 *
*/

#include "gedkInegerDefs.h"
#include <new>

namespace gedk
{

//-----------------------------------------------------------------------------
//
template <typename T, UBool32 fStaticStorage = kTrue32>
class Singleton;

//-----------------------------------------------------------------------------
//
template <typename T>
class Singleton <T, kTrue32>
{
public:
    typedef Size32 SizeType;
    typedef Index32 IndexType;
    typedef Count32 CountType;
    typedef T* PointerType;


public:
    static PointerType Instance()
    {
        if (!instance_)
        {
            instance_ = new (static_cast<void*>(T::GetMemory())) T();
        }
        return instance_;
    }

    static void Destroy()
    {
        if (instance_)
        {
            instance_->~T();
            instance_ = nullptr;
        }
    }

    virtual ~Singleton() { Destroy(); }

    PointerType get() { return static_cast<PointerType>(&T::memory_[0]); }
    const PointerType get() const { return static_cast<PointerType>(&T::memory_[0]); }

    PointerType operator->() { return get(); }
    const PointerType operator->() const { return get(); }

    T& operator*() { return *get(); }
    const T& operator*() const { return *get(); }

protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;


    static PointerType instance_;

};

//-----------------------------------------------------------------------------
template <typename T>
typename Singleton<T, kTrue32>::PointerType Singleton<T, kTrue32>::instance_ = nullptr;


//-----------------------------------------------------------------------------
template <>
class Singleton <int>
{
    Singleton();
    virtual ~Singleton() {  }
};

} // end of gedk
#endif // OPENGEDK_SINGLETON_H_INCLUDED
