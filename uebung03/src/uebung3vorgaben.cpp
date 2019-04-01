
#include <stdio.h> 
#include <GL_glut.h> 

#define WINDOW_SIZE     400 // Fenstergroesse

//--------------------------------------------------------
// Globale Variablen
//         
//--------------------------------------------------------

float position000[] = {0.0, 0.0, 0.0};
float position222[] = {2.0, 2.0, 2.0};
double drehen_x=0, drehen_y=0, drehen_z=0;	// Drehen des Objektes in den Achsen
int option = 0;
int dreh_faktor = 1;
int kamera_abstandsfaktor = 1;


// Beispiel Matrix - Verschiebung
//GLdouble model_translation[4][4] = {
//	{1.0, 0.0, 0.0, 0.0,},  // Spalte 1
//	{0.0, 1.0, 0.0, 0.0,},  // Spalte 2
//	{0.0, 0.0, 1.0, 0.0,},  // Spalte 3
//	{dx, dy, dz, 1.0}};  // Spalte 4


//// Beispiel Matrix - Rotation
//GLdouble model_rotation_phi[4][4] = {
//	{1.0, 0.0, 0.0, 0.0,},  // Spalte 1
//	{0.0, cos(phi), sin(phi), 0.0,},  // Spalte 2
//	{0.0, -sin(phi), cos(phi), 0.0,},  // Spalte 3
//	{0.0, 0.0, 0.0, 1.0}};  // Spalte 4


//// Beispiel Matrix - Scalierung
//GLdouble model_scale[4][4] = {
//	{sx, 0.0, 0.0, 0.0,},  // Spalte 1
//	{0.0, sy, 0.0, 0.0,},  // Spalte 2
//	{0.0, 0.0, sz, 0.0,},  // Spalte 3
//	{0.0, 0.0, 0.0, 1.0}};  // Spalte 4



//--------------------------------------------------------
// coord - Zeichnen eine Koordinatenkreuzes 
//         Abmaﬂe (-3,3),(-3,3),(-3,3)
//--------------------------------------------------------
void coord()  
{
	
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex3d(-3.0,0.0,0.0);
	glVertex3d(3.0,0.0,0.0);
	glVertex3d(2.8,0.2,0.0);
	glVertex3d(3.0,0.0,0.0);
	glVertex3d(2.8,-0.2,0.0);
	glVertex3d(3.0,0.0,0.0);
	glVertex3d(2.8,0.0,0.2);
	glVertex3d(3.0,0.0,0.0);
	glVertex3d(2.8,0.0,-0.2);
	glVertex3d(3.0,0.0,0.0);
  
	glColor3f(0.0,1.0,0.0);
	glVertex3d(0.0,-3.0,0.0);
	glVertex3d(0.0,3.0,0.0);
	glVertex3d(0.2,2.8,0.0);
	glVertex3d(0.0,3.0,0.0);
	glVertex3d(-0.2,2.8,0.0);
	glVertex3d(0.0,3.0,0.0);
	glVertex3d(0.0,2.8,0.2);
	glVertex3d(0.0,3.0,0.0);
	glVertex3d(0.0,2.8,-0.2);
	glVertex3d(0.0,3.0,0.0);
  
	glColor3f(0.0,0.0,1.0);
	glVertex3d(0.0,0.0,-3.0);
	glVertex3d(0.0,0.0,3.0);
	glVertex3d(0.0,0.2,2.8);
	glVertex3d(0.0,0.0,3.0);
	glVertex3d(0.0,-0.2,2.8);
	glVertex3d(0.0,0.0,3.0);
	glVertex3d(0.2,0.0,2.8);
	glVertex3d(0.0,0.0,3.0);
	glVertex3d(-0.2,0.0,2.8);
	glVertex3d(0.0,0.0,3.0);
	glEnd();
}

