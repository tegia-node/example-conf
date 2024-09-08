#ifndef H_TEST_CONSOLE
#define H_TEST_CONSOLE

#include <tegia/tegia.h>

#define ACTOR_TYPE "EXAMPLE::CONSOLE"

namespace EXAMPLE {

class CONSOLE: public tegia::actors::actor_t
{
	friend class tegia::actors::type_t<EXAMPLE::CONSOLE>;

	protected:
		CONSOLE(const std::string &name);

	public:
		~CONSOLE();
		
		//
		// ACTOR ACTIONS
		//
		
		int in(const std::shared_ptr<message_t> &message);
		int out(const std::shared_ptr<message_t> &message);
		int parse(const std::shared_ptr<message_t> &message);

	private:
};

}	// END namespace EXAMPLE


#endif