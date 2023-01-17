# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/ESP32/Espressif/esp-sdk/esp-idf/esp-idf-v4.4.2/components/bootloader/subproject"
  "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader"
  "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader-prefix"
  "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader-prefix/tmp"
  "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader-prefix/src/bootloader-stamp"
  "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader-prefix/src"
  "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Desktop/hanhaohao-watch/esp32_s3_prj/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
