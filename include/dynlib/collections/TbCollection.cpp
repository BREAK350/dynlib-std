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
namespace dynlib {
	namespace collections {
		TbCollection::TbObjData::~TbObjData() {
			if (data_) {
				delete data_;
				data_ = 0;
			}
		}

		TbCollectionItem* TbCollection::TbObjData::getData()const {
			return data_;
		}

		void TbCollection::TbObjData::setData_(TbCollectionItem *data_) {
			if (this->data_) {
				delete this->data_;
			}
			this->data_ = data_;
		}
	}
}

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		void TbCollection::addItem(TbCollectionItem * item) {
			TbRefData *data_ = new TbRefData();
			data_->setData(item);
			addData_(data_);
		}

		void TbCollection::addItem_(TbCollectionItem * item_) {
			TbObjData *data_ = new TbObjData();
			data_->setData_(item_);
			addData_(data_);
		}

		TbCollection::~TbCollection() {
		}
	}
}

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		TbCollectionItem::~TbCollectionItem() {
		}
	}
}

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		TbCollectionItemAction::~TbCollectionItemAction() {
		}
	}
}
// ---------------------------------------------------------------------------
