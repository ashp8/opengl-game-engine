#ifndef OPENGLCPP_G1_SHADER_H
#define OPENGLCPP_G1_SHADER_H

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>

class Shader{
public:
    unsigned int ID;
    Shader(const char *vertexPath, const char *fragmentPath);
    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setMatrix4(const std::string &name, const glm::mat4 &mat) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
