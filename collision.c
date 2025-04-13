//Matthew Stamm Project 3
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include<stdbool.h>


#define PI 3.14159265358979323846


//GLOBALS
/*----------------------------------------------------------------------*/
void myReshape(int w, int h) { glViewport(0, 0, w, h); }

float r = 0.0f;
float p = 0.0f;

float xA = 0.0f;
float yA = 0.0f;
float zA = 0.0f;
float rA = 1.0f;

float xB = 3.0f;
float yB = 0.0f;
float zB = 0.0f;
float rB = 1.0f;

bool collision = false;
bool explosion = false;

float clX = 0;
float clY = 0;
float clZ = 0;

void drawTexturedSphere(float radius, int slices, int stacks) {
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();

    glScalef(.2, .2, .2);
    glRotatef(r, 1, 0, 0);
    glTranslatef(p, 0, 0);

    for (int i = 0; i < stacks; ++i) {
        float lat0 = PI * (-0.5 + (float)(i) / stacks);
        float z0 = sin(lat0);
        float zr0 = cos(lat0);

        float lat1 = PI * (-0.5 + (float)(i + 1) / stacks);
        float z1 = sin(lat1);
        float zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float lng = 2 * PI * (float)(j - 1) / slices;
            float x = cos(lng);
            float y = sin(lng);

            glNormal3f(x * zr0, y * zr0, z0);
            glTexCoord2f((float)j / slices, (float)i / stacks);
            glVertex3f(x * zr0, y * zr0, z0);

            glNormal3f(x * zr1, y * zr1, z1);
            glTexCoord2f((float)j / slices, (float)(i + 1) / stacks);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }



    glPopMatrix();

    glPushMatrix();
    
    glScalef(.2, .2, .2);
    glTranslatef(3, 0, 0);

    for (int i = 0; i < stacks; ++i) {
        float lat0 = PI * (-0.5 + (float)(i) / stacks);
        float z0 = sin(lat0);
        float zr0 = cos(lat0);

        float lat1 = PI * (-0.5 + (float)(i + 1) / stacks);
        float z1 = sin(lat1);
        float zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; ++j) {
            float lng = 2 * PI * (float)(j - 1) / slices;
            float x = cos(lng);
            float y = sin(lng);

            glNormal3f(x * zr0, y * zr0, z0);
            glTexCoord2f((float)j / slices, (float)i / stacks);
            glVertex3f(x * zr0, y * zr0, z0);

            glNormal3f(x * zr1, y * zr1, z1);
            glTexCoord2f((float)j / slices, (float)(i + 1) / stacks);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }

    glPopMatrix();


    glDisable(GL_TEXTURE_2D);


}



typedef struct {
    float position[3]; // x, y, z position
    float velocity[3]; // x, y, z velocity
    int life; // life of the particle
} Particle;

Particle particles[10];



void boom() {
    float xM = (xA + xB) / 2;
    float yM = (yA + yB) / 2;
    float zM = (zA + zB) / 2;


    for (int i = 0; i < 10; i++) {
        particles[i].position[0] = xM;
        particles[i].position[1] = yM;
        particles[i].position[2] = zM;

    }


    glPushMatrix();
    glScalef(.2, .2, .2);
    glTranslatef(xM, yM, zM);
    glutWireSphere(1, 25, 25);
    glPopMatrix();


    // how many objects created in the explosion? lets say 10
    //for (int i = 0; i < 10; i++) {//iterate each time for an object in the explosion
    //
    //}
}

int duration = 5000;
int timeElapsed = 0;

void explosionSequence() {
    if (timeElapsed < duration) {
        
        printf("test");

        glutPostRedisplay();
        timeElapsed += 16;
        glutTimerFunc(16, explosionSequence, 0);
    }
}

void update(int value) {
    r += 1.0f;
    if (r > 360.0f) { r -= 360.0f; }

    p = p + .01;
    xA = xA + .01;

    float distance = sqrt(pow(xA - xB, 2) + pow(yA - yB, 2) + pow(zA - zB, 2));

    if (distance <= (2)) { 
        collision = true;
    }

    glutPostRedisplay();

    if (collision != true) {
        glutTimerFunc(16, update, 0);
       
    }
    else { glutTimerFunc(16, explosionSequence, 0); }
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

    gluLookAt(-1, 1, 1, 0, 0, 0, 0, 1, 0); //look based off inpuut


    if (collision == false) {
        drawTexturedSphere(1, 25, 25);
    }
    else {
        boom();
    }
    


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
    unsigned char* textureData = loadPPM("smiley.ppm", &width, &height);

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
    glutTimerFunc(16, update, 0);


    glClearColor(0.231, 0.231, 0.212, 1);
    //glClearColor(1, 1, 1, 1);
    glutMainLoop();
}
