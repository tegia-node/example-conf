#include "CONSOLE.h"


/////////////////////////////////////////////////////////////////////
#undef _LOG_LEVEL_
#define _LOG_LEVEL_ _LOG_WARNING_
#include <tegia/context/log.h>
/////////////////////////////////////////////////////////////////////


extern "C" tegia::actors::type_base_t * _init_type(const std::string &type_name)
{	
	auto type = new tegia::actors::type_t<EXAMPLE::CONSOLE>(ACTOR_TYPE);

	ADD_ACTION("/in",      &EXAMPLE::CONSOLE::in,      ROLES::SESSION::SYSTEM, ROLES::SESSION::PUBLIC, ROLES::SESSION::USER);
	ADD_ACTION("/out",     &EXAMPLE::CONSOLE::out,     ROLES::SESSION::SYSTEM, ROLES::SESSION::PUBLIC, ROLES::SESSION::USER);

	return type;
};



////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //
// ACTION FUNCTIONS                                                                       //
//                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////


namespace EXAMPLE {

CONSOLE::CONSOLE(const std::string &name): tegia::actors::actor_t(ACTOR_TYPE,name)
{

};	


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


