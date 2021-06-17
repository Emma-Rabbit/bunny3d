#include "GL/glew.h"
#pragma once

#include <map>
#include <string>
#include "ShaderLoader.hpp"
#include <glm/glm.hpp>

class ShaderProgram{
    GLuint programID;
    ShaderLoader& shaderLoader;
    std::map<std::string, int> uniforms;
    //IDEA: attach shaders and link program in constructor

    public:
        ShaderProgram(ShaderLoader&);
        void AttachShader(GLuint, std::string);
        void LinkAndValidate();
        void Bind();
        void AddUniform(std::string);
        void SetUniform4f(std::string, float, float, float, float);
        void SetUniform1i(std::string, int);
        void SetUniform1f(std::string, float);
        void SetUnifromMatrix4f(std::string, glm::mat4&);
};