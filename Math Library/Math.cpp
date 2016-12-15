#include <iostream>
#include <time.h>
#include <Windows.h>
#include <string>
#include "Math.h"
#include <cassert>
#include <fstream>
const float pi = 3.1415926535897;
std::ostream& operator<<(std::ostream& os, const Vector2 vec)
{
	os << '<' << vec.VA[0] << ',' << vec.VA[1] << '>';
	return os;
}
std::ostream& operator<<(std::ostream& os, const Vector3 vec)
{
	os << '<' << vec.VA[0] << ',' << vec.VA[1] << ',' << vec.VA[2] << '>';
	return os;
}
std::ostream& operator<<(std::ostream& os, const Vector4 vec)
{
	os << '<' << vec.VA[0] << ',' << vec.VA[1] << ',' << vec.VA[2] << ',' << vec.VA[3] << '>';
	return os;
}
std::ostream& operator<<(std::ostream& os, const Matrix2 mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (i % 4 == 0)
			os << "\n( ";
		os << mat.matrix2[i / 2][i % 2] << " ";
	}
	return os;
}
std::ostream& operator<<(std::ostream& os, const Matrix3 mat)
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 9 == 0)
			os << "\n(";
		os << mat.matrix3[i] << " ";
	}
	return os;
}
std::ostream& operator<<(std::ostream& os, const Matrix4 mat)
{
	for (int i = 0; i < 16; i++)
	{
		if (i % 16 == 0)
			os << "\n(";
		os << mat.matrix4[i / 4][i % 4] << " ";
	}
	return os;
}
int main()
{
	Vector2 a1 = Vector2(1, 3);
	Vector2 a2 = Vector2(1, 2);
	Vector2 a3 = Vector2(1, 3);
	Vector2 a4 = Vector2(1, 4);
	Vector2 a5 = Vector2(7, 4);
	Matrix2 b1 = Matrix2(2, 3, 4, 5);
	Matrix2 b2 = Matrix2(2, 3, 7, 5);
	Matrix2 b3 = Matrix2(1, 6, 3, 4);
	Matrix2 b4 = Matrix2(2, 3, 4, 9);

	Vector3 d1 = Vector3(3, 4, 5);
	Vector3 d2 = Vector3(3, 6, 5);
	Vector3 d3 = Vector3(6, 4, 5);
	Vector3 d4 = Vector3(3, 4, 7);
	Vector3 d5 = Vector3(3, 9, 5);
	Matrix3 e1 = Matrix3(5, 56, 7, 8, 19, 1, 33, 44, 55);
	Matrix3 e2 = Matrix3(5, 6, 7, 18, 9, 1, 33, 44, 55);
	Matrix3 e3 = Matrix3(5, 6, 17, 8, 99, 1, 33, 44, 55);
	Matrix3 e4 = Matrix3(5, 16, 7, 8, 9, 1, 33, 44, 55);
	Matrix3 Rotate3D1 = Matrix3(1, 1, 0, 1, 0, 1, 1, 0, 0);
	Matrix3 Rotate3D2 = Matrix3(1, 0, 1, 1, 0, 1, 1, 0, 0);
	Matrix3 Rotate3D3 = Matrix3(1, 0, 0, 1, 0, 1, 1, 0, 0);
	Matrix3 Rotate3D4 = Matrix3(0, 1, 0, 1, 0, 1, 1, 0, 0);
	Matrix3 Rotate3D5 = Matrix3(1, 0, 0, 0, 0, 1, 1, 0, 0);

	Vector4 f1 = Vector4(7, 4, 2, 4);
	Vector4 f2 = Vector4(7, 3, 3, 4);
	Vector4 f3 = Vector4(7, 3, 2, 2);
	Vector4 f4 = Vector4(7, 3, 2, 4);
	Vector4 f5 = Vector4(1, 3, 2, 4);
	Matrix4 g1 = Matrix4(11, 21, 33, 44, 57, 69, 72, 8, 9, 10, 1, 2, 3, 4, 5, 8);
	Matrix4 g2 = Matrix4(11, 21, 33, 44, 57, 69, 72, 8, 9, 10, 1, 2, 3, 4, 5, 8);
	Matrix4 g3 = Matrix4(11, 21, 33, 44, 57, 69, 72, 8, 9, 10, 1, 2, 3, 4, 5, 8);
	Matrix4 g4 = Matrix4(11, 21, 33, 44, 57, 69, 72, 8, 9, 10, 1, 2, 3, 4, 5, 8);
	Matrix4 Rotate4D1 = Matrix4(1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1);
	Matrix4 Rotate4D2 = Matrix4(1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1);
	Matrix4 Rotate4D3 = Matrix4(1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1);
	Matrix4 Rotate4D4 = Matrix4(0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1);
	Matrix4 Rotate4D5 = Matrix4(1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1);

	std::fstream mf;
	mf.open("Test.txt", std::ios_base::out);
	if (mf.is_open())
	{
		mf << "----------------------------------------TEST FUNCTIONS--------------------------------\n";
		mf << "Vector2 = Vector2 \nExpected Result: 1 , 0 , 1 , 1 , 1\n";
		mf << "Result: " << (a1 == a1) << " , " << (a1 == a2) << " , " << (a2 == a2) << " , " << (a2 == a2) << " , " << (a3 == a3);
		mf << "\n\n";
		mf << "Vector2 + Vector2 \nExpected Result: <2,6> , <2,5> , <2,4> , <2,5> , <2,6>\n";
		mf << "Result: " << a1 + a1 << " , " << a1 + a2 << " , " << a2 + a2 << " , " << a2 + a3 << " , " << a3 + a3;
		mf << "\n\n";
		mf << "Vector2 - Vector2 \nExpected Result: <0,0> , <0,1> , <0,0> , <0,-1> , <0,0>\n";
		mf << "Result: " << a1 - a1 << " , " << a1 - a2 << " , " << a2 - a2 << " , " << a2 - a3 << " , " << a3 - a3;
		mf << "\n\n";
		mf << "Vector2 * 2 \nExpected Result: <2,6> , <2,4> , <2,6> , <2,8> , <14,8>\n";
		mf << "Result: " << a1 * 2 << " , " << a2 * 2 << " , " << a3 * 2 << " , " << a4 * 2 << " , " << a5 * 2;
		mf << "\n\n";
		mf << "Matrix2 Magnitude \nExpected Result: 3.16228 , 2.23607 , 3.16228 , 4.12311 , 8.06226\n";
		mf << "Result: " << a1.Magnitude() << " , " << a2.Magnitude() << " , " << a3.Magnitude() << " , " << a4.Magnitude() << " , " << a5.Magnitude();
		mf << "\n\n";
		mf << "Matrix2 Normalize \nExpected Result: <0.316228,0.948683> , <0.447214,0.894427> , <0.316228,0.948683> , <0.242536,0.970143> , <0.868243,0.496139>  \n";
		mf << "Result: " << a1.Normalize() << " , " << a2.Normalize() << " , " << a3.Normalize() << " , " << a4.Normalize() << " , " << a5.Normalize();
		mf << "\n\n";
		mf << "Matrix2 DotProduct \nExpected Result: 10 , 7 , 10 , 13 , 19\n";
		mf << "Result: " << a1.DotProduct(a1) << " , " << a1.DotProduct(a2) << " , " << a1.DotProduct(a3) << " , " << a1.DotProduct(a4) << " , " << a1.DotProduct(a5);
		mf << "\n\n";
		mf << "Matrix2 * Matrix2 \nExpected Result: ( 11 24 19 44 ) (25 21 43 37) (11 24 22 62) (16 33 44 93) (16 21 28 37)\n";
		mf << "Result: 2x2 " << b1*b3 << ")" << b1*b2 << ")" << b2*b3 << ")" << b4*b4 << ")" << b1*b1 << ")";
		mf << "\n\n";
		mf << "Matrix2 * Vector2 \nExpectked Result: <14,18> , <16,13> , <10,18> , <18,39> , <30,41>\n";
		mf << "Result: " << b1*a1 << ")" << b1*b2 << ")" << b2*b3 << ")" << b4*b4 << ")" << b1*b1 << ")";
		mf << "\n";
		mf << "------------------------------------------------------------------------------------------\n";
		mf << "Vector3 = Vector3 \nExpected Result: 1 , 0 , 1 , 1 , 1\n";
		mf << "Result: " << (d1 == d1) << " , " << (d1 == d2) << " , " << (d2 == d2) << " , " << (d2 == d2) << " , " << (d3 == d3);
		mf << "\n\n";
		mf << "Vector3 + Vector3 \nExpected Result: <6,8,10> , <6,10,10> , <6,12,10> , <9,10,10> , <12,8,10>\n";
		mf << "Result: " << d1 + d1 << " , " << d1 + d2 << " , " << d2 + d2 << " , " << d2 + d3 << " , " << d3 + d3;
		mf << "\n\n";
		mf << "Vector3 - Vector3 \nExpected Result: <0,0,0> , <0,-2,0> , <0,0,0> , <-3,2,0> , <0,0,0>\n";
		mf << "Result: " << d1 - d1 << " , " << d1 - d2 << " , " << d2 - d2 << " , " << d2 - d3 << " , " << d3 - d3;
		mf << "\n\n";
		mf << "Vector3 * 3 \nExpected Result: <9,12,15> , <6,12,10> , <12,8,10> , <6,8,14> , <6,18,10>\n";
		mf << "Result: " << d1 * 3 << " , " << d2 * 2 << " , " << d3 * 2 << " , " << d4 * 2 << " , " << d5 * 2;
		mf << "\n\n";
		mf << "Matrix3 Magnitude \nExpected Result: 7.07107 , 8.3666 , 8.77496 , 8.60233 , 10.7238\n";
		mf << "Result: " << d1.Magnitude() << " , " << d2.Magnitude() << " , " << d3.Magnitude() << " , " << d4.Magnitude() << " , " << d5.Magnitude();
		mf << "\n\n";
		mf << "Matrix3 Normalize \nExpected Result: <0.424264,0.565685,0.707107> , <0.447214,0.894427> , <0.316228,0.948683> , <0.242536,0.970143> , <0.868243,0.496139>\n";
		mf << "Result: " << d1.Normalize() << " , " << d2.Normalize() << " , " << d3.Normalize() << " , " << d4.Normalize() << " , " << d5.Normalize();
		mf << "\n\n";
		mf << "Matrix3 DotProduct \nExpected Result: 50 , 58 , 59 , 60 , 70\n";
		mf << "Result: " << d1.DotProduct(d1) << " , " << d1.DotProduct(d2) << " , " << d1.DotProduct(d3) << " , " << d1.DotProduct(d4) << " , " << d1.DotProduct(d5);
		mf << "\n\n";
		mf << "Matrix3 CrossPoduct \nExpexted Result: <0,0,5> , <-10,0,15> , <0,-15,-10> , <8,6,5> , <-25,0,30>\n";
		mf << "Result: " << d1.CrossProduct(d1) << " , " << d1.CrossProduct(d2) << " , " << d1.CrossProduct(d3) << " , " << d1.CrossProduct(d4) << " , " << d1.CrossProduct(d5);
		mf << "\n\n";
		mf << "Matrix3 * Matrix3 \nExpected Result: (704 1652 476 225 853 130 2020 5332 3263 ) (1264 842 476 415 263 130 2070 3122 3263) (304 932 476 195 1043 370 2020 3212 3593)\n(384 532 436 145 253 120 2020 3092 3263) (704 1652 476 225 853 130 2020 5332 3263)\n";
		mf << "Result: " << e1*e1 << ")" << e1*e2 << ")" << e2*e3 << ")" << e4*e4 << ")" << e1*e4 << ")";
		mf << "\n\n";
		mf << "Matrix3 * Vector3 \nExpected Result: <212,464,300> <228,502,302> <267,292,321> <278,392,410> <252,349,305>\n";
		mf << "Result: " << e1*d1 << e1*d2 << e2*d3 << e4*d4 << e4*d5;
		mf << "\n\n";
		mf << "Matrix3 rotated 30.7 degrees around X axis \nExpected Result: \n(1 1 0 0.349309 0 0.859852 1.85985 0 0 )\n(1 0 1 0.349309 0 0.859852 1.85985 0 0)\n(1 0 0 0.349309 0 0.859852 1.85985 0 0)\n(0 1 0 0.349309 0 0.859852 1.85985 0 0)\n(1 0 0 - 0.510543 0 0.859852 0.859852 0 0)\n";
		mf << "Result: " << Rotate3D1.setRotateX((30.7 * pi) / 180) << ")" << Rotate3D2.setRotateX((30.7 * pi) / 180) << ")" << Rotate3D3.setRotateX((30.7 * pi) / 180) << ")" << Rotate3D4.setRotateX((30.7 * pi) / 180) << ")" << Rotate3D5.setRotateX((30.7 * pi) / 180) << ")";
		mf << "\n\n";
		mf << "Matrix3 rotated 35.2 degrees around Y axis \nExpected Result: \n(1.88922 0.817145 0 0.349309 0 0.859852 1.22877 -0.576432 0.495647 )\n(1.88922 0 0.817145 0.349309 0 0.859852 1.22877 0 - 0.0807857)\n(1.88922 0 0 0.349309 0 0.859852 1.22877 0 0.495647)\n(1.07208 0.817145 0 0.349309 0 0.859852 1.80521 - 0.576432 0.495647)\n(1.31279 0 0 - 0.510543 0 0.859852 - 0.290996 0 0.495647)\n";
		mf << "Result: " << Rotate3D1.setRotateY((35.2 * pi) / 180) << ")" << Rotate3D2.setRotateY((35.2 * pi) / 180) << ")" << Rotate3D3.setRotateY((35.2 * pi) / 180) << ")" << Rotate3D4.setRotateY((35.2 * pi) / 180) << ")" << Rotate3D5.setRotateY((35.2 * pi) / 180) << ")";
		mf << "\n\n";
		mf << "Matrix3 rotated 40.2 degrees around Z axis \nExpected Result: \n(1.21752 0.624132 -0.554998 1.48622 0.527432 0.656752 1.49557 -0.576432 0.495647 )\n(1.21752 0 0.0691338 1.48622 0 1.18418 1.49557 0 - 0.0807857)\n(1.21752 0 - 0.554998 1.48622 0 0.656752 1.49557 0 0.495647)\n(0.593385 0.624132 - 0.554998 0.958783 0.527432 0.656752 2.07201 - 0.576432 0.495647)\n(1.33224 0 - 0.554998 0.457401 0 0.656752 - 0.680947 0 0.495647)\n";
		mf << "Result: " << Rotate3D1.setRotateZ((40.2 * pi) / 180) << ")" << Rotate3D2.setRotateZ((40.2 * pi) / 180) << ")" << Rotate3D3.setRotateZ((40.2 * pi) / 180) << ")" << Rotate3D4.setRotateZ((40.2 * pi) / 180) << ")" << Rotate3D5.setRotateZ((40.2 * pi) / 180) << ")";
		mf << "\n";
		mf << "------------------------------------------------------------------------------------------\n";
		mf << "Vector4 = Vector4 \nExpected Result: 1 , 0 , 1 , 1 , 1\n";
		mf << "Result:" << (f1 == f1) << " , " << (f1 == f2) << " , " << (f2 == f2) << " , " << (f2 == f2) << " , " << (f3 == f3);
		mf << "\n\n";
		mf << "Vector4 + Vector4 \nExpected Result: <14,8,4,8> , <14,7,5,8> , <14,6,6,8> , <14,6,5,6> , <14,6,4,4>\n";
		mf << "Result:" << f1 + f1 << " , " << f1 + f2 << " , " << f2 + f2 << " , " << f2 + f3 << " , " << f3 + f3;
		mf << "\n\n";
		mf << "Vector4 - Vector4 \nExpected Result: <0,0,0,0> , <0,1,-1,0> , <0,0,0,0> , <0,0,1,2> , <0,0,0,0>\n";
		mf << "Result:" << f1 - f1 << " , " << f1 - f2 << " , " << f2 - f2 << " , " << f2 - f3 << " , " << f3 - f3;
		mf << "\n\n";
		mf << "Vector4 * A Number \nExpected Result: <28,16,8,16> , <14,6,6,8> , <14,6,4,4> , <49,21,14,28> , <3,9,6,12>\n";
		mf << "Result:" << f1 * 4 << " , " << f2 * 2 << " , " << f3 * 2 << " , " << f4 * 7 << " , " << f5 * 3;
		mf << "\n\n";
		mf << "Matrix4 Magnitude \nExpected Result: 9.21954 , 9.11043 , 8.12404 , 8.83176 , 5.47723\n";
		mf << "Result:" << f1.Magnitude() << " , " << f2.Magnitude() << " , " << f3.Magnitude() << " , " << f4.Magnitude() << " , " << f5.Magnitude();
		mf << "\n\n";
		mf << "Matrix4 Normalize \nExpected Result: <0.759257,0.433861,0.21693,0.433861> , <0.76835,0.329293,0.329293,0.439057> , <0.316228,0.948683> , <0.242536,0.970143> , <0.868243,0.496139>\n";
		mf << "Result:" << f1.Normalize() << " , " << f2.Normalize() << " , " << a3.Normalize() << " , " << a4.Normalize() << " , " << a5.Normalize();
		mf << "\n\n";
		mf << "Matrix4 DotProduct \nExpected Result: 85 , 83 , 73 , 81 , 39  \n";
		mf << "Result:" << f1.DotProduct(f1) << " , " << f1.DotProduct(f2) << " , " << f1.DotProduct(f3) << " , " << f1.DotProduct(f4) << " , " << f1.DotProduct(f5);
		mf << "\n\n";
		mf << "Matrix4 * Matrix4 \nExpected Result: \n(1747 2186 2128 1070 5232 6710 6961 3268 684 897 1028 494 330 421 432 238 )\n(1747 2186 2128 1070 5232 6710 6961 3268 684 897 1028 494 330 421 432 238)\n(1747 2186 2128 1070 5232 6710 6961 3268 684 897 1028 494 330 421 432 238)\n(1747 2186 2128 1070 5232 6710 6961 3268 684 897 1028 494 330 421 432 238)\n(1747 2186 2128 1070 5232 6710 6961 3268 684 897 1028 494 330 421 432 238)\n";
		mf << "Result:" << g1*g1 << ")" << g1*g2 << ")" << g2*g3 << ")" << g4*g4 << ")" << g1*g4 << ")";
		mf << "\n\n";
		mf << "Matrix4 * Vector4 \nExpected Result: \n<335,459,541,376> <287,400,470,370> <272,382,459,352> <278,390,469,368> <335,459,541,376>\n";
		mf << "Result:" << g1*f1 << g1*f2 << g2*f3 << g4*f4 << g1*f1;
		mf << "\n\n";
		mf << "Matrix4 rotated 30 degrees around X axis \nExpected Result: \n(1 1 1 1 0 0.366025 -0.5 0.866025 0 1.36603 0.866025 0.5 0 0 0 1 )\n(1 1 0 1 0 0.366025 - 0.5 0.866025 0 1.36603 0.866025 0.5 0 0 0 1)\n(1 0 1 1 0 0.366025 - 0.5 0.866025 0 1.36603 0.866025 0.5 0 0 0 1)\n(0 1 1 1 0 0.366025 - 0.5 0.866025 0 1.36603 0.866025 0.5 0 0 0 1)\n(1 1 1 0 0 0.366025 - 0.5 0.866025 0 1.36603 0.866025 0.5 0 0 0 1)\n";
		mf << "Result:" << Rotate4D1.setRotateX((30 * pi) / 180) << ")" << Rotate4D2.setRotateX((30 * pi) / 180) << ")" << Rotate4D3.setRotateX((30 * pi) / 180) << ")" << Rotate4D4.setRotateX((30 * pi) / 180) << ")" << Rotate4D5.setRotateX((30 * pi) / 180) << ")";
		mf << "\n\n";
		mf << "Matrix4 rotated 35 degrees around Y axis \nExpected Result: \n(0.819152 1.60267 1.31588 1.10594 0 0.366025 -0.5 0.866025 -0.573577 0.545406 0.13583 -0.164001 0 0 0 1 )\n(0.819152 1.60267 0.496732 1.10594 0 0.366025 - 0.5 0.866025 - 0.573577 0.545406 0.709406 - 0.164001 0 0 0 1)\n(0.819152 0.78352 1.31588 1.10594 0 0.366025 - 0.5 0.866025 - 0.573577 1.11898 0.13583 - 0.164001 0 0 0 1)\n(0 1.60267 1.31588 1.10594 0 0.366025 - 0.5 0.866025 0 0.545406 0.13583 - 0.164001 0 0 0 1)\n(0.819152 1.60267 1.31588 0.286788 0 0.366025 - 0.5 0.866025 - 0.573577 0.545406 0.13583 0.409576 0 0 0 1)\n";
		mf << "Result:" << Rotate4D1.setRotateY((35 * pi) / 180) << ")" << Rotate4D2.setRotateY((35 * pi) / 180) << ")" << Rotate4D3.setRotateY((35 * pi) / 180) << ")" << Rotate4D4.setRotateY((35 * pi) / 180) << ")" << Rotate4D5.setRotateY((35 * pi) / 180) << ")";
		mf << "\n\n";
		mf << "Matrix4 rotated 40 degrees around Z axis \nExpected Result: \n(0.627507 0.992441 1.32942 0.290529 0.526541 1.31057 0.462812 1.3743 -0.573577 0.545406 0.13583 -0.164001 0 0 0 1) \n(0.627507 0.992441 0.701912 0.290529 0.526541 1.31057 - 0.0637291 1.3743 - 0.573577 0.545406 0.709406 - 0.164001 0 0 0 1)\n(0.627507 0.364935 1.32942 0.290529 0.526541 0.784029 0.462812 1.3743 - 0.573577 1.11898 0.13583 - 0.164001 0 0 0 1)\n(0 0.992441 1.32942 0.290529 0 1.31057 0.462812 1.3743 0 0.545406 0.13583 - 0.164001 0 0 0 1)\n(0.627507 0.992441 1.32942 - 0.336978 0.526541 1.31057 0.462812 0.847758 - 0.573577 0.545406 0.13583 0.409576 0 0 0 1)\n";
		mf << "Result:" << Rotate4D1.setRotateZ((40 * pi) / 180) << ")" << Rotate4D2.setRotateZ((40 * pi) / 180) << ")" << Rotate4D3.setRotateZ((40 * pi) / 180) << ")" << Rotate4D4.setRotateZ((40 * pi) / 180) << ")" << Rotate4D5.setRotateZ((40 * pi) / 180) << ")";
		mf << "\n";
		mf << "------------------------------------------------------------------------------------------\n";
		mf.close();
	}
	else std::cout << "Unable to open file \n";
	system("pause");
	return 0;
}