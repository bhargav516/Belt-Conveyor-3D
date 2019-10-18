#include <limits.h>
//#include "tote.c"
#define PI 3.14159265

#define color_chunk(c) if(i == 0) { glColor3f(c, 0, 0); } \
                       if(i == 1) { glColor3f(0, c, 0); } \
                       if(i == 2) { glColor3f(0, 0, c); }


int items_made = 0;
float swivel = 0;
int dispense_random_angles = 1;
double first_timer=0, second_timer=0, third_timer=0;
char text_str[50];
float dispenser_y = 2.0f;
float dispenser_x = 30.0f;
float dispenser_z = 5.0f;
float belt_y = 0.1f;
//float scanner_1 =0.0f;
//float scanner_2 =0.0f;
float picker_y = 10.0f;
float table_width = 10;
float table_radius = 5;
float table_length = 50;
float table_thick = 1;
float conveyor_speed = -0.2;
float floor_y = -30;



void draw_table(void)
{
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslated(0, -(table_thick*2), 0);
    draw_closed_cuboid(table_width,table_length,table_thick);
    glPopMatrix();
}
void draw_table3(void)
{
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslated(0, -(table_thick*2), -table_length/2-(sqrt(table_width*table_width*0.75)/2));
    draw_closed_cuboid3(table_width*2,sqrt(table_width*table_width*0.75)*2,table_thick*20);
    glPopMatrix();
}
void draw_table1(void)
{
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslated(table_width, -(table_thick*2), -table_length*0.68);
    glRotatef(0,1,0,0);
    glRotated(-45,0,1,0);
    draw_closed_cuboid(table_width,table_length/2,table_thick);
    glPopMatrix();
}
void draw_table2(void)
{
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslated(-table_width, -(table_thick*2), -table_length*0.68);
    glRotatef(0,1,0,0);
    glRotated(45,0,1,0);
    draw_closed_cuboid(table_width,table_length/2,table_thick);
    glPopMatrix();
}
void draw_scanner1(void)
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(table_width*2/3, table_thick , table_length/2-(table_length/10));
    draw_closed_cuboid(table_width/3,table_length/20,table_thick*5);
    glPopMatrix();
}
void draw_scanner2(void)
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(-table_width*2/3, table_thick , -table_length/2+(table_length/10));
    draw_closed_cuboid(table_width/3,table_length/20,table_thick*5);
    glPopMatrix();
}
void draw_scanner3(void)
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(table_width*2/3, table_thick , -table_length/2+(table_length/10));
    draw_closed_cuboid(table_width/3,table_length/20,table_thick*5);
    glPopMatrix();
}
void draw_scanner4(void)
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(-table_width*2/3, table_thick , table_length/2-(table_length/10));
    draw_closed_cuboid(table_width/3,table_length/20,table_thick*5);
    glPopMatrix();
}


void draw_conveyor(void)
{


    

    glPushMatrix();
    

        //move_dispenser();
        //draw_table();
        //draw_table1();
        //draw_table2();
        draw_table3();
        //draw_scanner1();
        //draw_scanner2();
        //draw_scanner3();
        //draw_scanner4();
        //draw_items();
        //every_second();

     glPopMatrix();
    
}
