
# print_pointer_fd

## prototype

```c
int	print_pointer_fd(int fd, t_conv_specification *cs, va_list args);
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

* `%p`用の出力関数。
* `%#x`と同じような挙動になる。
