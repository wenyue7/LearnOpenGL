#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//包含以下两个任意一个头文件,目的是使用glm::to_string输出矩阵
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>

#include <opencv2/opencv.hpp>

int main()
{
	GLfloat a = -1;
	glm::mat2x2 glmtest(a, 0.2f, 0.3f, 0.4f);
	std::cout << "测试glm初始化方法,也可以使用vec初始化: " << glm::to_string(glmtest) << std::endl << std::endl;
	cv::Mat extr;
	extr = cv::Mat::eye(3, 4, CV_32FC1);
	extr.at<float>(0,0) = -0.1669; extr.at<float>(0,1) = 0.2891;  extr.at<float>(0,2) = -0.9426;
	extr.at<float>(1,0) = 0.8660;  extr.at<float>(1,1) = 0.5000;  extr.at<float>(1,2) = 0.0000;
	extr.at<float>(2,0) = 0.4713;  extr.at<float>(2,1) = -0.8164; extr.at<float>(2,2) = -0.3338;
	std::cout << "extr is: " << std::endl << extr << std::endl << std::endl;

	glm::vec4 vertex(98.4221f, 0.0011f, -0.9202f, 1.0f);
	glm::mat4x3 glmMat;
	cv::Mat extrTmp;
	cv::transpose(extr, extrTmp);
	memcpy(glm::value_ptr(glmMat), extrTmp.data, 12 * sizeof(float));
	std::cout << "glmMat is: " << std::endl << glm::to_string(glmMat) << std::endl << std::endl;

	//calc
	glm::vec3 result;
	result = (glmMat * vertex) / 200 + glm::vec3(0.5f, 0.5f, 0.5f);
	std::cout << "Result is: " << std::endl << glm::to_string(result) << std::endl;
}
