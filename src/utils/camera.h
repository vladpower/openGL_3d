#ifndef AFISKON_OPENGL_CAMERA_H
#define AFISKON_OPENGL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/core/type.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Camera {

private:
  sf::Window *window;
  glm::vec3 position;
  float horizontalAngleRad;
  float verticalAngleRad;

public:
  Camera(sf::Window* window, const glm::vec3&startPosition, float startHorizontalAngleRad, float startVerticalAngleRad);
  void getViewMatrix(float deltaTimeMs, glm::mat4* pOutViewMatrix);
  void getPosition(glm::vec3* pOutVec);

  Camera(Camera const &) = delete;
  void operator=(Camera const &x) = delete;
};

#endif // AFISKON_OPENGL_CAMERA_H
