#include <iostream>
#include <opencv2/opencv.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>

using namespace std;
using namespace cv;

main()
{
	Mat M(3,2,CV_8UC3,Scalar(0,0,255));
	Mat Z = Mat::zeros(2,3,CV_8UC1);
	Mat O = Mat::ones(2,3,CV_32F);
	Mat E = Mat::eye(2,3,CV_64F);

	cout << "M = " << endl << " " << M << endl;
	cout << "z = " << endl << " " << Z << endl;
	cout << "O = " << endl << " " << O << endl;
	cout << "E = " << endl << " " << E << endl << endl;

	cout << "========================  Mat  =======================" << endl;
	cv::Mat result;
	cv::Mat orignl = Mat::eye(3, 3, CV_32FC1);
	cv::Mat trans = Mat::eye(3, 3, CV_32FC1);
	trans.at<float>(0, 2) = 1;
	orignl.at<float>(0, 2) = 9;
	result = trans * orignl;
	cout << "trans mat is: " << endl << trans << endl;
	cout << "orignl mat is: " << endl << orignl << endl;
	cout << "Result is: " << endl << result << endl << endl;

	cout << "==============================  测试Mat中数据的存储方式  ===========================" << endl << endl << endl;
	float floTest;
	memcpy(&floTest, orignl.data + 2 * sizeof(float), sizeof(float));
	cout << "存储方式测试(相对于orignl矩阵起始位置偏移2个float单位): " << floTest << endl;
	// 结论: Mat中先存储行,在存储列

	cout << "========================  GLM  =======================" << endl;
	glm::mat4 glmOrignl, glmTrans, glmResult;
	memcpy(glm::value_ptr(glmOrignl), orignl.data, 16 * sizeof(float));
	memcpy(glm::value_ptr(glmTrans), trans.data, 16 * sizeof(float));
	glmResult = glmTrans * glmOrignl;
	memcpy(orignl.data, glm::value_ptr(glmOrignl), 16 * sizeof(float));
	memcpy(trans.data, glm::value_ptr(glmTrans), 16 * sizeof(float));
	memcpy(result.data, glm::value_ptr(glmResult), 16 * sizeof(float));

	cout << "trans mat is: " << endl << trans << endl;
	cout << "glm cpy trans mat is: " << endl << glm::to_string(glmTrans) << endl;
	cout << "orignl mat is: " << endl << orignl << endl;
	cout << "glm cpy orignl mat is: " << endl << glm::to_string(glmOrignl) << endl;
	cout << "Result is: " << endl << result << endl << endl;

	cout << "==============================  测试GLM中数据的存储方式  ===========================" << endl;
	float floTest2;
	memcpy(&floTest2, glm::value_ptr(glmOrignl) + 2 * sizeof(float), sizeof(float));
	cout << "存储方式测试(相对于glmOrignl矩阵起始位置偏移2个float单位): " << floTest << endl;
	return 0;
}
