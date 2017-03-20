//
// Created by Yuqiao Miao on 20/03/2017.
//

#include "Shader.h"

Shader::Shader() {
}

void Shader::LoadFramFile(string ShaderFilePath, GLenum ShaderType) {
    this->ShaderId = glCreateShader(ShaderType);

    string ShaderCode;
    ifstream ShaderStream(ShaderFilePath, ios::in);
    if (ShaderStream.is_open()) {
        string Line = "";
        while (getline(ShaderStream, Line)) {
            ShaderCode += "\n" + Line;
        }
        ShaderStream.close();
    } else {
        printf("Impossible to open %s.\n", ShaderFilePath.c_str());
        getchar();
        return;
    }

    CompileShader(ShaderCode, ShaderType);
}

void Shader::LoadFramString(string ShaderCode, GLenum ShaderType) {
    this->ShaderId = glCreateShader(ShaderType);
    CompileShader(ShaderCode, ShaderType);
}

/**Android**/
void Shader::LoadFromAsset(AssetFile assetFile, GLenum ShaderType) {
    this->ShaderId = glCreateShader(ShaderType);
    char const *ShaderCode = assetFile.ReadTextFile();
    CompileShader(ShaderCode, ShaderType);
}
/**Android**/

void Shader::CompileShader(char const *ShaderCode, GLenum ShaderType) {
    glShaderSource(this->ShaderId, 1, &ShaderCode, NULL);
    glCompileShader(this->ShaderId);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetShaderiv(this->ShaderId, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(this->ShaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0) {
        vector<char> ShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(this->ShaderId, InfoLogLength, NULL, &ShaderErrorMessage[0]);
        LOG_ERROR("%s\n",&ShaderErrorMessage[0]);
    }
}

void Shader::CompileShader(string ShaderCode, GLenum ShaderType) {
    char const *SourcePointer = ShaderCode.c_str();
    glShaderSource(this->ShaderId, 1, &SourcePointer, NULL);
    glCompileShader(this->ShaderId);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetShaderiv(this->ShaderId, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(this->ShaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0) {
        vector<char> ShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(this->ShaderId, InfoLogLength, NULL, &ShaderErrorMessage[0]);
        LOG_ERROR("%s\n",&ShaderErrorMessage[0]);
    }
}