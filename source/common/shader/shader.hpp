#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace our {

    class ShaderProgram {

    private:
        //Shader Program Handle (OpenGL object name)
        GLuint program;

    public:
        ShaderProgram(){
            //TODO: (Req 1) Create A shader program
            program = glCreateProgram();
        }
        ~ShaderProgram(){
            //TODO: (Req 1) Delete a shader program
            glDeleteProgram(program);
        }

        bool attach(const std::string &filename, GLenum type) const;

        bool link() const;

        void use() { 
            glUseProgram(program);
        }

        GLuint getUniformLocation(const std::string &name) {
            //TODO: (Req 1) Return the location of the uniform with the given name
            GLuint loc = glGetUniformLocation(program, name.c_str());//returns the location of name in the uniform location
            return loc;
        }

        void set(const std::string &uniform, GLfloat value) {
            //TODO: (Req 1) Send the given float value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniform1f(loc, value);
        }

        void set(const std::string &uniform, GLuint value) {
            //TODO: (Req 1) Send the given unsigned integer value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniform1ui(loc, value);
        }

        void set(const std::string &uniform, GLint value) {
            //TODO: (Req 1) Send the given integer value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniform1i(loc, value);
        }

        void set(const std::string &uniform, glm::vec2 value) {
            //TODO: (Req 1) Send the given 2D vector value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniform2f(loc, value.x, value.y);
        }

        void set(const std::string &uniform, glm::vec3 value) {
            
            //TODO: (Req 1) Send the given 3D vector value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniform3f(loc, value.x, value.y, value.z);
        }

        void set(const std::string &uniform, glm::vec4 value) {
            //TODO: (Req 1) Send the given 4D vector value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniform4f(loc, value.x, value.y, value.z, value.w);
        }

        void set(const std::string &uniform, glm::mat4 matrix) {
            //TODO: (Req 1) Send the given matrix 4x4 value to the given uniform
            GLuint loc = getUniformLocation(uniform);
            glUniformMatrix4fv(loc, 1, false, &matrix[0][0]);
        }

        // TODO: (Req 1) Delete the copy constructor and assignment operator.
        // Question: Why do we delete the copy constructor and assignment operator?
        // it is done so that if the object is destroyed and it was copied elsewhere it will be destroyed as well
        ShaderProgram (const ShaderProgram&) = delete;
        ShaderProgram& operator= (const ShaderProgram&) = delete;
    };
}

#endif