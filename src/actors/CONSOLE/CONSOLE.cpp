#include "CONSOLE.h"


/////////////////////////////////////////////////////////////////////
#undef _LOG_LEVEL_
#define _LOG_LEVEL_ _LOG_WARNING_
#include <tegia/context/log.h>
/////////////////////////////////////////////////////////////////////


extern "C" tegia::actors::type_base_t * _init_type(const std::string &type_name)
{	
	auto type = new tegia::actors::type_t<EXAMPLE::CONSOLE>(ACTOR_TYPE);

	type->add_action("/in",      &EXAMPLE::CONSOLE::in);
	type->add_action("/out",     &EXAMPLE::CONSOLE::out);
	type->add_action("/parse",   &EXAMPLE::CONSOLE::parse);

	RETURN_TYPE(type,EXAMPLE::CONSOLE)
};



////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// ACTION FUNCTIONS                                                                       //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


namespace EXAMPLE {


CONSOLE::~CONSOLE()
{
	
};


}	// END namespace EXAMPLE


////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// ACTION FUNCTIONS                                                                       //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


#include "actions/in.cpp"
#include "actions/out.cpp"
#include "actions/parse.cpp"


