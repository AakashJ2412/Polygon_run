#include "poly.h"
#include "main.h"

//First polygon


Poly1::Poly1(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
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

    this->object = create3DObject(GL_TRIANGLES, 120, vertex_buffer_data, colour_buffer_data,GL_FILL);
}

void Poly1::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Poly1::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Poly1::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

// Second polynomial

Poly2::Poly2(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
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
    0.0f,0.0f,0.0f,        //bottom decagon
    0.0f,0.93f,-2.85f,
    0.0f,-0.93f,-2.85f,
    0.0f,0.0f,0.0f,
    0.0f,-0.93f,-2.85f,
    0.0f,-2.43f,-1.76f,
    0.0f,0.0f,0.0f,
    0.0f,-2.43f,-1.76f,
    0.0f,-3.0f,0.0f,
    0.0f,0.0f,0.0f,
    0.0f,-3.0f,0.0f,
    0.0f,-2.43f,1.76f,
    0.0f,0.0f,0.0f,
    0.0f,-2.43f,1.76f,
    0.0f,-0.93f,2.85f,
    0.0f,0.0f,0.0f,
    0.0f,-0.93f,2.85f,
    0.0f,0.93f,2.85f,
    0.0f,0.0f,0.0f,
    0.0f,0.93f,2.85f,
    0.0f,2.43f,1.76f,
    0.0f,0.0f,0.0f,
    0.0f,2.43f,1.76f,
    0.0f,3.0f,0.0f,
    0.0f,0.0f,0.0f,
    0.0f,3.0f,0.0f,
    0.0f,2.43f,-1.76f,
    0.0f,0.0f,0.0f,
    0.0f,2.43f,-1.76f,
    0.0f,0.93f,-2.85f,
    2.0f,0.0f,0.0f,        //top decagon
    0.0f,0.93f,-2.85f,
    0.0f,-0.93f,-2.85f,
    2.0f,0.0f,0.0f,
    0.0f,-0.93f,-2.85f,
    0.0f,-2.43f,-1.76f,
    2.0f,0.0f,0.0f,
    0.0f,-2.43f,-1.76f,
    0.0f,-3.0f,0.0f,
    2.0f,0.0f,0.0f,
    0.0f,-3.0f,0.0f,
    0.0f,-2.43f,1.76f,
    2.0f,0.0f,0.0f,
    0.0f,-2.43f,1.76f,
    0.0f,-0.93f,2.85f,
    2.0f,0.0f,0.0f,
    0.0f,-0.93f,2.85f,
    0.0f,0.93f,2.85f,
    2.0f,0.0f,0.0f,
    0.0f,0.93f,2.85f,
    0.0f,2.43f,1.76f,
    2.0f,0.0f,0.0f,
    0.0f,2.43f,1.76f,
    0.0f,3.0f,0.0f,
    2.0f,0.0f,0.0f,
    0.0f,3.0f,0.0f,
    0.0f,2.43f,-1.76f,
    2.0f,0.0f,0.0f,
    0.0f,2.43f,-1.76f,
    0.0f,0.93f,-2.85f,
    };

    this->object = create3DObject(GL_TRIANGLES, 60, vertex_buffer_data, colour_buffer_data, GL_FILL);
}

void Poly2::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Poly2::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Poly2::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

// Third Polynomial

Poly3::Poly3(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
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
    this->object = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, colour_buffer_data, GL_FILL);
}

void Poly3::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Poly3::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Poly3::tick() {
    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}