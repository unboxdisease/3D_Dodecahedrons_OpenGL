#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    void move_xf();
    void move_xb();
    void move_yf();
    void move_yb();
        void move_zf();
    void move_zb();
    double speed;
private:
    VAO *object[50];
    VAO *object2[50];
    VAO *object3[50];
};

#endif // BALL_H
