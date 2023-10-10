// Copyright 2020 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file World_main.cpp
 *
 */

#include "CustomListenerPublisher.h"
#include "CustomListenerSubscriber.h"
#include "CustomListeners.h"


#include <fastdds/dds/domain/DomainParticipantFactory.hpp>

#include <fastrtps/log/Log.h>

using eprosima::fastdds::dds::Log;

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main(int argc, char** argv)
{
    cout << "ok" << endl;
	// 打印开始消息
	std::cout << "Starting " << std::endl;

	// 初始化默认参数
	int t_type = 1;               // 默认为发布者
	int count = 10;             // 默认发送10条消息
	int sleep = 100;            // 默认每条消息之间的间隔为100毫秒
	bool use_d;

	// 解析命令行参数
	if (argc > 2)
	{
		if (strcmp(argv[1], "publisher") == 0)
		{
			t_type = 1;
			if (argc > 3)
			{
				count = std::stoi(argv[3]); // 设置消息数量
				if (argc > 4)
				{
					sleep = std::stoi(argv[4]); // 设置间隔时间
				}
			}
		}
		else if (strcmp(argv[1], "subscriber") == 0)
		{
			t_type = 2;
		}

		// 设置use_d的值
		if (strcmp(argv[2], "1") == 0)
		{
			use_d = true;
		}
		else if (strcmp(argv[2], "0") == 0)
		{
			use_d = false;
		}
		else
		{
			std::cout << "Second argument must be 1 (true) or 0 (false)" << std::endl;
			Log::Reset();
			return 0;
		}
	}
	else
	{
		// 如果参数不足，打印使用方法
		//std::cout << "Use: ./DDSCustomListener [subscriber | publisher] [0|1] [count] [sleep]" << std::endl;
		std::cout << "not enough args" << std::endl;
		Log::Reset();
		return 0;
	}

	// 根据type的值，初始化并运行发布者或订阅者
	switch (t_type) {
	case 1:
	{
		CustomListenerPublisher mypub;
		if (mypub.init(use_d)) {
			mypub.run(static_cast<uint32_t>(count), static_cast<uint32_t>(sleep));
		}
		// 重置日志
		Log::Reset();
		//break;
		return 0;
	}
	case 2:
	{
		CustomListenerSubscriber mysub;
		if (mysub.init(use_d))
		{
			mysub.run();
		}
		// 重置日志
		Log::Reset();
		return 0;
		//break;
	}
	}
    return 0;
}

