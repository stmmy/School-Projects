//Matthew Stamm Project 3
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include<stdbool.h>

#ifndef M_PI
#define M_PI 3.14159
#endif

//GLOBALS
/*----------------------------------------------------------------------*/

GLfloat svertices[][3] = {
    //front square
    {-0.5, -0.2, 0.9},
    {-0.5, 0.7, 0.9},
    {0.5, 0.7, 0.9},
    {0.5, -0.2, 0.9}, // ind 3
    //back square
    {-0.5, -0.2, -0.9},
    {-0.5, 0.7, -0.9},
    {0.5, 0.7, -0.9},
    {0.5, -0.2, -0.9}, //ind 7
    //engine front
    {-0.5, -0.2, 1.3},
    {-0.5, 0.3, 1.3},
    {0.5, -0.2, 1.3},
    {0.5, 0.3, 1.3}, //ind 11
    {-0.5, 0.3, 0.9}, //midpoint sq 1
    {0.5, 0.3, 0.9}, //midpoint sq 2

    //leftside vertices 1 (fill rec below window)
    {-.5, -.2, .4}, //ind 14
    {-.5, -.2, -.9},
    {-.5, .3, -.9},
    {-.5, .3, .4},
    //leftside vertices 2 (small rec between door and window)
    {-.5, .3, .5},//ind 18
    {-.5, .3, .4},
    {-.5, .6, .4},
    {-.5, .6, .5},
    //leftside vertices 3 (small rec between window and end of bus)
    {-.5, .3, -.8},//ind 22
    {-.5, .3, -.9},
    {-.5, .6, -.9},
    {-.5, .6, -.8},
    //lefstide vertcies 4 (skinn rec on top)
    {-.5, .6, .9},//ind 26
    {-.5, .6, -.9},
    {-.5, .7, -.9},
    {-.5, .7, .9},
    //leftside vertices 5 (skinny rec on right)
    {-.5, -.2, .9},//ind 30
    {-.5, -.2, .8},
    {-.5, .7, .8},
    {-.5, .7, .9},
    //door
    {-.49, -.2, .8}, //ind 34
    {-.49, -.2, .4},
    {-.49, .6, .4},
    {-.49, .6, .8},
    //leftwindow
    {-.49, .3, .4},//ind 38
    {-.49, .3, -.8},
    {-.49, .6, -.8},
    {-.49, .6, .4},
    //rightwindow
    {.49, .3, .6},//ind 42
    {.49, .3, -.8},
    {.49, .6, -.8},
    {.49, .6, .6},
    //rightside 1 (bottom rec)
    {.5, -.2, .9},//ind 46
    {.5, -.2, -.9},
    {.5, .3, -.9},
    {.5, .3, .9},
    //rightside 2 (left rec)
    {.5, .3, .9},//ind 50
    {.5, .3, .6},
    {.5, .6, .6},
    {.5, .6, .9},
    //rightside 3 (right rec)
    {.5, .3, -.8},//ind 54
    {.5, .3, -.9},
    {.5, .7, -.9},
    {.5, .7, -.8},
    //rightside 4 (top rec)
    {.5, .6, .9},//ind 58
    {.5, .6, -.9},
    {.5, .7, -.9},
    {.5, .7, .9},

    //wheel 1
    {.51, -.3, -.5}, //62
    {.51, -.3, -.8},
    {.51, 0, -.8},
    {.51, 0, -.5},
    //wheel 2
    {.51, -.3, 1.2}, //66
    {.51, -.3, .9},
    {.51, 0, .9},
    {.51, 0, 1.2},
    //wheel 3
    {-.51, -.3, -.5}, //70
    {-.51, -.3, -.8},
    {-.51, 0, -.8},
    {-.51, 0, -.5},
    //wheel 4
    {-.51, -.3, 1.2}, //74
    {-.51, -.3, .9},
    {-.51, 0, .9},
    {-.51, 0, 1.2},
    //back window
    {-.3, .3, -.91}, // 78
    {-.3, .6, -.91},
    {.3, .6, -.91},
    {.3, .3, -.91},


    //rightside 5 (window divider)
    {.5, .3, .3}, //82
    {.5, .3, .2},
    {.5, .6, .2},
    {.5, .6, .3},

    //rightside 6 (wd 2)
    {.5, .3, -0.1}, //86
    {.5, .3, -0.2},
    {.5, .6, -0.2},
    {.5, .6, -0.1},

    //rightside 7 (wd 2)
    {.5, .3, -0.5}, //90
    {.5, .3, -0.6},
    {.5, .6, -0.6},
    {.5, .6, -0.5},

    //leftside (window divider)
    {-.5, .3, .4}, //94
    {-.5, .3, .3},
    {-.5, .6, .3},
    {-.5, .6, .4},

    //leftside (wd 2)
    {-.5, .3, 0}, //98
    {-.5, .3, -0.1},
    {-.5, .6, -0.1},
    {-.5, .6, 0},

    //leftside 7 (wd 2)
    {-.5, .3, -0.4}, //102
    {-.5, .3, -0.5},
    {-.5, .6, -0.5},
    {-.5, .6, -0.4},

    //left door frame
    {-.5, -.2, .4}, //106
    {-.5, -.2, .45},
    {-.5, .6, .45},
    {-.5, .6, .4},

    {-.5, -.2, .75}, //110
    {-.5, -.2, .8},
    {-.5, .6, .8},
    {-.5, .6, .75},

    {-.5, -.2, .8}, //114
    {-.5, -.2, .4},
    {-.5, -.15, .4},
    {-.5, -.15, .8},

    {-.5, .6, .8}, //118
    {-.5, .6, .4},
    {-.5, .55, .4},
    {-.5, .55, .8},

    {-.5, .6, .63}, //122
    {-.5, .6, .58},
    {-.5, -.2, .58},
    {-.5, -.2, .63},

    {-.3, .70009, -.8}, //126 back window
    {.3, .70009, -.8},
    {.3, .70009, -.2},
    {-.3, .70009, -.2},

    {-.3, .3, -.90009}, //130
    {-.3, .6, -.90009},
    {.3, .6, -.90009},
    {.3, .3, -.90009},

    {-.50009, -.1, -.9},//134
    {-.50009, 0, -.9},
    {-.50009, 0, .3},
    {-.50009, -.1, .3},

    {-.50009, .1, -.9},//138
    {-.50009, .2, -.9},
    {-.50009, .2, .3},
    {-.50009, .1, .3},

    {.50009, -.1, -.9},//138
    {.50009, 0, -.9},
    {.50009, 0, .7},
    {.50009, -.1, .7},

    {.50009, .1, -.9},//142
    {.50009, .2, -.9},
    {.50009, .2, .7},
    {.50009, .1, .7},

    {-.3, -.1, 1.30009},//146
    {-.3, .1, 1.30009},
    {.3, .1, 1.30009},
    {.3, -.1, 1.30009},

    //rightside window 1
    {0.5, .6, .6},
    {0.5, .6, .3},
    {0.5, .3, .3},
    { 0.5, .3, .6},

    //rightside window 2
    { 0.5, .6, .2 },
    { 0.5, .6, -.1 },
    { 0.5, .3, -.1 },
    { 0.5, .3, .2 },
    //rightside window 2
    { 0.5, .6, -.2 },
    { 0.5, .6, -.5 },
    { 0.5, .3, -.5 },
    { 0.5, .3, -.2 },
    //rightside window 2
    { 0.5, .6, -.6 },
    { 0.5, .6, -.8 },
    { 0.5, .3, -.8 },
    { 0.5, .3, -.6 },

    //leftisde window 1
    {-0.5, .3, .3},
    { -0.5, .3, 0.0 },
    { -0.5, .6, 0.0 },
    { -0.5, .6, .3 },
    //leftside window 2
    { -0.5, .3, -0.1 },
    { -0.5, .3, -0.4 },
    { -0.5, .6, -0.4 },
    { -0.5, .6, -0.1 },
    //leftside window 3
    { -0.5, 0.3, -0.5 },
    { -0.5, 0.3, -0.8 },
    { -0.5, 0.6, -0.8 },
    { -0.5, 0.6, -0.5 },
};

