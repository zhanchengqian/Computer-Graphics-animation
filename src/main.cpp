#include <cstdlib>
#include <iostream>
#include <GLUT/glut.h>
#include <cmath>
#include "TextureHandler.h"
#include "TextureDrawer.h"
#include "MatrixHandler.h"

using namespace std;

GLfloat eyeX = 0.0f, eyeY = 0.0f, eyeZ = 20.0f;
GLfloat angleX = 15.0f, angleY = 0.0f, angleZ = 0.0f;
GLfloat angleXInc = 15.0f, angleYInc = 15.0f;
GLfloat cubeRotate = 0.5f, cubeRotateInc = 0.35f;//cubeRotateInc = 0.7f;
GLfloat numMove = -1.2f, numMoveInc = 0.02f;
GLfloat AmbConfig[] = {0.1, 0.1, 0.1, 1.0};
GLfloat DffConfig[] = {0.8, 0.8, 0.8, 1.0};
GLfloat SpcConfig[] = {0.5, 0.5, 0.5, 1.0};
GLfloat ShnConfig[] = {50};
GLfloat LightConfig[] = {0.0, 20.0, 20.0, 0.0};
GLuint texture_core, texture_eave;
bool animate = true, down;
double mx, my;

#define AMP 1.5 // movement amplification

static void myShadowMatrix(float ground[4], float light[4]) {
    float dot;
    float shadowMat[4][4];

    dot = ground[0] * light[0] +
          ground[1] * light[1] +
          ground[2] * light[2] +
          ground[3] * light[3];

    shadowMat[0][0] = dot - light[0] * ground[0];
    shadowMat[1][0] = 0.0 - light[0] * ground[1];
    shadowMat[2][0] = 0.0 - light[0] * ground[2];
    shadowMat[3][0] = 0.0 - light[0] * ground[3];

    shadowMat[0][1] = 0.0 - light[1] * ground[0];
    shadowMat[1][1] = dot - light[1] * ground[1];
    shadowMat[2][1] = 0.0 - light[1] * ground[2];
    shadowMat[3][1] = 0.0 - light[1] * ground[3];

    shadowMat[0][2] = 0.0 - light[2] * ground[0];
    shadowMat[1][2] = 0.0 - light[2] * ground[1];
    shadowMat[2][2] = dot - light[2] * ground[2];
    shadowMat[3][2] = 0.0 - light[2] * ground[3];

    shadowMat[0][3] = 0.0 - light[3] * ground[0];
    shadowMat[1][3] = 0.0 - light[3] * ground[1];
    shadowMat[2][3] = 0.0 - light[3] * ground[2];
    shadowMat[3][3] = dot - light[3] * ground[3];

    glMultMatrixf((const GLfloat *) shadowMat);
}

static float groundPlane[4] =
        {0.0, 1.0, 0.0, 1.499};

static float lightPos[4] =
        {0.0, 20.0, 50.0, 1.0};

void output(int x, int y, float r, float g, float b, void * font, char *string)
{
    glColor3f( r, g, b );
    glWindowPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void display() {

    GLfloat modelView01[4][4];
    GLfloat modelView02[4][4];
    GLfloat modelView03[4][4];
    GLfloat modelView04[4][4];
    GLfloat modelView05[4][4];

    GLfloat modelView06[4][4];
    GLfloat modelView07[4][4];
    GLfloat modelView08[4][4];
    GLfloat modelView09[4][4];
    GLfloat modelView10[4][4];
    GLfloat modelView11[4][4];
    GLfloat modelView12[4][4];
    GLfloat modelView13[4][4];
    GLfloat modelView14[4][4];
    GLfloat modelView15[4][4];
    GLfloat modelView16[4][4];

    GLfloat viewMatrix[4][4];

    glClear(GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, 0.0, 3.5, -15.0, 0.0, 1.0, 0.0);

    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);

    pushAM
    char * s1 = const_cast<char *>("Zhancheng Qian | CS180 | Project2 | Fall 2017\n");
    char * s2 = const_cast<char *>("How to use: WASD keys or mouse-drag for changing view, Q for Quit, E for Animation\n");

    output (50,60,0,0,0,GLUT_BITMAP_HELVETICA_18,s1);
    output (50,40,0,0,0,GLUT_BITMAP_HELVETICA_18,s2);
    popAM

    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) viewMatrix);
    invert(viewMatrix);

    TextureHandler textureHandler((char *) "../texture/wood.bmp");
    texture_core = textureHandler.getTexture(0);
    texture_eave = textureHandler.getTexture(0);
    //pushAM

//    glEnable(GL_TEXTURE_2D);
//    pushAM
//    glTranslatef(0,3,8);
    //tx_framedCube(3, textureHandler.getTexture(0), textureHandler.getTexture(0));
    //tx_solidCurve(0.11, 0.24, 0.12, calc(-120), calc(120));