//--------------------------------------------------------
// cube - Zeichnen eines Wuerfels im Ursprung
//--------------------------------------------------------
void cube()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3d (0.0, 0.0, 0.0);
	glVertex3d (1.0, 0.0, 0.0);
	glVertex3d (1.0, 1.0, 0.0);
	glVertex3d (0.0, 1.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, -1.0);
	glVertex3d(0.0, 1.0, -1.0);
	glVertex3d(0.0, 1.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, -1.0);
	glVertex3d(1.0, 0.0, -1.0);
	glVertex3d(1.0, 0.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glVertex3d(0.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,1.0);
	glVertex3d(0.0, 0.0, -1.0);
	glVertex3d(0.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 0.0, -1.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex3d(1.0, 0.0, 0.0);
	glVertex3d(1.0, 1.0, 0.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 0.0, -1.0);
	glEnd();
} 

//--------------------------------------------------------
// cube - Zeichnen eines Wuerfels mit Optionen
// *pos - Vector mit x, y und z Koordinaten
// r,g,b - Farbwerte fuer den Wuerfel
// mit r,g,b alle 0 ergibt sich ein bunter Wuerfel, jede Seite eine Farbe
//--------------------------------------------------------
void cube_pos_color(float *pos,float r,float g,float b)
{
	float color_front[] = {1.0,1.0,0.0};
	float color_back[] = {0.0,1.0,0.0};
	float color_sidex[] = {0.0,1.0,1.0};
	float color_sidex2[] = {0.0,0.0,1.0};
	float color_bottom[] = {1.0,0.0,1.0};
	float color_top[] = {1.0,0.0,0.0};

	if ((r != 0) || (g != 0) || (b != 0))
	{
		color_front[0] = r;
		color_front[1] = g;
		color_front[2] = b;
		color_back[0] = r;
		color_back[1] = g;
		color_back[2] = b;
		color_sidex[0] = r;
		color_sidex[1] = g;
		color_sidex[2] = b;
		color_sidex2[0] = r;
		color_sidex2[1] = g;
		color_sidex2[2] = b;
		color_bottom[0] = r;
		color_bottom[1] = g;
		color_bottom[2] = b;
		color_top[0] = r;
		color_top[1] = g;
		color_top[2] = b;
	}

	glBegin(GL_QUADS);
	glColor3fv(color_back);
	glVertex3d (0.0+pos[0], 0.0+pos[1], 0.0+pos[2]);
	glVertex3d (1.0+pos[0], 0.0+pos[1], 0.0+pos[2]);
	glVertex3d (1.0+pos[0], 1.0+pos[1], 0.0+pos[2]);
	glVertex3d (0.0+pos[0], 1.0+pos[1], 0.0+pos[2]);
	

	glColor3fv(color_sidex);
	glVertex3d(0.0+pos[0], 0.0+pos[1], 0.0+pos[2]);
	glVertex3d(0.0+pos[0], 0.0+pos[1], -1.0+pos[2]);
	glVertex3d(0.0+pos[0], 1.0+pos[1], -1.0+pos[2]);
	glVertex3d(0.0+pos[0], 1.0+pos[1], 0.0+pos[2]);

	glColor3fv(color_bottom);
	glVertex3d(0.0+pos[0], 0.0+pos[1], 0.0+pos[2]);
	glVertex3d(0.0+pos[0], 0.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 0.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 0.0+pos[1], 0.0+pos[2]);
	

	glColor3fv(color_top);
	glVertex3d(0.0+pos[0], 1.0+pos[1], 0.0+pos[2]);
	glVertex3d(0.0+pos[0], 1.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 1.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 1.0+pos[1], 0.0+pos[2]);
	
	glColor3fv(color_front);
	glVertex3d(0.0+pos[0], 0.0+pos[1], -1.0+pos[2]);
	glVertex3d(0.0+pos[0], 1.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 1.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 0.0+pos[1], -1.0+pos[2]);
	
	glColor3fv(color_sidex2);
	glVertex3d(1.0+pos[0], 0.0+pos[1], 0.0+pos[2]);
	glVertex3d(1.0+pos[0], 1.0+pos[1], 0.0+pos[2]);
	glVertex3d(1.0+pos[0], 1.0+pos[1], -1.0+pos[2]);
	glVertex3d(1.0+pos[0], 0.0+pos[1], -1.0+pos[2]);
	glEnd();
} 


// Projektion transformations
/*
The GL_PROJECTION matrix should contain only the projection transformation
calls it needs to transform eye space coordinates into clip coordinates.
*/
 void projection_transformation(void)
{
 glMatrixMode(GL_PROJECTION);
  // prepare for and then define the projection transformation
  // einfuegen!!!

  // Beispiel-Matrix
  //GLdouble proj_mat[4][4] = {
	 // {0.2, 0.0, 0.0, 0.0},  // Spalte 1
	 // {0.0, 0.2, 0.0, 0.0},  // Spalte 2
	 // {0.0, 0.0, 0.2, 0.0},  // Spalte 3
	 // {0.0, 0.0, 0.0, 1.0}}; // Spalte 4
  //glLoadMatrixd((const double *)proj_mat);

 // oder OpenGl Funktionen
 glLoadIdentity(); 
 	switch(option)
	{
		case 7:		// View the scene with (1)orthographic projection

			break;
		case 8:		// View the scene with (2)perspective projection

			break;
		case 9:		// Draw the scene with orthographic projection as front view. 

			break;
		case 10:	// Draw the scene with orthographic projection as side view. 

			break;
		case 11:	// Draw the scene with orthographic projection as top view. 

			break;
		default:	// View the scene with orthographic projection
			glOrtho(-5.0, 5.0, -5.0, 5.0, 1.0, 15.0 * kamera_abstandsfaktor); 
			break;
	}

  // back to modelview matrix
  glMatrixMode(GL_MODELVIEW);
}

// Viewing transformations
/*
The GL_MODELVIEW matrix, as its name implies, 
should contain modeling and viewing transformations, 
which transform object space coordinates into eye space coordinates. 
Remember to place the camera transformations on the GL_MODELVIEW matrix and 
never on the GL_PROJECTION matrix.
*/
void viewing_transformation(void)
{
  // viewing transformation
  // einfuegen!
  // modeling or viewing transformations
  glMatrixMode(GL_MODELVIEW);
 
  //// Einheitsmatrix
  //GLdouble model_mat0[4][4] = {
	 // {1.0, 0.0, 0.0, 0.0},
	 // {0.0, 1.0, 0.0, 0.0},
	 // {0.0, 0.0, 1.0, 0.0},
	 // {0.0, 0.0, 0.0, 1.0}};
  //// clear the matrix
  //glLoadMatrixd((const double *)model_mat0);

  // oder OpenGl Funktionen
  glLoadIdentity(); 

  switch(option)
	{
		case 7:		// View the scene with (1)orthographic projection with eyepoint 5,2,5

			break;
		case 8:		// View the scene with (2)perspective projection with eyepoint 5,2,5

			break;
		case 9:		// Draw the scene with orthographic projection as front view. 

			break;
		case 10:	// Draw the scene with orthographic projection as side view.

			break;
		case 11:	// Draw the scene with orthographic projection as top view. 

			break;
		default:	// Draw the scene with orthographic projection
			gluLookAt(0 * kamera_abstandsfaktor,0 * kamera_abstandsfaktor, 5 * kamera_abstandsfaktor, 0, 0, 0, 0, 1, 0);
			break;
	}
}



//--------------------------------------------------------
// display - Zeichenmethode
//--------------------------------------------------------

void display(void) 
{
	
  // Setzen der Hintergrundfarbe des Fensters
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  
  glEnable(GL_COLOR_MATERIAL);

// Aktivieren des Z-Buffers
  glClear(GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);


  // Projektion transformation
  projection_transformation();

  // Viewing transformation
  viewing_transformation();

 
  // modeling transformations
  glMatrixMode(GL_MODELVIEW);

  // three-dimensional model data
  // Drehung des Modells/Objektes
  glRotatef(drehen_x,1,0,0);
  glRotatef(drehen_y,0,1,0);
  glRotatef(drehen_z,0,0,1);

  // Zeichne Koordinaten-System
  coord(); 

  // Beispiel Matrix-Multiplikation.
  //glMultMatrixd((const double *)model_mat1);
 
	switch(option)
	{
		case 0:		// frei
			break;
		case 1:		// 30 Grad drehen by matrix operations

			break;
		case 2:		// Verschieben nach 1,-1,3 by matrix operations

			break;
		case 3:		// Skalieren 6,0.7,3 by matrix operations

			break;
		case 4:		// Wuerfel 2,2,2 X-Achse durch Punkt 2,2,2 mit Matrix-Operationen

			break;
		case 5:		// Wuerfel 2,2,2 X-Achse durch Punkt 2,2,2 mit OpenGl-Operationen

			break;
		case 6:		// Wuerfel 2,2,2 Kommutativitaet der Transformationen

			break;
		default:
			break;
	}

	if (option <= 6)
	{
		// Zeichne Wuerfel an Position 2,2,2
		cube_pos_color(position222,0.0,0.0,0.0);
	}

	if ((option >= 7) && (option <= 11))
	{
		//pyramide();
	}

  glFlush(); 
} 

void myInit(void)
{

}

// In this example, both the projection transformation und 
// the viewport transformation are contained in the myReshape() routine,
// which is called when the window is first created and 
// whenever the window ist maved or reshaped.
void myReshape(GLsizei w, GLsizei h)
{
  //define the viewport transformations
  if (w < h)
	glViewport(0, ((float)h-(float)w)/2.0, w, w);
  else
	glViewport(((float)w-(float)h)/2.0, 0, h, h);

}

// Menuefunktion
void ProcessMenu(int value)
{
	option = value;
	switch(option)
	{
		case 0:		// frei
			drehen_x = 0.0;
			drehen_y = 0.0;
			drehen_z = 0.0;
			dreh_faktor = 1;
			kamera_abstandsfaktor = 1;
			break;
		default:
			break;
	}

	glutPostRedisplay(); // Anzeige aktualisieren
}

// Tastenfunktion
void NormalKeys(unsigned char key, int x, int y) 
{
	if(key == 27) { // ESC
		exit(0);
	}
	
	if(key == 'x') { // Gedreht um die X-Achse positiv
		drehen_x += 0.5 * dreh_faktor;
	}
	if(key == 'X') { // Gedreht um die X-Achse negativ
		drehen_x -= 0.5 * dreh_faktor;
	}
	if(key == 'y') { // Gedreht um die X-Achse positiv
		drehen_y += 0.5 * dreh_faktor;
	}
	if(key == 'Y') { // Gedreht um die X-Achse negativ
		drehen_y -= 0.5 * dreh_faktor;
	}
	if(key == 'z') { // Gedreht um die X-Achse positiv
		drehen_z += 0.5 * dreh_faktor;
	}
	if(key == 'Z') { // Gedreht um die X-Achse negativ
		drehen_z -= 0.5;
	}
	if(key == 'd') { // Drehfaktor positiv
		dreh_faktor += 5.0;
	}
	if(key == 'D') { // Drehfacktor negativ
		dreh_faktor -= 5.0;
	}
	if(key == 'k') { // Kamera Abstandsfaktor positiv
		kamera_abstandsfaktor += 1.0;
	}
	if(key == 'K') { // Kamera Abstandsfaktor negativ
		kamera_abstandsfaktor -= 1.0;
	}

	glutPostRedisplay(); // Anzeige aktualisieren

}

//
//--------------------------------------------------------
// Benutzerausgabe
//         
//--------------------------------------------------------

void benutzerausgabe(void)
{
	printf("Uebung Transformationen\n\n");
	printf("Mit der ESC-Taste im Ansichtsfenster koennen Sie das Programm beenden.\n\n");
	
	printf("Mit den x- und X-Tasten koennen Sie das Objekt um die X-Achse drehen.\n");
	printf("Mit den y- und Y-Tasten koennen Sie das Objekt um die Y-Achse drehen.\n");
	printf("Mit den z- und Z-Tasten koennen Sie das Objekt um die Z-Achse drehen.\n");
	printf("Mit den d- und D-Tasten koennen Sie Drehwinkelaenderung veraendern.\n\n");
	
	printf("Mit den k- und K-Tasten koennen Sie dem Kameraabstand veraendern.\n");

	printf("\n\n");
}


int main(int argc, char **argv) 
{ 
 benutzerausgabe(); 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

 glutInitWindowPosition(100,100); 
 glutInitWindowSize(400,400); 
 glutCreateWindow ("3D-Viewing Cube"); 

 int nMainMenu; //, nSubMenu;
 nMainMenu = glutCreateMenu(ProcessMenu);
 glutAddMenuEntry("Wuerfel 2,2,2", 0);
 glutAddMenuEntry("Wuerfel 2,2,2 30Grad drehen mit Matrix-Operationen", 1);
 glutAddMenuEntry("Wuerfel 2,2,2 Zu Position 1,-1,3 mit Matrix-Operationen", 2);
 glutAddMenuEntry("Wuerfel 2,2,2 Skalieren 6,0.7,3 mit Matrix-Operationen", 3);
 glutAddMenuEntry("Wuerfel 2,2,2 X-Achse durch Punkt 2,2,2 mit Matrix-Operationen", 4);
 glutAddMenuEntry("Wuerfel 2,2,2 X-Achse durch Punkt 2,2,2 mit OpenGl-Operationen", 5);
 glutAddMenuEntry("Wuerfel 2,2,2 Kommutativitaet Transformationen", 6);
 glutAddMenuEntry("Pyramide in (1)Parallelprojektion mit Augenpunkt in 5,2,5", 7);
 glutAddMenuEntry("Pyramide in (2)perspektivischer Projektion mit Augenpunkt in 5,2,5", 8);
 glutAddMenuEntry("Pyramide in Parallelprojektion mit Frontansicht", 9);
 glutAddMenuEntry("Pyramide in Parallelprojektion mit Seitenansicht", 10);
 glutAddMenuEntry("Pyramide in Parallelprojektion mit Draufsicht", 11);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 
 glutKeyboardFunc(NormalKeys);

 myInit();
 glutReshapeFunc(myReshape);
 glutDisplayFunc(display); 
 glutMainLoop(); 

 return 0; 
}



