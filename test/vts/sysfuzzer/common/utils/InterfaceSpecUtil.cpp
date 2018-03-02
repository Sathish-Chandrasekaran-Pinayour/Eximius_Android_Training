/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "InterfaceSpecUtil.h"

#include <iostream>
#include <sstream>
#include <string>

#include "test/vts/sysfuzzer/common/proto/InterfaceSpecificationMessage.pb.h"

namespace android {
namespace vts {

string GetFunctionNamePrefix(
    const InterfaceSpecificationMessage& message) {
  std::stringstream prefix_ss;
  prefix_ss << VTS_INTERFACE_SPECIFICATION_FUNCTION_NAME_PREFIX
      << message.component_class() << "_"
      << message.component_type() << "_"
      << message.component_type_version() << "_";
  return prefix_ss.str();
}

}  // namespace vts
}  // namespace android
