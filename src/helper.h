[[deprecated]]

#include <cstdlib>
#include <GLUT/glut.h>
#include <cmath>

#define BLUE_COLOR glColor3f(0.3, 0.3, 0.8);
#define BLACK_COLOR glColor3f(0, 0, 0);
#define GRAY_COLOR glColor3f(0.2, 0.2, 0.2);
#define WHITE_COLOR glColor3f(0.8, 0.8, 0.8);
#define RED_COLOR glColor3f(0.863, 0.078, 0.235);
#define YELLO_COLOR glColor3f(1.000, 0.549, 0.000);
#define GREEN_COLOR glColor3f(0.196, 0.804, 0.196);
#define PI 3.14159265

GLfloat calc (GLfloat x){
    return  x * (float) PI / 180.0f;
}

void pushAM() {
    glPushAttrib(GL_CURRENT_BIT);
    glPushMatrix();
}

void popAM() {
    glPopMatrix();
    glPopAttrib();
}

void draw_square(GLfloat size){
    glBegin(GL_POLYGON);
    glNormal3d(0, 0, 1);
    glVertex3f(size/2, size/2, 0);
    glVertex3f(size/2, -size/2, 0);
    glVertex3f(-size/2, -size/2, 0);
    glVertex3f(-size/2, size/2, 0);
    glEnd();
}

void draw_line_square(GLfloat size){
    BLACK_COLOR
    glBegin(GL_LINE_STRIP);
    glVertex3f(size/2, size/2, 0);
    glVertex3f(size/2, -size/2, 0);
    glVertex3f(-size/2, -size/2, 0);
    glVertex3f(-size/2, size/2, 0);
    glVertex3f(size/2, size/2, 0);
    glEnd();
}

void draw_solid_cube(GLfloat size)
{
    pushAM();

    pushAM();
//    glNormal3d(0, 1, 0);
    glTranslatef(0,0,size/2);
    draw_square(size);
    glTranslatef(0,0,-size/2);
    glRotatef(180.0f, 0, 1, 0);
    glTranslatef(0,0,size/2);
    draw_square(size);
    popAM();

    pushAM();
//    glNormal3d(0, -1, 0);
    glRotatef(90.0f, 1, 0, 0);
    glTranslatef(0,0,size/2);
    draw_square(size);
    glTranslatef(0,0,-size/2);
    glRotatef(180.0f, 1, 0, 0);
    glTranslatef(0,0,size/2);
    draw_square(size);
    popAM();

    pushAM();
//    glNormal3d(0, 0, 1);
    glRotatef(90.0f, 0, 1, 0);
    glTranslatef(0,0,size/2);
    draw_square(size);
    glTranslatef(0,0,-size/2);
    glRotatef(180.0f, 0, 1, 0);
    glTranslatef(0,0,size/2);
    draw_square(size);
    popAM();

    BLACK_COLOR
    pushAM();
//    glNormal3d(0, 0, -1);
    glTranslatef(0,0,size/2);
    draw_line_square(size);
    glTranslatef(0,0,-size);
    draw_line_square(size);
    popAM();

    pushAM();
//    glNormal3d(1, 0, 0);
    glRotatef(90.0f, 1, 0, 0);
    glTranslatef(0,0,size/2);
    draw_line_square(size);
    glTranslatef(0,0,-size);
    draw_line_square(size);
    popAM();

    pushAM();
//    glNormal3d(-1, 0, 0);
    glRotatef(90.0f, 0, 1, 0);
    glTranslatef(0,0,size/2);
    draw_line_square(size);
    glTranslatef(0,0,-size);
    draw_line_square(size);
    popAM();

    popAM();
}

void drawEave()
{
    pushAM();
    glScalef(0.1, 1.1, 0.1);
    BLUE_COLOR
    draw_solid_cube(1);
    popAM();
}

void drawSquareEaves()
{
    pushAM();
    glTranslatef(-0.5f, 0, -0.5f);
    drawEave();
    glTranslatef(1, 0, 0);
    drawEave();
    glTranslatef(0, 0, 1);
    drawEave();
    glTranslatef(-1, 0, 0);
    drawEave();
    popAM();
}

