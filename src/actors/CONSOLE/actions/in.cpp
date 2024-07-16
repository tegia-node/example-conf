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

	std::string uuid = tegia::random::uuid();
	
	auto msg = tegia::message::init();
	msg->data["input"] = input;
	msg->data["task"] = uuid;
	msg->callback.add(this->_name,"/out");

	tegia::message::send("example/phone/task/" + uuid,"/run",msg);


	/////////////////////////////////////////////////////////////////////////////////////////  
	return 200;
};


}	// END namespace EXAMPLE

