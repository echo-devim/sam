// Copyright (c) 2017-2018 LG Electronics, Inc.
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

#ifndef PRELAUNCHER_H
#define PRELAUNCHER_H

#include <lifecycle/stage/appitem/LaunchAppItem.h>

class Prelauncher {
public:
    Prelauncher();
    virtual ~Prelauncher();

    virtual void addItem(LaunchAppItemPtr item);
    virtual void removeItem(const std::string& app_uid);
    virtual void inputBridgedReturn(LaunchAppItemPtr item, const pbnjson::JValue& jmsg);
    virtual void cancelAll();

    boost::signals2::signal<void (const std::string& uid)> EventPrelaunchingDone;

private:
    static bool onReturnLSCall(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    static bool onReturnLSCallForBridgedRequest(LSHandle* handle, LSMessage* lsmsg, void* user_data);

    void runStages(LaunchAppItemPtr item);
    void handleStages(LaunchAppItemPtr prelaunching_item);

    void redirectToAnother(LaunchAppItemPtr prelaunching_item);
    void finishPrelaunching(LaunchAppItemPtr prelaunching_item);

    LaunchAppItemPtr getLSCallRequestItemByToken(const LSMessageToken& token);
    LaunchAppItemPtr getItemByUid(const std::string& uid);
    void removeItemFromLSCallRequestList(const std::string& uid);

private:
    LaunchItemList m_itemQueue;
    LaunchItemList m_lscallRequestList;

};

#endif
