#ifndef H_TEST_PHONE
#define H_TEST_PHONE

#include <tegia/tegia.h>

#define ACTOR_TYPE "EXAMPLE::PHONE"

namespace EXAMPLE {

class PHONE: public tegia::actors::actor_t
{
	friend class tegia::actors::type_t<EXAMPLE::PHONE>;

	protected:
		PHONE(const std::string &name);

	public:
		~PHONE();

		//
		// ACTOR ACTIONS
		//
		
		int parse(const std::shared_ptr<message_t> &message);
		
	private:
};

}	// END namespace EXAMPLE


#endif