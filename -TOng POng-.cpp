#include <iostream>
#include <raylib.h>

#define DARKBLUE \
    (Color) { 0, 82, 172, 255 }
#define PURPLE \
    (Color) { 200, 122, 255, 255 }
#define VIOLET \
    (Color) { 135, 60, 190, 255 }
#define DARKPURPLE \
    (Color) { 112, 31, 126, 255 }
#define LIME \
    (Color) { 0, 158, 47, 255 }

using namespace std;
const int scr_wd = 1280;
const int scr_ht = 720;
int player_point = 0;
int bot_point = 0;
class Ball
{

public:
    float x, y;
    int spx, spy;
    int rad;
    void draw()
    {
        DrawCircle(x, y, rad, PINK);
    }
    void move()
    {
        x += spx;
        y += spy;
        if (y + rad >= scr_ht || y - rad <= 0)
            spy *= -1;

        if (x + rad >= scr_wd)
        {
            bot_point++;
            reset();
        }
        else if (x - rad <= 0)
        {
            player_point++;
            reset();
        }
    }
    void reset()
    {
        x = 1280 / 2;
        y = 720 / 2;

        int turn[2] = {1, -1};
        spx *= turn[GetRandomValue(0, 1)];
        spy *= turn[GetRandomValue(0, 1)];
    }
};

class Danda
{
protected:
    void side()
    {
        if (y >= scr_ht - 120)
            y = scr_ht - 120;
        else if (y <= 0)
            y = 0;
    }

public:
    float x, y;
    float spy;
    float dwd, dht;

    void draw()
    {
        DrawRectangleRounded(Rectangle{x, y, dwd, dht}, 0.8, 0, WHITE);
    }
    void move()
    {
        if (IsKeyDown(KEY_W))
        {
            y -= spy;
        }
        else if (IsKeyDown(KEY_S))
        {
            y += spy;
        }
        side();
    }
};
class Bot : public Danda
{
public:
    void move(int ball_y)
    {
        if (y + dht / 2 >= ball_y)
            y -= spy;
        else
            y += spy;

        side();
    }
};
Ball ball;
Danda player;
Bot bot;
int main()
{
    InitWindow(scr_wd, scr_ht, "TONG PONG V1!");
    SetTargetFPS(60);

    // the frickin ball
    ball.x = scr_wd / 2;
    ball.y = scr_ht / 2;
    ball.spx = 7;
    ball.spy = 7;
    ball.rad = 20;

    // player shits
    player.x = 50;
    player.y = (scr_ht / 2 - 50);
    player.dht = 120;
    player.dwd = 20;
    player.spy = 10;

    // bot player stuffs
    bot.x = 1280 - 50;
    bot.y = (scr_ht / 2 - 50);
    bot.dht = 120;
    bot.dwd = 20;
    bot.spy = 6;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKPURPLE);
        DrawRectangle(scr_wd / 2, 0, scr_wd / 2, scr_ht, VIOLET);
        DrawCircle(scr_wd / 2, scr_ht / 2, 150, PURPLE);
        DrawLine(scr_wd / 2, 0, scr_wd / 2, scr_ht, WHITE);
        ball.draw();
        ball.move();
        player.draw();
        player.move();
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.rad, Rectangle{player.x, player.y, player.dwd, player.dht}))
            ball.spx *= -1;

        DrawText(TextFormat("%i", bot_point), scr_wd / 4 - 20, 20, 70, RED);
        DrawText(TextFormat("%i", player_point), (scr_wd / 4 - 20) + (scr_wd / 2), 20, 70, RED);

        bot.draw();
        bot.move(ball.y);

        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.rad, Rectangle{bot.x, bot.y, bot.dwd, bot.dht}))
            ball.spx *= -1;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
