
# print_percent_fd

## prototype

```c
int	print_percent_fd(int fd, t_conv_specification *cs, va_list args);
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

* `%i`用の出力関数。
* `%c`と同じような挙動になる。ただし、出力文字は`%`のみ。
* 引数`arg`を消費しない。
