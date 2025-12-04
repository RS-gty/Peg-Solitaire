#include <iostream>
#include <easyx.h>
#include <graphics.h>

int main()
{
    initgraph(480, 600);
    setlinecolor(WHITE);
    setfillcolor(RED);
    fillrectangle(150, 60, 200, 85);
    ExMessage m;
    int trigger = 0;
    while (1)
    {
        peekmessage(&m, EM_MOUSE);

        if (m.message == WM_LBUTTONDOWN)
        {
            trigger = 1;
        }
        else if (m.message == WM_LBUTTONUP && trigger == 1)
        {
            trigger = 0;
            printf("左键按键...... %d, %d\n", m.x, m.y);
            if (m.x >= 150 && m.x <= 200 && m.y >= 60 && m.y <= 85)
            {
                printf("点击了矩形区域！\n");
			}
		}
        else if (m.message == WM_RBUTTONDOWN)
        {
            printf("右键按键......\n");
			closegraph();
        }
    }
    return 0;
}