//materials vars
typedef struct material {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
} material;

material yellowMat = {
    {1.0, 1.0, 0.0, 1.0},
    {1.0, 1.0, 0.0, 1.0},
    {0.99, 0.91, 0.81, 1.0},
    27.5
};
material blueMat = {
    { 0.157, 0.69, 0.831, 0.5},
    { 0.157, 0.69, 0.831, 0.5},
    {0.99, 0.91, 0.81, 0.5},
    27.5
};
material blackMat = {
    {0.0, 0.0, 0.0, 1.0},
    {0.0, 0.0, 0.0, 1.0},
    {0, 0, 0, 1.0},
    27.5
};
material grayMat = {
    {0.5, 0.5, 0.5, 1.0},
    {0.5, 0.5, 0.5, 1.0},
    {0, 0, 0, 1.0},
    27.5
};

material* currentMaterials;

//spotlight vars
GLfloat lighPos[] = { -2.0f, 2.0f, 2.0f, 1.0f }; //spotlight pos
GLfloat lightDir[] = { 1.0f, -1.0f, -1.0f }; //spotlight direction vector
GLfloat spotCut = 90; //spotlight angle
GLfloat spotExp = 10.0f; //spotlight exponent

GLfloat AmbLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat DiffLight[] = { 0.6f, 0.6f, 0.6f, 1.0f };
GLfloat SpecLight[] = { .5f, .5f, .5f, 1.0f };  

