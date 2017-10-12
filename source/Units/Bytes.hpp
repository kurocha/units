//
//  Bytes.hpp
//  This file is part of the "Units" project and released under the MIT License.
//
//  Created by Samuel Williams on 12/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include <iosfwd>
#include <cstddef>

namespace Units
{
	struct Bytes
	{
		std::size_t value;
	};
	
	std::ostream & operator<<(std::ostream &, const Bytes &);
}
