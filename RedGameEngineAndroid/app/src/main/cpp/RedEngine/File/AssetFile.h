//
// Created by Yuqiao Miao on 21/03/2017.
//

#ifndef REDGAMEENGINEANDROID_ASSETFILE_H
#define REDGAMEENGINEANDROID_ASSETFILE_H

#include <string>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include "../Log/logger.h"

using namespace std;

class AssetFile {
public:
    AssetFile(AAssetManager *pAssetManager, string filePath);
    char * ReadTextFile();

private:
    AAssetManager *pAssetManager;
    string filePath;
};


#endif //REDGAMEENGINEANDROID_ASSETFILE_H
