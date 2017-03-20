//
// Created by Yuqiao Miao on 20/03/2017.
//

#ifndef REDGAMEENGINEANDROID_SHADER_H
#define REDGAMEENGINEANDROID_SHADER_H

#include <GLES3/gl3.h>
#include <string>
#include <vector>
#include <fstream>

#include "../Log/logger.h"
#include "../File/AssetFile.h"

using namespace std;

class Shader {

public:
    GLuint ShaderId;

    Shader();

    void LoadFramFile(string ShaderFilePath, GLenum ShaderType);

    void LoadFramString(string ShaderCode, GLenum ShaderType);

    void LoadFromAsset(AssetFile assetFile, GLenum ShaderType);

private:
    void CompileShader(string ShaderCode, GLenum ShaderType);
    void CompileShader(char const * ShaderCode, GLenum ShaderType);
};


#endif //REDGAMEENGINEANDROID_SHADER_H
