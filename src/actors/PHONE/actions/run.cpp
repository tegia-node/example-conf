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

int PHONE::run(const std::shared_ptr<message_t> &message)
{
	/////////////////////////////////////////////////////////////////////////////////////////  

	std::cout << "TASK RUN " << message->data["task"].get<std::string>() << std::endl;

	this->state.callback = message->callback;
	this->state.uuid = message->data["task"].get<std::string>();
	message->status = 100;
	//message->callback.pause();

	auto send_message_lambda = [this](std::string_view token)
	{
		if(token == "")	return;

		this->state._count++;

		auto msg = tegia::message::init();
		msg->data["input"] = token;
		msg->callback.add(this->_name,"/commit");
		tegia::message::send(this->_name,"/parse",msg);
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

