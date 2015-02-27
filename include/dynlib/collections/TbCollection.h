// ---------------------------------------------------------------------------
#ifndef TbCollectionH
#define TbCollectionH

// ---------------------------------------------------------------------------
// classes
namespace dynlib {
	namespace collections {
		class TbCollection;
		class TbCollectionItem;
		class TbCollectionItemAction;
	}
}

// ---------------------------------------------------------------------------
// includes
// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		class TbCollection {
		public:
			virtual ~TbCollection();

			virtual void addItem(TbCollectionItem *item);
			virtual void addItem_(TbCollectionItem *item_);
			virtual void removeItem(TbCollectionItem *item) = 0;
			virtual void removeAllItems() = 0;
			virtual bool contains(TbCollectionItem *item)const = 0;
			virtual void forEach(TbCollectionItemAction *action) = 0;
		};
	}
}

// ---------------------------------------------------------------------------
namespace dynlib {
	namespace collections {
		class TbCollectionItem {
		public:

		};
	}
}
// ---------------------------------------------------------------------------
#endif
