#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

/// 本程序演示sophus的基本用法

int main(int argc, char **argv) {

	Matrix3d R =Matrix3d::Identity();
	Quaterniond q(R);
	Vector3d omega{0.01,0.02,0.03};
	cout << "R = \n" << R << endl;
	cout << "q = \n" << Matrix3d(q) << endl;


	Matrix3d R_updated = R * Sophus::SO3d::exp(omega).matrix();
    cout << "R_updated = \n" << R_updated << endl;

    Eigen::Quaterniond dq;
    Eigen::Vector3d dtheta_half =  omega /2.0;
	dq.w() = 1;
	dq.x() = dtheta_half.x();
	dq.y() = dtheta_half.y();
	dq.z() = dtheta_half.z();
	dq.normalize();
    Quaterniond q_updated = q * dq;
    cout << "q_updated = \n" << Matrix3d(q_updated) << endl;


  return 0;
}
