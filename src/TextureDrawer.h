//
// Created by Zhancheng Qian on 2017/11/2.
//

#ifndef PROJECT2_TEXTUREDRAWER_H
#define PROJECT2_TEXTUREDRAWER_H

#include <cstdlib>
#include <GLUT/glut.h>
#include <iostream>
#include "helper.h"

#define pushAM glPushAttrib(GL_CURRENT_BIT); glPushMatrix();
#define popAM glPopMatrix(); glPopAttrib();
#define selectColor switch (i) {\
    case 1:\
        RED_COLOR\
        break;\
    case 2:\
        YELLO_COLOR\
        break;\
    case 3:\
        GREEN_COLOR\
        break;\
    case 4:\
        BLUE_COLOR\
        break;\
    case 5:\
        WHITE_COLOR\
        break;\
    case 6:\
        BLACK_COLOR\
        break;\
}

void cube(GLfloat size) {
    pushAM;
    glTranslatef(0, 0, size / 2);
    draw_square(size);
    glTranslatef(0, 0, -size / 2);
    glRotatef(180.0f, 0, 1, 0);
    glTranslatef(0, 0, size / 2);
    draw_square(size);
    popAM;

    pushAM;
    glRotatef(90.0f, 1, 0, 0);
    glTranslatef(0, 0, size / 2);
    draw_square(size);
    glTranslatef(0, 0, -size / 2);
    glRotatef(180.0f, 1, 0, 0);
    glTranslatef(0, 0, size / 2);
    draw_square(size);
    popAM;

    pushAM;
    glRotatef(90.0f, 0, 1, 0);
    glTranslatef(0, 0, size / 2);
    draw_square(size);
    glTranslatef(0, 0, -size / 2);
    glRotatef(180.0f, 0, 1, 0);
    glTranslatef(0, 0, size / 2);
    draw_square(size);
    popAM;
}

void tx_cube(GLfloat size, GLuint texture) {
    // Top
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size / 2, size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size / 2, size / 2, size / 2);
    glEnd();

    // Bottom
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3d(0, -1, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-size / 2, -size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(size / 2, -size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-size / 2, -size / 2, size / 2);
    glEnd();

    // Front
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3d(0, 0, 1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size / 2, -size / 2, size / 2);
    glEnd();

    // Back
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3d(0, 0, -1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-size / 2, -size / 2, -size / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(size / 2, -size / 2, -size / 2);
    glEnd();

    // Right
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3d(1, 0, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(size / 2, -size / 2, -size / 2);
    glEnd();

    // Left
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glNormal3d(-1, 0, 0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-size / 2, -size / 2, -size / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-size / 2, -size / 2, size / 2);
    glEnd();

    glDisable(GL_BLEND);
}

void tx_Eave(GLfloat size, GLuint texture) {
    pushAM;
    glScalef(0.1, 1.1, 0.1);
    tx_cube(size, texture);
    popAM;
}

void tx_SquareEaves(GLfloat size, GLuint texture) {
    pushAM;
    glTranslatef(-size / 2, 0, -size / 2);
    tx_Eave(size, texture);
    glTranslatef(size, 0, 0);
    tx_Eave(size, texture);
    glTranslatef(0, 0, size);
    tx_Eave(size, texture);
    glTranslatef(-size, 0, 0);
    tx_Eave(size, texture);
    popAM;
}

void tx_framedCube(GLfloat size, GLuint texture_core, GLuint texture_eave) {
    pushAM;
    tx_cube(size, texture_core);
    tx_SquareEaves(size, texture_eave);
    glRotatef(90.0f, 0.0, 0.0, 1.0);
    tx_SquareEaves(size, texture_eave);
    glRotatef(90.0f, 1.0, 0.0, 0.0);
    tx_SquareEaves(size, texture_eave);
    popAM;
}

void tx_sideStrip(GLfloat inner_r, GLfloat outer_r, GLfloat begin, GLfloat end, int sign) {
    glBegin(GL_TRIANGLE_STRIP);
    for (float i = begin; i < end; i += 0.01) {
        glNormal3d(0, 0, 1*sign);
        glVertex3f(cos(i) * inner_r, sin(i) * inner_r, 0.0);
        glVertex3f(cos(i) * outer_r, sin(i) * outer_r, 0.0);
    }
    glEnd();
}

void tx_curvedPiece(GLfloat radius, GLfloat z_offset, GLfloat begin, GLfloat end, int sign) {
    glBegin(GL_TRIANGLE_STRIP);
    for (float i = begin; i < end; i += 0.01) {
        glNormal3d(sign* radius * cos(i), sign* radius * sin(i), 0);
        glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
        glVertex3f(cos(i) * radius, sin(i) * radius, -z_offset);
    }
    glEnd();
}

void tx_doubleCaps(GLfloat inner_r, GLfloat outer_r, GLfloat angle, GLfloat z_offset) {
    glBegin(GL_POLYGON);
    glVertex3f(cos(angle) * inner_r, sin(angle) * inner_r, 0);
    glVertex3f(cos(angle) * inner_r, sin(angle) * inner_r, -z_offset);
    glVertex3f(cos(angle) * outer_r, sin(angle) * outer_r, -z_offset);
    glVertex3f(cos(angle) * outer_r, sin(angle) * outer_r, 0);
    glEnd();
}

void tx_solidCurve(GLfloat inner, GLfloat outer, GLfloat thickness, GLfloat begin, GLfloat end) {
    pushAM;
    tx_sideStrip(inner, outer, begin, end, 1);
    tx_curvedPiece(inner, thickness, begin, end, -1);
    tx_curvedPiece(outer, thickness, begin, end, 1);
    tx_doubleCaps(inner, outer, begin, thickness);
    tx_doubleCaps(inner, outer, end, thickness);
    glTranslatef(0, 0, -thickness);
    tx_sideStrip(inner, outer, begin, end, -1);
    popAM;
}


void tx_A() {
    pushAM;

    RED_COLOR
    glPushMatrix();
    glTranslatef(-0.16f, 0, 0);
    glRotatef(-25, 0, 0, 1);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16f, 0, 0);
    glRotatef(25, 0, 0, 1);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.2f, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.5, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_B() {
    pushAM;

    glPushMatrix();
    YELLO_COLOR
    glTranslatef(-0.095f, 0, 0);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, 0.18f, 0.06);
    tx_solidCurve(0.11, 0.24, 0.12, calc(-120), calc(120));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.18f, 0.06);
    tx_solidCurve(0.13, 0.24, 0.12, calc(-120), calc(120));
    glPopMatrix();

    popAM;
}

