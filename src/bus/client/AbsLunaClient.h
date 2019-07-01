// Copyright (c) 2019 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef BUS_CLIENT_ABSLUNACLIENT_H_
#define BUS_CLIENT_ABSLUNACLIENT_H_

#include <iostream>
#include <luna-service2/lunaservice.hpp>
#include <pbnjson.hpp>
#include <boost/signals2.hpp>

using namespace std;
using namespace LS;
using namespace pbnjson;

class AbsLunaClient {
public:
    static JValue& getEmptyPayload();
    static JValue& getSubscriptionPayload();

    AbsLunaClient(const string& name);
    virtual ~AbsLunaClient();

    virtual void initialize() final;

    virtual void onInitialze() = 0;
    virtual void onServerStatusChanged(bool isConnected) = 0;

    const string& getName()
    {
        return m_name;
    }

    bool isConnected()
    {
        return m_isConnected;
    }

    boost::signals2::signal<void(bool)> EventServiceStatusChanged;

private:
    static bool _onServerStatus(LSHandle *lshandle, LSMessage *message, void *userData);

    string m_name;
    bool m_isConnected;
    Call m_statusCall;
};

#endif /* BUS_CLIENT_ABSLUNACLIENT_H_ */
