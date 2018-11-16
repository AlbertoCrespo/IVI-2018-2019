#include <GL/glut.h>


int color = 0;
/* Función de renderizado */
void render () {
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Traslación */
  glTranslatef(0.0, 0.0, -4.0);

  /* Renderiza un triángulo blanco */
  if (color == 0){
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
  } else {
/* Renderiza un triángulo tres colores (rojo, verde y azul) */
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
  }

  /* Intercambio de buffers */
  glutSwapBuffers();
}

void resize (int w, int h) {
  /* Definición del viewport */
  glViewport(0, 0, w, h);

  /* Cambio a transform. vista */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* Actualiza el ratio ancho/alto */
  gluPerspective(50., w/(double)h, 1., 10.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW);
}

void ControlTeclado(unsigned char key, int x, int y) {
    switch (key)
    {
            case 99:
                if(color == 0) color = 1;
                else color = 0;
            break;

    }
    glutPostRedisplay();
}

void init (void) {
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(200, 200);

  glutCreateWindow("Hola Mundo con OpenGL!");

  init();

  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render);
  glutReshapeFunc(resize);

  /* Registro de la funcion reconocimiento del teclado */
  glutKeyboardFunc(ControlTeclado);

  /* Bucle de renderizado */
  glutMainLoop();

  return 0;
}