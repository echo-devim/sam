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

#ifndef CORE_LIFECYCLE_LIFECYCLE_LUNA_ADATER_H_
#define CORE_LIFECYCLE_LIFECYCLE_LUNA_ADATER_H_

#include "core/bus/luna_task.h"
#include "core/package/app_scanner.h"

class LifeCycleLunaAdapter {
public:
    LifeCycleLunaAdapter();
    ~LifeCycleLunaAdapter();

    void Init();

private:
    void InitLunaApiHandler();
    void NoHandler(LunaTaskPtr task);
    void RequestController(LunaTaskPtr task);
    void HandleRequest(LunaTaskPtr task);
    void OnReady();
    void OnScanFinished(ScanMode mode, const AppDescMaps& scannced_apps);

    // api handler
    void Launch(LunaTaskPtr task);
    void Open(LunaTaskPtr task);
    void Pause(LunaTaskPtr task);
    void CloseByAppId(LunaTaskPtr task);
    void CloseByAppIdForDev(LunaTaskPtr task);
    void CloseAllApps(LunaTaskPtr task);
    void Running(LunaTaskPtr task);
    void RunningForDev(LunaTaskPtr task);
    void ChangeRunningAppId(LunaTaskPtr task);
    void GetAppLifeEvents(LunaTaskPtr task);
    void GetAppLifeStatus(LunaTaskPtr task);
    void GetForegroundAppInfo(LunaTaskPtr task);
    void LockApp(LunaTaskPtr task);
    void RegisterApp(LunaTaskPtr task);
    void RegisterNativeApp(LunaTaskPtr task);
    void NotifyAlertClosed(LunaTaskPtr task);

    void OnForegroundAppChanged(const std::string& app_id);
    void OnExtraForegroundInfoChanged(const pbnjson::JValue& foreground_info);
    void OnLifeCycleEventGenarated(const pbnjson::JValue& event);

    // TODO : make them retired via sangria
    // api handler which should be deprecated
    void Close(LunaTaskPtr task);
    void NotifySplashTimeout(LunaTaskPtr task);
    void OnLaunch(LunaTaskPtr task);

    std::vector<LunaTaskPtr> pending_tasks_on_ready_;
    std::vector<LunaTaskPtr> pending_tasks_on_scanner_;
};

#endif  // CORE_LIFECYCLE_LIFECYCLE_LUNA_ADAPTER_H_
