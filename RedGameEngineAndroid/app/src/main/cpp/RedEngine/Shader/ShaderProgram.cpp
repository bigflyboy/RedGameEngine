//
// Created by Yuqiao Miao on 20/03/2017.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
    ProgramId = glCreateProgram();
}

void ShaderProgram::AddShader(GLuint shader) {
    shaderList.push_back(shader);
}

void ShaderProgram::LinkProgram() {
    vector<GLuint>::iterator it;
    for (it = shaderList.begin(); it != shaderList.end(); it++) {
        GLuint shader = *it;
        glAttachShader(ProgramId, shader);
    }
    glLinkProgram(ProgramId);
    GLint Result = GL_FALSE;
    int InfoLogLength;
    // Check the program
    glGetProgramiv(ProgramId, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(ProgramId, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        LOG_ERROR("%s\n",&ProgramErrorMessage[0]);
    }
    vector<GLuint>::iterator it_detach;
    for (it_detach = shaderList.begin(); it_detach != shaderList.end(); it_detach++) {
        GLuint shader = *it_detach;
        glDetachShader(ProgramId, shader);
        glDeleteShader(shader);
    }
}