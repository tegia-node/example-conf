#ifndef H_TEST_PHONE
#define H_TEST_PHONE

#include <tegia/tegia.h>
#include <tegia/app/router.h>

#include "state/state.h"

#define ACTOR_TYPE "EXAMPLE::PHONE"

namespace EXAMPLE {

class PHONE: public tegia::actors::actor_t<EXAMPLE::PHONE>
{
	public:

		PHONE(
			const std::string &name, 
			tegia::actors::type_t<EXAMPLE::PHONE> * type)
		: tegia::actors::actor_t<EXAMPLE::PHONE>(name,type)
		{

		};	

		~PHONE();

		//
		// ACTOR ACTIONS
		//
		
		int parse(const std::shared_ptr<message_t> &message);
		int run(const std::shared_ptr<message_t> &message);
		int commit(const std::shared_ptr<message_t> &message);
		

	private:
		EXAMPLE::PHONE_STATE state;
};

}	// END namespace EXAMPLE


#endif