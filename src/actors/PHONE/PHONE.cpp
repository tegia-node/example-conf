#include "PHONE.h"

/////////////////////////////////////////////////////////////////////
#undef _LOG_LEVEL_
#define _LOG_LEVEL_ _LOG_WARNING_
#include <tegia/context/log.h>
/////////////////////////////////////////////////////////////////////


extern "C" tegia::actors::type_base_t * _init_type(const std::string &type_name)
{	
	auto type = new tegia::actors::type_t<EXAMPLE::PHONE>(ACTOR_TYPE);

	type->add_action("/parse",&EXAMPLE::PHONE::parse);
	type->add_action("/test",&EXAMPLE::PHONE::test);

	RETURN_TYPE(type,EXAMPLE::PHONE)
};


////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// ACTION FUNCTIONS                                                                       //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


namespace EXAMPLE {

PHONE::~PHONE()
{
	
};


}	// END namespace EXAMPLE


////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// ACTION FUNCTIONS                                                                       //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


#include "actions/parse.cpp"
#include "actions/test.cpp"

