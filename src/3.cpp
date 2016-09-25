#include <time.h>
#include <GL/glut.h>

void Draw( void ) {
   glClear( GL_COLOR_BUFFER_BIT );
   glColor3f( 0.0, 1.0, 0.0 );
   glBegin( GL_LINES );
   glVertex2f( 50, 50 );   glVertex2f( 50, 50 );
   glEnd();
   glFlush();
}

int main( int argc, char *argv[] ) {

   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize( 640, 480 );
   glutInitWindowPosition( 100, 100 );
   glutCreateWindow( "GL Demo" );
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0,640,0,480);

   glutDisplayFunc( Draw );
   glClearColor( 0, 0, 0, 0 );
   glutMainLoop();
   return 0;
}
