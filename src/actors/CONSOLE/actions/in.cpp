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

int CONSOLE::in(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  

	std::string input;
	std::cout << _YELLOW_ << "tegia$ " << _BASE_TEXT_;
	std::getline(std::cin, input);

	auto msg = tegia::message::init();
	msg->data["message"] = input;
	msg->callback.add(this->name,"/out");

	tegia::message::send("example/phone","/parse",msg);
	
	/////////////////////////////////////////////////////////////////////////////////////////  
	return 200;
};


}	// END namespace EXAMPLE

