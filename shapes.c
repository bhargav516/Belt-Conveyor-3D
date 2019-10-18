#define changecols8 glColor3f(colors[0]*0.85f, colors[1]*0.85f, colors[2]*0.85f)
#define changecols7 glColor3f(colors[0]*0.75f, colors[1]*0.75f, colors[2]*0.75f)
#define changecols6 glColor3f(colors[0]*0.65f, colors[1]*0.65f, colors[2]*0.65f)
#define changecols5 glColor3f(colors[0]*0.55f, colors[1]*0.55f, colors[2]*0.55f)
#define changecols4 glColor3f(colors[0]*0.45f, colors[1]*0.45f, colors[2]*0.45f)

void draw_sphere(float radius);
void draw_cuboid(float width, float height, float thick);
void draw_closed_cylinder(float radius, float thick);
void draw_centered_closed_cylinder(float radius, float thick);

//prototype generic coloring routines

void color_darken(void);

void color_darken(void){
// ###################################
// Darkens the current drawing colour.
// ###################################
glGetFloatv(GL_CURRENT_COLOR, colors);
changecols8;
};

void draw_closed_cylinder(float radius, float thick){
// ###################################
// Draws a closed cylinder from [zero] extending [thick]
// ###################################
glPushMatrix();
glRotatef(90,1,0,0);


glRotatef(180,0,1,0);
gluDisk(quadDisk, 0, radius, 32, 1);
glRotatef(-180,0,1,0);
color_darken();
gluCylinder(quadCylinder, radius, radius, thick, 32, 16);
glTranslatef(0,0,thick);
color_darken();
gluDisk(quadDisk, 0, radius, 32, 1);
glPopMatrix();
};

void draw_centered_closed_cylinder(float radius, float thick){
// ###################################
// Draws a [centered on zero] closed cylinder. Relys on closed_cylinder.
// ###################################
glPushMatrix();
glTranslatef(0,0,-(thick/2));
draw_closed_cylinder(radius, thick);
glPopMatrix();
}


void draw_sphere(float radius){
// ###################################
// Draws a [centered on zero] sphere.
// ###################################
gluSphere(quadSphere, radius, 32, 16);
}

void draw_cuboid(float width, float height, float thick){
// ###################################
// Draws a [centered on zeros] cubic thing, extending from [zero].
// ###################################
glPushMatrix();
 glBegin(GL_TRIANGLES);
   glVertex3f( (width/2), (height/2),0); //V1
   glVertex3f( (width/2),-(height/2),0); //V2
   glVertex3f( (width/2),-(height/2),thick); //V3
   glVertex3f( (width/2), (height/2),0); //V1
   glVertex3f( (width/2),-(height/2),thick); //V3
   glVertex3f( (width/2), (height/2),thick); //V4
   glVertex3f(-(width/2), (height/2),0); //V5
   glVertex3f( (width/2), (height/2),0); //V1
   glVertex3f( (width/2), (height/2),thick); //V4
   glVertex3f(-(width/2), (height/2),0); //V5
   glVertex3f( (width/2), (height/2),thick); //V4
   glVertex3f(-(width/2), (height/2),thick); //V8
   glVertex3f(-(width/2), (height/2),thick); //V8
   glVertex3f(-(width/2),-(height/2),thick); //V7
   glVertex3f(-(width/2),-(height/2),0); //V6
   glVertex3f(-(width/2), (height/2),thick); //V8
   glVertex3f(-(width/2),-(height/2),0); //V6
   glVertex3f(-(width/2), (height/2),0); //V5
   glVertex3f(-(width/2),-(height/2),thick); //V7
   glVertex3f( (width/2),-(height/2),0); //V2
   glVertex3f( (width/2),-(height/2),thick); //V3
   glVertex3f(-(width/2),-(height/2),thick); //V7
   glVertex3f(-(width/2),-(height/2),0); //V6
   glVertex3f( (width/2),-(height/2),0); //V2
  glEnd();
  glPopMatrix();
}

void draw_closed_cuboid(float width, float height, float thick){
// ###################################
// Draws a [centered on zeros] cubic thing, extending from [zero].
// ###################################
glPushMatrix();
glGetFloatv(GL_CURRENT_COLOR, colors);
 glBegin(GL_LINE_LOOP);
 
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f((width/2),0,(height/2)); //V2
   glVertex3f((width/2),0,-(height/2)); //V3
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f((width/2),0-thick,(height/2)); //V6
   glVertex3f((width/2),0-thick,-(height/2)); //V7
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   

   //top
   glVertex3f(-(width/2),0, (height/2)); //V1
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f( (width/2),0, (height/2)); //V2
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f( (width/2),0, (height/2)); //V2

   //color_darken();

   changecols8;

   //side1
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f( (width/2),0,(height/2)); //V2
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f( (width/2),0-thick,(height/2)); //V6
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f( (width/2),0,(height/2)); //V2

   changecols7;

   //side2
   glVertex3f( (width/2),0,(height/2)); //V2
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f( (width/2),0-thick,(height/2)); //V6
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f( (width/2),0-thick,-(height/2)); //V7
   glVertex3f( (width/2),0-thick,(height/2)); //V6

   changecols6;

   //side3

   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f( (width/2),0-thick,-(height/2)); //V7
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8

   changecols5;

   //side4
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f(-(width/2),0-thick,(height/2)); //V5

   changecols4;

   //bottom
   glVertex3f( (width/2),0-thick,-(height/2)); //V7
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f( (width/2),0-thick, (height/2)); //V6
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f(-(width/2),0-thick, (height/2)); //V5
   glVertex3f( (width/2),0-thick, (height/2)); //V6

  glEnd();
  glPopMatrix();
}


