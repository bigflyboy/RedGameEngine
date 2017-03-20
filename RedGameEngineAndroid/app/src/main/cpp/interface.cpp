//
// Created by Yuqiao Miao on 20/03/2017.
//

#include <jni.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "RedEngine/Shader/ShaderProgram.h"
#include "RedEngine/Shader/Shader.h"

extern "C"
{

GLuint programId;

JNIEXPORT void JNICALL
Java_com_redknot_tool_NativeMethod_start(JNIEnv *env, jclass type,jobject assetManager) {

// TODO
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glDisable(GL_CULL_FACE);

    glEnable(GL_DEPTH_TEST);

    AAssetManager* g_pAssetManager = AAssetManager_fromJava(env, assetManager);

    Shader *v_shader = new Shader();
    AssetFile v_shader_file(g_pAssetManager, "shader/v_shader.shader");
    v_shader->LoadFromAsset(v_shader_file, GL_VERTEX_SHADER);

    Shader *f_shader = new Shader();
    AssetFile f_shader_file(g_pAssetManager, "shader/f_shader.shader");
    f_shader->LoadFromAsset(f_shader_file, GL_FRAGMENT_SHADER);

    ShaderProgram *shaderProgram = new ShaderProgram();
    shaderProgram->AddShader(v_shader->ShaderId);
    shaderProgram->AddShader(f_shader->ShaderId);
    programId = shaderProgram->ProgramId;

    delete (shaderProgram);
    delete (v_shader);
    delete (f_shader);
}


JNIEXPORT void JNICALL
Java_com_redknot_tool_NativeMethod_update(JNIEnv *env, jclass type) {

// TODO
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(programId);
}


}

