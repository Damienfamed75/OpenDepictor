#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//#include "Shader.h"
//#include "Texture.h"

class SpriteRenderer {
public:
    //SpriteRenderer(Shader shader);
    SpriteRenderer() {}
    ~SpriteRenderer();
    // Redners a defined quad textured with given sprite.
    //void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10,10), GLfloat rotate = 0.f, glm::vec3 color = glm::vec3(1.f));
private:
    // Render state
    //Shader shader;
    GLuint quadVAO;
    // Initializes and configures quad's buffer & vertex attrib.
    void initRenderData();
};
#endif //!SPRITERENDERER_H