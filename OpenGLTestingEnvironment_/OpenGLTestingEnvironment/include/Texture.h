#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

class Texture2D {
public:
    GLuint ID;
    GLuint width, height;

    GLuint Internal_Format; // Format of texture object
    GLuint Image_Format; // Format of laoded image

    GLuint Wrap_S; // Wrapping mode on the S axis
    GLuint Wrap_T; // Wrapping mode on the T axis
    GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels.
    GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels.

    Texture2D();

    // Generates texture from image data.
    void Generate(GLuint width_, GLuint height_, unsigned char *data);
    // binds texture as current active GL_TEXTURE_2D texture object.
    void Bind() const;
};

#endif //!TEXTURE_H