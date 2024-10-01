#include <raylib.h>
#include <time.h>

#define SCREENWIDTH 1200
#define SCREENHEIGHT 800
#define GRAVITY 1

struct Body2d{
  Vector2 Position;
  float Volume; //in 2d is just area
  float Density;
  float Mass;
  float Weight;
  float Velocity
};

struct Body2d ConstructBody2d(float x,float y, float Volume, float Density, float Velocity){

 struct Body2d Output;
  Output.Position.x = x;
  Output.Position.y = y;
  Output.Volume = Volume;
  Output.Density = Density;
  Output.Mass = Volume*Density;
  Output.Weight = Output.Mass * GRAVITY;
  Output.Velocity = Velocity;

return Output;

}


int main(void){
  SetTargetFPS(60);
  
  const float CIRCLERADIUS = 5;
  

  struct Body2d body = ConstructBody2d(SCREENWIDTH/2, SCREENHEIGHT/2, 2*CIRCLERADIUS*PI,5,5);


  InitWindow(SCREENWIDTH,SCREENHEIGHT,"H");
  
  while (!WindowShouldClose()) {

   float DeltaTime = GetFrameTime();
    body.Position.y += body.Velocity * DeltaTime;
    BeginDrawing();

    ClearBackground(BLACK);
    DrawCircleV(body.Position,CIRCLERADIUS,RED);

    
  
    EndDrawing();
  }
CloseWindow();
  return 0;
}
