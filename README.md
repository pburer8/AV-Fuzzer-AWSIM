# AV-Fuzzer

## Dependencies
  * Ubuntu 22.04 LTS
  * Autoware (with ROS2)
  * AWSIM v1.3.1
  * C++ 11.4.0
  
## Run AV-Fuzzer
  * Launch the AV-Fuzzer ROS2 packages (instructions found in src/README.md)
  * Configurate "simulation.cpp", "liability.cpp", and "drive_experiment.py" for driving environments, safety violation constraints, and experiment parameters
  * Run "python3 drive_experiment.py"

## Paper
  * AV-FUZZER: Finding Safety Violations in Autonomous Driving Systems (ISSRE'20)
