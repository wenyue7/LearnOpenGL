#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//包含以下两个任意一个头文件,目的是使用glm::to_string输出矩阵
#include <glm/ext.hpp>
#include <glm/gtx/string_cast.hpp>

#include <opencv2/opencv.hpp>

int main()
{
	std::cout << "======================== GLM ==========================" << std::endl;
	glm::mat4 glmTest;
	glmTest = glm::translate(glmTest, glm::vec3(1.0f, 0.0f, 0.0f));
	std::cout << "Result is: " << std::endl << glm::to_string(glmTest) << std::endl;
	std::cout << std::endl;
	
	// glm中的矩阵应该转置之后才是正常使用的矩阵
	glm::mat3x4 test;
	std::cout << "glm::mat3x4" << std::endl;
	std::cout << "1、3列4分量，即3列4行，每一个括号表示一个维度，每个维度4个分量" << std::endl;
	std::cout << "2、存储时先存储列后存储行，这个结论可以从后边程序中mat向glm转化得出" << std::endl;
	std::cout << "3、对于OpenCV中的矩阵可以按照正常思维理解，因为从后边at操作以及矩阵相乘中也可以得到该结论,关于存储也是先存储行，再存储列" << std::endl;
	std::cout << "4、qt中矩阵的声明方法类似于glm，比如：QMatrix3x4表示的是3列4行，这里可以定义两个矩阵来相乘测试，如果有问题是无法编译通过的，但是存储的时是先存储的行，再存储的列" << std::endl;
	std::cout << glm::to_string(test).c_str() << std::endl;
	
	std::cout << "====================== MAT-GLM ========================" << std::endl;
	cv::Mat matTest;
	//零矩阵
	matTest = cv::Mat::zeros(2, 3, CV_8UC1);
	std::cout << "z = " << std::endl << matTest << std::endl;
	//全1矩阵
	matTest = cv::Mat::ones(2, 3, CV_32F);
	std::cout << "O = " << std::endl << matTest << std::endl;
	//单位阵
	matTest = cv::Mat::eye(2, 3, CV_64F);
	std::cout << "E = " << std::endl << matTest << std::endl << std::endl;
	//更改某一个元素
	matTest.create(2, 3, CV_8UC1);
	matTest.at<uchar>(1, 1) = 5;
	// matTest.at<float>(1, 1) = 5;
	std::cout << "mat is: " << std::endl << matTest << std::endl << std::endl;

	//glm转Mat
	//注意:Mat的类型需要是 CV_32FC1
	// matTest.create(2, 3, CV_32F);
	// std::cout << "type 1: " << matTest.type() << std::endl;
	// matTest.create(3, 4, CV_32FC1);
	matTest = cv::Mat::eye(3, 4, CV_32FC1);
	glm::mat3x4 glmTest2;
	std::cout << "type 1: " << matTest.type() << std::endl;
	matTest.at<float>(0, 3) = 3;
	std::cout << "orignl mat is: " << std::endl << matTest << std::endl;
	float floTest;
	memcpy(&floTest, matTest.data + 3 * sizeof(float), sizeof(float));
	std::cout << "matTest.data + 3 * sizeof(f loat) is: " << floTest << std::endl;
	memcpy(glm::value_ptr(glmTest2), matTest.data, 12 * sizeof(float));
	std::cout << "convert mat to glm is: " << std::endl << glm::to_string(glmTest2) << std::endl;
	memcpy(matTest.data, glm::value_ptr(glmTest2), 12 * sizeof(float));
	std::cout << "convert glm to mat is: " << std::endl << matTest << std::endl << std::endl;

	std::cout << "====================== Mutiply GLM ========================" << std::endl;
//	glm::vec4 glmTestVec4(2.0f, 0.0f, 0.0f, 0.0f);
//	std::cout << "multimply glm and vec4(1 0 0 0) is: " << glm::to_string(glmTest2 * glmTestVec4) << std::endl;
	glm::vec3 glmTestVec3(2.0f, 0.0f, 0.0f);
	std::cout << "multiply glm and vec3(1 0 0) is: " << glm::to_string(glmTest2 * glmTestVec3) << std::endl << std::endl;

	std::cout << "====================== Mutiply MAT ========================" << std::endl;
	cv::Mat matTest2;
	matTest2 = cv::Mat::eye(4, 3, CV_32FC1);
	matTest2.at<float>(0,1) = 2;
	std::cout << "multiply mat(3行4列) and mat(4列3行):" << std::endl << matTest * matTest2 << std::endl << std::endl;
}

// void fromCV2GLM(const cv::Mat& cvmat, glm::mat4* glmmat) {
//     if (cvmat.cols != 4 || cvmat.rows != 4 || cvmat.type() != CV_32FC1) {
//         cout << "Matrix conversion error!" << endl;
//         return;
//     }
//     memcpy(glm::value_ptr(*glmmat), cvmat.data, 16 * sizeof(float));
// }
// 
// void fromGLM2CV(const glm::mat4& glmmat, cv::Mat* cvmat) {
//     if (cvmat->cols != 4 || cvmat->rows != 4) {
//         (*cvmat) = cv::Mat(4, 4, CV_32F);
//     }
//     memcpy(cvmat->data, glm::value_ptr(glmmat), 16 * sizeof(float));
// }
