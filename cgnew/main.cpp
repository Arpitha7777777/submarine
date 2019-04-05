
#include<stdio.h>
#include<GL/glut.h>

void sea();
void submarine();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void update1();
void update2();
void fish();

void control();
//
GLint a=300,b=-300,c=350,flag=0,traffic_regulator=1,control_keyl,control_keyr,ab=70;
GLfloat red=0.1,blue=0.8,green=0.3;
GLfloat yel1=1.0,yel2=0.9,yel3=0.0;
GLfloat red1=0.0,blue1=1.0,green1=1.0;
GLfloat p=0,q=0,r=0;

//-----------
void *currentfont;


GLubyte fishh[] = {
0x00, 0x60, 0x01, 0x00,
0x00, 0x90, 0x01, 0x00,
0x03, 0xf8, 0x02, 0x80,
0x1c, 0x37, 0xe4, 0x40,
0x20, 0x40, 0x90, 0x40,
0xc0, 0x40, 0x78, 0x80,
0x41, 0x37, 0x84, 0x80,
0x1c, 0x1a, 0x04, 0x80,
0x03, 0xe2, 0x02, 0x40,
0x00, 0x11, 0x01, 0x40,
0x00, 0x0f, 0x00, 0xe0,

};
//-----------draw fish


GLfloat randomFloat() {
return (GLfloat)rand() / ab;
}
void fishes() {
glPushMatrix();
glTranslated(a,20.0,0.0);
for (int i = 0; i < 50; i++) {

glColor3f(1,0,1);
glRasterPos3f(randomFloat(), randomFloat(), 0.0);
glBitmap(27, 11, 0, 0, 0, 0, fishh);
}
for (int i = 0; i < 13; i++) {

glColor3f(1,1,0);
glTranslatef(100,0.0,0.0);
glRasterPos3f(randomFloat(), randomFloat(), 0.0);
glBitmap(27, 11, 0, 0, 0, 0, fishh);
}
glFlush();
glPopMatrix();

}

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0.0,0.0,0.0,1.0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
drawstring(450.0,700.0,0.0,"NMAM INSTITUTE OF TECHNOLOGY ");
glColor3f(0.7,0,1);
drawstring(330,650,0.0,"DEPARTMENT OF INFORMATION SCIENCE AND ENGINEERING");
glColor3f(1,0.5,0);
drawstring(530,600,0.0,"A MINI PROJECT ON");
glColor3f(1,0,0);
drawstring(530,550,0.0,"SUBMARINE IN A SEA");
glColor3f(1,0.5,0);
drawstring(200,400,0.0,"BY:");
glColor3f(1,1,1);
drawstring(100,300,0.0,"Name :");
glColor3f(1,1,1);
drawstring(200,300,0.0,"ANUSHA K  4NM16IS010");
glColor3f(1,1,1);
drawstring(100,240,0.0,"Name:");
glColor3f(1,1.0,1.0);
drawstring(200,240,0.0,"ARPITHA 4NM16IS014");
glColor3f(1,0.5,0);
drawstring(980,400,0.0,"GUIDE:");
glColor3f(1,1,1);
drawstring(930,300,0.0,"Name:");
glColor3f(1,1,1);
drawstring(1000,300,0.0," SAPNA S");
glColor3f(1,0.1,1);
drawstring(543,100,0.0,"PRESS ENTER TO START");
glFlush();
}

/*void control()
{
	if(control_keyl!='l'||control_keyr!='r')
	{
	if(control_keyl=='l')
a=a+6;
	if(control_keyr=='r')
	 b=b-6;
	}

}*/

void myKeyboard( unsigned char key, int x, int y )

{
switch(key)
{
	case 13:
		if(flag==1)
		{
			flag=1;
			mydisplay();
		}
		if(flag==0) //Ascii of 'enter' key is 13
		{
	flag=1;mydisplay();
		}

	break;
	/*case 'l':control_keyl=key;
		p=0;q=0;r=1;
	break;
	case 'r':control_keyr=key;
		p=0;q=0;r=1;
	break;
	case 's':mydisplay();
	break;
	case 'h':flag=1;mydisplay();
		break;*/
	default:break;
}

}



void mydisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
frontscreen ();
if(flag==1)
display();
glutSwapBuffers();
}

void update(int value)
{
a=a-6;
b=b+6;
//control();

if(blue!=0&&green!=0)
{
blue-=.007;green-=.007;

}
}

void update1(int value)
{

/*making day to night*/

if(yel2!=1&&yel3!=1)
{
yel3+=.007;yel3+=.007;

}

glutPostRedisplay();
}

void update2(int value)
{

a=a-6;
b=b+6;
//control();

if(blue1!=0&&green1!=0)
{
blue1-=.007;green1-=.007;

}
}


