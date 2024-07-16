#include <tuple>
#include <iostream>
#include <thread>
#include <chrono>
#include <tegia/core/json.h>
#include <tegia/core/const.h>

////////////////////////////////////////////////////////////////////////////////////////////
/**

	\brief
	\detail

		
*/   
////////////////////////////////////////////////////////////////////////////////////////////

using namespace ::std::chrono_literals;

namespace EXAMPLE {

int CONSOLE::out(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  
	
	if(message->status == 100)
	{
		std::cout << "RUN TASK" << std::endl;	
		std::cout << message->data << std::endl;
	}

	if(message->status == 200)
	{
		std::cout << "END TASK" << std::endl;	
		std::cout << message->data << std::endl;
		tegia::message::send(this->_name,"/in",tegia::message::init());
	}

	/////////////////////////////////////////////////////////////////////////////////////////  
	return 200;
};


}	// END namespace EXAMPLE

