#include <GL/glut.h>
#include <stdio.h>

static GLint rotate = 0;
static GLint ejeX = 1;
static GLint ejeY = 0;
static GLint ejeZ = 0;


void render () { 
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Posición de la cámara virtual (position, look, up) */
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  /* Gira la tetera */
  glRotatef(rotate, ejeX, ejeY, ejeZ);
  /* En color blanco */
  glColor3f( 1.0, 1.0, 1.0 );  
  /* Renderiza la tetera */
  glutWireTeapot(1.5);
  /* Intercambio de buffers... Representation ---> Window */
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

void rotarSentidoPositivo(){
  rotate = rotate + 1;
  glutPostRedisplay();
}

void rotarSentidoNegativo(){
  rotate = rotate - 1;
  glutPostRedisplay();
}


void ControlTecladoEspecialKeys(unsigned char key, int x, int y) {
        switch (key)
    {
            case 100: /* Tecla izquierda */
              glutIdleFunc(rotarSentidoPositivo);
            break;
            case 102: /* Tecla derecha */
              glutIdleFunc(rotarSentidoNegativo);
            break;
    }
}

void ControlTeclado(unsigned char key, int x, int y) {
    switch (key)
    {
            case 120: /* tecla x */
              ejeX = 1;
              ejeY = 0;
              ejeZ = 0;
              glutIdleFunc(rotarSentidoPositivo);
            break;
            case 121: /* tecla y */
              ejeX = 0;
              ejeY = 1;
              ejeZ = 0;
              glutIdleFunc(rotarSentidoPositivo);
            break;
            case 122: /* tecla z */
              ejeX = 0;
              ejeY = 0;
              ejeZ = 1;
              glutIdleFunc(rotarSentidoPositivo);
            break;            
            case 115: /* tecla s */
              glutIdleFunc(NULL);
            break;
    }
}

int main (int argc, char* argv[]) { 
  glutInit( &argc, argv ); 
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE ); 
  glutInitWindowSize(640, 480); 
  glutCreateWindow( "IVI - Sesion 2" ); 
  glEnable (GL_DEPTH_TEST);
  
  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render); 
  glutReshapeFunc(resize); 

  /* Registro de la funcion reconocimiento del teclado */
  glutKeyboardFunc(ControlTeclado);

  /* Registro teclas especiales */
  glutSpecialFunc(ControlTecladoEspecialKeys);
  
  /* Bucle de renderizado */
  glutMainLoop();  
  
  return 0; 
} 
