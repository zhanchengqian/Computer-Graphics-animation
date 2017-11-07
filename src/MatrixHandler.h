//
// Created by Zhancheng Qian on 2017/11/3.
//

#ifndef PROJECT2_MATRIXHANDLER_H
#define PROJECT2_MATRIXHANDLER_H

#include <GLUT/glut.h>
#include <cstdlib>
#include <GLUT/glut.h>
#include <cstdio>
#include <cmath>

#define PI 3.14159265358979323846264338327950288419
#define N 4

struct MPoint {
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

// This function multiplies mat1[][] and mat2[][],
// and stores the result in res[][]
void mult(GLfloat mat1[N][N], GLfloat mat2[N][N], GLfloat res[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}

void vec_mult(GLfloat mat1[N][N], GLfloat mat2[N][1], GLfloat res[N][1])
{
    int i, j, k;
    for (i=0; i<N; i++)
    {
        for (j=0; j<1; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}

MPoint vec_mult_point(GLfloat mat1[N][N], MPoint light)
{
    GLfloat mat2[N][1] = {{light.x},{light.y},{light.z},{1}};
    GLfloat res[N][1];
    int i, j, k;
    MPoint ret;

    for (i=0; i<N; i++)
    {
        for (j=0; j<1; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
    ret.x = res[0][0];
    ret.y = res[1][0];
    ret.z = res[2][0];
    return ret;
}

void mult2(GLfloat mat1[N][N], GLfloat mat2[N][N])
{
    GLfloat res[N][N];
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            mat1[i][j] = res[i][j];
        }
    }
}

void translate(GLfloat x, GLfloat y, GLfloat z, GLfloat model[N][N])
{
    GLfloat mat [N][N] = { {1, 0, 0, x},
                           {0, 1, 0, y},
                           {0, 0, 1, z},
                           {0, 0, 0, 1}};
    mult2(model, mat);
}

void rotateX(GLfloat angle, GLfloat model[N][N])
{
    GLfloat mat [N][N] = { {1, 0, 0, 0},
                           {0, (GLfloat) cos(angle*PI/180), (GLfloat) -sin(angle*PI/180), 0},
                           {0, (GLfloat) sin(angle*PI/180), (GLfloat) cos(angle*PI/180), 0},
                           {0, 0, 0, 1}};
    mult2(model, mat);
}

void rotateY(GLfloat angle, GLfloat model[N][N])
{
    GLfloat mat [N][N] = { {(GLfloat) cos(angle*PI/180), 0, (GLfloat) sin(angle*PI/180), 0},
                           {0, 1, 0, 0},
                           {(GLfloat) -sin(angle*PI/180), 0, (GLfloat) cos(angle*PI/180), 0},
                           {0, 0, 0, 1}};
    mult2(model, mat);
}

void rotateZ(GLfloat angle, GLfloat model[N][N])
{
    GLfloat mat [N][N] = { {(GLfloat) cos(angle*PI/180), (GLfloat) -sin(angle*PI/180), 0, 0},
                           {(GLfloat) sin(angle*PI/180), (GLfloat) cos(angle*PI/180), 0, 0},
                           {0, 0, 1, 0},
                           {0, 0, 0, 1}};
    mult2(model, mat);
}

void scale(GLfloat x, GLfloat y, GLfloat z, GLfloat model[N][N])
{
    GLfloat mat [N][N] = { {x, 0, 0, 0},
                           {0, y, 0, 0},
                           {0, 0, z, 0},
                           {0, 0, 0, 1}};
    mult2(model, mat);
}

MPoint cast(MPoint l, MPoint p){
    MPoint plane;
    plane.x = (l.y * p.x - l.x * p.y) / (p.y - l.y);
    plane.z = (l.y * p.z - l.z * p.y) / (p.y - l.y);
    plane.y = -0.8;
    return plane;
}

void serialize(GLfloat model[N][N], GLfloat vector[16]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector[j+N*i] = model[i][j];
        }
    }
}

void deserialize(GLfloat vector[16], GLfloat model[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            model[i][j] = vector[j+N*i];
        }
    }
}

void gluInvertMatrix(const GLfloat m[16], GLfloat invOut[16])
{
    double inv[16], det;
    int i;

    inv[0] = m[5]  * m[10] * m[15] -
             m[5]  * m[11] * m[14] -
             m[9]  * m[6]  * m[15] +
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] -
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] +
             m[4]  * m[11] * m[14] +
             m[8]  * m[6]  * m[15] -
             m[8]  * m[7]  * m[14] -
             m[12] * m[6]  * m[11] +
             m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] -
             m[4]  * m[11] * m[13] -
             m[8]  * m[5] * m[15] +
             m[8]  * m[7] * m[13] +
             m[12] * m[5] * m[11] -
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] +
              m[4]  * m[10] * m[13] +
              m[8]  * m[5] * m[14] -
              m[8]  * m[6] * m[13] -
              m[12] * m[5] * m[10] +
              m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] +
             m[1]  * m[11] * m[14] +
             m[9]  * m[2] * m[15] -
             m[9]  * m[3] * m[14] -
             m[13] * m[2] * m[11] +
             m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] -
             m[0]  * m[11] * m[14] -
             m[8]  * m[2] * m[15] +
             m[8]  * m[3] * m[14] +
             m[12] * m[2] * m[11] -
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] +
             m[0]  * m[11] * m[13] +
             m[8]  * m[1] * m[15] -
             m[8]  * m[3] * m[13] -
             m[12] * m[1] * m[11] +
             m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] -
              m[0]  * m[10] * m[13] -
              m[8]  * m[1] * m[14] +
              m[8]  * m[2] * m[13] +
              m[12] * m[1] * m[10] -
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] -
             m[1]  * m[7] * m[14] -
             m[5]  * m[2] * m[15] +
             m[5]  * m[3] * m[14] +
             m[13] * m[2] * m[7] -
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] +
             m[0]  * m[7] * m[14] +
             m[4]  * m[2] * m[15] -
             m[4]  * m[3] * m[14] -
             m[12] * m[2] * m[7] +
             m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] -
              m[0]  * m[7] * m[13] -
              m[4]  * m[1] * m[15] +
              m[4]  * m[3] * m[13] +
              m[12] * m[1] * m[7] -
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] +
              m[0]  * m[6] * m[13] +
              m[4]  * m[1] * m[14] -
              m[4]  * m[2] * m[13] -
              m[12] * m[1] * m[6] +
              m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] +
             m[1] * m[7] * m[10] +
             m[5] * m[2] * m[11] -
             m[5] * m[3] * m[10] -
             m[9] * m[2] * m[7] +
             m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] -
             m[0] * m[7] * m[10] -
             m[4] * m[2] * m[11] +
             m[4] * m[3] * m[10] +
             m[8] * m[2] * m[7] -
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] +
              m[0] * m[7] * m[9] +
              m[4] * m[1] * m[11] -
              m[4] * m[3] * m[9] -
              m[8] * m[1] * m[7] +
              m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] -
              m[0] * m[6] * m[9] -
              m[4] * m[1] * m[10] +
              m[4] * m[2] * m[9] +
              m[8] * m[1] * m[6] -
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det == 0) {
        printf("Determinant equals zero\n");
        exit(1);
    }

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;

}

void copy(GLfloat model[N][N], GLfloat copy[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            copy[i][j] = model[i][j];
    }
}

void invert(GLfloat model[N][N]){
    GLfloat temp[N][N];
    GLfloat vec1[16]; GLfloat vec2[16];
    serialize(model, vec1);
    gluInvertMatrix(vec1, vec2);
    deserialize(vec2, temp);
    copy(temp, model);
}


#endif //PROJECT2_MATRIXHANDLER_H
