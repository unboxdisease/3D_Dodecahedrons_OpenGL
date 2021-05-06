#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    //Hexagonal Bipyramid
    static const GLfloat vertex_buffer_data1[] = {
        0.0f,1.0f,0.0f,
        -.866f,0.5f,0.0f,
        0.0f,0.0f,1.0f};
    static const GLfloat vertex_buffer_data2[] = {
        0.0f,1.0f,0.0f,
        0.866f,0.5f,0.0f,
        0.0f,0.0f,1.0f};
    static const GLfloat vertex_buffer_data3[] = {
        0.0f,-1.0f,0.0f,
        -0.866f,-0.5f,0.0f,
        0.0f,0.0f,1.0f};
    static const GLfloat vertex_buffer_data4[] = {
        0.0f,-1.0f,0.0f,
        0.866f,-0.5f,0.0f,
        0.0f,0.0f,1.0f};
    static const GLfloat vertex_buffer_data5[] = {
         0.866f,-0.5f,0.0f,
        0.866f,0.5f,0.0f,
        0.0f,0.0f,1.0f};
    static const GLfloat vertex_buffer_data6[] = {
         -0.866f,-0.5f,0.0f,
        -0.866f,0.5f,0.0f,
        0.0f,0.0f,1.0f};
    static const GLfloat vertex_buffer_data7[] = {
        0.0f,1.0f,0.0f,
        -0.866f,0.5f,0.0f,
        0.0f,0.0f,-1.0f};
    static const GLfloat vertex_buffer_data8[] = {
        0.0f,1.0f,0.0f,
        0.866f,0.5f,0.0f,
        0.0f,0.0f,-1.0f};
    static const GLfloat vertex_buffer_data9[] = {
        0.0f,-1.0f,0.0f,
        -0.866f,-0.5f,0.0f,
        0.0f,0.0f,-1.0f};
    static const GLfloat vertex_buffer_data10[] = {
         0.0f,-1.0f,0.0f,
        0.866f,-0.5f,0.0f,
        0.0f,0.0f,-1.0f};
    static const GLfloat vertex_buffer_data11[] = {
         0.866f,-0.5f,0.0f,
        0.866f,0.5f,0.0f,
        0.0f,0.0f,-1.0f};
    static const GLfloat vertex_buffer_data12[] = {
        -0.866f,-0.5f,0.0f,
        -0.866f,0.5f,0.0f,
        0.0f,0.0f,-1.0f};

    // };

    this->object[0] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data1, color, GL_FILL);
    color = { 276, 100, 185 };
    this->object[1] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data2, color, GL_FILL);
    color = { 176, 200, 105 };
    this->object[2] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data3, color, GL_FILL);
    color = { 176, 100, 285 };
    this->object[3] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data4, color, GL_FILL);
    color = { 196, 100, 185 };
    this->object[4] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data5, color, GL_FILL);
    color = { 076, 150, 125 };
    this->object[5] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data6, color, GL_FILL);
    color = { 276, 050, 105 };
    this->object[6] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data7, color, GL_FILL);
    color = { 176, 150, 205 };
    this->object[7] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data8, color, GL_FILL);
    color = { 276, 150, 205 };
    this->object[8] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data9, color, GL_FILL);
    color = { 276, 250, 10 };
    this->object[9] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data10, color, GL_FILL);
    color = { 76, 250, 10 };
    this->object[10] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data11, color, GL_FILL);
    color = { 27, 150, 205 };
    this->object[11] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data12, color, GL_FILL);

     static const GLfloat vertex_buffer_2data1[] = {
        -1.0f,-1.0f,1.0f,
        -1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f};
    static const GLfloat vertex_buffer_2data2[] = {
        -1.0f,-1.0f,1.0f,
        1.0f,-1.0f,1.0f,
        1.0f,1.0f,1.0f};
    static const GLfloat vertex_buffer_2data3[] = {
        -1.0f,-1.0f,-1.0f,
        -1.0f,1.0f,-1.0f,
        1.0f,1.0f,-1.0f};
    static const GLfloat vertex_buffer_2data4[] = {
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f,1.0f,-1.0f};
    static const GLfloat vertex_buffer_2data5[] = {
         1.0f,1.0f,1.0f,
        1.0f,-1.0f,1.0f,
        1.0f,-1.0f,-1.0f};
    static const GLfloat vertex_buffer_2data6[] = {
         1.0f,1.0f,1.0f,
        1.0f,1.0f,-1.0f,
        1.0f,-1.0f,-1.0f};
    static const GLfloat vertex_buffer_2data7[] = {
        -1.0f,1.0f,1.0f,
        -1.0f,-1.0f,1.0f,
        -1.0f,-1.0f,-1.0f};
    static const GLfloat vertex_buffer_2data8[] = {
         -1.0f,1.0f,1.0f,
        -1.0f,1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f};
    static const GLfloat vertex_buffer_2data9[] = {
        -1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,
        0.0f,2.0f,0.0f};
    static const GLfloat vertex_buffer_2data10[] = {
        1.0f,1.0f,-1.0f,
        1.0f,1.0f,1.0f,
        0.0f,2.0f,0.0f};
    static const GLfloat vertex_buffer_2data11[] = {
         -1.0f,1.0f,-1.0f,
        1.0f,1.0f,-1.0f,
        0.0f,2.0f,0.0f};
    static const GLfloat vertex_buffer_2data12[] = {
        -1.0f,1.0f,-1.0f,
        -1.0f,1.0f,1.0f,
        0.0f,2.0f,0.0f};
    static const GLfloat vertex_buffer_2data13[] = {
        -1.0f,-1.0f,1.0f,
        1.0f,-1.0f,1.0f,
        0.0f,-2.0f,0.0f};
    static const GLfloat vertex_buffer_2data14[] = {
        1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,1.0f,
        0.0f,-2.0f,0.0f};
    static const GLfloat vertex_buffer_2data15[] = {
         -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        0.0f,-2.0f,0.0f};
    static const GLfloat vertex_buffer_2data16[] = {
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,1.0f,
        0.0f,-2.0f,0.0f};

    // };

    this->object2[0] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data1, color, GL_FILL);
    // color = { 276, 100, 185 };
    this->object2[1] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data2, color, GL_FILL);
    color = { 176, 100, 285 };
    this->object2[2] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data3, color, GL_FILL);
    color = { 176, 100, 285 };
    this->object2[3] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data4, color, GL_FILL);
    color = { 076, 150, 125 };
    this->object2[4] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data5, color, GL_FILL);
    color = { 076, 150, 125 };
    this->object2[5] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data6, color, GL_FILL);
    color = { 176, 150, 205 };
    this->object2[6] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data7, color, GL_FILL);
    color = { 176, 150, 205 };
    this->object2[7] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data8, color, GL_FILL);
    color = { 76, 50, 205 };
    this->object2[8] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data9, color, GL_FILL);
    color = { 276, 150, 10 };
    this->object2[9] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data10, color, GL_FILL);
    color = { 76, 250, 110 };
    this->object2[10] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data11, color, GL_FILL);
    color = { 27, 150, 205 };
    this->object2[11] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data12, color, GL_FILL);
    color = { 227, 250, 5 };
    this->object2[12] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data13, color, GL_FILL);
    color = { 27, 50, 5 };
    this->object2[13] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data14, color, GL_FILL);
    color = { 27, 250, 5 };
    this->object2[14] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data15, color, GL_FILL);
    color = { 77, 50, 105 };
    this->object2[15] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_2data16, color, GL_FILL);

    //pentagonal antiprism

     static const GLfloat vertex_buffer_3data1[] = {
        0.0f,1.0f,0.5f,
        -0.58f,-0.81f,0.5f,
        0.58f,-0.81f,0.5f};
    static const GLfloat vertex_buffer_3data2[] = {
        0.0f,1.0f,0.5f,
        -0.58f,-0.81f,0.5f,
        -0.95f,0.31f,0.5f};
    static const GLfloat vertex_buffer_3data3[] = {
        0.0f,1.0f,0.5f,
        0.58f,-0.81f,0.5f,
        0.95f,0.31f,0.5f};
    static const GLfloat vertex_buffer_3data4[] = {
        0.0f,-1.0f,-0.5f,
        -0.58f,0.81f,-0.5f,
        0.58f,0.81f,-0.5f};
    static const GLfloat vertex_buffer_3data5[] = {
         0.0f,-1.0f,-0.5f,
        -0.58f,0.81f,-0.5f,
        -0.95f,-0.31f,-0.5f};
    static const GLfloat vertex_buffer_3data6[] = {
        0.0f,-1.0f,-0.5f,
        0.58f,0.81f,-0.5f,
        0.95f,-0.31f,-0.5f};
    static const GLfloat vertex_buffer_3data7[] = {
        0.0f,-1.0f,-0.5f,
        0.58f,-0.81f,0.5f,
        0.95f,-0.31f,-0.5f};
    static const GLfloat vertex_buffer_3data8[] = {
        0.0f,-1.0f,-0.5f,
        -0.58f,-0.81f,0.5f,
        -0.95f,-0.31f,-0.5f};
    static const GLfloat vertex_buffer_3data9[] = {
         0.0f,1.0f,0.5f,
        0.58f,0.81f,-0.5f,
        0.95f,0.31f,0.5f};
    static const GLfloat vertex_buffer_3data10[] = {
        0.0f,1.0f,0.5f,
        -0.58f,0.81f,-0.5f,
        0.58f,0.81f,-0.5f};
    static const GLfloat vertex_buffer_3data11[] = {
        0.0f,1.0f,0.5f,
        -0.58f,0.81f,-0.5f,
        -0.95f,0.31f,0.5f};
    static const GLfloat vertex_buffer_3data12[] = {
        -0.95f,0.31f,0.5f,
        -0.58f,-0.81f,0.5f,
        -0.95f,-0.31f,-0.5f};
    static const GLfloat vertex_buffer_3data13[] = {
        -0.95f,-0.31f,-0.5f,
        -0.58f,0.81f,-0.5f,
        -0.95f,0.31f,0.5f};
    static const GLfloat vertex_buffer_3data14[] = {
        0.95f,-0.31f,-0.5f,
        0.58f,0.81f,-0.5f,
        0.95f,0.31f,0.5f};
    static const GLfloat vertex_buffer_3data15[] = {
        -0.0f,-1.0f,-0.5f,
        0.58f,-0.81f,0.5f,
        -0.58f,-0.81f,0.5f};
    static const GLfloat vertex_buffer_3data16[] = {
        0.95f,0.31f,0.5f,
        0.58f,-0.81f,0.5f,
        0.95f,-0.31f,-0.5f};

    // };

    this->object3[0] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data1, color, GL_FILL);
    // color = { 276, 100, 185 };
    this->object3[1] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data2, color, GL_FILL);
    // color = { 176, 100, 285 };
    this->object3[2] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data3, color, GL_FILL);
    color = { 176, 100, 285 };
    this->object3[3] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data4, color, GL_FILL);
    // color = { 076, 150, 125 };
    this->object3[4] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data5, color, GL_FILL);
    // color = { 076, 150, 125 };
    this->object3[5] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data6, color, GL_FILL);
    color = { 176, 150, 205 };
    this->object3[6] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data7, color, GL_FILL);
    color = { 76, 50, 205 };
    this->object3[7] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data8, color, GL_FILL);
    color = { 276, 150, 10 };
    this->object3[8] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data9, color, GL_FILL);
    color = {136, 220, 110 };
    this->object3[9] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data10, color, GL_FILL);
    color = { 76, 250, 110 };
    this->object3[10] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data11, color, GL_FILL);
    color = { 27, 150, 205 };
    this->object3[11] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data12, color, GL_FILL);
    color = { 227, 250, 5 };
    this->object3[12] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data13, color, GL_FILL);
    color = { 27, 50, 5 };
    this->object3[13] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data14, color, GL_FILL);
    color = { 27, 250, 5 };
    this->object3[14] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data15, color, GL_FILL);
    color = { 177, 150, 05 };
    this->object3[15] = create3DObject(GL_TRIANGLES, 3, vertex_buffer_3data16, color, GL_FILL);



    
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate*rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(object11 == 1){    
        for(int i=0;i<16;i++)    
            draw3DObject(this->object2[i]);
    }
    if(object22 == 1){    
        for(int i=0;i<12;i++)    
            draw3DObject(this->object[i]);
    }
    if(object33 == 1){    
        for(int i=0;i<16;i++)    
            draw3DObject(this->object3[i]);
    }
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
void Ball::move_xf() {
    this->position.x +=0.1;
}
void Ball::move_xb() {
    this->position.x -=0.1;
}
void Ball::move_yf() {
    this->position.y +=0.1;
}
void Ball::move_yb() {
    this->position.y -=0.1;
}
void Ball::move_zf() {
    this->position.z +=0.1;
}
void Ball::move_zb() {
    this->position.z -=0.1;
}

