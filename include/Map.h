#ifndef MAP_H
#define MAP_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "glut.h"
#include "SOIL.h"

#include "Camera.h"

class Map {
public:
    Map();

    // Stockage des r�f�rences aux textures
    GLuint ListeTextures[20];
    GLuint Skybox[6];
    GLuint Skybox2[6];
    bool useSkybox2 = false; // Bool�en pour alterner entre les deux skyboxes
    void LoadTextures(void);

    void DrawGround(void);

    void DrawSkybox(Camera *cam);

    void SwitchSkybox(); // Nouvelle m�thode pour changer la skybox

    void SwitchTextures();
    int currentTextureIndex = 0; // Indice pour suivre la texture actuelle du bloc

protected:
private:

};

#endif // MAP_H
