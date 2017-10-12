//
//  Test.Bytes.cpp
//  This file is part of the "Units" project and released under the MIT License.
//
//  Created by Samuel Williams on 12/10/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Units/Bytes.hpp>

#include <sstream>
#include <iomanip>

namespace Units
{
	UnitTest::Suite BytesTestSuite {
		"Units::Bytes",
		
		{"it should format small values correctly",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				
				buffer << Bytes{512};
				
				examiner.expect(buffer.str()) == "512B";
			}
		},
		
		{"it should format large values correctly",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				
				buffer << Bytes{512*512*512};
				
				examiner.expect(buffer.str()) == "128MB";
			}
		},
		
		{"it should format large values correctly",
			[](UnitTest::Examiner & examiner) {
				std::stringstream buffer;
				
				buffer << Bytes{512*512*512+512*1024};
				
				examiner.expect(buffer.str()) == "128.5MB";
			}
		},
	};
}
