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
 * @file CustomListenerPublisher.h
 *
 */


#ifndef PCH_H
#define PCH_H
 
// 添加要在此处预编译的标头
#include "framework.h"
 
#endif //PCH_H
 
//定义宏
#ifdef IMPORT_DLL
#else
#define IMPORT_DLL extern "C" _declspec(dllimport) //指的是允许将其给外部调用




#ifndef CUSTOMLISTENERPUBLISHER_H_
#define CUSTOMLISTENERPUBLISHER_H_

#include "TopicPubSubTypes.h"
#include "CustomListeners.h"

#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>

IMPORT_DLL class CustomListenerPublisher
{
public:

    IMPORT_DLL CustomListenerPublisher();

    virtual ~CustomListenerPublisher();

    //!Initialize
    IMPORT_DLL bool init(
            bool use_dw);

    //!Publish a sample
    IMPORT_DLL bool publish(
            bool waitForListener = true);

    //!Run for number samples
    IMPORT_DLL void run(
            uint32_t number,
            uint32_t sleep);

private:

    Topic hello_;

    eprosima::fastdds::dds::DomainParticipant* participant_;

    eprosima::fastdds::dds::Publisher* publisher_;

    eprosima::fastdds::dds::Topic* topic_;

    eprosima::fastdds::dds::DataWriter* writer_;

    bool stop_;

    CustomDataWriterListener dw_listener_;

    CustomDomainParticipantListener p_listener_;

    void runThread(
            uint32_t number,
            uint32_t sleep);

    eprosima::fastdds::dds::TypeSupport type_;
};



#endif /* CUSTOMLISTENERPUBLISHER_H_ */