void draw_framed_cube()
{
    pushAM();
    WHITE_COLOR
    draw_solid_cube(1);
    drawSquareEaves();
    glRotatef(90.0f, 0.0, 0.0, 1.0);
    drawSquareEaves();
    glRotatef(90.0f, 1.0, 0.0, 0.0);
    drawSquareEaves();
    popAM();
}

void draw_side_strip(GLfloat inner_r, GLfloat outer_r, GLfloat begin, GLfloat end)
{
    BLUE_COLOR
    glBegin(GL_TRIANGLE_STRIP);
    for (float i = begin; i < end; i += 0.01) {
        glVertex3f(cos(i)*inner_r, sin(i)*inner_r, 0.0);
        glVertex3f(cos(i)*outer_r, sin(i)*outer_r, 0.0);
    }
    glEnd();
    BLACK_COLOR
    glBegin(GL_LINE_STRIP);
    for (float i = begin; i < end; i += 0.01)
        glVertex3f((inner_r) * cos(i), (inner_r) * sin(i), 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (float i = begin; i < end; i += 0.01)
        glVertex3f((outer_r) * cos(i), (outer_r) * sin(i), 0.0);
    glEnd();
}

void draw_curved_piece(GLfloat radius, GLfloat z_offset, GLfloat begin, GLfloat end)
{
    BLUE_COLOR
    glBegin(GL_TRIANGLE_STRIP);
    for (float i = begin; i < end; i += 0.01) {
        glVertex3f(cos(i)*radius, sin(i)*radius, 0.0);
        glVertex3f(cos(i)*radius, sin(i)*radius, -z_offset);
    }
    glEnd();
}

void draw_double_caps(GLfloat inner_r, GLfloat outer_r, GLfloat angle, GLfloat z_offset) {
    BLUE_COLOR
    glBegin(GL_POLYGON);
    glVertex3f(cos(angle)*inner_r, sin(angle)*inner_r, 0);
    glVertex3f(cos(angle)*inner_r, sin(angle)*inner_r, -z_offset);
    glVertex3f(cos(angle)*outer_r, sin(angle)*outer_r, -z_offset);
    glVertex3f(cos(angle)*outer_r, sin(angle)*outer_r, 0);
    glEnd();
    BLACK_COLOR
    glBegin(GL_LINE_STRIP);
    glVertex3f(cos(angle)*inner_r, sin(angle)*inner_r, 0);
    glVertex3f(cos(angle)*inner_r, sin(angle)*inner_r, -z_offset);
    glVertex3f(cos(angle)*outer_r, sin(angle)*outer_r, -z_offset);
    glVertex3f(cos(angle)*outer_r, sin(angle)*outer_r, 0);
    glVertex3f(cos(angle)*inner_r, sin(angle)*inner_r, 0);
    glEnd();
}

void draw_solid_curve(GLfloat inner, GLfloat outer, GLfloat thickness, GLfloat begin, GLfloat end)
{
    pushAM();
    draw_side_strip(inner, outer, begin, end);
    draw_curved_piece(inner, thickness, begin, end);
    draw_curved_piece(outer, thickness, begin, end);
    draw_double_caps(inner, outer, begin, thickness);
    draw_double_caps(inner, outer, end, thickness);
    glTranslatef(0, 0, -thickness);
    draw_side_strip(inner, outer, begin, end);
    popAM();
}

void draw_A(){
    pushAM();

    BLUE_COLOR
    glPushMatrix();
    glTranslatef(-0.16f, 0,0);
    glRotatef(-25, 0,0,1);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.16f, 0,0);
    glRotatef(25, 0,0,1);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.2f,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.5, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_B(){
    pushAM();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.095f, 0,0);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, 0.18f,0.06);
    draw_solid_curve(0.11, 0.24, 0.12, calc(-120), calc(120));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.18f,0.06);
    draw_solid_curve(0.13, 0.24, 0.12, calc(-120), calc(120));
    glPopMatrix();

    popAM();
}

void draw_C(){
    pushAM();

    glPushMatrix();
    glTranslatef(0.02f, 0.0f,-0.065f);
    glRotatef(180, 0,1,0);
    glScalef(1.5,1.8,1.5);
    draw_solid_curve(0.17, 0.24, 0.08, calc(-130), calc(130));
    glPopMatrix();

    popAM();
}

