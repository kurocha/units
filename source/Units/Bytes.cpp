//
//  Bytes.cpp
//  This file is part of the "Units" project and released under the MIT License.
//
//  Created by Samuel Williams on 12/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include "Bytes.hpp"

#include <iostream>

namespace Units
{
	std::ostream & operator<<(std::ostream & output, const Bytes & bytes)
	{
		const char * suffix[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
		std::size_t scale = 0;
		
		double amount = bytes.value;
		
		while (amount > 1024) {
			amount /= 1024;
			scale += 1;
			
			if (scale == sizeof(suffix)) break;
		}
		
		auto precision = output.precision(4);
		
		output << amount << suffix[scale];
		
		output.precision(precision);
		
		return output;
	}
}