void display(void)
{
glutTimerFunc(100,update,0);
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(red,green,blue,0);/*back ground for sky*/
sea();
fish();
fishes();
submarine();
glFlush();
}


void sea()
{//GLint n=-50;
glPushMatrix();
glScaled(40.0,40.0,0.0);
glPushMatrix();//for sun
glutTimerFunc(100,update1,0);
glTranslated(10.0,15.0,0.0);
glColor3f(yel1,yel2,yel3);
//glTranslatef(0.0,b,0.0);
//glTranslatef(n,0.0,0.0);

glutSolidSphere(2.0,25,25);
glPopMatrix();
glPushMatrix();
glutTimerFunc(100,update2,0);
glColor3f(red1,blue1,green1);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(40,0);
glVertex2f(40,12);
glVertex2f(0,12);
glEnd();
glPopMatrix();
glPushMatrix();
glBegin(GL_POLYGON);
glTranslatef(0,50,0);
glVertex2f(0,12);
glVertex2f(40,12);
glVertex2f(40,12.5);
glVertex2f(0,12.5);
glEnd();
glPopMatrix();
glBegin(GL_POLYGON);
glColor3f(1,1,0);
glVertex2f(40,1);
glVertex2f(0,1);
glColor3f(1,0.5,0);
glVertex2f(0,0);
glVertex2f(40,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.2,0.2,0.2);
glVertex2f(5, 0);
glVertex2f(6.5, 0);
glColor3f(0,0,0);
glVertex2f(6.5, 1);
glVertex2f(6, 1);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.2,0.2,0.2);
glVertex2f(15, 0);
glVertex2f(17, 0);
glColor3f(0,0,0);
glVertex2f(17, 1.5);
glVertex2f(16.5, 1.5);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.2,0.2,0.2);
glVertex2f(25, 0);
glVertex2f(27, 0);
glColor3f(0,0,0);
glVertex2f(27, 1.5);
glVertex2f(25.5, 1.5);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(2, 2);
glVertex2f(3, 0);
glVertex2f(4, 2);
glVertex2f(3, 0);
glVertex2f(3, 0);
glVertex2f(3, 2);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(6, 2);
glVertex2f(7, 0);
glVertex2f(8, 2);
glVertex2f(7, 0);
glVertex2f(7, 0);
glVertex2f(7, 2);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(11, 2);
glVertex2f(12, 0);
glVertex2f(13, 2);
glVertex2f(12, 0);
glVertex2f(12, 0);
glVertex2f(12, 2);
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(14, 2);
glVertex2f(15, 0);
glVertex2f(15, 0);
glVertex2f(16, 2);
glVertex2f(15, 0);
glVertex2f(15, 2);
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(18, 2);
glVertex2f(19, 0);
glVertex2f(19, 0);
glVertex2f(20, 2);
glVertex2f(19, 0);
glVertex2f(19, 2);
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(21, 2);
glVertex2f(22, 0);
glVertex2f(22, 0);
glVertex2f(23, 2);
glVertex2f(22, 0);
glVertex2f(22, 2);
glEnd();
glLineWidth(8);
glBegin(GL_LINE_STRIP);
glColor3f(0,0.5,0);
glVertex2f(26, 2);
glVertex2f(27, 0);
glVertex2f(28, 2);
glVertex2f(27, 0);
glVertex2f(27, 0);
glVertex2f(27, 2);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(a,0,0.0);
glBegin(GL_POLYGON);				// draw body
	glColor3f(0.1,0.4,0.3);
	glVertex2i(40,200);
	glVertex2i(120,280);
		glColor3f(0,0.5,0);
	glVertex2i(320,200);
	glVertex2i(100,160);
	glEnd();
	glPushMatrix();

	glBegin(GL_POLYGON);			//draw tail
		glColor3f(0.1,0.2,0.3);

	glVertex2i(320,200);
	glVertex2i(360,240);
	glVertex2i(340,200);
	glVertex2i(360,160);
	glVertex2i(320,200);
	glEnd();

	glBegin(GL_POLYGON);		 //draw Top Key
	//glColor3f(1.0,0.0,0.0);
		glColor3f(0.1,0.2,0.3);

	glVertex2i(120,280);
	glVertex2i(140,300);
	glVertex2i(280,216);
	glVertex2i(120,280);
	glEnd();

	glBegin(GL_POLYGON);		 //draw Buttom Key
	//glColor3f(1.0,0.0,0.0);
		glColor3f(0.1,0.2,0.3);

	glVertex2i(100,160);
	glVertex2i(140,200);
	glVertex2i(120,164);
	glVertex2i(100,160);
	glEnd();

