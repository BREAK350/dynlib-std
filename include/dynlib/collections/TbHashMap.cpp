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
	}
}
//---------------------------------------------------------------------------

