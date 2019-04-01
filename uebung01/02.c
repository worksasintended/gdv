#include <stdio.h>
#include <GL/glut.h>

void display(void){
  glClear( GL_COLOR_BUFFER_BIT);
  //default glShadeMode(GL_SMOOTH)
  glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); //red
    glVertex3f(1.0, 1.0, 0.0);
    
    glColor3f(0.0, 0.0, 1.0); //bue
    glVertex3f(1.0, 9.0, 0.0);
  
    glColor3f(0.0, 1.0, 0.0); //green
    glVertex3f(9.0, 1.0, 0.0);
  glEnd();
  glFlush();
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
  glutCreateWindow ("triangle");
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glLoadIdentity();
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
