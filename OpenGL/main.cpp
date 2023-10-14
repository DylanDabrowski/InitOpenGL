// OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>  // Required for std::setprecision

#include "GameController.h"

// Custom print function for glm::vec2
void to_string(const glm::vec2& vec) {
    std::cout << std::fixed << std::setprecision(3);  // Print up to 3 decimal places
    std::cout << "(" << vec.x << ", " << vec.y << ")";
}

// Custom print function for glm::vec3
void to_string(const glm::vec3& vec) {
    std::cout << std::fixed << std::setprecision(3);  // Print up to 3 decimal places
    std::cout << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
}

static void AddVectors()
{
    glm::vec2 a = { 3, 5 };
    glm::vec2 b = { 2, -1 };
    glm::vec2 c = a + b;
    to_string(c);
    std::cout << std::endl;

    glm::vec3 d = { 3, 5, 1 };
    glm::vec3 e = { 2, -1, -1 };
    glm::vec3 f = d + e;
    to_string(f);
    std::cout << std::endl;
}

static void SubtractVectors()
{
    glm::vec2 a = { 3, 5 };
    glm::vec2 b = { 2, -1 };
    glm::vec2 c = b - a;
    glm::vec2 d = a - b;
    to_string(c);
    std::cout << std::endl;
    std::cout << "     Magnitute: " << glm::length(c) << std::endl;
    to_string(d);
    std::cout << std::endl;
    std::cout << "     Magnitute: " << glm::length(d) << std::endl;
}

glm::vec3 pos = { 2, 2, 2 };
static void MultiplyVectors()
{
    // glm::vec3 pos = { 0, 0, 0 };
    glm::vec3 dest = { 1, 0, 0 };
    glm::vec3 dir = dest - pos;
    dir = glm::normalize(dir);
    pos += (dir * 0.1f);
    to_string(pos);
    std::cout << std::endl;
}

static void Distance()
{
    glm::vec3 p1 = { 1, 1, 0 };
    glm::vec3 p2 = { 2, 1, 2 };
    float distance = glm::distance(p1, p2);
    std::cout << "Distance = " << distance << std::endl;
}

static void DotProduct()
{
    glm::vec3 source = { 0, 0, 0 };
    glm::vec3 a = { 0, 2, 0 };
    glm::vec3 b = { 1, 1, 0 };
    glm::vec3 aVec = a - source;
    glm::vec3 bVec = b - source;
    aVec = glm::normalize(aVec);
    bVec = glm::normalize(bVec);
    float dot = glm::dot(aVec, bVec);
    std::cout << "Dot = " << dot << std::endl;
}

static void CrossProduct()
{
    glm::vec3 source = { 0, 0, 0 };
    glm::vec3 a = { 0, 2, 0 };
    glm::vec3 b = { 1, 1, 0 };
    glm::vec3 aVec = a - source;
    glm::vec3 bVec = b - source;
    glm::vec3 cross = glm::cross(aVec, bVec);
    cross = glm::normalize(cross);
    std::cout << "Cross = ";
    to_string(cross);
    std::cout << std::endl;

}


int main()
{
    GameController::GetInstance().Initialize();
    GameController::GetInstance().RunGame();

    std::cout << "---------- ADD VECTORS: ------------------" << std::endl;
    AddVectors();
    std::cout << "---------- SUBTRACT VECTORS: -------------" << std::endl;
    SubtractVectors();
    std::cout << "---------- MULTIPLY VECTORS: -------------" << std::endl;
    MultiplyVectors();

    std::cout << "---------- MULTIPLY 10 VECTORS: ----------" << std::endl;
    for (int count = 0; count < 10; count++)
        MultiplyVectors();
  
    std::cout << "---------- DISTANCE: ---------------------" << std::endl;
    Distance();

    std::cout << "---------- DOT PRODUCT: ------------------" << std::endl;
    DotProduct();

    std::cout << "---------- CROSS: ------------------------" << std::endl;
    CrossProduct();

    return 0;
}