//normals
GLfloat normals[][3] = {
    {0.0, 0.0, 1.0}, //0 front
    {0.0, 1.0, 0.0}, //1 up
    {-1.0, 0.0, 0.0}, //2 left
    {1.0, 0.0, 0.0}, //3 right
    {0.0, 0.0, -1.0}, //4 back
    {0.0, -1.0, 0.0} //5 down
};

//camera pos globals
bool flipNormals = false;

float lx, ly, lz, ux, uy, uz;
float ex = 0;
float ey = 0;
float ez = 0;

bool z = false;
bool zz = false;
bool i = true;
bool ii = false;
bool t = false;
bool u = false;
bool b = false;
bool f = false;
bool l = false;
bool r = false;

//light pos globals
bool light_l = false;
bool light_r = false;
bool light_b = false;
bool light_i = false;
bool light_il = false;

//DRAWING FUNCTIONS
/*----------------------------------------------------------------------*/
void wheel(float x, float y, float z, float r, float height, int s) {
    glPushMatrix();

    glTranslatef(x, y, z);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0, 0, 0);
    currentMaterials = &blackMat;
    glMaterialfv(GL_FRONT, GL_AMBIENT, currentMaterials->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, currentMaterials->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, currentMaterials->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, currentMaterials->shininess);


    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= s; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)s;
        float x = r * cos(theta);
        float z = r * sin(theta);

        glVertex3f(x, height / 2.0f, z);
        glVertex3f(x, -height / 2.0f, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= s; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)s;
        float x = r * cos(theta);
        float z = r * sin(theta);

        glVertex3f(x, height / 2.0f, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= s; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)s;
        float x = r * cos(theta);
        float z = r * sin(theta);

        glVertex3f(x, -height / 2.0f, z);
    }
    glEnd();

    glPopMatrix();
}

