#include <tuple>
#include <iostream>
#include <thread>

#include "../CONSOLE.h"

////////////////////////////////////////////////////////////////////////////////////////////
/**

	\brief
	\detail

		
*/   
////////////////////////////////////////////////////////////////////////////////////////////

namespace EXAMPLE {

int CONSOLE::parse(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  

	auto send_message_lambda = [](std::string_view token)
	{
		if(token == "")	return;
		auto msg = tegia::message::init();
		msg->data["input"] = token;
		msg->callback.add("example/console","/out");
		tegia::message::send("example/phone","/parse",msg);
	};

	// std::cout << message->data["input"].get<std::string>() << std::endl;

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

