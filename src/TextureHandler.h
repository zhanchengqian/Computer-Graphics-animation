//
// Created by Zhancheng Qian on 2017/11/2.
//

#ifndef PROJECT2_TEXTURE_H
#define PROJECT2_TEXTURE_H

#include <GLUT/glut.h>
#include <cstdlib>
#include <GLUT/glut.h>
#include "ImageHandler.h"

class TextureHandler {
public:
    int textureCounter;
    TextureHandler(char * filePath){
        textureCounter = 0;
        textureLoader(filePath);
    }

    void textureLoader(char * filePath) {
        ImageHandler imageHandler(filePath);
        imageHandler.textureMaker(textureArr + 0);
        textureCounter++;
    }

    GLuint getTexture (int i) const {
        return textureArr[i];
    }

private:
    GLuint textureArr[10];
};
#endif //PROJECT2_TEXTURE_H
