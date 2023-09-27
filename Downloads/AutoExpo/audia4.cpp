
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define car1 1
#define car2 0


GLint  c1flag = 1, c2flag = 0;
GLfloat vertices[][3] = { { -400.0, -400.0, -400.0 }, { 400.0, -400.0, -400.0 }, { 400.0, 400.0, -400.0 }, { -400.0, 400.0, -400.0 }, { -400.0, -400.0, 400.0 }, { 400.0, -400.0, 400.0 }, { 400.0, 400.0, 400.0 }, { -400.0, 400.0, 400.0 } };
GLfloat colors[][3] = { { 1.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 1.0 }, { 0.0, 0.0, 0.0 },
{ 0.0, 1.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 } };
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
GLint axis = 1;
void polygon(int a, int b, int c, int d)
{
	//draw a polygon via list of vertices
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}
void colorcube(void)
{ //map vertices to faces
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
}

void processMenuEvents(int options)
{
	switch (options)
	{
	case car1:{c1flag = 1; c2flag = 0; }
			  break;

	case car2:{c2flag = 1; c1flag = 0;  }
			  break;
	}
}


void menuoptions()
{
	int menu;

	menu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Lamborghini", car1);
	glutAddMenuEntry("audia4 cabriolet", car2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


}



void DrawCircle(float cx, float cy,float cz, float r, int num_segments)
{
	//glColor3f(1.0, 0.0, 0.0);
	//glBegin(GL_LINE_LOOP);
	//glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex3d(x + cx, y + cy,cz);//output vertex 

	}

	glEnd();

}


void DrawCirclez(float cx, float cy, float cz, float r, int num_segments)
{
	//glColor3f(1.0, 0.0, 0.0);
	//glBegin(GL_LINE_LOOP);
	//glBegin(GL_POLYGON);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float z = r * sinf(theta);//calculate the y component 

		glVertex3d(x + cx, cy, z + cz);//output vertex 

	}

	glEnd();

}

