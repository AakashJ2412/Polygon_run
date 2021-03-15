#include "main.h"
#include "timer.h"
#include "poly.h"

using namespace std;

GLMatrices Matrices;
GLuint programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Poly1 poly1;
Poly2 poly2;
Poly3 poly3;
int polybit;
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
const float cameraSpeed = 0.1f;
const float objectSpeed = 0.1f;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw()
{
    // clear the color and depth in the frame buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram(programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye(5 * cos(camera_rotation_angle * M_PI / 180.0f), 0, 5 * sin(camera_rotation_angle * M_PI / 180.0f));
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    // glm::vec3 target(0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    // glm::vec3 up(0, 1, 0);

    // Compute Camera matrix (view)
    //Matrices.view = glm::lookAt(eye, target, up); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    Matrices.view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP; // MVP = Projection * View * Model

    // Scene render
    if (polybit == 1)
        poly1.draw(VP);
    else if (polybit == 2)
        poly2.draw(VP);
    else if (polybit == 3)
        poly3.draw(VP);
}

void tick_elements()
{
    if (polybit == 1)
        poly1.tick();
    else if (polybit == 2)
        poly2.tick();
    else if (polybit == 3)
        poly3.tick();
    //camera_rotation_angle += 1;
}

void tick_input(GLFWwindow *window)
{
    int left = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int e = glfwGetKey(window, GLFW_KEY_E);
    int x = glfwGetKey(window, GLFW_KEY_X);
    int f = glfwGetKey(window, GLFW_KEY_F);
    int c = glfwGetKey(window, GLFW_KEY_C);
    int r = glfwGetKey(window, GLFW_KEY_R);
    int t = glfwGetKey(window, GLFW_KEY_T);
    int k1 = glfwGetKey(window, GLFW_KEY_1);
    int k2 = glfwGetKey(window, GLFW_KEY_2);
    int k3 = glfwGetKey(window, GLFW_KEY_3);
    if (a)
        move_object('L');
    if (s)
        move_object('D');
    if (d)
        move_object('R');
    if (w)
        move_object('U');
    if (e)
        move_object('F');
    if (x)
        move_object('B');
    if (r)
        tick_elements();
    if (f)
        cameraPos += cameraSpeed * cameraFront;
    if (c)
        cameraPos -= cameraSpeed * cameraFront;
    if (up)
        cameraPos += cameraSpeed * cameraUp;
    if (down)
        cameraPos -= cameraSpeed * cameraUp;
    if (left)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (right)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (t)
    {
        if (polybit == 1)
        {
            float r = sqrt((poly1.position.x - cameraPos.x) * (poly1.position.x - cameraPos.x) + (poly1.position.y - cameraPos.y) * (poly1.position.y - cameraPos.y) + (poly1.position.z - cameraPos.z) * (poly1.position.z - cameraPos.z));
            float xval, zval;
            if (poly1.position.x <= cameraPos.x)
                zval = -cameraSpeed*r;
            else
                zval = cameraSpeed*r;
            if (poly1.position.z <= cameraPos.z)
                xval = -cameraSpeed*r;
            else
                xval = cameraSpeed*r;
            cameraPos += glm::vec3(xval, 0.0f, zval);
            cameraFront = glm::vec3(poly1.position.x - cameraPos.x, poly1.position.y - cameraPos.y, poly1.position.z - cameraPos.z);
        }
        else if (polybit == 2)
        {
        }
        else if (polybit == 3)
        {
        }
    }
    if (k1)
    {
        if (polybit == 1)
        {
            cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
            cameraFront = glm::vec3(poly1.position.x, poly1.position.y, poly1.position.z - 10.0f);
            cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        }
        else if (polybit == 2)
        {
            cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
            cameraFront = glm::vec3(poly2.position.x, poly2.position.y, poly2.position.z - 10.0f);
            cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        }
        else if (polybit == 3)
        {
            cameraPos = glm::vec3(0.0f, 0.0f, 10.0f);
            cameraFront = glm::vec3(poly3.position.x, poly3.position.y, poly3.position.z - 10.0f);
            cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        }
    }
    if (k2)
    {
        if (polybit == 1)
        {
            cameraPos = glm::vec3(14.0f, -7.0f, 7.0f);
            cameraFront = glm::vec3(poly1.position.x - 14.0f, poly1.position.y + 7.0f, poly1.position.z - 7.0f);
            cameraUp = glm::vec3(0.0f, 1.0f, 2.0f);
        }
        else if (polybit == 2)
        {
            cameraPos = glm::vec3(14.0f, -7.0f, 7.0f);
            cameraFront = glm::vec3(poly2.position.x - 14.0f, poly2.position.y + 7.0f, poly2.position.z - 7.0f);
            cameraUp = glm::vec3(0.0f, 1.0f, 2.0f);
        }
        else if (polybit == 3)
        {
            cameraPos = glm::vec3(14.0f, -7.0f, 7.0f);
            cameraFront = glm::vec3(poly3.position.x - 14.0f, poly3.position.y + 7.0f, poly3.position.z - 7.0f);
            cameraUp = glm::vec3(0.0f, 1.0f, 2.0f);
        }
    }
    if (k3)
    {
        if (polybit == 1)
        {
            cameraPos = glm::vec3(8.0f, 6.0f, 10.0f);
            cameraFront = glm::vec3(poly1.position.x - 8.0f, poly1.position.y - 6.0f, poly1.position.z - 10.0f);
            cameraUp = glm::vec3(1.0f, 1.0f, 0.0f);
        }
        else if (polybit == 2)
        {
            cameraPos = glm::vec3(8.0f, 6.0f, 10.0f);
            cameraFront = glm::vec3(poly2.position.x - 8.0f, poly2.position.y - 6.0f, poly2.position.z - 10.0f);
            cameraUp = glm::vec3(1.0f, 1.0f, 0.0f);
        }
        else if (polybit == 3)
        {
            cameraPos = glm::vec3(8.0f, 6.0f, 10.0f);
            cameraFront = glm::vec3(poly3.position.x - 8.0f, poly3.position.y - 6.0f, poly3.position.z - 10.0f);
            cameraUp = glm::vec3(1.0f, 1.0f, 0.0f);
        }
    }
}

