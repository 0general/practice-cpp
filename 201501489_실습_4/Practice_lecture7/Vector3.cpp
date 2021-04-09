#include "Vector3.h"

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Vector3::Vector3() {
	v0 = 0;
	v1 = 0;
	v2 = 0;
}
Vector3::Vector3(int b0, int b1, int b2) : v0(b0), v1(b1), v2(b2) {
	/*this->v0 = b0;
	this->v1 = b1;
	this->v2 = b2;*/
}
const int Vector3::distance(const Vector3& vec) const
{
	int ans = abs(this->v0 - vec.v0) + abs(this->v1 - vec.v1) + abs(this->v2 - vec.v2);
	return ans;
}



// elementwise operations
const Vector3 operator +(const Vector3& vec1, const Vector3& vec2) {
	Vector3 veca;
	veca.v0 = vec1.v0 + vec2.v0;
	veca.v1 = vec1.v1 + vec2.v1;
	veca.v2 = vec1.v2 + vec2.v2;
	return veca;
}
const Vector3 operator -(const Vector3& vec1, const Vector3& vec2) {
	Vector3 veca;
	veca.v0 = vec1.v0 - vec2.v0;
	veca.v1 = vec1.v1 - vec2.v1;
	veca.v2 = vec1.v2 - vec2.v2;
	return veca;
}

// comparison operations
bool operator ==(const Vector3& vec1, const Vector3& vec2) {
	if (vec1.v0 == vec2.v0) {
		if (vec1.v1 == vec2.v1) {
			if (vec1.v2 == vec2.v2) {
				return true;
			}
			else { return false; }
		}
		else { return false;  }
	}
	else { return false; }
}
bool operator !=(const Vector3& vec1, const Vector3& vec2) {
	if (vec1.v0 == vec2.v0) {
		if (vec1.v1 == vec2.v1) {
			if (vec1.v2 == vec2.v2) {
				return false;
			}
			else { return true; }
		}
		else { return true; }
	}
	else { return true; }

}
bool operator <(const Vector3& vec1, const Vector3& vec2) {
	if (vec1.v0 > vec2.v0) {
		return false;
	}
	else if (vec1.v0 == vec2.v0) {
		if (vec1.v1 > vec2.v1) {
			return false;
		}
		else if (vec1.v1 == vec2.v1) {
			if (vec1.v2 > vec2.v2) {
				return false;
			}
			else if (vec1.v2 == vec2.v2) {
				return false;
			}
			else { return true; }
		}
		else { return true; }
	}
	else { return true; }

}
bool operator <=(const Vector3& vec1, const Vector3& vec2) {
	if (vec1.v0 > vec2.v0) {
		return false;
	}
	else if (vec1.v0 == vec2.v0) {
		if (vec1.v1 > vec2.v1) {
			return false;
		}
		else if (vec1.v1 == vec2.v1) {
			if (vec1.v2 > vec2.v2) {
				return false;
			}
			else if (vec1.v2 == vec2.v2) {
				return true;
			}
			else { return true; }
		}
		else { return true; }
	}
	else { return true; }

}
bool operator >(const Vector3& vec1, const Vector3& vec2) {
	if (vec1.v0 > vec2.v0) {
		return true;
	}
	else if (vec1.v0 == vec2.v0) {
		if (vec1.v1 > vec2.v1) {
			return true;
		}
		else if (vec1.v1 == vec2.v1) {
			if (vec1.v2 > vec2.v2) {
				return true;
			}
			else if (vec1.v2 == vec2.v2) {
				return false;
			}
			else { return false; }
		}
		else { return false; }
	}
	else { return false; }

}
bool operator >=(const Vector3& vec1, const Vector3& vec2) {
	if (vec1.v0 > vec2.v0) {
		return true;
	}
	else if (vec1.v0 == vec2.v0) {
		if (vec1.v1 > vec2.v1) {
			return true;
		}
		else if (vec1.v1 == vec2.v1) {
			if (vec1.v2 > vec2.v2) {
				return true;
			}
			else if (vec1.v2 == vec2.v2) {
				return true;
			}
			else { return false; }
		}
		else { return false; }
	}
	else { return false; }
}
void Vector3::print() const
{
	cout << "(" << v0 << ", " << v1 << ", " << v2 << ")" << endl;
}


