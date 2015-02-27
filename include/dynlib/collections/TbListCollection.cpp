// ---------------------------------------------------------------------------
#pragma hdrstop
#include "TbListCollection.h"
#pragma package(smart_init)

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		TbListCollection::TbListCollection() {
			first_ = 0;
			last = 0;
		}

		TbListCollection::~TbListCollection() {
			if (first_) {
				delete first_;
				first_ = 0;
			}
			last = 0;
		}

		void TbListCollection::addData_(TbData *data_) {
			if (first_) {
				last->addNext_(data_);
				last = last->getNext();
			}
			else {
				first_ = new TbItem();
				first_->setData_(data_);
				last = first_;
			}
		}

		void TbListCollection::removeItem(TbCollectionItem *item) {
		}

		void TbListCollection::removeAllItems() {
		}

		bool TbListCollection::contains(TbCollectionItem *item)const {
		}

		void TbListCollection::forEach(TbCollectionItemAction *action) {
			if (action) {
				TbItem *item = first_;
				while (item) {
					action->perform(item->getData());
					item = item->getNext();
				}
			}
		}

		int TbListCollection::getSize()const {

		}
	}
}

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		TbListCollection::TbItem::TbItem() {
			data_ = 0;
			next_ = 0;
			prev = 0;
		}

		TbListCollection::TbItem::~TbItem() {
			if (data_) {
				delete data_;
				data_ = 0;
			}
			if (next_) {
				delete next_;
				next_ = 0;
			}
			prev = 0;
		}

		TbListCollection::TbItem* TbListCollection::TbItem::getNext()const {
			return next_;
		}

		void TbListCollection::TbItem::setData_(TbData *data_) {
			if (this->data_) {
				delete this->data_;
			}
			this->data_ = data_;
		}

		void TbListCollection::TbItem::setNext_(TbItem *item_) {
			item_->prev = this;
			if (next_) {
				item_->next_ = next_;
				next_->prev = item_;
			}
			next_ = item_;
		}

		void TbListCollection::TbItem::addNext_(TbData *data_) {
			TbItem *item_ = new TbItem();
			item_->setData_(data_);
			setNext_(item_);
		}

		TbCollectionItem* TbListCollection::TbItem::getData()const {
			return data_->getData();
		}

	}
}
// ---------------------------------------------------------------------------
