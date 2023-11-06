# get_conv_specification

## prototype

```c
t_conv_specification *get_conv_specification(const char *format);
```

## 戻り値

成功時: 変換指定子の構造体
失敗時: NULL

## description

* 文字列から次の変換指定子の構造体を取得する。
* 一文字目が`%`である必要があります。
