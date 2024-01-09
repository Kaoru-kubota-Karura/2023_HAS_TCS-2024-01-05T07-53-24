using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor back_l;
extern motor back_r;
extern motor front_l;
extern motor front_r;
extern motor catapult;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );