/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 16:23:50
 * @LastEditTime: 2020-08-05 16:34:36
 * @FilePath: \gtk\key_event\key_event.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>	// 头文件
#include <gdk/gdkkeysyms.h>	//键盘头文件

// 键盘按下事件处理函数
gboolean deal_key_press(GtkWidget *widget, GdkEventKey  *event, gpointer data)
{
	switch(event->keyval)
    {	
        // 键盘键值类型
        case GDK_Up:
            g_print("Up\n");
            break;

        case GDK_Left:
            g_print("Left\n");
            break;

        case GDK_Right:
            g_print("Right\n");
            break;

        case GDK_Down:
            g_print("Down\n");
            break;

        default:
            printf("Unknown Button!!\n");
    }

	int key = event->keyval; // 获取键盘键值类型
	g_print("keyval = %d\n", key);
	
	return TRUE;
}

int main( int argc, char *argv[] )
{
	gtk_init(&argc, &argv);		// 初始化

    // 创建顶层窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// 设置窗口的标题
	gtk_window_set_title(GTK_WINDOW(window), "cpucode mouse_event");
	// 设置窗口在显示器中的位置为居中
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	// 设置窗口的最小大小
	gtk_widget_set_size_request(window, 400, 300);
	// "destroy" 和 gtk_main_quit 连接
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// "key-press-event" 与 deal_key_press 连接
	g_signal_connect(window, "key-press-event", G_CALLBACK(deal_key_press), NULL);

    gtk_widget_show_all(window);	// 显示窗口全部控件
	
    gtk_main();		// 主事件循环
	
    return 0;
}







