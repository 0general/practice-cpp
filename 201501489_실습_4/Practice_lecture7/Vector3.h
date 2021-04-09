#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{
public:
	Vector3();
	Vector3(int b0, int b1, int b2);
	const int distance(const Vector3& vec) const;
	//elementwise operations
	friend const Vector3 operator +(const Vector3& vec1, const Vector3& vec2);
	friend const Vector3 operator -(const Vector3& vec1, const Vector3& vec2);
	// comparison operations
	friend bool operator ==(const Vector3& vec1, const Vector3& vec2);
	friend bool operator !=(const Vector3& vec1, const Vector3& vec2);
	friend bool operator <(const Vector3& vec1, const Vector3& vec2);
	friend bool operator <=(const Vector3& vec1, const Vector3& vec2);
	friend bool operator >(const Vector3& vec1, const Vector3& vec2);
	friend bool operator >=(const Vector3& vec1, const Vector3& vec2);
	void print() const;
private:
	int v0, v1, v2;
};


#endif // !VECTOR3



