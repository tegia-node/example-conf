#ifndef H_EXAMPLE_PHONE_STATE
#define H_EXAMPLE_PHONE_STATE

#include <mutex>
#include <atomic>

#include <tegia/tegia.h>
#include <tegia/core/json.h>

//
//
//

namespace EXAMPLE {

class PHONE;

//
//
//

class PHONE_STATE
{
	friend class EXAMPLE::PHONE;

	private:
		PHONE_STATE() = default;
		~PHONE_STATE() = default;

		void add(nlohmann::json * data);

		int status = 0;
		nlohmann::json data;
		std::mutex mutex;

		std::string uuid;
		std::atomic<int> _count = 0;
		callback_t callback;		
};


} // END namespace EXAMPLE

#endif