void move_object(char dim)
{
    if (polybit == 1)
    {
        switch (dim)
        {
        case 'L':
            poly1.set_position(poly1.position.x - objectSpeed, poly1.position.y, poly1.position.z);
            break;
        case 'R':
            poly1.set_position(poly1.position.x + objectSpeed, poly1.position.y, poly1.position.z);
            break;
        case 'U':
            poly1.set_position(poly1.position.x, poly1.position.y + objectSpeed, poly1.position.z);
            break;
        case 'D':
            poly1.set_position(poly1.position.x, poly1.position.y - objectSpeed, poly1.position.z);
            break;
        case 'F':
            poly1.set_position(poly1.position.x, poly1.position.y, poly1.position.z + objectSpeed);
            break;
        case 'B':
            poly1.set_position(poly1.position.x, poly1.position.y, poly1.position.z - objectSpeed);
            break;
        }
    }
    else if (polybit == 2)
    {
        switch (dim)
        {
        case 'L':
            poly2.set_position(poly2.position.x - objectSpeed, poly2.position.y, poly2.position.z);
            break;
        case 'R':
            poly2.set_position(poly2.position.x + objectSpeed, poly2.position.y, poly2.position.z);
            break;
        case 'U':
            poly2.set_position(poly2.position.x, poly2.position.y + objectSpeed, poly2.position.z);
            break;
        case 'D':
            poly2.set_position(poly2.position.x, poly2.position.y - objectSpeed, poly2.position.z);
            break;
        case 'F':
            poly2.set_position(poly2.position.x, poly2.position.y, poly2.position.z + objectSpeed);
            break;
        case 'B':
            poly2.set_position(poly2.position.x, poly2.position.y, poly2.position.z - objectSpeed);
            break;
        }
    }
    else if (polybit == 3)
    {
        switch (dim)
        {
        case 'L':
            poly3.set_position(poly3.position.x - objectSpeed, poly3.position.y, poly3.position.z);
            break;
        case 'R':
            poly3.set_position(poly3.position.x + objectSpeed, poly3.position.y, poly3.position.z);
            break;
        case 'U':
            poly3.set_position(poly3.position.x, poly3.position.y + objectSpeed, poly3.position.z);
            break;
        case 'D':
            poly3.set_position(poly3.position.x, poly3.position.y - objectSpeed, poly3.position.z);
            break;
        case 'F':
            poly3.set_position(poly3.position.x, poly3.position.y, poly3.position.z + objectSpeed);
            break;
        case 'B':
            poly3.set_position(poly3.position.x, poly3.position.y, poly3.position.z - objectSpeed);
            break;
        }
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    if (polybit == 1)
        poly1 = Poly1(0, 0, 0, COLOR_RED);
    else if (polybit == 2)
        poly2 = Poly2(0, 0, 0, COLOR_BLACK);
    else if (polybit == 3)
        poly3 = Poly3(0, 0, 0, COLOR_GREEN);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow(window, width, height);

    // Background color of the scene
    glClearColor(COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Error: Invalid number of arguments\n";
        return 0;
    }
    if (strcmp(argv[1], "poly1") == 0)
    {
        polybit = 1;
    }
    else if (strcmp(argv[1], "poly2") == 0)
    {
        polybit = 2;
    }
    else if (strcmp(argv[1], "poly3") == 0)
    {
        polybit = 3;
    }
    else
    {
        cout << "Error: Invalid argument provided\n";
        return 0;
    }

    srand(time(0));
    int width = 800;
    int height = 800;

    window = initGLFW(width, height);

    initGL(window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window))
    {
        // Process timers

        if (t60.processTick())
        {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            //tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b)
{
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen()
{
    float top = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left = screen_center_x - 4 / screen_zoom;
    float right = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
}