void draw_closed_cuboid1(float width, float height, float thick){
// ###################################
// Draws a [centered on zeros] cubic thing, extending from [zero].
// ###################################
glPushMatrix();
glGetFloatv(GL_CURRENT_COLOR, colors);
 glBegin(GL_TRIANGLES);
 /*
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f((width/2),0,(height/2)); //V2
   glVertex3f((width/2),0,-(height/2)); //V3
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f((width/2),0-thick,(height/2)); //V6
   glVertex3f((width/2),0-thick,-(height/2)); //V7
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   */

   //top
  

   //color_darken();

   changecols8;

   //side1
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f( (width/2),0,(height/2)); //V2
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f( (width/2),0-thick,(height/2)); //V6
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f( (width/2),0,(height/2)); //V2

   changecols7;

   //side2
   glVertex3f( (width/2),0,(height/2)); //V2
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f( (width/2),0-thick,(height/2)); //V6
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f( (width/2),0-thick,-(height/2)); //V7
   glVertex3f( (width/2),0-thick,(height/2)); //V6

   changecols6;

   //side3

   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f( (width/2),0-thick,-(height/2)); //V7
   glVertex3f( (width/2),0,-(height/2)); //V3
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8

   changecols5;

   //side4
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0-thick,(height/2)); //V5
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f(-(width/2),0,-(height/2)); //V4
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f(-(width/2),0-thick,(height/2)); //V5

   changecols4;

   //bottom
   glVertex3f( (width/2),0-thick,-(height/2)); //V7
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f( (width/2),0-thick, (height/2)); //V6
   glVertex3f(-(width/2),0-thick,-(height/2)); //V8
   glVertex3f(-(width/2),0-thick, (height/2)); //V5
   glVertex3f( (width/2),0-thick, (height/2)); //V6

  glEnd();
  glPopMatrix();
}

void draw_closed_cuboid3(float width, float height, float thick){
// ###################################
// Draws a [centered on zeros] cubic thing, extending from [zero].
// ###################################
glPushMatrix();
glGetFloatv(GL_CURRENT_COLOR, colors);
    glBegin(GL_LINE_LOOP);        // Draw The Cube Using quads
    glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);    // Color Red    
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)

  glEnd();
  glPopMatrix();
}

void draw_closed_triangle(float width, float height, float thick){
// ###################################
// Draws a [centered on zeros] cubic thing, extending from [zero].
// ###################################
glPushMatrix();

glGetFloatv(GL_CURRENT_COLOR, colors);

 glBegin(GL_TRIANGLES);
 /*
   glVertex3f(-(width/2),0,(height/3)); //V1
   glVertex3f((width/2),0,(height/3)); //V2
   glVertex3f(0,0,-((2*height)/3)); //V3
   glVertex3f(-(width/2),0-thick,(height/3)); //V4
   glVertex3f((width/2),0-thick,(height/3)); //V5
   glVertex3f(0,0-thick,-((2*height)/3)); //V6
   */

   //top
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f(0,0,-((height)/2)); //V3
   glVertex3f((width/2),0,(height/2)); //V2

   changecols8;

   //side1
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f((width/2),0,(height/2)); //V2
   glVertex3f(-(width/2),0-thick,(height/2)); //V4
   glVertex3f(-(width/2),0-thick,(height/2)); //V4
   glVertex3f((width/2),0,(height/2)); //V2
   glVertex3f((width/2),0-thick,(height/2)); //V5

   changecols7;


   //side2
   glVertex3f((width/2),0,(height/2)); //V2
   glVertex3f(0,0,-((height)/2)); //V3
   glVertex3f(0,0-thick,-((height)/2)); //V6
   glVertex3f(0,0-thick,-((height)/2)); //V6
   glVertex3f((width/2),0-thick,(height/2)); //V5
   glVertex3f((width/2),0,(height/2)); //V2

   changecols6;

   //side3
   glVertex3f(0,0,-((height)/2)); //V3
   glVertex3f(-(width/2),0,(height/2)); //V1
   glVertex3f(-(width/2),0-thick,(height/2)); //V4
   glVertex3f(-(width/2),0-thick,(height/2)); //V4
   glVertex3f(0,0-thick,-((height)/2)); //V6
   glVertex3f(0,0,-((height)/2)); //V3

   changecols5;

   //bottom
   glVertex3f(0,0-thick,-((height)/2)); //V6
   glVertex3f(-(width/2),0-thick,(height/2)); //V4
   glVertex3f((width/2),0-thick,(height/2)); //V5

  glEnd();
  glPopMatrix();
}
