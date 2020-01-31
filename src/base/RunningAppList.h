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

#ifndef BASE_RUNNINGAPPLIST_H_
#define BASE_RUNNINGAPPLIST_H_

#include <iostream>
#include <memory>
#include <map>

#include "interface/ISingleton.h"
#include "interface/IClassName.h"
#include "RunningApp.h"

using namespace std;

class RunningAppList : public ISingleton<RunningAppList>,
                       public IClassName {
friend class ISingleton<RunningAppList>;
public:
    virtual ~RunningAppList();

    RunningAppPtr createByLunaTask(LunaTaskPtr lunaTask);
    RunningAppPtr createByAppId(const string& appId);
    RunningAppPtr createByLaunchPointId(const string& launchPointId);
    RunningAppPtr createByLaunchPoint(LaunchPointPtr launchPoint);

    RunningAppPtr getByLunaTask(LunaTaskPtr lunaTask);
    RunningAppPtr getByIds(const string& instanceId, const string& launchPointId, const string& appId, const int displayId = -1);
    RunningAppPtr getByInstanceId(const string& instanceId);
    RunningAppPtr getByToken(const LSMessageToken& token);
    RunningAppPtr getByLaunchPointId(const string& launchPointId, const int displayId = -1);
    RunningAppPtr getByAppId(const string& appId, const int displayId = -1);
    RunningAppPtr getByWebprocessid(const string& webprocessid);

    bool add(RunningAppPtr runningApp);

    bool removeByObject(RunningAppPtr runningApp);
    bool removeByIds(const string& instanceId, const string& launchPointId, const string& appId);
    bool removeByInstanceId(const string& instanceId);
    bool removeByPid(const string& processId);
    bool removeAllByType(AppType type);
    bool removeAllByConext(AppType type, const int context);
    bool removeAllByLaunchPoint(LaunchPointPtr launchPoint);

    bool setConext(AppType type, const int context);

    void toJson(JValue& array, bool devmodeOnly = false);

private:
    void onAdd(RunningAppPtr runningApp);
    void onRemove(RunningAppPtr runningApp);

    RunningAppList();

    map<string, RunningAppPtr> m_map;
};

#endif /* BASE_RUNNINGAPPLIST_H_ */
