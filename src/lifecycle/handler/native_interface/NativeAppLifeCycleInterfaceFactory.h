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

#ifndef LIFECYCLE_HANDLER_NATIVE_INTERFACE_NATIVEAPPLIFECYCLEINTERFACEFACTORY_H_
#define LIFECYCLE_HANDLER_NATIVE_INTERFACE_NATIVEAPPLIFECYCLEINTERFACEFACTORY_H_

#include "interface/ISingleton.h"
#include "NativeAppLifeCycleInterfaceVer1.h"
#include "NativeAppLifeCycleInterfaceVer2.h"

class NativeAppLifeCycleInterfaceFactory : public ISingleton<NativeAppLifeCycleInterfaceFactory> {
friend class ISingleton<NativeAppLifeCycleInterfaceFactory>;
public:
    virtual ~NativeAppLifeCycleInterfaceFactory() {}

    AbsNativeAppLifecycleInterface& getInterface(AppPackagePtr appDescPtr);

private:
    NativeAppLifeCycleInterfaceFactory() {}

    NativeAppLifeCycleInterfaceVer1 m_nativeHandlerV1;
    NativeAppLifeCycleInterfaceVer2 m_nativeHandlerV2;
};

#endif /* LIFECYCLE_HANDLER_NATIVE_INTERFACE_NATIVEAPPLIFECYCLEINTERFACEFACTORY_H_ */
