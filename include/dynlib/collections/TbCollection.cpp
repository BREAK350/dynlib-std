// ---------------------------------------------------------------------------
#pragma hdrstop
#include "TbCollection.h"
#pragma package(smart_init)

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		TbCollection::TbData::~TbData() {
		}
	}
}

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		TbCollection::TbRefData::~TbRefData() {
			data = 0;
		}

		TbCollectionItem* TbCollection::TbRefData::getData()const {
			return data;
		}

		void TbCollection::TbRefData::setData(TbCollectionItem *data) {
			this->data = data;
		}
	}
}

// ---------------------------------------------------------------------------
