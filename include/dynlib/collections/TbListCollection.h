// ---------------------------------------------------------------------------
#ifndef TbListCollectionH
#define TbListCollectionH

// ---------------------------------------------------------------------------
// classes
namespace dynlib {
	namespace collections {
		class TbListCollection;
	}
}
// ---------------------------------------------------------------------------
// includes
#include "TbCollection.h"

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		class TbListCollection : public TbCollection {
		private:
			// classes
			class TbItem {
			private:
				TbData *data_;
				TbItem *next_;
				TbItem *prev;

				virtual void setNext_(TbItem *item_);

			public:
				TbItem();
				virtual ~TbItem();
				virtual TbItem* getNext()const;
				virtual void setData_(TbData *data_);
				virtual void setNext_(TbData *data_);
			};

		protected:
			virtual void addData_(TbData *data_);

		public:
			virtual void removeItem(TbCollectionItem *item);
			virtual void removeAllItems();
			virtual bool contains(TbCollectionItem *item)const;
			virtual void forEach(TbCollectionItemAction *action);
		};
	}
}
// ---------------------------------------------------------------------------
#endif
