// Copyright (c) 2023 Boston Dynamics AI Institute LLC. All rights reserved.

#pragma once

#include <bosdyn/client/image/image_client.h>
#include <bosdyn/client/sdk/client_sdk.h>
#include <spot_driver_cpp/api/spot_image_sources.hpp>
#include <spot_driver_cpp/api/time_sync_api.hpp>
#include <spot_driver_cpp/interfaces/image_client_interface.hpp>

#include <memory>
#include <string>

namespace spot_ros2 {
/**
 * @brief Implements ImageClientInterface to use the Spot C++ Image Client.
 */
class DefaultImageClient : public ImageClientInterface {
 public:
  DefaultImageClient(::bosdyn::client::ImageClient* image_client, std::shared_ptr<TimeSyncApi> time_sync_api,
                     const std::string& robot_name);
  ~DefaultImageClient() = default;

  tl::expected<GetImagesResult, std::string> getImages(::bosdyn::api::GetImageRequest request) override;

 private:
  ::bosdyn::client::ImageClient* image_client_;
  std::shared_ptr<TimeSyncApi> time_sync_api_;
  std::string robot_name_;
};
}  // namespace spot_ros2
