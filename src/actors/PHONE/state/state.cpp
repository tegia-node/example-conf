#include "state.h"

#include <tegia/tegia.h>
#include <tegia/core/cast.h>
#include <tegia/db/mysql/mysql.h>

namespace EXAMPLE {


////////////////////////////////////////////////////////////////////////////////////////////
/*

*/
////////////////////////////////////////////////////////////////////////////////////////////


void PHONE_STATE::add(nlohmann::json * data)
{
	this->mutex.lock();
	this->data.push_back( *data );
	this->mutex.unlock();
};


}	// END namespace EXAMPLE
