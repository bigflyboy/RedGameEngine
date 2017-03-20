//
// Created by Yuqiao Miao on 20/03/2017.
//

#ifndef REDGAMEENGINEANDROID_SHADERPROGRAM_H
#define REDGAMEENGINEANDROID_SHADERPROGRAM_H

#include <stdio.h>
#include <GLES3/gl3.h>
#include <vector>

#include "../Log/logger.h"

using namespace std;

class ShaderProgram {
public:
    GLuint ProgramId;
    vector<GLuint> shaderList;

    ShaderProgram();
    void AddShader(GLuint shader);
    void LinkProgram();
};


#endif //REDGAMEENGINEANDROID_SHADERPROGRAM_H
