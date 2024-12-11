# SerialPi-Test

Raspberry Pi でシリアル通信のテスト用プログラム

## セットアップ

実行には wiringpi が必要です。
以下のコマンドでインストールしてください。

```sh
sudo apt update
sudo apt dist-upgrade
sudo apt autoremove
sudo apt install wiringpi
```

## ビルド

```sh
gcc -o serial_test serial_test.c -lwiringPi
```

## 利用可能なCOMポート表示コマンド

```sh
ls /dev/tty*
```
