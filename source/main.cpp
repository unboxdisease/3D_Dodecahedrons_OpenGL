#include "main.h"
#include "timer.h"
#include "ball.h"
#include <unistd.h>
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;
int rotate_switch = 0;
/**************************
* Customizable functions *
**************************/
float tx=0,ty=0,tz=0;
int spino = 0,spin = 0;
Ball ball1;
int object11 = 0,object22 =0,object33 =0;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
float x=0,y=0,xx=0,yy=0,zz=0;
Timer t60(1.0 / 60);
float pos= 1;
/* Render the scene with openGL */
/* Edit this function according to your assignment */
    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f) , 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);



    // Compute Camera matrix (view)
    glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f)+ xx, 0 + yy, 5*sin(camera_rotation_angle*M_PI/180.0f) + zz );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0 + tx, 0+ty, 0+tz);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0 + tz, 1 + ty, 0 + tz);
    
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    ball1.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int obj1 = glfwGetKey(window, GLFW_KEY_1);
    int obj2 = glfwGetKey(window, GLFW_KEY_2);
    int obj3 = glfwGetKey(window, GLFW_KEY_3);
    
    if (left) {
        xx += 0.1;
    }
    if (right) {
        xx -= 0.1;
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        yy +=0.1;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        yy -= 0.1;
    if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS)
        zz +=0.1;
    if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS)
        zz -= 0.1;
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS){
        tx = -1;
        ty = 5;
        tz = -5;
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS){
        tx = 1;
        ty = 1;
        tz = 1;
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS){
        tx = 0;
        ty = 0;
        tz = 0;
    }
    if(obj1){
        object11 = 1;
        object22 = 0;
        object33 = 0;
    }
    if(obj2){
        object11 = 0;
        object22 = 1;
        object33 = 0;
    }  
    if(obj3){
        object11 = 0;
        object22 = 0;
        object33 = 1;
    }
    

    if(spin){
        camera_rotation_angle += 1;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        ball1.move_yf();
        
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        ball1.move_yb();
        
    // if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    //     eye -= target;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        ball1.move_xf();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        ball1.move_xb();
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        ball1.move_zf();
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        ball1.move_zb();
    if(spino){
        ball1.rotation +=1;
    }
}

void tick_elements() {
    ball1.tick();
    camera_rotation_angle += 0;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ball1       = Ball(0, 0, COLOR_RED);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            // tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
