#include <vector>
#include <eigen3/Eigen/Dense>
#include "ros/ros.h"
#include "octomap/octomap.h"
#include "octomap/OcTreeNode.h"
#include "octomap/OcTree.h"
#define EXTENSION_RANGE 5.0
#define VMAX 1.2
#define YAWMAX 0.75
#define SQ(x) ((x)*(x))
#define PITCH 0.0
#define CAM_HORIZONTAL 90.0
#define CAM_VERTICAL 60.0
#define SQRT2 0.70711
#define DEGRESSIVE_COEFF 1.0

namespace nbvInspection
{
  template<typename stateVec>
  class nbvplanner
  {
  public:
    typedef std::vector<stateVec> vector_t;
    typedef octomap::OcTree octomap_t;
    
    nbvplanner();
    ~nbvplanner();
    vector_t expand(nbvplanner<stateVec>& instance, int N, int M, vector_t s, double& IGout, vector_t (nbvplanner<stateVec>::*sample)(stateVec), double (nbvplanner<stateVec>::*informationGain)(stateVec));
    vector_t expandStructured(nbvplanner<stateVec>& instance, int I, vector_t s, double& IGout, double (nbvplanner<stateVec>::*informationGain)(stateVec));
    vector_t sampleHolonomic(stateVec s);
    vector_t sampleEuler(stateVec s);
    double informationGainRand(stateVec s);
    double informationGainSimple(stateVec s);
    double informationGainCone(stateVec s);
    octomap_t * octomap;
    std::vector<Eigen::Vector3f> camBoundNormals;
  };
}
