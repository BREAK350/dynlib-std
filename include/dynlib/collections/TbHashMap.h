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
