#include "ShaderProgram.hpp"
#include <iostream>

ShaderProgram::ShaderProgram(ShaderLoader& sl)
    : shaderLoader{sl}
{
    programID = glCreateProgram();
}

void ShaderProgram::AttachShader(GLuint type, std::string key){
    GLuint shader = shaderLoader.getShader(type, key);
    glAttachShader(programID, shader);
    //TODO: delete shaders
}

void ShaderProgram::LinkAndValidate(){
    glLinkProgram(programID);
    glValidateProgram(programID);
}

void ShaderProgram::AddUniform(std::string key){
    int uniform = glGetUniformLocation(programID, key.c_str());
    if(uniform == -1){
        std::cout << "WARNING! Uniform " << key << " does not exist";
    }
    uniforms[key] = uniform;
    std::cout << "Uniform " << key << " registered\n";
}

void ShaderProgram::SetUniform4f(std::string name, float v0, float v1, float v2, float v3){
    glUniform4f(uniforms[name], v0, v1, v2, v3);
}

void ShaderProgram::SetUniform1i(std::string name, int value){
    glUniform1i(uniforms[name], value);
}

void ShaderProgram::SetUniform1f(std::string name, float value){
    glUniform1f(uniforms[name], value);
}

void ShaderProgram::SetUnifromMatrix4f(std::string name, glm::mat4& value){
    glUniformMatrix4fv(uniforms[name], 1, GL_FALSE, &value[0][0]);
}

void ShaderProgram::Bind(){
    glUseProgram(programID);
}