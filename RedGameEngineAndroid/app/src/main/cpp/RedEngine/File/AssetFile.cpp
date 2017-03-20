//
// Created by Yuqiao Miao on 21/03/2017.
//

#include "AssetFile.h"

AssetFile::AssetFile(AAssetManager *pAssetManager, string filePath)
{
    this->pAssetManager = pAssetManager;
    this->filePath = filePath;
}

char * AssetFile::ReadTextFile()
{
    AAsset *pAsset = NULL;
    char *pBuffer = NULL;
    off_t size = -1;
    int numByte = -1;

    if (NULL == pAssetManager)
    {
        return NULL;
    }
    pAsset = AAssetManager_open(pAssetManager, this->filePath.c_str(), AASSET_MODE_UNKNOWN);

    size = AAsset_getLength(pAsset);
    pBuffer = (char *)malloc(size+1);
    pBuffer[size] = '\0';

    numByte = AAsset_read(pAsset, pBuffer, size);
    AAsset_close(pAsset);

    LOG_INFO("%s\n",pBuffer);

    return pBuffer;
}