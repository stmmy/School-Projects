//Matthew Stamm
#define GL_SILENCE_DEPRECATION
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef float vertex[3];

vertex svertices[] = {
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
    {.5, .7, .2},
    {.5, .7, .3},

    //rightside 6 (wd 2)
    {.5, .3, -0.1}, //86
    {.5, .3, -0.2},
    {.5, .7, -0.2},
    {.5, .7, -0.1},
    //rightside 7 (wd 2)
    {.5, .3, -0.5}, //90
    {.5, .3, -0.6},
    {.5, .7, -0.6},
    {.5, .7, -0.5},
    
    //leftside (window divider)
    {-.5, .3, .4}, //94
    {-.5, .3, .3},
    {-.5, .7, .3},
    {-.5, .7, .4},

    //leftside (wd 2)
    {-.5, .3, 0}, //98
    {-.5, .3, -0.1},
    {-.5, .7, -0.1},
    {-.5, .7, 0},
    
    //leftside 7 (wd 2)
    {-.5, .3, -0.4}, //102
    {-.5, .3, -0.5},
    {-.5, .7, -0.5},
    {-.5, .7, -0.4},
    
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
    
    {-.3, .70001, -.8}, //126 back window
    {.3, .70001, -.8},
    {.3, .70001, -.2},
    {-.3, .70001, -.2},

    {-.3, .3, -.90001},
    {-.3, .6, -.90001},
    {.3, .6, -.90001},
    {.3, .3, -.90001},
    
    {-.50001, -.1, -.9},
    {-.50001, 0, -.9},
    {-.50001, 0, .3},
    {-.50001, -.1, .3},
    
    {-.50001, .1, -.9},
    {-.50001, .2, -.9},
    {-.50001, .2, .3},
    {-.50001, .1, .3},
    
    {.50001, -.1, -.9},
    {.50001, 0, -.9},
    {.50001, 0, .7},
    {.50001, -.1, .7},
    
    {.50001, .1, -.9},
    {.50001, .2, -.9},
    {.50001, .2, .7},
    {.50001, .1, .7},

    {-.3, -.1, 1.30002},
    {-.3, .1, 1.30002},
    {.3, .1, 1.30002},
    {.3, -.1, 1.30002},
};


void square(int a, int b, int c, int d, float r, float g, float bb, bool outline) {
    if (outline == true) {
        glColor3f(0,0,0);
        glBegin(GL_LINE_LOOP);
        glVertex3fv(svertices[a]);
        glVertex3fv(svertices[b]);
        glVertex3fv(svertices[c]);
        glVertex3fv(svertices[d]);
        glEnd();
    }


    
    glColor3f(r, g, bb);
    glBegin(GL_POLYGON);
    glNormal3fv(svertices[a]);
    glVertex3fv(svertices[a]);
    glVertex3fv(svertices[b]);
    glVertex3fv(svertices[c]);
    glVertex3fv(svertices[d]);
    glEnd();
}




void wheel(float x, float y, float z, float radius, float height, int segments) {
    glPushMatrix();
    
    glTranslatef(x, y, z);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0, 0, 0);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)segments;
        float x = radius * cos(theta);
        float z = radius * sin(theta);

        glVertex3f(x, height / 2.0f, z);
        glVertex3f(x, -height / 2.0f, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)segments;
        float x = radius * cos(theta);
        float z = radius * sin(theta);

        glVertex3f(x, height / 2.0f, z);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)segments;
        float x = radius * cos(theta);
        float z = radius * sin(theta);

        glVertex3f(x, -height / 2.0f, z);
    }
    glEnd();
    
    glPopMatrix();
}



