#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>

int main()
{
	std::cout << "======================== GLM ==========================" << std::endl;
	glm::mat4 glmTestRotate;
	// 参数二是弧度制的角度，参数三是旋转使用的轴，旋转方向为逆时针方向
	glmTestRotate = glm::rotate(glmTestRotate, (float)1.5, glm::vec3(1, 0, 0)/*xAxis*/);
	std::cout << "rotate result is: " << std::endl << glm::to_string(glmTestRotate) << std::endl;
	std::cout << "after rotate vec4(0 1 0 0) is: " << glm::to_string(glmTestRotate * glm::vec4(0.0f, 1.0f, 0.0f, 0.0f)) << std::endl << std::endl;

	glm::mat4 glmTestTrans;
	glmTestTrans = glm::translate(glmTestTrans, glm::vec3(1.0f, 0.0f, 0.0f));
	std::cout << "translate result is: " << std::endl << glm::to_string(glmTestTrans) << std::endl;
	std::cout << std::endl;
}