void square(int a, int b, int c, int d, float r, float g, float bb, int normalInd, int color) {

    if (color == 0) { currentMaterials = &blackMat; }
    else if (color == 1) { currentMaterials = &yellowMat; }
    else if (color == 2) { currentMaterials = &blueMat; }
    else if (color == 3) { currentMaterials = &grayMat; }
    glMaterialfv(GL_FRONT, GL_AMBIENT, currentMaterials->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, currentMaterials->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, currentMaterials->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, currentMaterials->shininess);

    if (normalInd == 0) {
        if (flipNormals == true) { glNormal3fv(normals[4]); }
        else { glNormal3fv(normals[0]); }
    }
    if (normalInd == 1) {
        if (flipNormals == true) { glNormal3fv(normals[5]); }
        else { glNormal3fv(normals[1]); }
    }
    if (normalInd == 2) {
        if (flipNormals == true) { glNormal3fv(normals[3]); }
        else { glNormal3fv(normals[2]); }
    }
    if (normalInd == 3) {
        if (flipNormals == true) { glNormal3fv(normals[2]); }
        else { glNormal3fv(normals[3]); }
    }
    if (normalInd == 4) {
        if (flipNormals == true) { glNormal3fv(normals[0]); }
        else { glNormal3fv(normals[4]); }
    }
    if (normalInd == 5) {
        if (flipNormals == true) { glNormal3fv(normals[1]); }
        else { glNormal3fv(normals[5]); }
    }

    glColor3f(r, g, bb);
    glBegin(GL_POLYGON);
    glVertex3fv(svertices[a]);
    glVertex3fv(svertices[b]);
    glVertex3fv(svertices[c]);
    glVertex3fv(svertices[d]);
    glEnd();
}

void schoolBus()
{
    //wheels
    wheel(0.5, -0.2, 0.9, .15, .1, 50);
    wheel(0.5, -0.2, -0.6, .15, .1, 50);
    wheel(-0.5, -0.2, 0.9, .15, .1, 50);
    wheel(-0.5, -0.2, -0.6, .15, .1, 50);

    //bus
    square(4, 5, 6, 7, 1, 1, 0, 4, 1); //back
    square(4, 7, 3, 0, 1, 1, 0, 5, 1); //below
    square(1, 2, 6, 5, 1, 1, 0, 1, 1); //top
    square(0, 3, 2, 1, 0.157, 0.69, 0.831, 0, 2); //front

    //Bus engine
    square(8, 0, 3, 10, 1, 1, 0, 5, 1);//bottom
    square(8, 9, 12, 0, 1, 1, 0, 2, 1);//left
    square(10, 11, 13, 3, 1, 1, 0, 3, 1);//right
    square(9, 11, 13, 12, 1, 1, 0, 1, 1);//top
    square(8, 9, 11, 10, 1, 1, 0, 0, 1);//front
    square(150, 151, 152, 153, 0, 0, 0, 0, 0);

    //rightside
    square(46, 47, 48, 49, 1, 1, 0, 3, 1);
    square(50, 51, 52, 53, 1, 1, 0, 3, 1);
    square(54, 55, 56, 57, 1, 1, 0, 3, 1); //window divider
    square(58, 59, 60, 61, 1, 1, 0, 3, 1);
    square(82, 83, 84, 85, 1, 1, 0, 3, 1); //window divider
    square(86, 87, 88, 89, 1, 1, 0, 3, 1); //window divider
    square(90, 91, 92, 93, 1, 1, 0, 3, 1); //window divider
    square(154, 155, 156, 157, 0.157, 0.69, 0.831, 3, 2); //right window 1
    square(158, 159, 160, 161, 0.157, 0.69, 0.831, 3, 2); //right window 2
    square(162, 163, 164, 165, 0.157, 0.69, 0.831, 3, 2); //right window 3
    square(166, 167, 168, 169, 0.157, 0.69, 0.831, 3, 2); //right window 4

    //leftside
    square(14, 15, 16, 17, 1, 1, 0, 2, 1);
    square(22, 23, 24, 25, 1, 1, 0, 2, 1);
    square(26, 27, 28, 29, 1, 1, 0, 2, 1);
    square(30, 31, 32, 33, 1, 1, 0, 2, 1);
    square(94, 95, 96, 97, 1, 1, 0, 2, 1); //window divider
    square(98, 99, 100, 101, 1, 1, 0, 2, 1); //window divider
    square(102, 103, 104, 105, 1, 1, 0, 2, 1); //window divider
    square(170, 171, 172, 173, 1, 1, 0, 2, 2); //window
    square(174, 175, 176, 177, 1, 1, 0, 2, 2); //window
    square(178, 179, 180, 181, 1, 1, 0, 2, 2); //window

    //leftside door
    square(34, 35, 36, 37, 0.157, 0.69, 0.831, 2, 2); //window
    square(106, 107, 108, 109, 0.5, 0.5, 0.5, 2, 3);
    square(110, 111, 112, 113, 0.5, 0.5, 0.5, 2, 3);
    square(114, 115, 116, 117, 0.5, 0.5, 0.5, 2, 3);
    square(118, 119, 120, 121, 0.5, 0.5, 0.5, 2, 3);
    square(122, 123, 124, 125, 0.5, 0.5, 0.5, 2, 3);
}


