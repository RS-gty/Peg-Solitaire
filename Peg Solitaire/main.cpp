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
    while (1) // 进入无限循环
    {
        peekmessage(&m, EM_MOUSE); // 检查是否有鼠标消息，将消息存储在m中

        if (m.message == WM_LBUTTONDOWN) // 如果检测到鼠标左键按下消息
        {
            trigger = 1;
        }
        else if (m.message == WM_LBUTTONUP && trigger == 1) // 如果检测到鼠标左键抬起消息且触发器为1
        {
            trigger = 0; // 重置触发器
            printf("左键按键...... %d, %d\n", m.x, m.y); // 输出提示信息：左键按键
            if (m.x >= 150 && m.x <= 200 && m.y >= 60 && m.y <= 85) // 如果鼠标位置在指定矩形区域内
            {
                printf("点击了矩形区域！\n"); // 输出提示信息：点击了矩形区域
			}
		}
        else if (m.message == WM_RBUTTONDOWN) // 如果检测到鼠标右键按下消息
        {
            printf("右键按键......\n"); // 输出提示信息：右键按键
			closegraph(); // 关闭图形窗口
        }
    }
    return 0;
}