//    popAM
//    glDisable(GL_TEXTURE_2D);

    pushAM
    glTranslatef(-6.5f, 1, 4);
    glRotatef(15, 0, 1, 0);
    glRotatef(cubeRotate, 0, 1, 0);
    glScalef(2, 2, 2);
    glEnable(GL_TEXTURE_2D);
    WHITE_COLOR
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView01);
    mult2(modelView01, viewMatrix);
    tx_framedCube(1, texture_core, texture_eave);
    glDisable(GL_TEXTURE_2D);

    pushAM
    glTranslatef(0, 0, 0.5);
    tx_A();
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_B();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    tx_2(1);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_3(3);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 1, 0, 0);
    glRotatef(270, 0, 0, 1);
    glTranslatef(0, 0, 0.5);
    tx_9(2);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_D();
    glRotatef(180, 0, 1, 0);
    popAM
    popAM

    pushAM
    glTranslatef(-2, 1, 2);
    glRotatef(-10, 0, 1, 0);
    glRotatef(-cubeRotate, 0, 1, 0);
    glScalef(2, 2, 2);
    glEnable(GL_TEXTURE_2D);
    WHITE_COLOR
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView02);
    mult2(modelView02, viewMatrix);
    tx_framedCube(1, texture_core, texture_eave);
    glDisable(GL_TEXTURE_2D);
    glTranslatef(0, 0, 0.5);
    pushAM
    tx_E();
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_F();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    tx_5(3);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_1(2);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 1, 0, 0);
    glRotatef(270, 0, 0, 1);
    glTranslatef(0, 0, 0.5);
    tx_8(1);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_F();
    glRotatef(180, 0, 1, 0);
    popAM
    popAM

    pushAM
    glTranslatef(2, 1, 2.5);
    glRotatef(15, 0, 1, 0);
    glRotatef(cubeRotate, 0, 1, 0);
    glScalef(2, 2, 2);
    glEnable(GL_TEXTURE_2D);
    WHITE_COLOR
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView03);
    mult2(modelView03, viewMatrix);
    tx_framedCube(1, texture_core, texture_eave);
    glDisable(GL_TEXTURE_2D);
    glTranslatef(0, 0, 0.5);
    pushAM
    tx_8(4);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_3(2);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    pushAM
    glRotatef(180, 0, 1, 0);
    glRotatef(180, 0, 0, 1);
    tx_C();
    popAM
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_B();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 1, 0, 0);
    glRotatef(270, 0, 0, 1);
    glTranslatef(0, 0, 0.5);
    tx_9(3);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_7(1);
    glRotatef(180, 0, 1, 0);
    popAM
    popAM

    pushAM
    glTranslatef(6.5, 1, 3.5);
    glRotatef(-35, 0, 1, 0);
    glRotatef(-cubeRotate, 0, 1, 0);
    glScalef(2, 2, 2);
    glEnable(GL_TEXTURE_2D);
    WHITE_COLOR
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView04);
    mult2(modelView04, viewMatrix);
    tx_framedCube(1, texture_core, texture_eave);
    glDisable(GL_TEXTURE_2D);
    glTranslatef(0, 0, 0.5);
    pushAM
    tx_6(3);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_1(1);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    tx_B();
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_8(1);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 1, 0, 0);
    glRotatef(270, 0, 0, 1);
    glTranslatef(0, 0, 0.5);
    tx_1(2);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_9(4);
    glRotatef(180, 0, 1, 0);
    popAM
    popAM

    pushAM
    glTranslatef(0, 1, 7);
    glRotatef(-35, 0, 1, 0);
    glRotatef(cubeRotate, 0, 1, 0);
    glScalef(2, 2, 2);
    glEnable(GL_TEXTURE_2D);
    WHITE_COLOR
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView05);
    mult2(modelView05, viewMatrix);
    tx_framedCube(1, texture_core, texture_eave);
    glDisable(GL_TEXTURE_2D);
    glTranslatef(0, 0, 0.5);
    pushAM
    tx_1(4);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_1(1);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    tx_2(2);
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_9(3);
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 0.5);
    glRotatef(90, 1, 0, 0);
    glRotatef(270, 0, 0, 1);
    glTranslatef(0, 0, 0.5);
    tx_D();
    glTranslatef(0, 0, -1);
    glRotatef(180, 0, 1, 0);
    tx_A();
    glRotatef(180, 0, 1, 0);
    popAM
    popAM

    pushAM
    glScalef(3, 3, 3);
    glTranslatef(-5, 0.5, -3.5f);
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(1)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(1)));
//
    pushAM
    glTranslatef(0, static_cast<GLfloat> ((GLfloat) AMP * sin(numMove)), 0);
    glTranslatef(0, 0, static_cast<GLfloat> ((GLfloat) AMP * cos(numMove)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView06);
    mult2(modelView06, viewMatrix);
    tx_0(4);
    popAM
//
    glTranslatef(1, 0, 0);

    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 0.2)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 0.2)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView07);
    mult2(modelView07, viewMatrix);
    tx_1(3);
    popAM

    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 0.4)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 0.4)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView08);
    mult2(modelView08, viewMatrix);
    tx_2(4);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 0.6)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 0.6)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView09);
    mult2(modelView09, viewMatrix);
    tx_3(1);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 0.8)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 0.8)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView10);
    mult2(modelView10, viewMatrix);
    tx_4(2);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 1)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 1)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView11);
    mult2(modelView11, viewMatrix);
    tx_5(3);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 1.2)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 1.2)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView12);
    mult2(modelView12, viewMatrix);
    tx_6(4);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 1.4)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 1.4)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView13);
    mult2(modelView13, viewMatrix);
    tx_7(1);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 1.6)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 1.6)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView14);
    mult2(modelView14, viewMatrix);
    tx_8(2);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 1.8)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 1.8)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView15);
    mult2(modelView15, viewMatrix);
    tx_9(3);
    popAM
