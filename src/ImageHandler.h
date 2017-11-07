//
// Created by Zhancheng Qian on 2017/11/1.
//

#ifndef PROJECT2_IMAGEHANDLER_H
#define PROJECT2_IMAGEHANDLER_H

#include <cstdlib>
#include <GLUT/glut.h>
#include <iostream>

class ImageHandler{
public:
    char * filePath;
    unsigned int dataPos;
    unsigned int width, height;
    unsigned int imageSize;

    ImageHandler(char * input){
        filePath = input;
        imageLoader(filePath);
    }

    void imageLoader (char * filePath){
        FILE * f = fopen(filePath, "rb");
        if (!f) { printf("Image not found\n"); exit(1); }

        if ( fread(header, 1, 54, f)!=54 ){
            printf("Not a correct BMP file\n");
            exit(1);
        }
        if ( header[0]!='B' || header[1]!='M' ){
            printf("Not a correct BMP file\n");
            exit(1);
        }

        dataPos = 	*(int*)&(header[0x0A]);
        imageSize = *(int*)&(header[0x22]);
        width = 	*(int*)&(header[0x12]);
        height = 	*(int*)&(header[0x16]);

        imageSize = width * height * 3;
        if(dataPos==0) dataPos = 54;

        data = (unsigned char *)malloc(imageSize);
        fread(data,1,imageSize,f);
        fclose(f);
    }

    void textureMaker (GLuint *texture){
        glGenTextures(1, &texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    }

private:
    unsigned char header[54];
    unsigned char * data;
};

#endif //PROJECT2_IMAGEHANDLER_H