//GLUT AUXILIARY FUNCTIONS
/*----------------------------------------------------------------------*/
void myReshape(int w, int h) { glViewport(0, 0, w, h); }

void key(unsigned char k) {
    //change camera pos
    if (k == 'i') { i = true; }
    else if (k == 'I') { ii = true; }
    else if (k == 'l') { l = true; }
    else if (k == 'r') { r = true; }
    else if (k == 'u') { u = true; }
    else if (k == 't') { t = true; }
    else if (k == 'f') { f = true; }
    else if (k == 'b') { b = true; }
    else if (k == 'z') { z = true; }
    else if (k == 'Z') { zz = true; }

    //change light pos (may need to double tap key for it to work)
    if (k == '1') { light_l = true; }
    else if (k == '2') { light_r = true; }
    else if (k == '3') { light_i = true; }
    else if (k == '4') { light_il = true; }

    //change spotlight anlge
    if (k == 'x') { lightDir[0] += .05; }
    if (k == 'X') { lightDir[0] -= .05; }
    if (k == 'c') { lightDir[1] += .05; }
    if (k == 'C') { lightDir[1] -= .05; }
    if (k == 'v') { lightDir[2] += .05; }
    if (k == 'V') { lightDir[2] -= .05; }

    glutPostRedisplay();
}

void renderText() {
    
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.1f, 0.71f, -0.8f);
    glScalef(0.002f, 0.002f, 0.002f);
    glRotatef(90, 0, 1, 0);
    glRotatef(-90, 1, 0, 0);
    glRotatef(180, 0, 0, 1);

    char text[] = "S'COOL BUS";

    for (int i = 0; i < 10; i++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    }

    glPopMatrix();
}

void renderLight() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lighPos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDir);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotCut);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExp);
    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, SpecLight);
}

void renderTexture() {
    glEnable(GL_TEXTURE_2D);

    glPushMatrix(); 

    glTranslatef(-0.51, 0.1, 0);
    glScalef(0.15f , 0.15f, 0.15f);
    glRotatef(90, 0, 1, 0);
    glRotatef(180, 0, 0, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.51, 0.1, 0);
    glScalef(0.15f, 0.15f, 0.15f);
    glRotatef(270, 0, 1, 0);
    glRotatef(180, 0, 0, 1);


    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
    glEnd();

    

    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}

