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
 * @file CustomListenerSubscriber.h
 *
 */


#ifndef PCH_H
#define PCH_H
 
// 添加要在此处预编译的标头
#include "framework.h"
 
#endif //PCH_H
 
//定义宏
#ifdef IMPORT_DLL_dds
#else
#define IMPORT_DLL_dds extern "C" _declspec(dllimport) //指的是允许将其给外部调用





#ifndef CUSTOMLISTENERSUBSCRIBER_H_
#define CUSTOMLISTENERSUBSCRIBER_H_

#include "TopicPubSubTypes.h"
#include "CustomListeners.h"

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastdds/dds/core/status/SubscriptionMatchedStatus.hpp>

IMPORT_DLL_dds class CustomListenerSubscriber
{
public:

    IMPORT_DLL_dds CustomListenerSubscriber();

    virtual ~CustomListenerSubscriber();

    //!Initialize the subscriber
    IMPORT_DLL_dds bool init(
            bool use_dr);

    //!RUN the subscriber
    IMPORT_DLL_dds void run();

    //!Run the subscriber until number samples have been received.
    IMPORT_DLL_dds void run(
            uint32_t number);

private:

    eprosima::fastdds::dds::DomainParticipant* participant_;

    eprosima::fastdds::dds::Subscriber* subscriber_;

    eprosima::fastdds::dds::Topic* topic_;

    eprosima::fastdds::dds::DataReader* reader_;

    eprosima::fastdds::dds::TypeSupport type_;

    eprosima::fastdds::dds::StatusMask p_mask_;

    CustomDataReaderListener dr_listener_;

    CustomDomainParticipantListener p_listener_;
};

#endif /* CUSTOMLISTENERSUBSCRIBER_H_ */
