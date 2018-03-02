/*
 * Copyright 2016 The Android Open Source Project
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

#ifndef __VTS_SYSFUZZER_COMMON_FUZZER_WRAPPER_H__
#define __VTS_SYSFUZZER_COMMON_FUZZER_WRAPPER_H__

#include "component_loader/DllLoader.h"
#include "fuzz_tester/FuzzerBase.h"

#include "test/vts/sysfuzzer/common/proto/InterfaceSpecificationMessage.pb.h"


using namespace std;

namespace android {
namespace vts {


// Wrapper used to get the pointer to a FuzzerBase class which provides
// APIs to conduct fuzz testing on a loaded component.
class FuzzerWrapper {
 public:
  explicit FuzzerWrapper();
  virtual ~FuzzerWrapper() {}

  // Loads a given component file.
  bool LoadInterfaceSpecificationLibrary(const char* spec_dll_path);

  // Returns the pointer to a FuzzerBase class of the loaded component where
  // the class is designed to do the testing using the given interface
  // specification message.
  FuzzerBase* GetFuzzer(const vts::InterfaceSpecificationMessage& message);

 private:
  // loaded file path.
  const char* spec_dll_path_;

  // DLL Loader class.
  DllLoader dll_loader_;
};

}  // namespace vts
}  // namespace android

#endif  // __VTS_SYSFUZZER_COMMON_FUZZER_WRAPPER_H__