void display(void) {
    //VIEWING
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(45.0f, ratio, .5f, 10.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // view transform based on input
    if (i == true) {
        lx = -3;
        ly = 3;
        lz = 3;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 1;
        uz = 0;
        i = false;
    }
    else if (ii == true) {
        lx = 3;
        ly = 3;
        lz = 3;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 1;
        uz = 0;
        ii = false;
    }
    else if (l == true) {
        lx = -3;
        ly = 0;
        lz = 0;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 1;
        uz = 0;
        l = false;
    }
    else if (r == true) {
        lx = 3;
        ly = 0;
        lz = 0;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 1;
        uz = 0;
        r = false;
    }
    else if (u == true) {
        lx = 0;
        ly = -3;
        lz = 0;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 0;
        uz = 1;
        u = false;
    }
    else if (t == true) {
        lx = 0;
        ly = 3;
        lz = 0;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 0;
        uz = -1;
        t = false;
    }
    else if (f == true) {
        lx = 0;
        ly = 0;
        lz = 3;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 1;
        uz = 0;
        f = false;
    }
    else if (b == true) {
        lx = 0;
        ly = 0;
        lz = -3;
        ex = 0;
        ey = 0;
        ez = 0;
        ux = 0;
        uy = 1;
        uz = 0;
        b = false;
    }
    if (z == true) {
        if (lx < 0) { lx += 0.1f; }
        else if (lx > 0) { lx -= 0.1f; }
        if (ly < 0) { ly += 0.1f; }
        else if (ly > 0) { ly -= 0.1f; }
        if (lz < 0) { lz += 0.1f; }
        else if (lz > 0) { lz -= 0.1f; }

        z = false;
    }
    else if (zz == true) {
        if (lx < 0) { lx -= 0.1f; }
        else if (lx > 0) { lx += 0.1f; }
        if (ly < 0) { ly -= 0.1f; }
        else if (ly > 0) { ly += 0.1f; }
        if (lz < 0) { lz -= 0.1f; }
        else if (lz > 0) { lz += 0.1f; }

        zz = false;
    }


    //spotlight pos input change
    if (light_l == true) {
        lighPos[0] = -2.0f;
        lighPos[1] = 2.0f;
        lighPos[2] = 2.0f;
        lightDir[0] = 1.0f;
        lightDir[1] = -1.0f;
        lightDir[2] = -1.0f;
        spotCut = 45;
        spotExp = 10.0f;
        light_l = false;
        flipNormals = false;
    }
    else if (light_r == true) {
        lighPos[0] = 2.0f;
        lighPos[1] = 2.0f;
        lighPos[2] = 2.0f;
        lightDir[0] = -1.0f;
        lightDir[1] = -1.0f;
        lightDir[2] = -1.0f;
        spotCut = 45;
        spotExp = 10.0f;
        light_r = false;
        flipNormals = false;
    }
    else if (light_i == true) {

        flipNormals = true;

        lx = 1.0;
        ly = .3;
        lz = 0;
        ux = 0;
        uy = 2;
        uz = 0;

        ex = -2.0f;
        ey = .3f;
        ez = 0.0f; 

        lighPos[0] = 0.4f; 
        lighPos[1] = .5f;
        lighPos[2] = 0.7f;
        lightDir[0] = 0.0f;
        lightDir[1] = -.5f;
        lightDir[2] = -1.0f;
        spotCut = 20;
        spotExp = 20;

        light_i = false;

    }
    else if (light_il == true) {

        flipNormals = true;

        lx = -.3;
        ly = .5;
        lz = 1.3;
        ux = 0;
        uy = 2;
        uz = 2;

        ex = 0.0f;
        ey = 0.0f;
        ez = -2.0f;

        lighPos[0] = 0.4f;
        lighPos[1] = .5f;
        lighPos[2] = 0.7f;
        lightDir[0] = 0.0f;
        lightDir[1] = -.5f;
        lightDir[2] = -1.0f;
        spotCut = 20;
        spotExp = 20;

        light_il = false;
    }

    gluLookAt(lx, ly, lz, ex, ey, ez, ux, uy, uz); //look based off inpuut


    //Draw school bus
    renderLight(); // renders the lighting
    schoolBus(); //draws the vertices of the bus
    renderText(); //renders the text on the bus
    renderTexture();
    

    glutSwapBuffers();
}

unsigned char* loadPPM(const char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    char header[3];
    fscanf(file, "%s", header);
    fscanf(file, "%d %d %*d\n", width, height);
    int dataSize = (*width) * (*height) * 3;
    unsigned char* data = (unsigned char*)malloc(dataSize);
    fread(data, sizeof(unsigned char), dataSize, file);
    fclose(file);
    return data;
}

void loadTexture() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    int width, height;
    unsigned char* textureData = loadPPM("..\\stop_sign.ppm", &width, &height);

    if (!textureData) {
        fprintf(stderr, "Failed to load texture\n");
        exit(1);
    }

    GLuint textureID;
    glGenTextures(1, &textureID);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    free(textureData);
}

//MAIN
/*----------------------------------------------------------------------*/
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Stamm Matthew Bus Version 3");
    glEnable(GL_DEPTH_TEST);

    loadTexture();

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    glClearColor(0.231, 0.231, 0.212, 1);
    //glClearColor(1, 1, 1, 1);
    glutMainLoop();
}
