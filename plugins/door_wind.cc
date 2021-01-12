#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <stdlib.h>

namespace gazebo
{
  class DoorWind : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model, link and joint

      this->model = _parent;
      this->link=  this->model->GetChildLink("door_simple::lever");
      this->joint=  this->model->GetJoint("door_simple::joint_frame_door");

      // Random wind force and direction
      srand(time(0)); 
      int wind_yawn_direction = rand() % 360;   //  Random 0-360 degrees
      float wind_force = float(rand() % 600 + 400)/1000;      //  Random from 400mN to 1N
      wind.X()= wind_force*cos(wind_yawn_direction*3.1416/180);
      wind.Y()= wind_force*sin(wind_yawn_direction*3.1416/180);
      wind.Z()= 0.0;
      std::cerr << "wind yawn: " << wind_yawn_direction << std::endl;
      std::cerr << "wind force: " << wind_force << std::endl;
      
      
      // Listen to the update event. This event is broadcast every
      // simulation iteration.
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          std::bind(&DoorWind::OnUpdate, this));
    }

    // Called by the world update start event
    public: void OnUpdate()
    {
      //  Apply force at every interaction
      link->AddForce(ignition::math::Vector3d(wind.X(), wind.Y(), wind.Z()));

    }

    // Pointer to the model
    private: physics::ModelPtr model;
    private: physics::LinkPtr link;
    private: physics::JointPtr joint;
    private: ignition::math::Vector3d wind;
    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(DoorWind)
}

