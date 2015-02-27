//---------------------------------------------------------------------------
#ifndef TbHashMapH
#define TbHashMapH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	namespace collections
	{
		class TbHashMap;
		class TbHashable;
	}
}
//---------------------------------------------------------------------------
// includes
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace collections
	{
		class TbHashMap
		{
			private:
				// classes
				class TbHashMapItem
				{
					private:
						TbHashMapItem *next_;
					public:
                        TbHashMapItem();
						virtual ~TbHashMapItem();
						virtual TbHashable* getData()const = 0;
						virtual int getHash()const;

						virtual void setNext_(TbHashMapItem *next_);
						virtual TbHashMapItem* getNext()const;
				};

				class TbHashMapRoot
				{
					private:
						int count;
						TbHashMapItem *root_;
					public:
						TbHashMapRoot();
						virtual ~TbHashMapRoot();

						virtual void add_(TbHashMapItem *item_);
						virtual TbHashable* get(const int &hash)const;
                };
        };
	}
}
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace collections
	{
		class TbHashable
		{
			public:
				virtual ~TbHashable() {};
				virtual int getHash()const = 0;
		};
	}
}
//---------------------------------------------------------------------------
#endif
