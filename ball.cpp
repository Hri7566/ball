#include <iostream>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>

class Ball {
public:
    int x, y, velx, vely, oldx, oldy;
    Ball(int xx, int yy) {
        x = xx;
        y = yy;
        velx = 1;
        vely = 1;
    };
};

int main()
{
    // Vars
    int c = 0;
    Ball ball = Ball(5, 8);

    // Init
    initscr();
    noecho();
    curs_set(0);

    while (c != 1) {
        // Update
        ball.oldx = ball.x;
        ball.oldy = ball.y;

        if (ball.x < 2 || ball.x > 28) {
            ball.velx = -ball.velx;
        }
        if (ball.y < 2 || ball.y > 8) {
            ball.vely = -ball.vely;
        }
        ball.x += ball.velx;
        ball.y += ball.vely;

        // Draw
        
        // Draw walls
        
        mvprintw(0, 0, "+");
        mvprintw(0, 30, "+");
        mvprintw(10, 0, "+");
        mvprintw(10, 30, "+");
        for (int i = 1; i < 30; i++) {
            mvprintw(0, i, "-");
            mvprintw(10, i, "-");
        }
        for (int i = 1; i < 10; i++) {
            mvprintw(i, 0, "|");
            mvprintw(i, 30, "|");
        }

        // Draw ball
        mvprintw(ball.y, ball.x, "O");
        mvprintw(ball.oldy, ball.oldx, " ");

        mvprintw(11, 0, "Ball by Hri7566");

        // Refresh to show changes
        refresh();
        usleep(100000);
    }

    endwin();
    return 0;
}