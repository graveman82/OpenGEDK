#ifndef OPENGEDK_MEMORYPOOL_H_INCLUDED
#define OPENGEDK_MEMORYPOOL_H_INCLUDED

/* File: gedkMemoryPool.h
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
 * Purpose: memory pool template.
 *
 */

#include <vector>
#include <memory>
#include "gedkStandardAllocationStartegy.h"
#include "gedkInegerDefs.h"
#include "gedkSingleton.h"

#define GEDK_MEMORY_POOL_DEBUG_MODE 1

#if GEDK_MEMORY_POOL_DEBUG_MODE
#   include <iostream>
#endif // GEDK_MEMORY_POOL_DEBUG_MODE

namespace gedk
{
//-----------------------------------------------------------------------------
//
template <int kTypeSize, typename TAllocStrategy = StandardAllocationStrategy>
class MemoryPool : public Singleton<MemoryPool<kTypeSize, TAllocStrategy>>
{
    friend class Singleton<MemoryPool>;

private:
	typedef Size32 SizeType;
	typedef Index32 IndexType;

	struct NodeBase
	{
		NodeBase()
		{
#if GEDK_MEMORY_POOL_DEBUG_MODE
		    std::cout << "NodeBase[" << std::hex << int(this) << "]: constructor()" << std::dec << std::endl;
#endif
        }
#if GEDK_MEMORY_POOL_DEBUG_MODE
		~NodeBase() { std::cout << "NodeBase[" << std::hex << int(this) << "]: destructor()" << std::dec << std::endl;}
#endif

		NodeBase *next{};
	};

	struct Node : public NodeBase
	{
		DataByte memory[kTypeSize]; // data are placed there
	};

	typedef std::vector<Node> NodeVector;

	struct Block;
	typedef std::unique_ptr<Block> BlockUP;

	struct Block
	{
		Block(SizeType capacity) : nodes(capacity) {}

		BlockUP next;
		NodeVector nodes;
	};

    static constexpr SizeType SizeOf()  { return sizeof(Singleton<int>) +
                                                   sizeof(BlockUP) +
                                                   sizeof(Node*) +
                                                   sizeof(SizeType); }
    enum
    {
        kInstanceSize = SizeOf(),
        kInstanceSizeAligned16 = kInstanceSize + (16u - kInstanceSize % 16u)
    };

    static DataByte memory_[kInstanceSizeAligned16];
    static DataByte* GetMemory() { return &memory_[0]; }

public:

	void *Allocate();
	void Free(void *);
    SizeType Capacity() const { return capacity_; }

    virtual ~MemoryPool() = default;
protected:
    MemoryPool() { }


private:
	void Reserve();

	BlockUP firstBlock_;
	Node *firstUnusedNode_{};
	SizeType capacity_{};
};

//-----------------------------------------------------------------------------
template <int kTypeSize, typename TAllocStrategy>
DataByte MemoryPool<kTypeSize, TAllocStrategy>::memory_[MemoryPool<kTypeSize, TAllocStrategy>::kInstanceSizeAligned16];

//-----------------------------------------------------------------------------

template <int kTypeSize, typename TAllocStrategy>
void
MemoryPool<kTypeSize, TAllocStrategy>::Reserve()
{
	SizeType nNewCapacity = TAllocStrategy::ProposeCapacity(capacity_);
	BlockUP newBlock{new Block(nNewCapacity)};
	capacity_ += nNewCapacity;
#if GEDK_MEMORY_POOL_DEBUG_MODE
    std::cout << "Reserve() before block linking" << std::endl;
#endif
	newBlock->next.reset(firstBlock_.release());
	firstBlock_.reset(newBlock.release());
#if GEDK_MEMORY_POOL_DEBUG_MODE
    std::cout << "Reserve() after block linking" << std::endl;
#endif
	auto& newNodes = firstBlock_.get()->nodes;
	for(IndexType i = 0; i < (SizeType)newNodes.size() - 1; ++i) {
		Node &node = newNodes[i];
		Node &nextNode = newNodes[i + 1];
		node.next = &nextNode;
	}

	firstUnusedNode_ = &newNodes[0];
#if GEDK_MEMORY_POOL_DEBUG_MODE
    std::cout << "Reserve() end of function newBlock.get(): " << int(newBlock.get())<< std::endl;
#endif
}

//-----------------------------------------------------------------------------

template <int kTypeSize, typename TAllocStrategy>
void *
MemoryPool<kTypeSize, TAllocStrategy>::Allocate()
{
	if(!firstUnusedNode_) { Reserve(); }

	Node *resultNode = firstUnusedNode_;
	firstUnusedNode_ = static_cast<Node*>(firstUnusedNode_->next);
	resultNode->next = nullptr;

	return &resultNode->memory[0];
}

//-----------------------------------------------------------------------------

template <int kTypeSize, typename TAllocStrategy>
void
MemoryPool<kTypeSize, TAllocStrategy>::Free(void* p)
{
	DataByte *pBytes = reinterpret_cast<DataByte *>(p);
	NodeBase* pNodeBase{};
	Node* pNode = static_cast<Node*>(pNodeBase);
	Node *node = reinterpret_cast<Node *>( pBytes - ( ((DataByte*)&pNode->memory[0]) - ((DataByte*)pNodeBase) ) );

	node->next = firstUnusedNode_;
	firstUnusedNode_ = node;
}
} // end of gedk
#endif // OPENGEDK_MEMORYPOOL_H_INCLUDED
