//
//  Camera.cpp
//  Minecraft_cpp
//
//  Created by Shun Sato on 8/10/18.
//  Copyright © 2018 ShunSato. All rights reserved.
//

#include "Camera.hpp"

#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/noise.hpp>

#include <cmath>

#include "Coordinates.hpp"

Camera::Camera()
:position(4, 3, 3)
,up(0, 1, 0)
,lookat(0, 0, 0)
,previousMouseX(-1)
,previousMouseY(-1)
{
    angle = lookat - position;
}

Camera::~Camera() {
    
}

void Camera::mouseInput(double x, double y) {
    if (previousMouseX == -1 && previousMouseY == -1) {
        previousMouseX = x;
        previousMouseY = y;
        return;
    }
    
    auto deltaX = x - previousMouseX;
    auto deltaY = y - previousMouseY;
    std::cout << "Camera::mouseInput x:" << x << " y:" << y << " deltaX:" << deltaX << " deltaY:" << deltaY << std::endl;
    
    auto windowSize = getWindowSize();

    lookat -= up * 0.01f * static_cast<float>(deltaY);
    lookat += glm::cross(glm::normalize(lookat-position), up) * 0.05f * static_cast<float>(deltaX);
    
    lookat = position + (lookat-position) * 3.0f / glm::distance(lookat, position);
    
    previousMouseX = x;
    previousMouseY = y;
}

const glm::vec3& Camera::getPosition() const {
    return position;
}

glm::mat4 Camera::getMVPMatrix() const {
    auto windowSize = getWindowSize();
//
//    glm::mat4 view = glm::lookAt(position, position + lookat, up);
//    glm::mat4 projection = glm::perspective(45.0f, static_cast<float>(windowSize.width/windowSize.height), 0.01f, 1000.0f);
//
//    return projection * view;
    
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(windowSize.width/windowSize.height), 0.1f, 100.0f);
    // Camera matrix
    glm::mat4 view       = glm::lookAt(
                                       position, // Camera is at (4,3,3), in World Space
                                       lookat, // and looks at the origin
                                       up  // Head is up (set to 0,-1,0 to look upside-down)
                                       );
    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    return projection * view * model; // Remember, matrix multiplication is the other way around
}

// Calculate the forward, right and lookat vectors from the angle vector
void Camera::updateVectors() {
//    _forward.x = sin(angle.x);
//    _forward.y = 0;
//    _forward.z = cos(angle.x);
//
//    _right.x = -cos(angle.x);
//    _right.y = 0;
//    _right.z = sin(angle.x);
//
//    lookat.x = sin(angle.x) * cos(angle.y);
//    lookat.y = sin(angle.y);
//    lookat.z = cos(angle.x) * cos(angle.y);
}

void Camera::forward() {
    std::cout << "Camera::forward distance:" << glm::distance(lookat, position) << std::endl;
    auto delta = glm::normalize(lookat-position) * 0.1f;
    position += delta;
    lookat += delta;
}

void Camera::back() {
    auto delta = glm::normalize(lookat-position) * 0.1f;
    position -= delta;
    lookat -= delta;
}

void Camera::left() {
    auto delta = glm::cross(glm::normalize(lookat-position), up) * 0.1f;
    position -= delta;
    lookat -= delta;
}

void Camera::right() {
    auto delta = glm::cross(glm::normalize(lookat-position), up) * 0.1f;
    position += delta;
    lookat += delta;
}
