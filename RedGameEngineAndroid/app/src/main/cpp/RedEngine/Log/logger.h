//
// Created by Yuqiao Miao on 21/03/2017.
//

#ifndef REDGAMEENGINEANDROID_LOGGER_H_H
#define REDGAMEENGINEANDROID_LOGGER_H_H

#include <string.h>
#include <android/log.h>

#define LOG_TAG "RedEngine"

#define LOG_INFO(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_ERROR(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#endif //REDGAMEENGINEANDROID_LOGGER_H_H
