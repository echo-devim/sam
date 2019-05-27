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

#ifndef CORE_BUS_LAUNCHPOINT_LUNA_ADATER_H_
#define CORE_BUS_LAUNCHPOINT_LUNA_ADATER_H_

#include "core/bus/luna_task.h"

class LaunchPointLunaAdapter {
public:
    LaunchPointLunaAdapter();
    ~LaunchPointLunaAdapter();

    void init();

private:
    void initLunaApiHandler();
    void onReady();
    void requestController(LunaTaskPtr task);
    void handleRequest(LunaTaskPtr task);

    void addLaunchPoint(LunaTaskPtr task);
    void updateLaunchPoint(LunaTaskPtr task);
    void removeLaunchPoint(LunaTaskPtr task);
    void moveLaunchPoint(LunaTaskPtr task);
    void listLaunchPoints(LunaTaskPtr task);
    void searchApps(LunaTaskPtr task);

    void onLaunchPointsListChanged(const pbnjson::JValue& launch_points);
    void onLaunchPointChanged(const std::string& change, const pbnjson::JValue& launch_point);

    std::vector<LunaTaskPtr> m_pendingTasks;
};

#endif  // CORE_BUS_LAUNCHPOINT_LUNA_ADAPTER_H_

