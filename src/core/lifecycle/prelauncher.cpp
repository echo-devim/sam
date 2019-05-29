// Copyright (c) 2012-2018 LG Electronics, Inc.
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

#include "core/lifecycle/prelauncher.h"

Prelauncher::Prelauncher()
{
}

Prelauncher::~Prelauncher()
{
}

void Prelauncher::add_item(AppLaunchingItemPtr item)
{
}

void Prelauncher::remove_item(const std::string& item_uid)
{
}

void Prelauncher::input_bridged_return(AppLaunchingItemPtr item, const pbnjson::JValue& jmsg)
{
}

void Prelauncher::cancel_all()
{
}