glPopMatrix();
////////


glPopMatrix();
///////
glPopMatrix();
}
void fish()
{
glPushMatrix();
glTranslated(0,a,0.0);
//glTranslated(20,190.0,0.0);
glScaled(35,35.0,0.0);
//for(int i=0;i<10;i++){
//glTranslatef(10,0,0);
glBegin(GL_POLYGON);
glColor3f(1,0.8,0.4);
glVertex2f(22, 2);
glVertex2f(21, 5);
glVertex2f(21,3);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(19, 4);
glVertex2f(21, 3);
glVertex2f(23, 4);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(21, 5);
glVertex2f(20, 2);
glVertex2f(21,3);
glEnd();

glPopMatrix();

}



void submarine()
{
//////
glPushMatrix();
glTranslated(b,250.0,0.0);
glScaled(30.0,30.0,0.0);
glColor3f(1,1,1);
glBegin(GL_POLYGON);
glVertex2f(7,7);
glVertex2f(5,5);
glVertex2f(22,5);
glVertex2f(20,7);
glEnd();
glColor3f(0.2,0.2,0.2);
glBegin(GL_LINE);
glVertex2f(-1,3);
glVertex2f(0,3);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(0,3);
glVertex2f(0,4);
glVertex2f(1,6);
glVertex2f(25,6);
glVertex2f(26,3);
glVertex2f(25,1);
glVertex2f(1,1);
glVertex2f(1,1);
glEnd();
glColor3f(0.4,0.5,0.5);
glBegin(GL_POLYGON);
glVertex2f(5,6);
glVertex2f(21,6);
glColor3f(0.1,0.1,0.1);
glVertex2f(20,7);
glVertex2f(6,7);
glEnd();
glColor3f(0.1,0.7,0.976471);
glBegin(GL_LINE_LOOP);
glVertex2f(22,3);
glVertex2f(22,5.5);
glVertex2f(24.5,5.5);
glVertex2f(25.5,3);
glVertex2f(24.5,3);

glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(5,2);
glVertex2f(7,2);
glVertex2f(7,4);
glVertex2f(5,4);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(9,2);
glVertex2f(11,2);
glVertex2f(11,4);
glVertex2f(9,4);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(13,2);
glVertex2f(15,2);
glVertex2f(15,4);
glVertex2f(13,4);
glEnd();
glBegin(GL_LINE_LOOP);
glVertex2f(17,2);
glVertex2f(19,2);
glVertex2f(19,4);
glVertex2f(17,4);
glEnd();
//////////
glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
glColor3f(0,0,0);
glVertex2f(19,10);
glColor3f(0.5,0.5,0.5);
glVertex2f(20,10);
glColor3f(1,1,1);
glVertex2f(21,10);
glColor3f(0.5,0.5,0.5);
glVertex2f(21,9);
glColor3f(0,0,0);
glVertex2f(20,9);
glColor3f(0.5,0.5,0.5);
glVertex2f(20,7);
glVertex2f(19,7);
glVertex2f(19,7);
glEnd();
glColor3f(0.1,0.1,0.1);
glLineWidth(1);
glBegin(GL_LINE_LOOP);
glVertex2f(19,7);
glVertex2f(19,10);
glColor3f(0,0,0);
glVertex2f(20,10);
glVertex2f(21,10);
glVertex2f(21,9);
glVertex2f(20,9);
glVertex2f(20,7);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0,0,1);
glVertex2f(22,3);
glVertex2f(22,5.5);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(24.5,5.5);
glVertex2f(25.5,3);
glVertex2f(24.5,3);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(5,2);
glVertex2f(7,2);
glColor3f(0,0,1);
glVertex2f(7,4);
glVertex2f(5,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(9,2);
glVertex2f(11,2);
glColor3f(0,0,1);
glVertex2f(11,4);
glVertex2f(9,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(13,2);
glVertex2f(15,2);
glColor3f(0,0,1);
glVertex2f(15,4);
glVertex2f(13,4);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.439216,0.858824,0.776471);
glVertex2f(17,2);
glVertex2f(19,2);
glColor3f(0,0,1);
glVertex2f(19,4);
glVertex2f(17,4);
glEnd();

glPopMatrix();
glPopMatrix();
glPushMatrix();

glTranslated(b,250.0,0.0);
glScalef(20,20,0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(1,1,1);
drawstring(8,7,0,"NMAMIT SUBMARINE 2019");
glPopMatrix();
////////////////////////////////////////////////////////////////////////////////////////////////
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1346,728);
glutInitWindowPosition(0,0);
glutCreateWindow("SUBMARINE");
myinit();
glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboard);
glutMainLoop();
}
