/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include "io/paddle_test_inference_api.h"
namespace paddle_mobile {
template <typename Dtype, Precision P>
double PaddleTester<Dtype, P>::CaculatePredictTime(std::string *cl_path) {
  PaddleMobile<Dtype, P> paddle_mobile;
#ifdef PADDLE_MOBILE_CL
  if (cl_path) {
    paddle_mobile.SetCLPath(*cl_path);
  }

#endif
  return paddle_mobile.GetPredictTime();
}
template class PaddleTester<CPU, Precision::FP32>;
template class PaddleTester<FPGA, Precision::FP32>;
template class PaddleTester<GPU_MALI, Precision::FP32>;

template class PaddleTester<GPU_CL, Precision::FP32>;

}  // namespace paddle_mobile
