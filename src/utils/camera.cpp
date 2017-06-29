#include <glm/gtc/matrix_transform.hpp>
//#include <GLFW/glfw3.h>
#include "camera.h"
#include <iostream>

static const float speed = 40.0f; // units per second
static const float mouseSpeedRad = 0.0005f;

Camera::Camera(sf::Window* window, const glm::vec3& startPosition, float startHorizontalAngleRad, float startVerticalAngleRad):
  window(window),
  position(startPosition),
  horizontalAngleRad(startHorizontalAngleRad),
  verticalAngleRad(startVerticalAngleRad) { }

void Camera::getPosition(glm::vec3 *pOutVec) {
  *pOutVec = position;
}

void Camera::getViewMatrix(float deltaTimeMs, glm::mat4* pOutViewMatrix) {
  float deltaTimeSec = deltaTimeMs/1000.0f;

  int windowWidth, windowHeight;
  windowWidth = window->getSize().x;
  windowHeight = window->getSize().y;
  //glfwGetWindowSize(window, &windowWidth, &windowHeight);

  double mouseX, mouseY;
  // get global mouse position
  sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
  mouseX = mousePos.x;
  mouseY = mousePos.y;
  //glfwGetCursorPos(window, &mouseX, &mouseY);

  horizontalAngleRad += mouseSpeedRad * (windowWidth/2 - mouseX);
  verticalAngleRad += mouseSpeedRad * (windowHeight/2 - mouseY);


  // set mouse position relative to a window
  sf::Mouse::setPosition(sf::Vector2i(windowWidth/2, windowHeight/2), *window);
  //glfwSetCursorPos(window, windowWidth/2, windowHeight/2);

  glm::vec3 direction(
    cos(verticalAngleRad) * sin(horizontalAngleRad),
    sin(verticalAngleRad),
    cos(verticalAngleRad) * cos(horizontalAngleRad)
  );

  glm::vec3 right = glm::vec3(
    sin(horizontalAngleRad - 3.14f/2.0f),
    0,
    cos(horizontalAngleRad - 3.14f/2.0f)
  );
  std::cout<<position.x<<' '<<position.y<<' '<<position.z<<std::endl;

  glm::vec3 up = glm::cross(right, direction);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      position += direction * deltaTimeSec * speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      position -= direction * deltaTimeSec * speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      position -= right * deltaTimeSec * speed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      position += right * deltaTimeSec * speed;
  }

  *pOutViewMatrix = glm::lookAt(position, position + direction, up);
}