void draw_D(){
    pushAM();
    glTranslatef(-0.1f, 0,0);
    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.095f, 0,0);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.08f, 0.0f,0.06);
    glScalef(1.3,1.5,1.2);
    draw_solid_curve(0.18, 0.28, 0.12, calc(-120), calc(120));
    glPopMatrix();

    popAM();
}

void draw_F(){
    pushAM();
    glTranslatef(-0.1f, 0,0);
    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.095f, 0,0);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.15, 0.35,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.6, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.15, 0,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.4, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_E(){
    pushAM();
    glPushMatrix();
    draw_F();
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.15, -0.35f,0);
    glTranslatef(-0.1f, 0,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.6, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_1(){
    pushAM();

    glTranslatef(0.15f, 0,0);
    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.05f, 0,0);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    BLUE_COLOR
    glPushMatrix();
    glTranslatef(-0.2f, 0.25,0);
    glRotatef(-50, 0,0,1);
    glScalef(0.12, 0.3, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_2(){
    pushAM();

    glPushMatrix();
    glTranslatef(0.02f, 0.18f,0.06);
    draw_solid_curve(0.11, 0.24, 0.12, calc(-40), calc(180));
    glPopMatrix();

    BLUE_COLOR
    glPushMatrix();
    glTranslatef(0.04f, -0.1f,0);
    glRotatef(-34.0f, 0,0,1);
    glScalef(0.12, 0.6, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.05, -0.35f,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.45, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_3(){
    pushAM();

    glPushMatrix();
    glTranslatef(0.02f, 0.18f,0.06);
    draw_solid_curve(0.11, 0.24, 0.12, calc(-90), calc(140));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f,0.06);
    draw_solid_curve(0.11, 0.24, 0.12, calc(-160), calc(90));
    glPopMatrix();

    popAM();
}

void draw_4(){
    pushAM();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.23f, 0,0);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    BLUE_COLOR
    glPushMatrix();
    glTranslatef(0.03f, 0.15,0);
    glRotatef(-40, 0,0,1);
    glScalef(0.12, 0.7, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.0, -0.1f,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.4, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_5(){
    pushAM();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.1f, 0.15,0);
    glScalef(0.12, 0.5, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f,0.06);
    draw_solid_curve(0.11, 0.24, 0.12, calc(-160), calc(135));
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.05, 0.35f,0);
    glRotatef(90, 0,0,1);
    glScalef(0.12, 0.4, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_6(){
    pushAM();

    BLUE_COLOR
    glPushMatrix();
    glTranslatef(-0.05f, 0.1,0);
    glRotatef(-30, 0,0,1);
    glScalef(0.12, 0.7, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f,0.06);
    draw_solid_curve(0.17, 0.27, 0.12, calc(0), calc(360));
    glPopMatrix();

    popAM();
}

void draw_7(){
    pushAM();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.05f, 0,0);
    glRotatef(-20, 0,0,1);
    glScalef(0.12, 0.85, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    BLUE_COLOR
    glPushMatrix();
    glTranslatef(0.0f, 0.35,0);
    glRotatef(-90, 0,0,1);
    glScalef(0.12, 0.5, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}

void draw_8(){
    pushAM();

    glPushMatrix();
    glTranslatef(0.02f, 0.2f,0.06);
    draw_solid_curve(0.13, 0.23, 0.12, calc(0), calc(360));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.02f, -0.2f,0.06);
    draw_solid_curve(0.17, 0.27, 0.12, calc(0), calc(360));
    glPopMatrix();

    popAM();
}

void draw_9(){
    pushAM();

    glPushMatrix();
    glRotatef(180, 0,0,1);
    draw_6();
    glPopMatrix();

    popAM();
}

void draw_0(){
    pushAM();

    glPushMatrix();
    glTranslatef(0.0f, 0.15f,0.06);
    draw_solid_curve(0.17, 0.27, 0.12, calc(-0), calc(180));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -0.2f,0.06);
    glRotatef(180, 0,0,1);
    draw_solid_curve(0.17, 0.27, 0.12, calc(-0), calc(180));
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(-0.22f, -0.03f,0);
    glScalef(0.1, 0.4, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    glPushMatrix();
    BLUE_COLOR
    glTranslatef(0.22f, -0.03f,0);
    glScalef(0.1, 0.4, 0.12);
    draw_solid_cube(1);
    glPopMatrix();

    popAM();
}