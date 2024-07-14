#include <tuple>
#include <iostream>
#include <thread>

#include "../CONSOLE.h"

#include <tegia/types/types.h>


////////////////////////////////////////////////////////////////////////////////////////////
/**

	\brief
	\detail

		
*/   
////////////////////////////////////////////////////////////////////////////////////////////

namespace EXAMPLE {


auto parse_lambda = [](const std::shared_ptr<message_t> &message) -> int
{
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

	return 200;
};


int CONSOLE::parse(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  

	auto send_message_lambda = [](std::string_view token)
	{
		if(token == "")	return;

		auto msg = tegia::message::init();
		msg->data["input"] = token;
		msg->callback.add("example/console","/out");
		tegia::message::send(msg,parse_lambda);

		// std::cout << msg->data << std::endl;
	};

	std::string input = message->data["input"].get<std::string>();
	char delimiter = ';';
    std::string token;
    size_t start = 0, end = 0;

	while ((end = input.find(delimiter, start)) != std::string::npos) 
	{
		token = input.substr(start, end - start);
		send_message_lambda(token);
		start = end + 1;
	}
	token = input.substr(start);
	send_message_lambda(token);
	
	/////////////////////////////////////////////////////////////////////////////////////////  
	return 200;
};


}	// END namespace EXAMPLE

