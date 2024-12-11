# SerialPi-Test

Raspberry Pi でシリアル通信のテスト用プログラム

## セットアップ

実行には wiringpi が必要です。
以下のコマンドをインストールしてください。

```sh
sudo apt-get update
sudo apt-get install wiringpi
```

## ビルド

```sh
gcc -o serial_test serial_test.c -lwiringPi
```
