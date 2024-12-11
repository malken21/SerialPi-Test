#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>

int main()
{
    char *port = "/dev/ttyUSB0";                 // 使用するシリアルポートを指定
    int baud_rate = 9600;                        // ボーレートを指定
    const char *command = "your_command_here\n"; // 送信するコマンド

    int serial_port;
    // シリアルポートを開く
    if ((serial_port = serialOpen(port, baud_rate)) < 0)
    {
        fprintf(stderr, "Unable to open serial port\n");
        return 1;
    }

    // wiringPiの初期化
    if (wiringPiSetup() == -1)
    {
        fprintf(stderr, "Unable to start wiringPi\n");
        return 1;
    }

    // コマンドをシリアルポートに送信
    serialPuts(serial_port, command);

    // 返信がある場合、読み取る
    char response[256];
    int index = 0;
    while (serialDataAvail(serial_port))
    {
        response[index++] = serialGetchar(serial_port);
        if (index >= sizeof(response) - 1)
            break;
    }
    response[index] = '\0'; // 文字列の終端を追加
    printf("Response: %s\n", response);

    // シリアルポートを閉じる
    serialClose(serial_port);

    return 0;
}
