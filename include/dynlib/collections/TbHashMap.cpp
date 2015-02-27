//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbHashMap.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace collections
	{

	}
}
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace collections
	{
		TbHashMap::TbHashMapItem::~TbHashMapItem()
		{
			if(next_)
			{
				delete next_;
				next_ = 0;
			}
		}

		TbHashMap::TbHashMapItem::TbHashMapItem()
		{
        	next_ = 0;
		}

		int TbHashMap::TbHashMapItem::getHash()const
		{
			TbHashable *data = getData();
			return data ? data->getHash() : -1;
		}

		void TbHashMap::TbHashMapItem::setNext_(TbHashMapItem *next_)
		{
			if(this->next_)
			{
				delete next_;
			}
			this->next_ = next_;
		}

		TbHashMap::TbHashMapItem* TbHashMap::TbHashMapItem::getNext()const
		{
        	return next_;
        }
	}
}
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace collections
	{
		TbHashMap::TbHashMapRoot::TbHashMapRoot()
		{
			count = 0;
			root_ = 0;
        }

		TbHashMap::TbHashMapRoot::~TbHashMapRoot()
		{
			if(root_)
			{
				delete root_;
				root_ = 0;
				count = 0;
            }
        }

		int TbHashMap::TbHashMapRoot::add_(TbHashMapItem *item_, const int &maxElements)
		{
			if(item_)
			{
				item_->setNext_(root_);
				root_ = item_;
				++count;
			}
			return count < maxElements;
        }

		TbHashable* TbHashMap::TbHashMapRoot::get(const int &hash)const
		{
			TbHashMapItem *item = root_;
			while(item && item->getHash() != hash)
			{
                item = item->getNext();
			}
			return item ? item->getData() : 0;
        }
	}
}
//---------------------------------------------------------------------------