void DrawArc(float cx, float cy, float cz, float r, float start_angle, float arc_angle, int num_segments)
{
	start_angle = (start_angle * 22) / 1260;

	arc_angle = (arc_angle * 22) / 1260;

	float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

	float tangetial_factor = tanf(theta);

	float radial_factor = cosf(theta);


	float x = r * cosf(start_angle);//we now start at the start angle
	float y = r * sinf(start_angle);

	//glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
	
	//glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex3d(x + cx, y+cy,cz);
		//if (ii == 0)
			//printf("%f,%f\n", x + cx, y + cy);
		float tx = -y;
		float ty = x;

		x += tx * tangetial_factor;
		y += ty * tangetial_factor;

		x *= radial_factor;
		y *= radial_factor;

	}
	//glEnd();

}
void draw()//car1
{

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	DrawArc(-225, -125, 200.5, 100, 331, 235, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	DrawArc(325, -125, 200.5, 100, 327, 235, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(220, -170, 200);//p0
	glVertex3d(-100, -175, 200);//p1



	glVertex3d(-350, -175, 200);//p2
	glVertex3d(-485, -175, 200);//p3
	glVertex3d(-475, -160, 200);//p4
	glVertex3d(-465, -160, 200);//p5
	//glVertex3d(-450, -175, 150);
	glVertex3d(-450, -170, 200);//p6
	glVertex3d(-425, -155, 200);//p7
	glVertex3d(-460, -90, 200);
	glVertex3d(-495, -125, 200);//p8
	glVertex3d(-503, -100, 200);//p12

	DrawArc(-145, -490, 200, 525, 133, -22.5, 999);

	glVertex3d(-325, 7.5, 200);//pp13
	
	DrawArc(-175, -400, 200, 440, 92, -18, 999);

	glVertex3d(370, 60, 200);//p16
	glVertex3d(540, 30, 200);//p19
	glVertex3d(555, -15, 200);//p20
	glVertex3d(535, -15, 200);//p21
	glVertex3d(540, -60, 200);//p25
	glVertex3d(555, -75, 200);//p26
	glVertex3d(565, -100, 200);//p27
	glVertex3d(550, -100, 200);//p28

	DrawArc(280, 125, 200, 350, 319, -22.5, 999);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, .5, .5);
	glVertex3d(-325, 7.5, 200);
	glVertex3d(-210, 25, 200);
	glVertex3d(-75, 95, 200);
	glVertex3d(-80, 110, 200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	DrawArc(50, -400, 200, 525, +70, 35, 999);
	DrawArc(50, -400, 200, 515, 105, -35, 999);
	glEnd();

	

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	DrawArc(50, -400, 200, 490, 105, 15, 999);
	glVertex3d(-210, 25, 200);
	glVertex3d(-75, 95, 200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(370, 60, 200);
	DrawArc(50, -400, 200, 515, 70, 35, 999);
	DrawArc(50, -400, 200, 490, 105, -39, 999);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(.5, .5, .5);
	DrawArc(50, -400, 201, 490, 105, 15, 999);
	DrawArc(-175, -400, 201, 425, 92, -14, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.5, .5, .5);
	glVertex3d(-75, 10, 201);
	DrawArc(50, -400, 201, 490, 106, -40, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-80,70,202);
	glVertex3d(-65,80,202);
	glVertex3d(-90,15,202);
	glVertex3d(-75,10,202);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(95, 27, 201.5);
	glVertex3d(85,85,201.5);
	glVertex3d(95,85,201.5);
	glVertex3d(110,30,201.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	DrawCircle(-225, -125, 201,85, 999);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	DrawCircle(325, -125, 201, 85, 999);

	

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(-225, -125, 202, 60, 999);

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-230, -60, 202.5);
	glVertex3d(-220, -60, 202.5);
	glVertex3d(-220, -185, 202.5);
	glVertex3d(-230, -185, 202.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-165, -120, 202.5);
	glVertex3d(-165, -130, 202.5);
	glVertex3d(-285, -130, 202.5);
	glVertex3d(-285, -120, 202.5);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(325, -125, 202, 60, 999);

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(320, -60, 202.5);
	glVertex3d(330, -60, 202.5);
	glVertex3d(330, -185, 202.5);
	glVertex3d(320, -185, 202.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(385, -120, 202.5);
	glVertex3d(385, -130, 202.5);
	glVertex3d(260, -130, 202.5);
	glVertex3d(260, -120, 202.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(-225, -125, 203, 5, 999);
	
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(325, -125, 203, 5, 999);


	
	
	//draw border

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(-225, -125, 200, 110, 331, 235, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(325, -125, 200, 110, 327, 235, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3d(220, -170, 200.5);//p0
	glVertex3d(-100, -175, 200.5);//p1



	glVertex3d(-350, -175, 200.5);//p2
	glVertex3d(-485, -175, 200.5);//p3
	glVertex3d(-475, -160, 200.5);//p4
	glVertex3d(-465, -160, 200.5);//p5
	//glVertex3d(-450, -175, 150);
	glVertex3d(-450, -170, 200.5);//p6
	glVertex3d(-425, -155, 200.5);//p7
	glVertex3d(-460, -90, 200.5);
	glVertex3d(-495, -125, 200.5);//p8
	glVertex3d(-503, -100, 200.5);//p12

	DrawArc(-145, -490, 200.5, 525, 133, -22.5, 999);

	glVertex3d(-325, 7.5, 200.5);//pp13
	//glVertex3d(-210, 25, 150);//p14
	//glVertex3d(-190, 25, 150);//p15

	DrawArc(-175, -400, 200.5, 440, 92, -18, 999);

	glVertex3d(370, 60, 200.5);//p16
	glVertex3d(540, 30, 200.5);//p19
	glVertex3d(555, -15, 200.5);//p20
	glVertex3d(535, -15, 200.5);//p21
	glVertex3d(540, -60, 200.5);//p25
	glVertex3d(555, -75, 200.5);//p26
	glVertex3d(565, -100, 200.5);//p27
	glVertex3d(550, -100, 200.5);//p28

	DrawArc(280, 125, 200.5, 350, 319, -22.5, 999);

	glEnd();




	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(50, -400, 200.5, 525, +70, 35, 999);
	DrawArc(50, -400, 200.5, 515, 105, -35, 999);
	glEnd();

	

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(50, -400, 200.5, 490, 105, 15, 999);
	glVertex3d(-210, 25, 200.5);
	glVertex3d(-75, 95, 200.5);
	glEnd();

	


	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	DrawArc(50, -400, 201.5, 490, 105, 15, 999);
	DrawArc(-175, -400, 201.5, 425, 92, -14, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3d(-75, 10, 201.5);
	DrawArc(50, -400, 201.5, 490, 106, -40, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	DrawCircle(-225, -125, 201.5, 85, 999);
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	DrawCircle(325, -125, 201.5, 85, 999);

	

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);

	glVertex3d(-475,-160,200);
	glVertex3d(-465,-160,200);
	glVertex3d(-465,-125,200);
	glVertex3d(-475,-125,200);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);

	glVertex3d(-475, -160, -150);
	glVertex3d(-465, -160, -150);
	glVertex3d(-465, -125, -150);
	glVertex3d(-475, -125, -150);
	glEnd();

	//another side
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	DrawArc(-225, -125, -150.5, 100, 331, 235, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	DrawArc(325, -125, -150.5, 100, 327, 235, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(220, -170, -150);//p0
	glVertex3d(-100, -175, -150);//p1



	glVertex3d(-350, -175, -150);//p2
	glVertex3d(-485, -175, -150);//p3
	glVertex3d(-475, -160, -150);//p4
	glVertex3d(-465, -160, -150);//p5
	//glVertex3d(-450, -175, 150);
	glVertex3d(-450, -170, -150);//p6
	glVertex3d(-425, -155, -150);//p7
	glVertex3d(-460, -90, -150);
	glVertex3d(-495, -125, -150);//p8
	glVertex3d(-503, -100, -150);//p12

	DrawArc(-145, -490, -150, 525, 133, -22.5, 999);

	glVertex3d(-325, 7.5, -150);//pp13

	DrawArc(-175, -400, -150, 440, 92, -18, 999);

	glVertex3d(370, 60, -150);//p16
	glVertex3d(540, 30, -150);//p19
	glVertex3d(555, -15, -150);//p20
	glVertex3d(535, -15, -150);//p21
	glVertex3d(540, -60, -150);//p25
	glVertex3d(555, -75, -150);//p26
	glVertex3d(565, -100, -150);//p27
	glVertex3d(550, -100, -150);//p28

	DrawArc(280, 125, -150, 350, 319, -22.5, 999);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, .5, .5);
	glVertex3d(-325, 7.5, -150);
	glVertex3d(-210, 25, -150);
	glVertex3d(-75, 95, -150);
	glVertex3d(-80, 110, -150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	DrawArc(50, -400, -150, 525, +70, 35, 999);
	DrawArc(50, -400, -150, 515, 105, -35, 999);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	DrawArc(50, -400, -150, 490, 105, 15, 999);
	glVertex3d(-210, 25, -150);
	glVertex3d(-75, 95, -150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(370, 60, -150);
	DrawArc(50, -400, -150, 515, 70, 35, 999);
	DrawArc(50, -400, -150, 490, 105, -39, 999);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(.5, .5, .5);
	DrawArc(50, -400, -151, 490, 105, 15, 999);
	DrawArc(-175, -400, -151, 425, 92, -14, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.5, .5, .5);
	glVertex3d(-75, 10, -151);
	DrawArc(50, -400, -151, 490, 106, -40, 999);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-80, 70, -152);
	glVertex3d(-65, 80, -152);
	glVertex3d(-90, 15, -152);
	glVertex3d(-75, 10, -152);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(95, 27, -151.5);
	glVertex3d(85, 85, -151.5);
	glVertex3d(95, 85, -151.5);
	glVertex3d(110, 30, -151.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	DrawCircle(-225, -125, -151, 85, 999);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	DrawCircle(325, -125, -151, 85, 999);



	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(-225, -125, -152, 60, 999);

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-230, -60, -152.5);
	glVertex3d(-220, -60, -152.5);
	glVertex3d(-220, -185, -152.5);
	glVertex3d(-230, -185, -152.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-165, -120, -152.5);
	glVertex3d(-165, -130, -152.5);
	glVertex3d(-285, -130, -152.5);
	glVertex3d(-285, -120, -152.5);
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(325, -125, -152, 60, 999);

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(320, -60, -152.5);
	glVertex3d(330, -60, -152.5);
	glVertex3d(330, -185, -152.5);
	glVertex3d(320, -185, -152.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(385, -120, -152.5);
	glVertex3d(385, -130, -152.5);
	glVertex3d(260, -130, -152.5);
	glVertex3d(260, -120, -152.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(-225, -125, -153, 5, 999);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(325, -125, -153, 5, 999);




	//draw border

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(-225, -125, -150, 110, 331, 235, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(325, -125, -150, 110, 327, 235, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3d(220, -170, -150);//p0
	glVertex3d(-100, -175, -150);//p1



	glVertex3d(-350, -175, -150.5);//p2
	glVertex3d(-485, -175, -150.5);//p3
	glVertex3d(-475, -160, -150.5);//p4
	glVertex3d(-465, -160, -150.5);//p5
	//glVertex3d(-450, -175, 150);
	glVertex3d(-450, -170, -150.5);//p6
	glVertex3d(-425, -155, -150.5);//p7
	glVertex3d(-460, -90, -150.5);
	glVertex3d(-495, -125, -150.5);//p8
	glVertex3d(-503, -100, -150.5);//p12

	DrawArc(-145, -490, -150.5, 525, 133, -22.5, 999);

	glVertex3d(-325, 7.5, -150.5);//pp13
	//glVertex3d(-210, 25, 150);//p14
	//glVertex3d(-190, 25, 150);//p15

	DrawArc(-175, -400, -150.5, 440, 92, -18, 999);

	glVertex3d(370, 60, -150.5);//p16
	glVertex3d(540, 30, -150.5);//p19
	glVertex3d(555, -15, -150.5);//p20
	glVertex3d(535, -15, -150.5);//p21
	glVertex3d(540, -60, -150.5);//p25
	glVertex3d(555, -75, -150.5);//p26
	glVertex3d(565, -100, -150.5);//p27
	glVertex3d(550, -100, -150.5);//p28

	DrawArc(280, 125, -150.5, 350, 319, -22.5, 999);

	glEnd();




	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(50, -400, -150.5, 525, +70, 35, 999);
	DrawArc(50, -400, -150.5, 515, 105, -35, 999);
	glEnd();



	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(50, -400, -150.5, 490, 105, 15, 999);
	glVertex3d(-210, 25, -150.5);
	glVertex3d(-75, 95, -150.5);
	glEnd();




	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	DrawArc(50, -400, -151.5, 490, 105, 15, 999);
	DrawArc(-175, -400, -151.5, 425, 92, -14, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3d(-75, 10, -151.5);
	DrawArc(50, -400, -151.5, 490, 106, -40, 999);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	DrawCircle(-225, -125, -151.5, 85, 999);
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	DrawCircle(325, -125, -151.5, 85, 999);



	//TOP VIEW
	for (int l = 200; l >= -150; l--)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(1, 0, 0);
		DrawArc(50, -400, l, 525, 70, 35, 999);
		glEnd();
	}

	for (int m = 200; m >= 150; m--)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(-225, -125, m, 85, 999);
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(325, -125, m, 85, 999);
		if (m == 151)
		{
			glBegin(GL_POLYGON);
			glColor3f(0, 0, 0);
			DrawCircle(-225, -125, m, 85, 999);
			glBegin(GL_POLYGON);
			glColor3f(0, 0, 0);
			DrawCircle(325, -125, m, 85, 999);
		}
	}
	



	for (int m = -150; m <= -100; m++)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(-225, -125, m, 85, 999);
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(325, -125, m, 85, 999);
		if (m == -101)
		{
			glBegin(GL_POLYGON);
			glColor3f(0, 0, 0);
			DrawCircle(-225, -125, m, 85, 999);
			glBegin(GL_POLYGON);
			glColor3f(0, 0, 0);
			DrawCircle(325, -125, m, 85, 999);
	
			glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			DrawCircle(-225, -125,-101.8 , 85, 999);
			glBegin(GL_LINE_LOOP);
			glColor3f(1,1,1);
			DrawCircle(325, -125, -101.8, 85, 999);
		}
	}


	for (int o = -215; o >= -315; o--)
	{

		glBegin(GL_POLYGON);
		glColor4f(0, 0, 1, 0.5);
		DrawCirclez(0, o, 0, 600, 999);

	}

	for (int z1 = 200; z1 >= -150; z1--)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(1, 0, 0);
		DrawArc(-145, -490, z1, 525, 133, -22.5, 999);
		glEnd();
	}


	for (int z2 = 200; z2 >= -150; z2--)
	{
		glColor3f(1, 0, 0);
		glBegin(GL_LINE_STRIP);
		DrawArc(280, 125, z2, 350, 319, -22.5, 999);
		glEnd();
	}

	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(.5, .5, .5,.4);
	glVertex3d(-330,0,200);
	glVertex3d(-80, 110, 200);
	glVertex3d(-80, 110, -150);
	glVertex3d(-330, 0, -150);
	glEnd();
	glDisable(GL_BLEND);

	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex3d(-330, 1, 200);
	glVertex3d(-80, 111, 200);
	glVertex3d(-80, 111, 180);
	glVertex3d(-330, 1, 180);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-80, 111, -150);
	glVertex3d(-330, 1, -150);
	glVertex3d(-330, 1, -130);
	glVertex3d(-80, 111, -130);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3f(540,30,200);
	glVertex3f(220,85,200);
	glVertex3f(220,85,-150);
	glVertex3f(540,30,-150);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(220, 85, 200);
	glVertex3f(225, 95, 200);
	glVertex3f(225, 95, -150);
	glVertex3f(220, 85, -150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(540,30,200);
	glVertex3d(555,-15,200);
	glVertex3d(555,-15,-150);
	glVertex3d(540,30,-150);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(555,-15,200);
	glVertex3d(535,-15,200);
	glVertex3d(535,-15,-150);
	glVertex3d(555,-15,-150);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(535,-15,200);
	glVertex3d(540,-60,200);
	glVertex3d(540,-60,-150);
	glVertex3d(535,-15,-150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(540,-60,200);
	glVertex3d(555,-75,200);
	glVertex3d(555,-75,-150);
	glVertex3d(540,-60,-150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(555,-75,200);
	glVertex3d(565,-100,200);
	glVertex3d(565,-100,-150);
	glVertex3d(555,-75,-150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(565,-100,200);
	glVertex3d(540,-105,200);
	glVertex3d(540,-100,-150);
	glVertex3d(565,-105,-150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(-495,-125,200);
	glVertex3d(-503,-100,200);
	glVertex3d(-503,-100,-150);
	glVertex3d(-495,-125,-150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(-495,-125,200);
	glVertex3d(-475,-125,200);
	glVertex3d(-475,-125,-150);
	glVertex3d(-495,-125,-150);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3d(-475,-125,200);
	glVertex3d(-475,-160,200);
	glVertex3d(-475,-160,-150);
	glVertex3d(-475,-125,-150);
	glEnd();



	glBegin(GL_POLYGON);
	glVertex3d(-475,-160,200);
	glVertex3d(-485,-175,200);
	glVertex3d(-485,-175,-150);
	glVertex3d(-475,-160,-150);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(-475,-155,200);
	glVertex3d(-445,-110,200);
	glVertex3d(-445,-110,-150);
	glVertex3d(-475,-155,-150);
	glEnd();



}
void draw1()//car2
{

	/*glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3d(400, 400, 200);
	glVertex3d(-400, 400, 200);
	glVertex3d(-400, -400, 200);
	glVertex3d(400, -400, 200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3d(400, 400, -200);
	glVertex3d(-400, 400, -200);
	glVertex3d(-400, -400,-200);
	glVertex3d(400, -400, -200);
	glEnd();
	*/
	

	glBegin(GL_POLYGON);
	
	glColor3f(1, 0, 0);

	glVertex3d(-190, -110, 200);//p0
	glVertex3d(-355, -110, 200);//p3
	glVertex3d(-370,-100,200);//p4
	glVertex3d(-415,-95,200);//p5
	glVertex3d(-455,-70,200);//p6
	glVertex3d(-470,-70,200);//p7
	glVertex3d(-475,-60,200);//p8
	glVertex3d(-475,-25,200);//p9
	glVertex3d(-470,-20,200);//p10
	glVertex3d(-465,-20,200);//p11
	glVertex3d(-460,-15,200);//p12
	glVertex3d(-430,55,200);//p13
	glVertex3d(-445,62,200);//p14
	glVertex3d(-335,65,200);//p15
	glVertex3d(-330,70,200);//p17
	glVertex3d(160,47.5,200);//p18
	glVertex3d(125,75,200);//p19
	glVertex3d(52,120,200);//p20
	glVertex3d(52,125,200);//p21
	glVertex3d(60,132.5,200);//p22
	glVertex3d(80,125,200);//p23
	glVertex3d(70,120,200);//p24
	glVertex3d(123,87,200);//p25
	glVertex3d(192.5,45,200);//p26
	glVertex3d(215,47.5,200);//p27
	glVertex3d(245,50,200);//p28
	glVertex3d(250,49,200);//p29
	glVertex3d(395,30,200);//p30
	glVertex3d(446, 9, 200);//added point
	glVertex3d(447.5,7.5,200);//p31
	glVertex3d(450,10,200);//p32
	glVertex3d(447.5,2.5,200);//p33
	glVertex3d(450,-5,200);//p34
	glVertex3d(455,-2.5,200);//p35
	glVertex3d(465,-17.5,200);//p36
	glVertex3d(463,-21.5,200);//p37
	glVertex3d(475,-37,200);//p38
	glVertex3d(475,-65,200);//p39
	glVertex3d(470,-70,200);//p40
	glVertex3d(465,-97,200);//p41
	glVertex3d(469,-100,200);//p42
	glVertex3d(467,-102,200);//p43
	glVertex3d(450,-105,200);//p44
	glVertex3d(365,-110,200);//p45
	glVertex3d(193,-110,200);//p46
	glVertex3d(165,-105,200);//p47
	glEnd();


	glBegin(GL_LINE_LOOP);

	glColor3f(0, 0, 0);

	glVertex3d(-190, -110, 201);//p0
	glVertex3d(-355, -110, 201);//p3
	glVertex3d(-370, -100, 201);//p4
	glVertex3d(-415, -95, 201);//p5
	glVertex3d(-455, -70, 201);//p6
	glVertex3d(-470, -70, 201);//p7
	glVertex3d(-475, -60, 201);//p8
	glVertex3d(-475, -25, 201);//p9
	glVertex3d(-470, -20, 201);//p10
	glVertex3d(-465, -20, 201);//p11
	glVertex3d(-460, -15, 201);//p12
	glVertex3d(-430, 55, 201);//p13
	glVertex3d(-445, 62, 201);//p14
	glVertex3d(-335, 65, 201);//p15
	glVertex3d(-330, 70, 201);//p17
	glVertex3d(160, 47.5, 201);//p18
	glVertex3d(125, 75, 201);//p19
	glVertex3d(52, 120, 201);//p20
	glVertex3d(52, 125, 201);//p21
	glVertex3d(60, 132.5, 201);//p22
	glVertex3d(80, 125, 201);//p23
	glVertex3d(70, 120, 201);//p24
	glVertex3d(123, 87, 201);//p25
	glVertex3d(192.5, 45, 201);//p26
	glVertex3d(215, 47.5, 201);//p27
	glVertex3d(245, 50, 201);//p28
	glVertex3d(250, 49, 201);//p29
	glVertex3d(395, 30, 201);//p30
	glVertex3d(446, 9, 201);//added point
	glVertex3d(447.5, 7.5, 201);//p31
	glVertex3d(450, 10, 201);//p32
	glVertex3d(447.5, 2.5, 201);//p33
	glVertex3d(450, -5, 201);//p34
	glVertex3d(455, -2.5, 201);//p35
	glVertex3d(465, -17.5, 201);//p36
	glVertex3d(463, -21.5, 201);//p37
	glVertex3d(475, -37, 201);//p38
	glVertex3d(475, -65, 201);//p39
	glVertex3d(470, -70, 201);//p40
	glVertex3d(465, -97, 201);//p41
	glVertex3d(469, -100, 201);//p42
	glVertex3d(467, -102, 201);//p43
	glVertex3d(450, -105, 201);//p44
	glVertex3d(365, -110, 201);//p45
	glVertex3d(193, -110, 201);//p46
	glVertex3d(165, -105, 201);//p47
	glEnd();

	
	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(0.50, 0.50, 0.50,0.4);

	glVertex3d(80, 125, 200);//p23
	glVertex3d(70, 120, 200);//p24
	glVertex3d(123, 87, 200);//p25
	glVertex3d(192.5, 45, 200);//p26
	glVertex3d(225, 48, 200);
	glEnd();
	
	//glDisable(GL_BLEND);

	/*glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0);
	glVertex3d(-330,70,201);
	glVertex3d(160,47.5,201);
	glVertex3d(52,125,201);
	glEnd();*/
	
	glBegin(GL_POLYGON);
	glColor3f(.5, .5, 0.5);
	//glVertex3d(-275, -80, 200);
	//glVertex3d(-190, -110, 200);

	DrawArc(-275, -80, 200.5, 80, 337, 225, 999);
	
	//glVertex3d(-355, -110, 200);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(.5, .5, 0.5);
	//glVertex3d(275, -80, 200);
	///glVertex3d(365, -110, 200);

	DrawArc(275, -80, 200.5, 80, 337, 225, 999);

	//glVertex3d(193, -110, 200);

	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	DrawCircle(-275, -80, 201, 70, 999);
	
	glBegin(GL_POLYGON);
	DrawCircle(275, -80, 201, 70, 999);
	
	
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(-275, -80, 201.5, 50, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(-275, -80, 202.5, 45, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(-275, -80, 202.5, 35, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(-275, -80, 202.5, 5, 999);


	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(275, -80, 201.5, 50, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(275, -80, 202.5, 45, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(275, -80, 202.5, 35, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(275, -80, 202.5, 5, 999);
	
	
	//WINDOW
	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(0.5, 0.5, 0.5,.4);
	glVertex3d(52,125,202);
	
	glVertex3d(-70,120,202);

	glVertex3d(-60,60,202);

	glVertex3d(160,47.5,202);

	glEnd();
	//glDisable(GL_BLEND);


	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3d(-60,60,201);
    glVertex3d(-85,30,201);
	glVertex3d(-80,-30,201);
	glVertex3d(-75,-40,201);
	glVertex3d(-75,-65,201);
	glVertex3d(-65,-85,201);
	glVertex3d(160,-85,201);
	glVertex3d(180, -80, 201);
	glVertex3d(185,-65,201);
	glVertex3d(185,-35,201);
	glVertex3d(185,-20,201);
	glVertex3d(180,25,201);
	glVertex3d(160,47.5,201);
	glEnd();


	//top for sideview
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	DrawArc(-75, -315, 200, 470, 72, 32, 999);
	glVertex3d(-330, 70, 200);
	//glVertex3d(-210, 55, 200);
	glVertex3d(-205, 65, 200);
	//DrawArc(0, -200, 201, 335, 127, -25, 999);
	glVertex3d(52, 125, 200);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	DrawArc(0, -200, 201, 335, 102, 25, 999);
	//glVertex3d(-210, 55, 205);
	DrawArc(0, -200, 201, 330, 127, -25, 999);
	glEnd();

	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(0.5, .5, .5,.4);
	glVertex3d(-60,60,202);
	DrawArc(0, -200, 202, 330, 102, 25, 999);
	glEnd();
	//glDisable(GL_BLEND);
	

	

	//
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0,0.0);
	glVertex3d(-70, 125, 203);
	glVertex3d(-60, 60, 203);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);

	glVertex3d(-70, 125, 203);
	glVertex3d(-70, 120, 203);
	glVertex3d(60, 120, 203);
	glVertex3d(52, 125, 203);
	glEnd();


	//door lock
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3d(-60, 35, 201);
	glVertex3d(-75, 30, 201);
	glVertex3d(-70, 25, 201);
	glVertex3d(-50, 20, 201);
	glVertex3d(-45, 20, 201);
	glVertex3d(-40, 25, 201);
	glVertex3d(-30, 30, 201);
	glVertex3d(-35, 35, 201);
	glVertex3d(-70, 35, 201);
	glEnd();



	//FOR FUEL PORT
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);

	glVertex3d(-345,45,201);
	glVertex3d(-350,40,201);

	glVertex3d(-350,20,201);
	glVertex3d(-345, 15, 201);

	glVertex3d(-320, 15, 201);
	glVertex3d(-315,20,201);

	glVertex3d(-315,40,200);
	glVertex3d(-320, 45, 200);

	glEnd();


	

	

	//another side with z axis
	glBegin(GL_POLYGON);

	glColor3f(1, 0, 0);

	glVertex3d(-190, -110, -200);//p0
	glVertex3d(-355, -110, -200);//p3
	glVertex3d(-370, -100, -200);//p4
	glVertex3d(-415, -95, -200);//p5
	glVertex3d(-455, -70, -200);//p6
	glVertex3d(-470, -70, -200);//p7
	glVertex3d(-475, -60, -200);//p8
	glVertex3d(-475, -25, -200);//p9
	glVertex3d(-470, -20, -200);//p10
	glVertex3d(-465, -20, -200);//p11
	glVertex3d(-460, -15, -200);//p12
	glVertex3d(-430, 55, -200);//p13
	glVertex3d(-445, 62, -200);//p14
	glVertex3d(-335, 65, -200);//p15
	glVertex3d(-330, 70, -200);//p17
	glVertex3d(160, 47.5, -200);//p18
	glVertex3d(125, 75, -200);//p19
	glVertex3d(52, 120, -200);//p20
	glVertex3d(52, 125, -200);//p21
	glVertex3d(60, 132.5, -200);//p22
	glVertex3d(80, 125, -200);//p23
	glVertex3d(70, 120, -200);//p24
	glVertex3d(123, 87, -200);//p25
	glVertex3d(192.5, 45, -200);//p26
	glVertex3d(215, 47.5, -200);//p27
	glVertex3d(245, 50, -200);//p28
	glVertex3d(250, 49, -200);//p29
	glVertex3d(395, 30, -200);//p30
	glVertex3d(446, 9, -200);//added point
	glVertex3d(447.5, 7.5, -200);//p31
	glVertex3d(450, 10, -200);//p32
	glVertex3d(447.5, 2.5, -200);//p33
	glVertex3d(450, -5, -200);//p34
	glVertex3d(455, -2.5, -200);//p35
	glVertex3d(465, -17.5, -200);//p36
	glVertex3d(463, -21.5, -200);//p37
	glVertex3d(475, -37, -200);//p38
	glVertex3d(475, -65, -200);//p39
	glVertex3d(470, -70, -200);//p40
	glVertex3d(465, -97, -200);//p41
	glVertex3d(469, -100, -200);//p42
	glVertex3d(467, -102, -200);//p43
	glVertex3d(450, -105, -200);//p44
	glVertex3d(365, -110, -200);//p45
	glVertex3d(193, -110, -200);//p46
	glVertex3d(165, -105, -200);//p47
	glEnd();


	glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
	glVertex3d(-190, -110, -201);//p0
	glVertex3d(-355, -110, -201);//p3
	glVertex3d(-370, -100, -201);//p4
	glVertex3d(-415, -95, -201);//p5
	glVertex3d(-455, -70, -201);//p6
	glVertex3d(-470, -70, -201);//p7
	glVertex3d(-475, -60, -201);//p8
	glVertex3d(-475, -25, -201);//p9
	glVertex3d(-470, -20, -201);//p10
	glVertex3d(-465, -20, -201);//p11
	glVertex3d(-460, -15, -201);//p12
	glVertex3d(-430, 55, -201);//p13
	glVertex3d(-445, 62, -201);//p14
	glVertex3d(-335, 65, -201);//p15
	glVertex3d(-330, 70, -201);//p17
	glVertex3d(160, 47.5, -201);//p18
	glVertex3d(125, 75, -201);//p19
	glVertex3d(52, 120, -201);//p20
	glVertex3d(52, 125, -201);//p21
	glVertex3d(60, 132.5, -201);//p22
	glVertex3d(80, 125, -201);//p23
	glVertex3d(70, 120, -201);//p24
	glVertex3d(123, 87, -201);//p25
	glVertex3d(192.5, 45, -201);//p26
	glVertex3d(215, 47.5, -201);//p27
	glVertex3d(245, 50, -201);//p28
	glVertex3d(250, 49, -201);//p29
	glVertex3d(395, 30, -201);//p30
	glVertex3d(446, 9, -201);//added point
	glVertex3d(447.5, 7.5, -201);//p31
	glVertex3d(450, 10, -201);//p32
	glVertex3d(447.5, 2.5, -201);//p33
	glVertex3d(450, -5, -201);//p34
	glVertex3d(455, -2.5, -201);//p35
	glVertex3d(465, -17.5, -201);//p36
	glVertex3d(463, -21.5, -201);//p37
	glVertex3d(475, -37, -201);//p38
	glVertex3d(475, -65, -201);//p39
	glVertex3d(470, -70, -201);//p40
	glVertex3d(465, -97, -201);//p41
	glVertex3d(469, -100, -201);//p42
	glVertex3d(467, -102, -201);//p43
	glVertex3d(450, -105, -201);//p44
	glVertex3d(365, -110, -201);//p45
	glVertex3d(193, -110, -201);//p46
	glVertex3d(165, -105, -201);//p47
	glEnd();

	
	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(0.50, 0.50, 0.50,.4);
    glVertex3d(80, 125, -200);//p23
	glVertex3d(70, 120, -200);//p24
	glVertex3d(123, 87, -200);//p25
	glVertex3d(192.5, 45, -200);//p26
	glVertex3d(225, 48, -200);
	glEnd();
	//glDisable(GL_BLEND);


	glBegin(GL_POLYGON);
	glColor3d(1.0, 1.0, 1.0);
	glVertex3d(-200,60,-201);
	glVertex3d(160,47.5,-201);
	glVertex3d(52,125,-201);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(.5, .5, 0.5);
	DrawArc(-275, -80, -200.5, 80, 337, 225, 999);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.5, .5, 0.5);
	DrawArc(275, -80, -200.5, 80, 337, 225, 999);
    glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	DrawCircle(-275, -80, -201, 70, 999);

	glBegin(GL_POLYGON);
	DrawCircle(275, -80, -201, 70, 999);


	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(-275, -80, -201.5, 50, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(-275, -80, -202.5, 45, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(-275, -80, -202.5, 35, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(-275, -80, -202.5, 5, 999);

	//BORDER
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	DrawCircle(275, -80, -201.5, 50, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(275, -80, -202.5, 45, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(275, -80, -202.5, 35, 999);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	DrawCircle(275, -80, -202.5, 5, 999);


	//WINDOW
	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(0.5, 0.5, 0.5,.4);
	glVertex3d(52, 125, -202);
	glVertex3d(-70, 120, -202);
	glVertex3d(-60, 60, -202);
	glVertex3d(160, 47.5, -202);
	glEnd();
	//glDisable(GL_BLEND);


	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex3d(-60, 60, -201);
	glVertex3d(-85, 30, -201);
	glVertex3d(-80, -30, -201);
	glVertex3d(-75, -40, -201);
	glVertex3d(-75, -65, -201);
	glVertex3d(-65, -85, -201);
	glVertex3d(160, -85, -201);
	glVertex3d(180, -80, -201);
	glVertex3d(185, -65, -201);
	glVertex3d(185, -35, -201);
	glVertex3d(185, -20, -201);
	glVertex3d(180, 25, -201);
	glVertex3d(160, 47.5, -201);
	glEnd();


	//top
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	DrawArc(-75, -315, -200, 470, 72, 32, 999);
	glVertex3d(-330, 70, -200);
	glVertex3d(-205, 65, -200);
	glVertex3d(52, 125, -200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	DrawArc(0, -200, -201, 335, 102, 25, 999);
	DrawArc(0, -200, -201, 330, 127, -25, 999);
	glEnd();

	//glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(0.5, .5, .5,.4);
	glVertex3d(-60, 60, -202);
	DrawArc(0, -200, -202, 330, 102, 25, 999);
	glEnd();
	//glDisable(GL_BLEND);


	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3d(-70, 125, -203);
	glVertex3d(-60, 60, -203);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);

	glVertex3d(-70, 125, -203);
	glVertex3d(-70, 120, -203);
	glVertex3d(60, 120, -203);
	glVertex3d(52, 125, -203);
	glEnd();



	////////////////////////////////////TOP VIEW//////////////////////////////
	
	for (int l = 200; l >= -200; l--)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 0);
		DrawArc(-75, -315, l, 470, 72, 32, 999);
		glEnd();
	}

	for (int m = 200; m >= 150; m--)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(-275, -80, m, 70, 999);
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(275, -80, m, 70, 999);
	}
	glBegin(GL_POLYGON);
	DrawCircle(275, -80, 150, 70, 999);
	glBegin(GL_POLYGON);
	DrawCircle(-275, -80, 150, 70, 999);


	for (int m = -200; m <= -150; m++)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(-275, -80, m, 70, 999);
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		DrawCircle(275, -80, m, 70, 999);
	}

	glBegin(GL_POLYGON);
	DrawCircle(275, -80, -150, 70, 999);
	glBegin(GL_POLYGON);
	DrawCircle(-275, -80, -150, 70, 999);


	for (int o = -150; o >= -250; o--)
	{
		
		glBegin(GL_POLYGON);
		glColor4f(0,0,1,0.5);
		DrawCirclez(0, o, 0, 600, 999);
		
	}




	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(60,132.5,200);
	glVertex3d(80,125,200);
	glVertex3d(80,125,-200);
	glVertex3d(60,132.5,-200);
	glEnd();

	glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(.5, .5, .5,.4);
	glVertex3d(80,125,200);
	glVertex3d(215,47.5,200);
	glVertex3d(215,47.5,-200);
	glVertex3d(80,125,-200);
	glEnd();
	glDisable(GL_BLEND);


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(245, 50, 200);//p28
	glVertex3d(250, 49, 200);//p29
	glVertex3d(250, 49, -200);
	glVertex3d(245, 49, -200);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(250, 49, 200);//p29
	glVertex3d(395, 30, 200);//p30
	glVertex3d(395, 30, -200);
	glVertex3d(250, 49, -200);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(215,47.5,200);
	glVertex3d(245,50,200);
	glVertex3d(245, 50, -200);
	glVertex3d(215, 47.5, -200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(395, 30, 200);
	glVertex3d(447.5, 7.5, 200);
	glVertex3d(447.5, 7.5, -200);
	glVertex3d(395, 30, -200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(447.5, 7.5, -200);//p31
	glVertex3d(450, 10, -200);//p32
	glVertex3d(447.5, 2.5, -200);//p33
	glVertex3d(450, -5, -200);//p34
	glVertex3d(455, -2.5, -200);//p35
	glVertex3d(465, -17.5, -200);//p36
	glVertex3d(463, -21.5, -200);//p37
	glVertex3d(475, -37, -200);//p38
	glVertex3d(475, -65, -200);//p39
	glVertex3d(470, -70, -200);//p40
	glVertex3d(465, -97, -200);//p41
	glVertex3d(469, -100, -200);//p42
	glVertex3d(467, -102, -200);//p43

	glVertex3d(467, -102, 200);//p43
	glVertex3d(469, -100, 200);//p42
	glVertex3d(465, -97, 200);//p41
	glVertex3d(470, -70, 200);//p40
	glVertex3d(475, -65, 200);//p39
	glVertex3d(475, -37, 200);//p38
	glVertex3d(463, -21.5, 200);//p37
	glVertex3d(465, -17.5, 200);//p36
	glVertex3d(455, -2.5, 200);//p35
	glVertex3d(450, -5, 200);//p34
	glVertex3d(447.5, 2.5, 200);//p33
	glVertex3d(450, 10, 200);//p32
	glVertex3d(447.5, 7.5, 200);//p31

	glEnd();





	//top extended
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-330, 70, 200);//p17
	glVertex3d(-80, 145, 200);
	glVertex3d(-80, 145, -200);
	glVertex3d(-330, 70, -200);
	glEnd();

	
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-330,70,200);//p17
	glVertex3d(-335, 65, 200);//p15
	glVertex3d(-355, 65, -200);
	glVertex3d(-330, 70, -200);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-335,65,200);//p15
	glVertex3d(-445,62,200);//p14
	glVertex3d(-445, 62, -200);
	glVertex3d(-335, 65, -200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-430,55,200);//p13
	glVertex3d(-445, 62, 200);//p14
	glVertex3d(-445, 62, -200);
	glVertex3d(-430, 55, -200);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-355, -110, 200);//p3
	glVertex3d(-370, -100, 200);//p4
	glVertex3d(-370, -100, -200);//p4
	glVertex3d(-355, -110, -200);//p3
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-370, -100, 200);//p4
	glVertex3d(-415, -95, 200);//p5
	glVertex3d(-415, -95, -200);//p5
	glVertex3d(-370, -100, -200);//p4
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-415, -95, 200);//p5
	glVertex3d(-455, -70, 200);//p6
	glVertex3d(-455, -70, -200);//p6
	glVertex3d(-415, -95, -200);//p5
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-455, -70, 200);//p6
	glVertex3d(-470, -70, 200);//p7
	glVertex3d(-470, -70, -200);//p7
	glVertex3d(-455, -70, -200);//p6
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-470, -70, 200);//p7
	glVertex3d(-475, -60, 200);//p8
	glVertex3d(-475, -60, -200);//p8
	glVertex3d(-470, -70, -200);//p7
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-475, -60, 200);//p8
	glVertex3d(-475, -25, 200);//p9
	glVertex3d(-475, -25, -200);//p9
	glVertex3d(-475, -60, -200);//p8
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-475, -25, 200);//p9
	glVertex3d(-470, -20, 200);//p10
	glVertex3d(-470, -20, -200);//p10
	glVertex3d(-475, -25, -200);//p9
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-470, -20, 200);//p10
	glVertex3d(-465, -20, 200);//p11
	glVertex3d(-465, -20, -200);//p11
	glVertex3d(-470, -20, -200);//p10
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-465, -20, 200);//p11
	glVertex3d(-460, -15, 200);//p12
	glVertex3d(-460, -15, -200);//p12
	glVertex3d(-465, -20, -200);//p11
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex3d(-460, -15, 200);//p12
	glVertex3d(-430, 55, 200);//p13
	glVertex3d(-430, 55, -200);//p13
	glVertex3d(-460, -15, -200);//p12
	glEnd();


	//rear window
	glEnable(GL_BLEND);
	glBegin(GL_POLYGON);
	glColor4f(.5, .5, .5,.4);
	glVertex3d(-300, 80, 150);
	glVertex3d(-280, 85, 150);
	glVertex3d(-245, 125, 150);
	glVertex3d(-235, 120, 150);


	glVertex3d(-235, 120, -150);
	glVertex3d(-245, 125, -150);
	glVertex3d(-280, 85, -150);
	glVertex3d(-300, 80, -150);
	glEnd();
	glDisable(GL_BLEND);


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3d(395, 30, 201);
	glVertex3d(395, 30, -201);
	
	
	glEnd();
}


void display(void)
{
	
	// display callback , clear frame buffer an Z buffer ,rotate cube and draw , swap buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	/*void coverpage() 
		{
		
				glDisable(GL_LIGHTING);
				glColor3f(0.5, 0.5, 0.5);
				rasterText(358, 675, "VIDYAVARDHAKA COLLEGE OF ENGINEERING");
				rasterText(500, 650, "MYSORE");
				rasterText(355, 610, "Sixth semester, Computer Science and Engineering");
				rasterText(455, 570, "OpenGL Mini Project On");
				rasterText(390, 540, "\"Car launch\"");
				rasterText(160, 400, "Submitted By :");
				rasterText(190, 350, "M M Vinaykumar (4VV12CS025)");
				rasterText(190, 300, "Madhukumar (4VV12CS026)");
				rasterText(680, 400, "Under the Guidence of :");
				rasterText(710, 350, "Sunitha B K");
				rasterText(710, 300, "Assistant Professor,");
				rasterText(710, 250, "Department of CS&E");
				strokeText(430, 100, "Press ENTER to go to next screen");
				glEnable(GL_LIGHTING);
				glFlush();
				glutSwapBuffers();
			}

*/


	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	//colorcube();
	
	if (c1flag==1)draw();
	if (c2flag == 1)draw1();
	glFlush();
	glutSwapBuffers();
}
void spinCube()
{
	// idle callback,spin cube 2 degreees about selected axis
	theta[axis] += 1.0;
	if (theta[axis]>180.0)
		theta[axis] -= 180.0;
	glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y)
{
	//mouse calback ,select an axis about which to rotate
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		axis = 2; menuoptions();
	}
}
void myReshape(int w, int h)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-800.0, 800.0, -500.0, 500.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//need both double buffering and Zbuffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1290.44, 755.90);
	glutCreateWindow("Rotating a color cube ");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	
	glutIdleFunc(spinCube);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);  //Enable hidden surface removal
	glutMainLoop();
	return 0;
}