//
    glTranslatef(1, 0, 0);
//
    pushAM
    glTranslatef(0, static_cast<GLfloat>((GLfloat) AMP * sin(numMove + 2)), 0);
    glTranslatef(0, 0, static_cast<GLfloat>((GLfloat) AMP * cos(numMove + 2)));
    glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) modelView16);
    mult2(modelView16, viewMatrix);
    tx_0(4);
    popAM
//
    popAM


    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView01);
    BLACK_COLOR
    tx_framedCube(1, texture_core, texture_eave);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView02);
    BLACK_COLOR
    tx_framedCube(1, texture_core, texture_eave);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView03);
    BLACK_COLOR
    tx_framedCube(1, texture_core, texture_eave);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView04);
    BLACK_COLOR
    tx_framedCube(1, texture_core, texture_eave);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView05);
    BLACK_COLOR
    tx_framedCube(1, texture_core, texture_eave);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView06);
    tx_0(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView07);
    tx_1(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView08);
    tx_2(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView09);
    tx_3(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView10);
    tx_4(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView11);
    tx_5(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView12);
    tx_6(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView13);
    tx_7(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView14);
    tx_8(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView15);
    tx_9(6);
    popAM
    glPopAttrib();

    pushAM
    glPushAttrib(GL_CURRENT_BIT);
    myShadowMatrix(groundPlane, lightPos);
    glTranslatef(0.0, 0.0, 2.0);
    glMultMatrixf((const GLfloat *) modelView16);
    tx_0(6);
    popAM
    glPopAttrib();

    int cube_size = 350;
    glTranslatef(0, -cube_size / 2 - 2, 0);
    glColor3f(0.65, 0.65, 0.65);
    cube(cube_size);

////     draws horizontal grid
//#define HALF_GRID_SIZE 50
//    glDisable(GL_LINE_SMOOTH);
//    glBegin(GL_LINES);
//    glColor3f(0.35f, 0.35f, 0.35f);
//    for (int i = -HALF_GRID_SIZE; i <= HALF_GRID_SIZE; i++) {
//        glVertex3f((float) i, 0, (float) -HALF_GRID_SIZE);
//        glVertex3f((float) i, 0, (float) HALF_GRID_SIZE);
//        glVertex3f((float) -HALF_GRID_SIZE, 0, (float) i);
//        glVertex3f((float) HALF_GRID_SIZE, 0, (float) i);
//    }
//    glEnd();
//    glEnable(GL_LINE_SMOOTH);

    if (animate) {
        cubeRotate += cubeRotateInc;
        numMove += numMoveInc;
    }

    glutSwapBuffers();
}

void initialize(int x, int y) {
    if (y == 0)
        y = 1;
    GLfloat ratio = (float) x / y;

    glClearColor(0.4f, 0.4f, 0.4f, 0.5f);
    glClearDepth(1.0f);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);

    glLightfv(GL_LIGHT0, GL_POSITION, LightConfig);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, AmbConfig);
    glMaterialfv(GL_FRONT, GL_SPECULAR, SpcConfig);
    glMaterialfv(GL_FRONT, GL_SHININESS, ShnConfig);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, DffConfig);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55.0f, ratio, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}

void reshape(int x, int y) {
    if (y == 0)
        y = 1;
    GLfloat ratio = (float) x / y;
    glViewport(0, 0, x, y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(55.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angleY += angleYInc;
            break;
        case 'd':
            angleY -= angleYInc;
            break;
        case 'w':
            angleX += angleXInc;
            break;
        case 's':
            angleX -= angleXInc;
            break;
        case '.':
            eyeZ -= 2;
            break;
        case ',':
            eyeZ += 2;
            break;
        case 'q':
            exit(0);
        case 'e':
            animate = !animate;
            break;
        default:
            cout << "Invalid input\n";
            break;
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        down = (state == GLUT_DOWN);
        mx = x;
        my = y;
    }
}

void motion(int x, int y) {
    if (down) {
        angleY += -(mx - x) / 10;
        angleX += -(my - y) / 10;
        mx = x;
        my = y;
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Title");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    initialize(640, 480);
    glutMainLoop();
    return 0;
}

