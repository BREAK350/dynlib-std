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
