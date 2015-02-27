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
		protected:
			// classes
			class TbData {
			public:
				virtual ~TbData();
				virtual TbCollectionItem* getData()const = 0;
			};

		private:
			class TbRefData : public TbData {
			private:
				TbCollectionItem *data;

			public:
				virtual ~TbRefData();
				virtual TbCollectionItem* getData()const;
				virtual void setData(TbCollectionItem *data);
			};

		protected:
			virtual void addData_(TbData *data_) = 0;

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
