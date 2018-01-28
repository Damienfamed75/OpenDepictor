#ifndef TEXTURE_H
#define TEXTURE_H

#ifndef __gladh_h_
    #include <glad/glad.h>
#endif //!__glad_h_

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include "stb_image.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Texture {
public:
    unsigned int ID;
    /// constructor generates the texture on the fly
    /// --------------------------------------------
    Texture(const char *texturePath) {

        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;

        unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
        if(data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

    }
};

#endif //!TEXTURE_H