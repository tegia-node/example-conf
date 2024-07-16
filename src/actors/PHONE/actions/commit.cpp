#include <tuple>
#include <iostream>
#include <thread>
#include <chrono>
#include <tegia/core/json.h>
#include <tegia/core/const.h>

#include <tegia/types/types.h>


////////////////////////////////////////////////////////////////////////////////////////////
/**

	\brief
	\detail

		
*/   
////////////////////////////////////////////////////////////////////////////////////////////

using namespace ::std::chrono_literals;

namespace EXAMPLE {

int PHONE::commit(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  
	
	this->state.add(&message->data);

	this->state._count--;
	if(this->state._count == 0)
	{		
		message->data.clear();
		message->data["data"] = this->state.data;
		message->data["task"] = this->state.uuid;
		message->data["status"] = 200;
		
		message->callback = this->state.callback;
		message->status = 200;

		// std::cout << "PHONE::end" << std::endl;
		// std::cout << message->data << std::endl;
	}

	/////////////////////////////////////////////////////////////////////////////////////////  
	return 200;
};


}	// END namespace EXAMPLE