void schoolBus()
{
    //wheels
    wheel(0.5,-0.2,0.9,.15,.1,50);
    wheel(0.5,-0.2,-0.6,.15,.1,50);
    wheel(-0.5,-0.2,0.9,.15,.1,50);
    wheel(-0.5,-0.2,-0.6,.15,.1,50);
    

    square(4, 5, 6, 7, 1, 1, 0, true); //back
    square(0, 3, 7, 4, 1, 1, 0, true); //below
    square(1, 2, 6, 5, 1, 1, 0, true); //top
    square(0, 3, 2, 1, 0.157, 0.69, 0.831, false);//front
    
    square(126, 127, 128, 129, 0.157, 0.69, 0.831, true); //top window
    square(130, 131, 132, 133, 0.157, 0.69, 0.831, true); //back window
    
    square(134, 135, 136, 137, 0, 0, 0, false);
    square(138, 139, 140, 141, 0, 0, 0, false);
    square(142, 143, 144, 145, 0, 0, 0, false);
    square(146, 147, 148, 149, 0, 0, 0, false);
    
    square(150, 151, 152, 153, 0, 0, 0, false);
    //leftside
    square(14, 15, 16, 17, 1, 1, 0, false);
    square(22, 23, 24, 25, 1, 1, 0, false);
    square(26, 27, 28, 29, 1, 1, 0, false);
    square(30, 31, 32, 33, 1, 1, 0, false);
    square(34, 35, 36, 37, 0.157, 0.69, 0.831, false);//door
    square(38, 39, 40, 41, 0.157, 0.69, 0.831, false);//window
    square(94, 95, 96, 97, 1, 1, 0, false);
    square(98, 99, 100, 101, 1, 1, 0, false);
    square(102, 103, 104, 105, 1, 1, 0, false);
    
    //door frames
    square(106, 107, 108, 109, 0.5, 0.5, 0.5, false);
    square(110, 111, 112, 113, 0.5, 0.5, 0.5, false);
    square(114, 115, 116, 117, 0.5, 0.5, 0.5, false);
    square(118, 119, 120, 121, 0.5, 0.5, 0.5, false);
    square(122, 123, 124, 125, 0.5, 0.5, 0.5, false);
    
    //rightside
    square(42, 43, 44, 45, 0.157, 0.69, 0.831, false);//window
    square(46, 47, 48, 49, 1, 1, 0, false);
    square(50, 51, 52, 53, 1, 1, 0, false);
    square(54, 55, 56, 57, 1, 1, 0, false);
    square(58, 59, 60, 61, 1, 1, 0, false);
    square(82, 83, 84, 85, 1, 1, 0, false);
    square(86, 87, 88, 89, 1, 1, 0, false);
    square(90, 91, 92, 93, 1, 1, 0, false);

    //frontBusEngine
    square(8, 0, 3, 10, 1, 1, 0, true);//bottom
    square(8, 9, 12, 0, 1, 1, 0, false);//left
    square(10, 11, 13, 3, 1, 1, 0, false);//right
    square(9, 11, 13, 12, 1, 1, 0, true);//top
    square(8, 9, 11, 10, 1, 1, 0, true);//front
}

//input globals

unsigned char view = 'i';
bool help = false;

float lx = 0.0f;
float ly = 0.0f;
float lz = -2.0f;

void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float ratio = (float)glutGet(GLUT_WINDOW_WIDTH)/(float)glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(45.0f, ratio, .5f, 10.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    if (view == 'i') {
        gluLookAt(-2,2,2,0,0,0,0,1,0);
    }
    else if (view == 'I') {
        gluLookAt(1,1,1,0,0,0,0,1,0);
    }
    else if (view == 'l') {
        gluLookAt(-2,0,0,0,0,0,0,1,0);
    }
    else if (view == 'r') {
        gluLookAt(2,0,0,0,0,0,0,1,0);
    }
    else if (view == 'u') {
        gluLookAt(0,-1,0,0,0,0,0,0,1);
    }
    else if (view == 't') {
        gluLookAt(0,1,0,0,0,0,0,0,1);
    }
    else if (view == 'f') {
        gluLookAt(0,0,1,0,0,0,0,1,0);
    }
    else if (view == 'b') {
        gluLookAt(0,0,-2,0,0,0,0,1,0);
    }
    
    else if (view = 'z') {
        

        lz += .1f;
        gluLookAt(lx, ly, lz, 0, 0, 0, 0, 1, 0);
    }
    
    if (help == true) {
        float x = -2;
        float y = 1;
        glColor3f(1.0, 1.0, 1.0); // Set text color (black)

        glRasterPos2f(-3 , .5); // Set position for the text

        char *text = "Press 'f' for front view Press 'b' for back view\Press 'r' for right side view Press 'l' for left side view Press 't' for top view Press 'u' for under view\Press 'i' for isometric view";
        
        // Display each character in the string
        for (int i = 0; i < strlen(text); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
        }

    }
    
    
    schoolBus();
    glFlush();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glutPostRedisplay();
}



void input(unsigned char k) {
    if (k == 'i') {view = 'i';}
    else if (k == 'I') {view = 'I';}
    else if (k == 'l') {view = 'l';
    }
    else if (k == 'r') {
        view = 'r';
    }
    else if (k == 'u') {
        view = 'u';
    }
    else if (k == 't') {
        view = 't';
    }
    else if (k == 'f') {
        view = 'f';
    }
    else if (k == 'b') {
        view = 'b';
    }
    else if (k == 'h') {
        if (help == true) {help = false;}
        else if (help == false) {help = true;}
    }
    else if (k == 'z') {
        view = 'z';
        //zf += 0.1f;
    }
    else if (k == 'Z') {
        view = 'Z';
    }
    glutPostRedisplay();
}


void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Stamm Matthew BUS Version 2");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(input);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glutMainLoop();
}
