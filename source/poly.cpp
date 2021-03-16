#include "poly.h"
#include "main.h"

//First polygon

Poly1::Poly1(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Decagonal Prism. Made of 2 2D decagons connected along the 3rd plane
    static const GLfloat vertex_buffer_data[] = {
    0.93f,0.0f,0.0f,        //top decagon
    0.93f,0.93f,-2.85f,
    0.93f,-0.93f,-2.85f,
    0.93f,0.0f,0.0f,
    0.93f,-0.93f,-2.85f,
    0.93f,-2.43f,-1.76f,
    0.93f,0.0f,0.0f,
    0.93f,-2.43f,-1.76f,
    0.93f,-3.0f,0.0f,
    0.93f,0.0f,0.0f,
    0.93f,-3.0f,0.0f,
    0.93f,-2.43f,1.76f,
    0.93f,0.0f,0.0f,
    0.93f,-2.43f,1.76f,
    0.93f,-0.93f,2.85f,
    0.93f,0.0f,0.0f,
    0.93f,-0.93f,2.85f,
    0.93f,0.93f,2.85f,
    0.93f,0.0f,0.0f,
    0.93f,0.93f,2.85f,
    0.93f,2.43f,1.76f,
    0.93f,0.0f,0.0f,
    0.93f,2.43f,1.76f,
    0.93f,3.0f,0.0f,
    0.93f,0.0f,0.0f,
    0.93f,3.0f,0.0f,
    0.93f,2.43f,-1.76f,
    0.93f,0.0f,0.0f,
    0.93f,2.43f,-1.76f,
    0.93f,0.93f,-2.85f,
    -0.93f,0.0f,0.0f,           // bottom decagon
    -0.93f,0.93f,-2.85f,
    -0.93f,-0.93f,-2.85f,
    -0.93f,0.0f,0.0f,
    -0.93f,-0.93f,-2.85f,
    -0.93f,-2.43f,-1.76f,
    -0.93f,0.0f,0.0f,
    -0.93f,-2.43f,-1.76f,
    -0.93f,-3.0f,0.0f,
    -0.93f,0.0f,0.0f,
    -0.93f,-3.0f,0.0f,
    -0.93f,-2.43f,1.76f,
    -0.93f,0.0f,0.0f,
    -0.93f,-2.43f,1.76f,
    -0.93f,-0.93f,2.85f,
    -0.93f,0.0f,0.0f,
    -0.93f,-0.93f,2.85f,
    -0.93f,0.93f,2.85f,
    -0.93f,0.0f,0.0f,
    -0.93f,0.93f,2.85f,
    -0.93f,2.43f,1.76f,
    -0.93f,0.0f,0.0f,
    -0.93f,2.43f,1.76f,
    -0.93f,3.0f,0.0f,
    -0.93f,0.0f,0.0f,
    -0.93f,3.0f,0.0f,
    -0.93f,2.43f,-1.76f,
    -0.93f,0.0f,0.0f,
    -0.93f,2.43f,-1.76f,
    -0.93f,0.93f,-2.85f,
    0.93f,0.93f,-2.85f,     // first side
    0.93f,-0.93f,-2.85f,
    -0.93f,-0.93f,-2.85f,
    -0.93f,0.93f,-2.85f,
    -0.93f,-0.93f,-2.85f,
    0.93f,0.93f,-2.85f,
    0.93f,-0.93f,2.85f,     //second side
    0.93f,0.93f,2.85f,
    -0.93f,0.93f,2.85f,
    -0.93f,-0.93f,2.85f,
    -0.93f,0.93f,2.85f,
    0.93f,-0.93f,2.85f,
    0.93f,-0.93f,-2.85f,     // third side
    0.93f,-2.43f,-1.76f,
    -0.93f,-2.43f,-1.76f,
    -0.93f,-0.93f,-2.85f,
    -0.93f,-2.43f,-1.76f,
    0.93f,-0.93f,-2.85f,
    0.93f,0.93f,2.85f,     // fourth side
    0.93f,2.43f,1.76f,
    -0.93f,2.43f,1.76f,
    -0.93f,0.93f,2.85f,
    -0.93f,2.43f,1.76f,
    0.93f,0.93f,2.85f,
    0.93f,-2.43f,-1.76f,     // fifth side
    0.93f,-3.0f,0.0f,
    -0.93f,-3.0f,0.0f,
    -0.93f,-2.43f,-1.76f,
    -0.93f,-3.0f,0.0f,
    0.93f,-2.43f,-1.76f,
    0.93f,2.43f,1.76f,     // sixth side
    0.93f,3.0f,0.0f,
    -0.93f,3.0f,0.0f,
    -0.93f,2.43f,1.76f,
    -0.93f,3.0f,0.0f,
    0.93f,2.43f,1.76f,
    0.93f,-3.0f,0.0f,     // seventh side
    0.93f,-2.43f,1.76f,
    -0.93f,-2.43f,1.76f,
    -0.93f,-3.0f,0.0f,
    -0.93f,-2.43f,1.76f,
    0.93f,-3.0f,0.0f,
    0.93f,3.0f,0.0f,     // eigthth side
    0.93f,2.43f,-1.76f,
    -0.93f,2.43f,-1.76f,
    -0.93f,3.0f,0.0f,
    -0.93f,2.43f,-1.76f,
    0.93f,3.0f,0.0f,
    0.93f,-0.93f,2.85f,     // ninth side
    0.93f,-2.43f,1.76f,
    -0.93f,-2.43f,1.76f,
    -0.93f,-0.93f,2.85f,
    -0.93f,-2.43f,1.76f,
    0.93f,-0.93f,2.85f,
    0.93f,0.93f,-2.85f,     // tenth side
    0.93f,2.43f,-1.76f,
    -0.93f,2.43f,-1.76f,
    -0.93f,0.93f,-2.85f,
    -0.93f,2.43f,-1.76f,
    0.93f,0.93f,-2.85f,
    };
    static const GLfloat colour_buffer_data[] = {
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,

     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,

     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,

     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
        
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,

     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
       
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
        
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,

    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,

    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,

    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    };
    this->object = create3DObject(GL_TRIANGLES, 120, vertex_buffer_data, colour_buffer_data,GL_FILL);
}

