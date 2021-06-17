#pragma once

#include "GL/glew.h"
#include <string>
#include <map>
#include <filesystem>

class ShaderLoader{
    std::map<const std::string, GLuint> verShaders;
    std::map<const std::string, GLuint> fragShaders;
    std::string LoadCode(std::filesystem::path);
    GLuint Compile(GLuint, std::string&);

    public:
        void LoadShader(GLuint, std::filesystem::path);
        GLuint getShader(GLuint, std::string);
        //TODO: write a delete shader function
};