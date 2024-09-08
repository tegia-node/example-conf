#include "PHONE.h"

/////////////////////////////////////////////////////////////////////
#undef _LOG_LEVEL_
#define _LOG_LEVEL_ _LOG_WARNING_
#include <tegia/context/log.h>
/////////////////////////////////////////////////////////////////////


extern "C" tegia::actors::type_base_t * _init_type(const std::string &type_name)
{	
	auto type = new tegia::actors::type_t<EXAMPLE::PHONE>(ACTOR_TYPE);

	ADD_ACTION("/parse",     &EXAMPLE::PHONE::parse,     ROLES::SESSION::SYSTEM);

	return type;
};


////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// ACTION FUNCTIONS                                                                       //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


namespace EXAMPLE {

PHONE::PHONE(const std::string &name): tegia::actors::actor_t(ACTOR_TYPE,name)
{

};	

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

