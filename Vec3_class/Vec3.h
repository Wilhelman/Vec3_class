#ifndef _VEC3_CLASS_
#define _VEC3_CLASS_

template<class TYPE>

class Vec3
{
public:
	TYPE x, y, z;

public:
	Vec3() { x = y = z = 0; }

	Vec3(TYPE x, TYPE y, TYPE z) : x(x), y(y), z(z) { }

	void zero() { x = y = z = 0; }

	bool operator==(const Vec3& v) const
	{
		if (x == v.x && y == v.y && z == v.z)
			return true;
		else
			return false;
	}

	Vec3<TYPE> operator+(const Vec3& v) const
	{
		return Vec3<TYPE>(x+v.x,y+v.y,z+v.z);
	}

	void operator+=(const Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	Vec3<TYPE> operator-(const Vec3& v) const
	{
		return Vec3<TYPE>(x - v.x, y - v.y, z - v.z);
	}

	void operator-=(const Vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vec3<TYPE> operator*(const TYPE& k) const
	{
		return Vec3<TYPE>(x * v.x, y * v.y, z * v.z);
	}

	void operator*=(const TYPE& k)
	{
		x *= k;
		y *= k;
		z *= k;
	}

	Vec3<TYPE> operator/(const TYPE& k) const
	{
		return Vec3<TYPE>(x / k, y / k, z / k);
	}

	Vec3<TYPE> operator/=(const TYPE& k)
	{
		return Vec3<TYPE>(x /= k, y /= k, z /= k);
	}

	float vecNorm() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	TYPE dotProduct(const Vec3& v) const
	{
		return (x*v.x + y*v.y + z*v.z);
	}

	void normalise()
	{
		x /= vecNorm();
		y /= vecNorm();
		z /= vecNorm();
	}


	void displayVector() const
	{
		cout << "Vector: " << this->x << "\t" << this->y << "\t" << this->z << endl;
	}

	TYPE getDistance(const Vec3& vector_2) const
	{
		TYPE dx = vector_2.x - x;
		TYPE dy = vector_2.y - y;
		TYPE dz = vector_2.z - z;

		return sqrt(dx*dx + dy*dy + dz*dz);
	}


};

#endif // _VEC3_CLASS_