void Poly1::draw(glm::mat4 VP) {
    // code that updates the translation and rotation of the scene
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Poly1::set_position(float x, float y, float z) {
    // function that updates position of the polygon
    this->position = glm::vec3(x, y, z);
}

void Poly1::tick() {
    this->rotation += speed;
}

// Second polynomial

Poly2::Poly2(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Undecagonal Prism. Made of undecagon converted to a 3D pyramid
    static const GLfloat vertex_buffer_data[] = {
    0.0f,0.0f,0.0f,        //bottom decagon
    0.93f,0.0f,-2.85f,
    -0.93f,0.0f,-2.85f,
    0.0f,0.0f,0.0f,
    -0.93f,0.0f,-2.85f,
    -2.43f,0.0f,-1.76f,
    0.0f,0.0f,0.0f,
    -2.43f,0.0f,-1.76f,
    -3.0f,0.0f,0.0f,
    0.0f,0.0f,0.0f,
    -3.0f,0.0f,0.0f,
    -2.43f,0.0f,1.76f,
    0.0f,0.0f,0.0f,
    -2.43f,0.0f,1.76f,
    -0.93f,0.0f,2.85f,
    0.0f,0.0f,0.0f,
    -0.93f,0.0f,2.85f,
    0.93f,0.0f,2.85f,
    0.0f,0.0f,0.0f,
    0.93f,0.0f,2.85f,
    2.43f,0.0f,1.76f,
    0.0f,0.0f,0.0f,
    2.43f,0.0f,1.76f,
    3.0f,0.0f,0.0f,
    0.0f,0.0f,0.0f,
    3.0f,0.0f,0.0f,
    2.43f,0.0f,-1.76f,
    0.0f,0.0f,0.0f,
    2.43f,0.0f,-1.76f,
    0.93f,0.0f,-2.85f,
    0.0f,2.0f,0.0f,        //top decagon
    0.93f,0.0f,-2.85f,
    -0.93f,0.0f,-2.85f,
    0.0f,2.0f,0.0f,
    -0.93f,0.0f,-2.85f,
    -2.43f,0.0f,-1.76f,
    0.0f,2.0f,0.0f,
    -2.43f,0.0f,-1.76f,
    -3.0f,0.0f,0.0f,
    0.0f,2.0f,0.0f,
    -3.0f,0.0f,0.0f,
    -2.43f,0.0f,1.76f,
    0.0f,2.0f,0.0f,
    -2.43f,0.0f,1.76f,
    -0.93f,0.0f,2.85f,
    0.0f,2.0f,0.0f,
    -0.93f,0.0f,2.85f,
    0.93f,0.0f,2.85f,
    0.0f,2.0f,0.0f,
    0.93f,0.0f,2.85f,
    2.43f,0.0f,1.76f,
    0.0f,2.0f,0.0f,
    2.43f,0.0f,1.76f,
    3.0f,0.0f,0.0f,
    0.0f,2.0f,0.0f,
    3.0f,0.0f,0.0f,
    2.43f,0.0f,-1.76f,
    0.0f,2.0f,0.0f,
    2.43f,0.0f,-1.76f,
    0.93f,0.0f,-2.85f,
    };
    static const GLfloat colour_buffer_data[] = {
    0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,

     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,

     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,

     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
        
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,

     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
       
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
        
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,

    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,

    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,

    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    };

    this->object = create3DObject(GL_TRIANGLES, 60, vertex_buffer_data, colour_buffer_data, GL_FILL);
}

void Poly2::draw(glm::mat4 VP) {
    // code that updates the translation and rotation of the scene
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Poly2::set_position(float x, float y, float z) {
    // function that updates position of the polygon
    this->position = glm::vec3(x, y, z);
}

void Poly2::tick() {
    this->rotation += speed;
}

// Third Polynomial

Poly3::Poly3(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Hexagonal Diprism. Made of hexagon as base, with pyramid extending in opposite sides across 3rd plane perpendicular to hexagon
    static const GLfloat vertex_buffer_data[] = {
    0.0f,2.0f,0.0f,        //top hexagon
    1.5f,0.0f,-2.6f,
    -1.5f,0.0f,-2.6f,
    0.0f,2.0f,0.0f,
    -1.5f,0.0f,-2.6f,
    -3.0f,0.0f,0.0f,
    0.0f,2.0f,0.0f,
    -3.0f,0.0f,0.0f,
    -1.5f,0.0f,2.6f,
    0.0f,2.0f,0.0f,
    -1.5f,0.0f,2.6f,
    1.5f,0.0f,2.6f,
    0.0f,2.0f,0.0f,
    1.5f,0.0f,2.6f,
    3.0f,0.0f,0.0f,
    0.0f,2.0f,0.0f,
    3.0f,0.0f,0.0f,
    1.5f,0.0f,-2.6f,
    0.0f,-2.0f,0.0f,        //botton hexagon
    1.5f,0.0f,-2.6f,
    -1.5f,0.0f,-2.6f,
    0.0f,-2.0f,0.0f,
    -1.5f,0.0f,-2.6f,
    -3.0f,0.0f,0.0f,
    0.0f,-2.0f,0.0f,
    -3.0f,0.0f,0.0f,
    -1.5f,0.0f,2.6f,
    0.0f,-2.0f,0.0f,
    -1.5f,0.0f,2.6f,
    1.5f,0.0f,2.6f,
    0.0f,-2.0f,0.0f,
    1.5f,0.0f,2.6f,
    3.0f,0.0f,0.0f,
    0.0f,-2.0f,0.0f,
    3.0f,0.0f,0.0f,
    1.5f,0.0f,-2.6f,        
    };
    static const GLfloat colour_buffer_data[] = {
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,
     0.622f, 0.369f, 0.423f,

     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,
     0.483f, 0.971f, 0.314f,

     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,
     0.297f, 0.789f, 0.361f,

     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,
     0.997f, 0.393f, 0.264f,

     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
     0.669f, 0.327f, 0.805f,
        
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,
     0.712f, 0.245f, 0.474f,

     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
     0.458f, 0.418f, 0.875f,
       
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
     0.220f, 0.266f, 0.714f,
        
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,
    0.067f, 0.328f, 0.055f,

    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,
    0.575f, 0.642f, 0.264f,

    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,
    0.482f, 0.509f, 0.033f,

    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    0.837f, 0.673f, 0.143f,
    };
    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, colour_buffer_data, GL_FILL);
}

void Poly3::draw(glm::mat4 VP) {
    // code that updates the translation and rotation of the scene
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Poly3::set_position(float x, float y, float z) {
    // function that updates position of the polygon
    this->position = glm::vec3(x, y, z);
}

void Poly3::tick() {
    this->rotation += speed;
}