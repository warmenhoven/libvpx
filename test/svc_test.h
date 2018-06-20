/*
 *  Copyright (c) 2018 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef TEST_SVC_TEST_H_
#define TEST_SVC_TEST_H_

#include "./vpx_config.h"
#include "third_party/googletest/src/include/gtest/gtest.h"
#include "test/codec_factory.h"
#include "test/encode_test_driver.h"
#include "test/i420_video_source.h"
#include "test/util.h"
#include "test/y4m_video_source.h"
#include "vpx/vpx_codec.h"
#include "vpx_ports/bitops.h"

namespace svc_test {
class OnePassCbrSvc : public ::libvpx_test::EncoderTest {
 public:
  explicit OnePassCbrSvc(const ::libvpx_test::CodecFactory *codec)
      : EncoderTest(codec) {}

 protected:
  virtual ~OnePassCbrSvc() {}

  virtual void PreEncodeFrameHookSetup(::libvpx_test::VideoSource *video,
                                       ::libvpx_test::Encoder *encoder);

  virtual void PostEncodeFrameHook(::libvpx_test::Encoder *encoder);

  virtual void AssignLayerBitrates();

  virtual void MismatchHook(const vpx_image_t *, const vpx_image_t *) {}

  vpx_svc_extra_cfg_t svc_params_;
  int64_t bits_in_buffer_model_[VPX_MAX_LAYERS];
  int layer_target_avg_bandwidth_[VPX_MAX_LAYERS];
  int base_speed_setting_;
  int speed_setting_;
  int superframe_count_;
  int temporal_layer_id_;
  int number_temporal_layers_;
  int number_spatial_layers_;
};
}  // namespace svc_test

#endif  // TEST_SVC_TEST_H_
