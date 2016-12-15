#pragma once
class Vector2
{
public:
	//Default constructor
	Vector2();
	//Constructor that takes in floats that are set to equal points in the array
	Vector2(float xpos, float ypos);
	//Name: operator ==
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns a check if each point is equal to the set one
	bool operator == (const Vector2 &A);
	//Name: operator +
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and adds each 
	//point to the other and returns that Vector
	Vector2 operator +(const Vector2 &A);
	//Name: operator -
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and subtracts each 
	//point to the other and returns that Vector
	Vector2 operator -(const Vector2 &A);
	//Name: operator *
	//Arguments: Takes in a variable called "Mult" with type float
	//Description: Creates a temporary Vector that takes the Vector in the arguments and multiplies each 
	//point to the number that is taken in and returns that Vector
	Vector2 operator *(float Mult);
	//Name: Magnitude
	//Arguments: N/A
	//Description: Multplies each point times itself then adds each number up and square roots the whole thing
	float Magnitude();
	//Name: Normalize 
	//Arguments: N/A
	//Description: Creates a temporary vector that dives each point by the Magnitude function then returns that Vector
	Vector2 Normalize();
	//Name: DotProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns each point times the taken in Vector and adds each of those numbers 
	float DotProduct(const Vector2 &A);
	float VA[2];
	float x, y;
};

class Vector3
{
public:
	//Default constructor
	Vector3();
	//Constructor that takes in floats that are set to equal points in the array
	Vector3(float xpos, float ypos, float zpos);
	//Name: operator ==
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns a check if each point is equal to the set one
	bool operator == (const Vector3 &A);
	//Name: operator +
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and adds each 
	//point to the other and returns that Vector
	Vector3 operator +(const Vector3 &A);
	//Name: operator -
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and subtracts each 
	//point to the other and returns that Vector
	Vector3 operator -(const Vector3 &A);
	//Name: operator *
	//Arguments: Takes in a variable called "Mult" with type float
	//Description: Creates a temporary Vector that takes the Vector in the arguments and multiplies each 
	//point to the number that is taken in and returns that Vector
	Vector3 operator *(float Mult);
	//Name: Magnitude
	//Arguments: N/A
	//Description: Multplies each point times itself then adds each number up and square roots the whole thing
	float Magnitude();
	//Name: Normalize 
	//Arguments: N/A
	//Description: Creates a temporary vector that dives each point by the Magnitude function then returns that Vector
	Vector3 Normalize();
	//Name: DotProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns each point times the taken in Vector and adds each of those numbers 
	float DotProduct(const Vector3 &A);
	//Name: CrossProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary vector that values are given by the cross product
	Vector3 CrossProduct(const Vector3 &A);
	float VA[3];
	float x, y, z;
};

class Vector4
{
public:
	//Default constructor
	Vector4();
	//Constructor that takes in floats that are set to equal points in the array
	Vector4(float xpos, float ypos, float zpos, float wpos);
	//Name: operator ==
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns a check if each point is equal to the set one
	bool operator == (const Vector4 &A);
	//Name: operator +
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and adds each 
	//point to the other and returns that Vector
	Vector4 operator +(const Vector4 &A);
	//Name: operator -
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Creates a temporary Vector that takes the Vector in the arguments and subtracts each 
	//point to the other and returns that Vector
	Vector4 operator -(const Vector4 &A);
	//Name: operator *
	//Arguments: Takes in a variable called "Mult" with type float
	//Description: Creates a temporary Vector that takes the Vector in the arguments and multiplies each 
	//point to the number that is taken in and returns that Vector
	Vector4 operator *(float Mult);
	//Name: Magnitude
	//Arguments: N/A
	//Description: Multplies each point times itself then adds each number up and square roots the whole thing
	float Magnitude();
	//Name: Normalize 
	//Arguments: N/A
	//Description: Creates a temporary vector that dives each point by the Magnitude function then returns that Vector
	Vector4 Normalize();
	//Name: DotProduct
	//Arguments: Takes in a refrenced variable called "A" with const type Vector
	//Description: Returns each point times the taken in Vector and adds each of those numbers 
	float DotProduct(const Vector4 &A);
	float VA[4];
	float x, y, z, w;
};

class Matrix2
{
public:
	//Default constructor
	Matrix2();
	//Constructor that takes a 2x2 array
	Matrix2(float a[2][2]);
	//Constructor that takes in floats to initialize the 2x2 array
	Matrix2(float a, float b, float c, float d);
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 2x2 Matrix
	//Description: Creates a temporary Matrix that holds each equation that will equal that number at that current point
	//then returns that matrix
	Matrix2 operator * (const Matrix2 &a);
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 2x2 Matrix
	//Description: Creates a temporary Vector that holds each equation that will equal that number at that current point
	//then returns that vector
	Vector2 operator * (const Vector2 &a);
	float matrix2[2][2];
};

class Matrix3
{
public:
	//Default constructor
	Matrix3();
	//Constructor that takes a 1D array
	Matrix3(float a[9]);
	//Constructor that takes in floats to initialize the 1D array
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 3x3 Matrix
	//Description: Creates floats for each indivdual point in a 3x3 matrix equal to each equation that will get the number
	//at the current point then sets a temporary matrix that has each float and returns it
	Matrix3 operator * (const Matrix3 &a);
	//Name: Overloading the multiplication operator for vector multiplication
	//Arguments: One argument that takes in a 4D Vector 
	//Description: Creates 3 floats that will has equations that will equal each X, Y, and Z.
	//Then creates a temporay Vector thas holds each float and returns that Vector
	Vector3 operator * (const Vector3 &a);
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the X axis for 3D using the
	//overloading operator returning the current instance 
	Matrix3 setRotateX(float a);
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Y axis for 3D using the
	//overloading operator returning the current instance 
	Matrix3 setRotateY(float a);
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Z axis for 3D using the
	//overloading operator returning the current instance 
	Matrix3 setRotateZ(float a);
	float matrix3[9];
};

class Matrix4
{
public:
	//Default constructor
	Matrix4();
	//Constructor that takes a 4x4 array
	Matrix4(float a[4][4]);
	//Constructor that takes in floats to initialize the array
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	//Name: setRotateX
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the X axis for 4D using the
	//overloading operator returning the current instance 
	Matrix4 setRotateX(float a);
	//Name: setRotateY
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Y axis for 4D using the
	//overloading operator returning the current instance 
	Matrix4 setRotateY(float a);
	//Name: setRotateZ
	//Arguments: Takes in variable a with type float
	//Description: Fuction for rotating around the Z axis for 4D using the
	//overloading operator returning the current instance 
	Matrix4 setRotateZ(float a);
	//Name: Overloading the multiplication operator for matrix multiplication
	//Arguments: One argument that takes in 4x4 Matrix
	//Description: Creates a temporary matrix that is all zeros then sets them all equal
	//to the two that are multiplied together
	Matrix4 operator * (const Matrix4 &a)const;
	//Name: Overloading the multiplication operator for vector multiplication
	//Arguments: One argument that takes in a 4D Vector 
	//Description: Creates a temporary vector that is all zeros loops through the vector
	//and matrix to then multiply each one  
	Vector4 operator * (const Vector4 &a)const;
	float matrix4[4][4];
};