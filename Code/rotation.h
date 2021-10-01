
// rotation functions

void multiply_Ax(double A[3+1][3+1], double x[3+1], double b[3+1]);
// multiply a matrix times a vector, b = A*x

void multiply_AB(double A[3+1][3+1], double B[3+1][3+1], double C[3+1][3+1]);
// multiply two 3x3 matrices, C = A*B

void x_rotation(double R[3+1][3+1], double u);
void y_rotation(double R[3+1][3+1], double u);
void z_rotation(double R[3+1][3+1], double u);

// conversion functions between euler angles, rotation matrix,
// and quaternion representations

void euler_to_rotation(double yaw, double pitch, double roll,
					   double R[3+1][3+1]);

void rotation_to_euler(double R[3+1][3+1], 
					double &yaw, double &pitch, double &roll);

void euler_to_quaternion(double yaw, double pitch, double roll,
	double &e0, double &e1, double &e2, double &e3);

void rotation_to_quaternion(double R[3+1][3+1],
	double &e0, double &e1, double &e2, double &e3);

void quaternion_to_rotation(double e0, double e1, double e2,
		double e3, double R[3+1][3+1]);

void quaternion_to_euler(double e0, double e1, double e2,
		double e3, double &yaw, double &pitch, double &roll);

void update_RT(double R1[3+1][3+1], double T1[3+1], double Re[3+1][3+1], double Te[3+1]);

void rt_transform(double R[3+1][3+1], double T[3+1],
				  double *x, double *y, double *z,
				  double *X, double *Y, double *Z, int n);
