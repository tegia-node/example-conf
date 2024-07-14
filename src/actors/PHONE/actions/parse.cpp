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

int PHONE::parse(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  


	std::cout << _YELLOW_ << "RUN TEST" << _BASE_TEXT_ << std::endl;

	tegia::types::phone_t phone;
	int res = phone.parse(message->data["input"].get<std::string>());

	switch(res)
	{
		case 0:
		{
			message->data["phone"] = "";
			message->data["is_valid"] = false;
			message->data["code"] = phone.code();
			message->data["thread"] = tegia::context::tid();
		}
		break;

		case 1:
		{
			message->data["phone"] = phone.value();
			message->data["is_valid"] = true;
			message->data["code"] = phone.code();
			message->data["thread"] = tegia::context::tid();
		}
		break;

		case 2:
		{
			message->data["phone"] = "";
			message->data["is_valid"] = false;
			message->data["code"] = phone.code();
			message->data["thread"] = tegia::context::tid();
		}
		break;
	}

	
	/////////////////////////////////////////////////////////////////////////////////////////  
	return 200;
};


}	// END namespace EXAMPLE

