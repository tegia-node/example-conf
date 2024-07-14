#ifndef H_TEST_PHONE
#define H_TEST_PHONE

#include <tegia/tegia.h>
#include <tegia/app/router.h>

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
		int test(const std::shared_ptr<message_t> &message);
		

	private:
};

}	// END namespace EXAMPLE


#endif