void tx_C() {
    pushAM;

    glPushMatrix();
    GREEN_COLOR
    glTranslatef(0.02f, 0.0f, -0.065f);
    glRotatef(180, 0, 1, 0);
    glScalef(1.5, 1.8, 1.5);
    tx_solidCurve(0.17, 0.24, 0.08, calc(-130), calc(130));
    glPopMatrix();

    popAM;
}

void tx_D() {
    pushAM;

    glTranslatef(-0.1f, 0, 0);
    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.095f, 0, 0);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f, 0.06);
    glScalef(1.3, 1.5, 1.2);
    tx_solidCurve(0.18, 0.28, 0.12, calc(-120), calc(120));
    glPopMatrix();

    popAM;
}

void tx_F() {
    pushAM;
    glTranslatef(-0.1f, 0, 0);
    glPushMatrix();
    YELLO_COLOR
    glTranslatef(-0.095f, 0, 0);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.35, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.6, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.4, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_E() {

    pushAM;
    glTranslatef(-0.1f, 0, 0);
    glPushMatrix();
    RED_COLOR
    glTranslatef(-0.095f, 0, 0);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0.35, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.6, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, 0, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.4, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, -0.35f, 0);
    glTranslatef(-0.01f, 0, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.6, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_1(int i) {
    pushAM;
    selectColor(i);
    glTranslatef(0.15f, 0, 0);
    glPushMatrix();

    glTranslatef(-0.05f, 0, 0);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2f, 0.25, 0);
    glRotatef(-50, 0, 0, 1);
    glScalef(0.12, 0.3, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_2(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(0.02f, 0.18f, 0.06);
    tx_solidCurve(0.11, 0.24, 0.12, calc(-40), calc(180));
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.04f, -0.1f, 0);
    glRotatef(-34.0f, 0, 0, 1);
    glScalef(0.12, 0.6, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05, -0.35f, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.45, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_3(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(0.02f, 0.18f, 0.06);
    tx_solidCurve(0.11, 0.24, 0.12, calc(-90), calc(140));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f, 0.06);
    tx_solidCurve(0.11, 0.24, 0.12, calc(-160), calc(90));
    glPopMatrix();

    popAM;
}

void tx_4(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(0.23f, 0, 0);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.03f, 0.15, 0);
    glRotatef(-40, 0, 0, 1);
    glScalef(0.12, 0.7, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.1f, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.4, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_5(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(-0.1f, 0.15, 0);
    glScalef(0.12, 0.5, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f, 0.06);
    tx_solidCurve(0.11, 0.24, 0.12, calc(-160), calc(135));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05, 0.35f, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.12, 0.4, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_6(int i) {
    pushAM;
    selectColor(i);

    glPushMatrix();
    glTranslatef(-0.05f, 0.1, 0);
    glRotatef(-30, 0, 0, 1);
    glScalef(0.12, 0.7, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f, 0.06);
    tx_solidCurve(0.17, 0.27, 0.12, calc(0), calc(360));
    glPopMatrix();

    popAM;
}

void tx_7(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(0.05f, 0, 0);
    glRotatef(-20, 0, 0, 1);
    glScalef(0.12, 0.85, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.35, 0);
    glRotatef(-90, 0, 0, 1);
    glScalef(0.12, 0.5, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}

void tx_8(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(0.02f, 0.2f, 0.06);
    tx_solidCurve(0.13, 0.23, 0.12, calc(0), calc(360));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f, 0.06);
    tx_solidCurve(0.17, 0.27, 0.12, calc(0), calc(360));
    glPopMatrix();

    popAM;
}

void tx_9(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glRotatef(180, 0, 0, 1);
    glPushMatrix();
    glTranslatef(-0.05f, 0.1, 0);
    glRotatef(-30, 0, 0, 1);
    glScalef(0.12, 0.7, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f, 0.06);
    tx_solidCurve(0.17, 0.27, 0.12, calc(0), calc(360));
    glPopMatrix();
    glPopMatrix();

    popAM;
}

void tx_0(int i) {
    pushAM;
    selectColor(i);
    glPushMatrix();

    glTranslatef(0.0f, 0.15f, 0.06);
    tx_solidCurve(0.17, 0.27, 0.12, calc(-0), calc(180));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.06);
    glRotatef(180, 0, 0, 1);
    tx_solidCurve(0.17, 0.27, 0.12, calc(-0), calc(180));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.22f, -0.03f, 0);
    glScalef(0.1, 0.4, 0.12);
    cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.22f, -0.03f, 0);
    glScalef(0.1, 0.4, 0.12);
    cube(1);
    glPopMatrix();

    popAM;
}


#endif //PROJECT2_TEXTUREDRAWER_H

